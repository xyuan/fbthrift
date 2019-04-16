/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "thrift/compiler/test/fixtures/constants/gen-cpp2/module_constants.h"

#include <folly/Indestructible.h>

namespace cpp2 {

constexpr int32_t const module_constants::myInt_;

constexpr char const * const module_constants::name_;

std::vector<std::map<std::string, int32_t>> const& module_constants::states() {
  static folly::Indestructible<std::vector<std::map<std::string, int32_t>>> const instance(std::initializer_list<std::map<std::string, int32_t>>{std::initializer_list<std::pair<const std::string, int32_t>>{{apache::thrift::StringTraits< std::string>::fromStringLiteral("San Diego"), 3211000},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("Sacramento"), 479600},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("SF"), 837400}},
  std::initializer_list<std::pair<const std::string, int32_t>>{{apache::thrift::StringTraits< std::string>::fromStringLiteral("New York"), 8406000},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("Albany"), 98400}}});
  return *instance;
}

constexpr double const module_constants::x_;

constexpr double const module_constants::y_;

constexpr double const module_constants::z_;

constexpr double const module_constants::zeroDoubleValue_;

constexpr double const module_constants::longDoubleValue_;

constexpr char const * const module_constants::foo_;

constexpr  ::cpp2::MyIntIdentifier const module_constants::bar_;

 ::cpp2::Internship const& module_constants::instagram() {
  static folly::Indestructible< ::cpp2::Internship> const instance(::apache::thrift::detail::make_constant< ::cpp2::Internship>(::apache::thrift::detail::wrap_argument<1>(12), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("Software Engineer")), ::apache::thrift::detail::wrap_argument<3>( ::cpp2::Company::INSTAGRAM)));
  return *instance;
}

 ::cpp2::Internship const& module_constants::partial_const() {
  static folly::Indestructible< ::cpp2::Internship> const instance(::apache::thrift::detail::make_constant< ::cpp2::Internship>(::apache::thrift::detail::wrap_argument<1>(8), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("Some Job"))));
  return *instance;
}

std::vector< ::cpp2::Range> const& module_constants::kRanges() {
  static folly::Indestructible<std::vector< ::cpp2::Range>> const instance(std::initializer_list< ::cpp2::Range>{::apache::thrift::detail::make_constant< ::cpp2::Range>(::apache::thrift::detail::wrap_argument<1>(1), ::apache::thrift::detail::wrap_argument<2>(2)),
  ::apache::thrift::detail::make_constant< ::cpp2::Range>(::apache::thrift::detail::wrap_argument<1>(5), ::apache::thrift::detail::wrap_argument<2>(6))});
  return *instance;
}

std::vector< ::cpp2::Internship> const& module_constants::internList() {
  static folly::Indestructible<std::vector< ::cpp2::Internship>> const instance(std::initializer_list< ::cpp2::Internship>{::cpp2::module_constants::instagram(),
  ::apache::thrift::detail::make_constant< ::cpp2::Internship>(::apache::thrift::detail::wrap_argument<1>(10), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("Sales Intern")), ::apache::thrift::detail::wrap_argument<3>( ::cpp2::Company::FACEBOOK))});
  return *instance;
}

 ::cpp2::struct1 const& module_constants::pod_0() {
  static folly::Indestructible< ::cpp2::struct1> const instance;
  return *instance;
}

 ::cpp2::struct1 const& module_constants::pod_1() {
  static folly::Indestructible< ::cpp2::struct1> const instance(::apache::thrift::detail::make_constant< ::cpp2::struct1>(::apache::thrift::detail::wrap_argument<1>(10), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("foo"))));
  return *instance;
}

 ::cpp2::struct2 const& module_constants::pod_2() {
  static folly::Indestructible< ::cpp2::struct2> const instance(::apache::thrift::detail::make_constant< ::cpp2::struct2>(::apache::thrift::detail::wrap_argument<1>(98), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("gaz")), ::apache::thrift::detail::wrap_argument<3>(::apache::thrift::detail::make_constant< ::cpp2::struct1>(::apache::thrift::detail::wrap_argument<1>(12), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("bar")))), ::apache::thrift::detail::wrap_argument<4>(std::initializer_list<int32_t>{11,
  22,
  33})));
  return *instance;
}

 ::cpp2::struct3 const& module_constants::pod_3() {
  static folly::Indestructible< ::cpp2::struct3> const instance(::apache::thrift::detail::make_constant< ::cpp2::struct3>(::apache::thrift::detail::wrap_argument<1>(apache::thrift::StringTraits< std::string>::fromStringLiteral("abc")), ::apache::thrift::detail::wrap_argument<2>(456), ::apache::thrift::detail::wrap_argument<3>(::apache::thrift::detail::make_constant< ::cpp2::struct2>(::apache::thrift::detail::wrap_argument<1>(888), ::apache::thrift::detail::wrap_argument<3>(::apache::thrift::detail::make_constant< ::cpp2::struct1>(::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("gaz")))), ::apache::thrift::detail::wrap_argument<4>(std::initializer_list<int32_t>{1,
  2,
  3})))));
  return *instance;
}

 ::cpp2::union1 const& module_constants::u_1_1() {
  static folly::Indestructible< ::cpp2::union1> const instance(::apache::thrift::detail::make_constant< ::cpp2::union1>(::apache::thrift::detail::wrap_argument<1>(97)));
  return *instance;
}

 ::cpp2::union1 const& module_constants::u_1_2() {
  static folly::Indestructible< ::cpp2::union1> const instance(::apache::thrift::detail::make_constant< ::cpp2::union1>(::apache::thrift::detail::wrap_argument<2>(5.6)));
  return *instance;
}

 ::cpp2::union1 const& module_constants::u_1_3() {
  static folly::Indestructible< ::cpp2::union1> const instance;
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_1() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<1>(51)));
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_2() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<2>(6.7)));
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_3() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<3>(::apache::thrift::detail::make_constant< ::cpp2::struct1>(::apache::thrift::detail::wrap_argument<1>(8), ::apache::thrift::detail::wrap_argument<2>(apache::thrift::StringTraits< std::string>::fromStringLiteral("abacabb"))))));
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_4() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<4>(::apache::thrift::detail::make_constant< ::cpp2::union1>(::apache::thrift::detail::wrap_argument<1>(43)))));
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_5() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<4>(::apache::thrift::detail::make_constant< ::cpp2::union1>(::apache::thrift::detail::wrap_argument<2>(9.8)))));
  return *instance;
}

 ::cpp2::union2 const& module_constants::u_2_6() {
  static folly::Indestructible< ::cpp2::union2> const instance(::apache::thrift::detail::make_constant< ::cpp2::union2>(::apache::thrift::detail::wrap_argument<4>(::apache::thrift::detail::make_constant< ::cpp2::union1>())));
  return *instance;
}

