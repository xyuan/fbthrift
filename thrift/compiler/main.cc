/*
 * Copyright 2017-present Facebook, Inc.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/**
 * thrift - a lightweight cross-language rpc/serialization tool
 *
 * This file contains the main compiler engine for Thrift, which invokes the
 * scanner/parser to build the thrift object tree. The interface generation
 * code for each language lives in a file by the language name under the
 * generate/ folder, and all parse structures live in parse/
 *
 */

#ifdef _WIN32
#include <process.h> // @manual
#else
#include <unistd.h>
#endif
#include <ctime>

#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem.hpp>

#include <thrift/compiler/generate/t_generator.h>
#include <thrift/compiler/mutator/mutator.h>
#include <thrift/compiler/platform.h>
#include <thrift/compiler/validator/validator.h>

#include <thrift/compiler/parse/parsing_driver.h>

using namespace std;

/**
 * Flags to control code generation
 */
bool gen_recurse = false;

ofstream genfile_file;
bool record_genfiles = false;

/**
 * Diplays the usage message and then exits with an error code.
 */
[[noreturn]] static void usage() {
  fprintf(stderr, "Usage: thrift [options] file\n");
  fprintf(stderr, "Options:\n");
  fprintf(
      stderr, "  -o dir      Set the output directory for gen-* packages\n");
  fprintf(stderr, "               (default: current directory)\n");
  fprintf(
      stderr, "  -out dir    Set the output location for generated files\n");
  fprintf(
      stderr,
      "  --templates dir    Set the directory containing mstch templates\n");
  fprintf(stderr, "               (no gen-* folder will be created)\n");
  fprintf(stderr, "  -I dir      Add a directory to the list of directories\n");
  fprintf(stderr, "                searched for include directives\n");
  fprintf(stderr, "  -nowarn     Suppress all compiler warnings (BAD!)\n");
  fprintf(stderr, "  -strict     Strict compiler warnings on\n");
  fprintf(stderr, "  -v[erbose]  Verbose mode\n");
  fprintf(stderr, "  -r[ecurse]  Also generate included files\n");
  fprintf(stderr, "  -debug      Parse debug trace to stdout\n");
  fprintf(
      stderr,
      "  --allow-neg-keys  Allow negative field keys (Used to "
      "preserve protocol\n");
  fprintf(stderr, "                compatibility with older .thrift files)\n");
  fprintf(stderr, "  --allow-neg-enum-vals Allow negative enum vals\n");
  fprintf(
      stderr,
      "  --allow-64bit-consts  Do not print warnings about using 64-bit constants\n");
  fprintf(
      stderr,
      "  --gen STR   Generate code with a dynamically-registered generator.\n");
  fprintf(
      stderr,
      "                STR has the form language[:key1=val1[,key2,[key3=val3]]].\n");
  fprintf(
      stderr,
      "                Keys and values are options passed to the generator.\n");
  fprintf(stderr, "                Many options will not require values.\n");
  fprintf(stderr, "  --record-genfiles FILE\n");
  fprintf(stderr, "              Save the list of generated files to FILE\n");
  fprintf(stderr, "  --python-compiler FILE\n");
  fprintf(
      stderr,
      "              Path to the python implementation of the thrift compiler\n");
  fprintf(stderr, "\n");
  fprintf(stderr, "Available generators (and options):\n");

  t_generator_registry::gen_map_t gen_map =
      t_generator_registry::get_generator_map();
  t_generator_registry::gen_map_t::iterator iter;
  for (iter = gen_map.begin(); iter != gen_map.end(); ++iter) {
    fprintf(
        stderr,
        "  %s (%s):\n",
        iter->second->get_short_name().c_str(),
        iter->second->get_long_name().c_str());
    fprintf(stderr, "%s", iter->second->get_documentation().c_str());
  }
  exit(1);
}

