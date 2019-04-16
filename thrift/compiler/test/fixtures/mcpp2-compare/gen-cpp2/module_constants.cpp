/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/module_constants.h"

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_constants.h"
#include <folly/Indestructible.h>

namespace some { namespace valid { namespace ns {

constexpr bool const module_constants::aBool_;

constexpr int8_t const module_constants::aByte_;

constexpr int16_t const module_constants::a16BitInt_;

constexpr int32_t const module_constants::a32BitInt_;

constexpr int64_t const module_constants::a64BitInt_;

constexpr float const module_constants::aFloat_;

constexpr double const module_constants::aDouble_;

constexpr char const * const module_constants::aString_;

std::vector<bool> const& module_constants::aList() {
  static folly::Indestructible<std::vector<bool>> const instance(std::initializer_list<bool>{true,
  false});
  return *instance;
}

std::map<std::string, int32_t> const& module_constants::anEmptyMap() {
  static folly::Indestructible<std::map<std::string, int32_t>> const instance;
  return *instance;
}

std::map<int32_t, std::string> const& module_constants::aMap() {
  static folly::Indestructible<std::map<int32_t, std::string>> const instance(std::initializer_list<std::pair<const int32_t, std::string>>{{1, apache::thrift::StringTraits< std::string>::fromStringLiteral("foo")},
  {2, apache::thrift::StringTraits< std::string>::fromStringLiteral("bar")}});
  return *instance;
}

std::set<std::string> const& module_constants::aSet() {
  static folly::Indestructible<std::set<std::string>> const instance(std::initializer_list<std::string>{apache::thrift::StringTraits< std::string>::fromStringLiteral("foo"),
  apache::thrift::StringTraits< std::string>::fromStringLiteral("bar")});
  return *instance;
}

std::vector<std::vector<int32_t>> const& module_constants::aListOfLists() {
  static folly::Indestructible<std::vector<std::vector<int32_t>>> const instance(std::initializer_list<std::vector<int32_t>>{std::initializer_list<int32_t>{1,
  3,
  5,
  7,
  9},
  std::initializer_list<int32_t>{2,
  4,
  8,
  10,
  12}});
  return *instance;
}

std::vector<std::map<std::string, int32_t>> const& module_constants::states() {
  static folly::Indestructible<std::vector<std::map<std::string, int32_t>>> const instance(std::initializer_list<std::map<std::string, int32_t>>{std::initializer_list<std::pair<const std::string, int32_t>>{{apache::thrift::StringTraits< std::string>::fromStringLiteral("San Diego"), 3211000},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("Sacramento"), 479600},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("SF"), 837400}},
  std::initializer_list<std::pair<const std::string, int32_t>>{{apache::thrift::StringTraits< std::string>::fromStringLiteral("New York"), 8406000},
  {apache::thrift::StringTraits< std::string>::fromStringLiteral("Albany"), 98400}}});
  return *instance;
}

std::vector< ::some::valid::ns::MyEnumA> const& module_constants::AConstList() {
  static folly::Indestructible<std::vector< ::some::valid::ns::MyEnumA>> const instance(std::initializer_list< ::some::valid::ns::MyEnumA>{ ::some::valid::ns::MyEnumA::fieldA,
   ::some::valid::ns::MyEnumA::fieldB,
  static_cast< ::some::valid::ns::MyEnumA>(3)});
  return *instance;
}

constexpr int32_t const module_constants::AnIntegerEnum2_;

std::vector<int32_t> const& module_constants::AnIntegerEnum2() {
  static folly::Indestructible<std::vector<int32_t>> const instance(std::initializer_list<int32_t>{2,
  1});
  return *instance;
}

constexpr  ::some::valid::ns::MyEnumA const module_constants::constEnumA_;

constexpr  ::some::valid::ns::MyEnumA const module_constants::constEnumB_;

}}} // some::valid::ns