constexpr char const * const module_constants::apostrophe_;

constexpr char const * const module_constants::tripleApostrophe_;

constexpr char const * const module_constants::quotationMark_;

constexpr char const * const module_constants::backslash_;

constexpr char const * const module_constants::escaped_a_;

std::map<std::string, int32_t> const& module_constants::char2ascii() {
  static folly::Indestructible<std::map<std::string, int32_t>> const instance(std::initializer_list<std::pair<const std::string, int32_t>>{{apache::thrift::StringTraits< std::string>::fromStringLiteral("'"), 39},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("\""), 34},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("\\"), 92},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("\x61"), 97}});
  return *instance;
}

std::vector<std::string> const& module_constants::escaped_strings() {
  static folly::Indestructible<std::vector<std::string>> const instance(std::initializer_list<std::string>{apache::thrift::StringTraits< std::string>::fromStringLiteral("\x61"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\xab"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\x6a"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\xa6"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\x61yyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\xabyyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\x6ayyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("\xa6yyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\x61"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\xab"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\x6a"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\xa6"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\x61yyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\xabyyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\x6ayyy"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("zzz\xa6yyy")});
  return *instance;
}

constexpr bool const module_constants::false_c_;

constexpr bool const module_constants::true_c_;

constexpr int8_t const module_constants::zero_byte_;

constexpr int16_t const module_constants::zero16_;

constexpr int32_t const module_constants::zero32_;

constexpr int64_t const module_constants::zero64_;

constexpr double const module_constants::zero_dot_zero_;

constexpr char const * const module_constants::empty_string_;

std::vector<int32_t> const& module_constants::empty_int_list() {
  static folly::Indestructible<std::vector<int32_t>> const instance;
  return *instance;
}

std::vector<std::string> const& module_constants::empty_string_list() {
  static folly::Indestructible<std::vector<std::string>> const instance;
  return *instance;
}

std::set<int32_t> const& module_constants::empty_int_set() {
  static folly::Indestructible<std::set<int32_t>> const instance;
  return *instance;
}

std::set<std::string> const& module_constants::empty_string_set() {
  static folly::Indestructible<std::set<std::string>> const instance;
  return *instance;
}

std::map<int32_t, int32_t> const& module_constants::empty_int_int_map() {
  static folly::Indestructible<std::map<int32_t, int32_t>> const instance;
  return *instance;
}

std::map<int32_t, std::string> const& module_constants::empty_int_string_map() {
  static folly::Indestructible<std::map<int32_t, std::string>> const instance;
  return *instance;
}

std::map<std::string, int32_t> const& module_constants::empty_string_int_map() {
  static folly::Indestructible<std::map<std::string, int32_t>> const instance;
  return *instance;
}

std::map<std::string, std::string> const& module_constants::empty_string_string_map() {
  static folly::Indestructible<std::map<std::string, std::string>> const instance;
  return *instance;
}

} // cpp2