static bool python_generator(
    std::string& options,
    const std::string& user_python_compiler,
    std::vector<std::string>& arguments) {
  // Attempt to call the new python compiler if we can find it
  string path = arguments[0];
  size_t last = path.find_last_of("/");
  if (last != string::npos) {
    ifstream ifile;
    auto dirname = path.substr(0, last + 1);
    std::string pycompiler;
    std::vector<std::string> pycompilers;
    if (!user_python_compiler.empty()) {
      pycompilers.push_back(user_python_compiler);
    }
    pycompilers.insert(
        pycompilers.end(),
        {
            dirname + "py/thrift.lpar",
            dirname + "../py/thrift.lpar",
            dirname + "py/thrift.par",
            dirname + "../py/thrift.par",
            dirname + "py/thrift.xar",
            dirname + "../py/thrift.xar",
            dirname + "py/thrift.pex",
            dirname + "../py/thrift.pex",
        });
    for (const auto& comp : pycompilers) {
      pycompiler = comp;
      ifile.open(pycompiler.c_str());
      if (ifile)
        break;
    }
    int ret = 0;
    if (ifile) {
      // Convert arguments to argv
      std::vector<char*> argv(arguments.size() + 1);
      for (size_t i = 0; i < arguments.size(); ++i) {
        if (arguments[i][0] == '-' && arguments[i] != "-I" &&
            arguments[i] != "-o") {
          arguments[i].insert(0, "-");
        }
        argv[i] = const_cast<char*>(arguments[i].c_str());
      }
      argv[arguments.size()] = nullptr;
      ret = execv(pycompiler.c_str(), argv.data());
    }
    if (!ifile || ret < 0) {
      pwarning(
          1,
          "Unable to get a generator for \"%s\" ret: %d.\n",
          options.c_str(),
          ret);
    }
  }
  return true;
}

static void filter_py_cpp2_reflection_lang_argument(std::string& lang) {
  std::set<std::string> const passthrough = {
      "include_prefix",
  };

  auto const colon_pos = lang.find(':');
  if (colon_pos == std::string::npos) {
    return;
  }
  auto const lang_name = lang.substr(0, colon_pos);
  if (lang_name != "cpp2" && lang_name != "mstch_cpp2") {
    return;
  }

  auto const lang_args = lang.substr(colon_pos + 1);
  std::vector<std::string> parts;
  boost::algorithm::split(
      parts, lang_args, [](auto const c) { return c == ','; });
  std::vector<std::string> out_args;
  for (auto const& part : parts) {
    auto const equal_pos = part.find('=');
    auto const arg_name = part.substr(0, equal_pos);
    if (passthrough.count(arg_name) != 0) {
      out_args.push_back(part);
    }
  }
  std::string out = "cpp2";
  if (!out_args.empty()) {
    out += ":";
    out += boost::algorithm::join(out_args, ",");
  }
  lang = out;
}

// remove all arguments which py cpp2 reflection generator does not know
static void filter_py_cpp2_reflection_arguments(
    std::vector<std::string>& arguments) {
  for (auto i = size_t(0); i < arguments.size(); ++i) {
    auto const& arg = arguments[i];
    if (arg != "-gen" && arg != "--gen") {
      continue;
    }

    if (i + 1 >= arguments.size()) {
      std::cerr << boost::algorithm::join(arguments, " ") << std::endl;
    }
    assert(i + 1 < arguments.size());
    filter_py_cpp2_reflection_lang_argument(arguments[++i]);
  }
}

static bool generate_cpp2(
    t_program* program,
    t_generation_context context,
    std::string& gen_string,
    const std::string& user_python_compiler,
    std::vector<std::string>& arguments) {
  bool gen_py_cpp2_reflection =
      gen_string.find("reflection") != std::string::npos;

  t_generator* generator =
      t_generator_registry::get_generator(program, context, gen_string);
  if (generator) {
    pverbose("Generating \"%s\"\n", gen_string.c_str());
    generator->generate_program();
    if (record_genfiles) {
      for (const std::string& s : generator->get_genfiles()) {
        genfile_file << s << "\n";
      }
    }
    delete generator;
  }

  if (gen_py_cpp2_reflection) {
    auto py_cpp2_reflection_arguments = arguments;
    filter_py_cpp2_reflection_arguments(py_cpp2_reflection_arguments);
    python_generator(
        gen_string, user_python_compiler, py_cpp2_reflection_arguments);
  }
  return true;
}

/**
 * Generate code
 */
static bool generate(
    t_program* program,
    t_generation_context context,
    vector<string>& generator_strings,
    std::set<std::string>& already_generated,
    const std::string& user_python_compiler,
    std::vector<std::string>& arguments) {
  // Oooohh, recursive code generation, hot!!
  if (gen_recurse) {
    const vector<t_program*>& includes = program->get_included_programs();
    for (const auto& include : includes) {
      if (already_generated.count(include->get_path())) {
        continue;
      }

      if (!generate(
              include,
              context,
              generator_strings,
              already_generated,
              user_python_compiler,
              arguments)) {
        return false;
      } else {
        already_generated.insert(include->get_path());
      }
    }
  }

  // Generate code!
  try {
    pverbose("Program: %s\n", program->get_path().c_str());

    if (dump_docs) {
      dump_docstrings(program);
    }

    for (auto gen_string : generator_strings) {
      auto pos = gen_string.find(":");
      std::string lang = gen_string.substr(0, pos);
      if (lang.find("cpp2") != std::string::npos) {
        generate_cpp2(
            program, context, gen_string, user_python_compiler, arguments);
        continue;
      }

      t_generator* generator =
          t_generator_registry::get_generator(program, context, gen_string);
      if (generator) {
        pverbose("Generating \"%s\"\n", gen_string.c_str());
        generator->generate_program();
        if (record_genfiles) {
          for (const std::string& s : generator->get_genfiles()) {
            genfile_file << s << "\n";
          }
        }
        delete generator;
      }
    }

  } catch (const string& s) {
    printf("Error: %s\n", s.c_str());
    return false;
  } catch (const char* exc) {
    printf("Error: %s\n", exc);
    return false;
  }

  return true;
}

