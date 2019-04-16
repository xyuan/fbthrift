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

#include "thrift/compiler/test/fixtures/optionals/gen-cpp2/module_types.h"

namespace cpp2 {

struct _AnimalEnumDataStorage {
  using type = Animal;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<Animal, 3> values = {{
    Animal::DOG,
    Animal::CAT,
    Animal::TARANTULA,
  }};
  static constexpr const std::array<folly::StringPiece, 3> names = {{
    "DOG",
    "CAT",
    "TARANTULA",
  }};
};

} // cpp2
namespace apache { namespace thrift {

template <> struct TEnumDataStorage< ::cpp2::Animal> {
  using storage_type =  ::cpp2::_AnimalEnumDataStorage;
};

}} // apache::thrift

