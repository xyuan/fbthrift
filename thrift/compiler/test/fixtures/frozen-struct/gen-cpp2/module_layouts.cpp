/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/module_layouts.h"

namespace apache { namespace thrift { namespace frozen {

FROZEN_CTOR( ::some::ns::ModuleA,
  FROZEN_CTOR_FIELD(i32Field, 1)
  FROZEN_CTOR_FIELD(strField, 2)
  FROZEN_CTOR_FIELD(listField, 3)
  FROZEN_CTOR_FIELD(mapField, 4)
  FROZEN_CTOR_FIELD(inclAField, 5)
  FROZEN_CTOR_FIELD(inclBField, 6))
FROZEN_MAXIMIZE( ::some::ns::ModuleA,
  FROZEN_MAXIMIZE_FIELD(i32Field)
  FROZEN_MAXIMIZE_FIELD(strField)
  FROZEN_MAXIMIZE_FIELD(listField)
  FROZEN_MAXIMIZE_FIELD(mapField)
  FROZEN_MAXIMIZE_FIELD(inclAField)
  FROZEN_MAXIMIZE_FIELD(inclBField))
FROZEN_LAYOUT( ::some::ns::ModuleA,
  FROZEN_LAYOUT_FIELD(i32Field)
  FROZEN_LAYOUT_FIELD(strField)
  FROZEN_LAYOUT_FIELD(listField)
  FROZEN_LAYOUT_FIELD(mapField)
  FROZEN_LAYOUT_FIELD(inclAField)
  FROZEN_LAYOUT_FIELD(inclBField))
FROZEN_FREEZE( ::some::ns::ModuleA,
  FROZEN_FREEZE_FIELD(i32Field)
  FROZEN_FREEZE_FIELD(strField)
  FROZEN_FREEZE_FIELD(listField)
  FROZEN_FREEZE_FIELD(mapField)
  FROZEN_FREEZE_FIELD(inclAField)
  FROZEN_FREEZE_FIELD(inclBField))
FROZEN_THAW( ::some::ns::ModuleA,
  FROZEN_THAW_FIELD(i32Field)
  FROZEN_THAW_FIELD(strField)
  FROZEN_THAW_FIELD(listField)
  FROZEN_THAW_FIELD(mapField)
  FROZEN_THAW_FIELD(inclAField)
  FROZEN_THAW_FIELD(inclBField))
FROZEN_DEBUG( ::some::ns::ModuleA,
  FROZEN_DEBUG_FIELD(i32Field)
  FROZEN_DEBUG_FIELD(strField)
  FROZEN_DEBUG_FIELD(listField)
  FROZEN_DEBUG_FIELD(mapField)
  FROZEN_DEBUG_FIELD(inclAField)
  FROZEN_DEBUG_FIELD(inclBField))
FROZEN_CLEAR( ::some::ns::ModuleA,
  FROZEN_CLEAR_FIELD(i32Field)
  FROZEN_CLEAR_FIELD(strField)
  FROZEN_CLEAR_FIELD(listField)
  FROZEN_CLEAR_FIELD(mapField)
  FROZEN_CLEAR_FIELD(inclAField)
  FROZEN_CLEAR_FIELD(inclBField))
FROZEN_CTOR( ::some::ns::ModuleB,
  FROZEN_CTOR_FIELD(i32Field, 1)
  FROZEN_CTOR_FIELD(inclEnumB, 2))
FROZEN_MAXIMIZE( ::some::ns::ModuleB,
  FROZEN_MAXIMIZE_FIELD(i32Field)
  FROZEN_MAXIMIZE_FIELD(inclEnumB))
FROZEN_LAYOUT( ::some::ns::ModuleB,
  FROZEN_LAYOUT_FIELD(i32Field)
  FROZEN_LAYOUT_FIELD(inclEnumB))
FROZEN_FREEZE( ::some::ns::ModuleB,
  FROZEN_FREEZE_FIELD(i32Field)
  FROZEN_FREEZE_FIELD(inclEnumB))
FROZEN_THAW( ::some::ns::ModuleB,
  FROZEN_THAW_FIELD(i32Field)
  FROZEN_THAW_FIELD(inclEnumB))
FROZEN_DEBUG( ::some::ns::ModuleB,
  FROZEN_DEBUG_FIELD(i32Field)
  FROZEN_DEBUG_FIELD(inclEnumB))
FROZEN_CLEAR( ::some::ns::ModuleB,
  FROZEN_CLEAR_FIELD(i32Field)
  FROZEN_CLEAR_FIELD(inclEnumB))

}}} // apache::thrift::frozen