static string get_include_path(
    const vector<string>& generator_strings,
    const string& input_filename) {
  string include_prefix;
  for (const auto& generator_string : generator_strings) {
    if (generator_string.find("cpp") == string::npos) {
      continue;
    } else {
      auto const colon_pos = generator_string.find(':');
      if (colon_pos == std::string::npos) {
        continue;
      }
      auto const lang_name = generator_string.substr(0, colon_pos);
      if (lang_name != "cpp2" && lang_name != "mstch_cpp2") {
        continue;
      }

      auto const lang_args = generator_string.substr(colon_pos + 1);
      std::vector<std::string> parts;
      boost::algorithm::split(
          parts, lang_args, [](const char& c) { return c == ','; });
      for (auto const& part : parts) {
        auto const equal_pos = part.find('=');
        auto const arg_name = part.substr(0, equal_pos);
        if (arg_name.find("include_prefix") != string::npos) {
          include_prefix = part.substr(equal_pos + 1);
        }
      }
    }
  }

  // infer cpp include prefix from the filename passed in if none specified.
  if (include_prefix == "") {
    if (input_filename.rfind("/") != string::npos) {
      include_prefix = input_filename.substr(0, input_filename.rfind("/"));
    }
  }

  return include_prefix;
}

/**
 * Parse it up.. then spit it back out, in pretty much every language. Alright
 * not that many languages, but the cool ones that we care about.
 */
