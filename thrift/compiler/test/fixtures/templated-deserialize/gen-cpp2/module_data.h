/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <array>
#include <cstddef>
#include <thrift/lib/cpp/Thrift.h>

#include "thrift/compiler/test/fixtures/templated-deserialize/gen-cpp2/module_types.h"

namespace cpp2 {

struct _MyEnumAEnumDataStorage {
  using type = MyEnumA;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<MyEnumA, 3> values = {{
    MyEnumA::fieldA,
    MyEnumA::fieldB,
    MyEnumA::fieldC,
  }};
  static constexpr const std::array<folly::StringPiece, 3> names = {{
    "fieldA",
    "fieldB",
    "fieldC",
  }};
};

} // cpp2
namespace apache { namespace thrift {

template <> struct TEnumDataStorage< ::cpp2::MyEnumA> {
  using storage_type =  ::cpp2::_MyEnumAEnumDataStorage;
};

}} // apache::thrift

