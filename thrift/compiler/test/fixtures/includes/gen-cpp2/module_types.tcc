/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::cpp2::MyStruct> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

template <class Protocol_>
void MyStruct::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_STRUCT))) {
    goto _loop;
  }
_readField_MyIncludedField:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::read(iprot, &this->MyIncludedField);
    this->__isset.MyIncludedField = true;
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_STRUCT))) {
    goto _loop;
  }
_readField_MyOtherIncludedField:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::read(iprot, &this->MyOtherIncludedField);
    this->__isset.MyOtherIncludedField = true;
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_I64))) {
    goto _loop;
  }
_readField_MyIncludedInt:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral,  ::cpp2::IncludedInt64>::readWithContext(*iprot, this->MyIncludedInt, _readState);
    this->__isset.MyIncludedInt = true;
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<MyStruct>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_MyIncludedField;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_MyOtherIncludedField;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I64))) {
        goto _readField_MyIncludedInt;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t MyStruct::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("MyStruct");
  xfer += prot_->serializedFieldSize("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSize(prot_, &this->MyIncludedField);
  xfer += prot_->serializedFieldSize("MyOtherIncludedField", apache::thrift::protocol::T_STRUCT, 2);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSize(prot_, &this->MyOtherIncludedField);
  xfer += prot_->serializedFieldSize("MyIncludedInt", apache::thrift::protocol::T_I64, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral,  ::cpp2::IncludedInt64>::serializedSize<false>(*prot_, this->MyIncludedInt);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t MyStruct::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("MyStruct");
  xfer += prot_->serializedFieldSize("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSizeZC(prot_, &this->MyIncludedField);
  xfer += prot_->serializedFieldSize("MyOtherIncludedField", apache::thrift::protocol::T_STRUCT, 2);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::serializedSizeZC(prot_, &this->MyOtherIncludedField);
  xfer += prot_->serializedFieldSize("MyIncludedInt", apache::thrift::protocol::T_I64, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral,  ::cpp2::IncludedInt64>::serializedSize<false>(*prot_, this->MyIncludedInt);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t MyStruct::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("MyStruct");
  xfer += prot_->writeFieldBegin("MyIncludedField", apache::thrift::protocol::T_STRUCT, 1);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::write(prot_, &this->MyIncludedField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("MyOtherIncludedField", apache::thrift::protocol::T_STRUCT, 2);
  xfer += ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::write(prot_, &this->MyOtherIncludedField);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("MyIncludedInt", apache::thrift::protocol::T_I64, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral,  ::cpp2::IncludedInt64>::write(*prot_, this->MyIncludedInt);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