int main(int argc, char** argv) {
  std::string out_path;
  bool out_path_is_absolute = false;
  std::vector<std::string> arguments(argv, argv + argc);

  // Check for necessary arguments, you gotta have at least a filename and
  // an output language flag
  if (argc < 2) {
    usage();
  }

  std::string user_python_compiler;
  vector<std::string> generator_strings;

  g_stage = "arguments";

  std::vector<std::string> incl_searchpath;

  int strict = 127;
  bool allow_neg_field_keys = false;
  bool allow_neg_enum_vals = false;
  bool allow_64bit_consts = false;

  // Hacky parameter handling... I didn't feel like using a library sorry!
  size_t i;
  for (i = 1; i < arguments.size() - 1; ++i) {
    // Treat double dashes as single dashes
    if (arguments[i][0] == '-' && arguments[i][1] == '-') {
      arguments[i] = arguments[i].replace(0, 1, "");
    }

    if (arguments[i] == "-debug") {
      g_debug = 1;
    } else if (arguments[i] == "-nowarn") {
      g_warn = 0;
    } else if (arguments[i] == "-strict") {
      strict = 255;
      g_warn = 2;
    } else if (arguments[i] == "-v" || arguments[i] == "-verbose") {
      g_verbose = 1;
    } else if (arguments[i] == "-r" || arguments[i] == "-recurse") {
      gen_recurse = true;
    } else if (arguments[i] == "-allow-neg-keys") {
      allow_neg_field_keys = true;
    } else if (arguments[i] == "-allow-neg-enum-vals") {
      allow_neg_enum_vals = true;
    } else if (arguments[i] == "-allow-64bit-consts") {
      allow_64bit_consts = true;
    } else if (arguments[i] == "-record-genfiles") {
      record_genfiles = true;
      if (i + 1 == arguments.size() - 1) {
        fprintf(
            stderr,
            "!!! Missing genfile file specification between %s and '%s'\n",
            arguments[i].c_str(),
            arguments[i + 1].c_str());
        usage();
      }
      genfile_file.open(arguments[++i]);
    } else if (arguments[i] == "-gen") {
      if (i + 1 == arguments.size() - 1) {
        fprintf(
            stderr,
            "!!! Missing generator specification between %s and '%s'\n",
            arguments[i].c_str(),
            arguments[i + 1].c_str());
        usage();
      }
      generator_strings.push_back(arguments[++i]);
    } else if (arguments[i] == "-cpp_use_include_prefix") {
      g_cpp_use_include_prefix = true;
    } else if (arguments[i] == "-I") {
      if (i + 1 == arguments.size() - 1) {
        fprintf(
            stderr,
            "!!! Missing Include directory between %s and '%s'\n",
            arguments[i].c_str(),
            arguments[i + 1].c_str());
        usage();
      }
      // An argument of "-I\ asdf" is invalid and has unknown results
      incl_searchpath.push_back(arguments[++i]);
      continue;
    } else if (arguments[i] == "-templates") {
      if (i + 1 == arguments.size() - 1) {
        fprintf(stderr, "-templates: missing template directory");
        usage();
      }
      g_template_dir = arguments[++i];
      continue;
    } else if (arguments[i] == "-o" || (arguments[i] == "-out")) {
      out_path_is_absolute = (arguments[i] == "-out") ? true : false;
      if (i + 1 == arguments.size() - 1) {
        fprintf(
            stderr,
            "-o: missing output directory between %s and '%s'\n",
            arguments[i].c_str(),
            arguments[i + 1].c_str());
        usage();
      }
      out_path = arguments[++i];

      // Strip out trailing \ on a Windows path
      if (apache::thrift::compiler::isWindows()) {
        int last = out_path.length() - 1;
        if (out_path[last] == '\\') {
          out_path.erase(last);
        }
      }

      if (out_path_is_absolute) {
        // Invoker specified `-out blah`. We are supposed to output directly
        // into blah, e.g. `blah/Foo.java`. Make the directory if necessary,
        // just like how for `-o blah` we make `o/gen-java`
        boost::system::error_code errc;
        boost::filesystem::create_directory(out_path, errc);
        if (errc) {
          fprintf(
              stderr,
              "Output path %s is unusable or not a directory\n",
              out_path.c_str());
          return -1;
        }
      }
      if (!boost::filesystem::is_directory(out_path)) {
        fprintf(
            stderr,
            "Output path %s is unusable or not a directory\n",
            out_path.c_str());
        return -1;
      }
      continue;
    } else if (arguments[i] == "-python-compiler") {
      if (i + 1 == arguments.size() - 1) {
        fprintf(
            stderr,
            "No path was given for the python compiler between "
            "%s and '%s'\n",
            arguments[i].c_str(),
            arguments[i + 1].c_str());
        usage();
      }
      user_python_compiler = arguments[++i];
      continue;
    } else {
      fprintf(stderr, "!!! Unrecognized option: %s\n", arguments[i].c_str());
      usage();
    }
  }

  // You gotta generate something!
  if (generator_strings.empty()) {
    fprintf(stderr, "!!! No output language(s) specified\n\n");
    usage();
  }

  // Real-pathify it
  if (arguments.size() < i) {
    fprintf(stderr, "!!! Missing file name\n");
    usage();
  }

  std::string input_file = compute_absolute_path(arguments[i]);

  string input_filename = arguments[i];
  string include_prefix = get_include_path(generator_strings, input_filename);

  g_stage = "parse";

  // Parse it!
  apache::thrift::parsing_params params{};
  params.debug = (g_debug != 0);
  params.verbose = (g_verbose != 0);
  params.warn = g_warn;
  params.strict = strict;
  params.allow_neg_field_keys = allow_neg_field_keys;
  params.allow_neg_enum_vals = allow_neg_enum_vals;
  params.allow_64bit_consts = allow_64bit_consts;
  params.incl_searchpath = std::move(incl_searchpath);
  auto program_bundle{
      parse_and_dump_diagnostics(input_file, std::move(params))};

  // Mutate it!
  apache::thrift::compiler::mutator::mutate(program_bundle->get_root_program());

  // Validate it!
  auto errors = apache::thrift::compiler::validator::validate(
      program_bundle->get_root_program());
  if (!errors.empty()) {
    for (const auto& error : errors) {
      std::cerr << error << std::endl;
    }
    return 1;
  }

  // Generate it!

  g_stage = "generation";

  program_bundle->get_root_program()->set_include_prefix(include_prefix);

  bool success;
  try {
    auto generation_context = (out_path.size() > 0)
        ? t_generation_context{out_path, out_path_is_absolute}
        : t_generation_context{};
    std::set<std::string> already_generated{
        program_bundle->get_root_program()->get_path()};
    success = generate(
        program_bundle->get_root_program(),
        generation_context,
        generator_strings,
        already_generated,
        user_python_compiler,
        arguments);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  // Finished
  if (success) {
    return 0;
  } else {
    return 1;
  }
}
