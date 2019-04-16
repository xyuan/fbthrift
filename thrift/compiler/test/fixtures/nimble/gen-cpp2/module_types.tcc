/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/nimble/gen-cpp2/module_types.h"

#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>
#include <thrift/lib/cpp2/gen/module_types_tcc.h>

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/ProtocolReaderStructReadState.h>


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits< ::cpp2::BasicTypes> {
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
void BasicTypes::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;

  bool isset_first = false;

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_first:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::read(*iprot, this->first);
    isset_first = true;
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_second:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::read(*iprot, this->second);
    this->__isset.second = true;
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_I64))) {
    goto _loop;
  }
_readField_third:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::read(*iprot, this->third);
    this->__isset.third = true;
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          4,
          apache::thrift::protocol::T_BOOL))) {
    goto _loop;
  }
_readField_isTrue:
  {
    iprot->readBool(this->isTrue);
    this->__isset.isTrue = true;
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          4,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  if (!isset_first) {
    TProtocolException::throwMissingRequiredField("first", "BasicTypes");
  }
  return;

_loop:
  if (_readState.fieldType == apache::thrift::protocol::T_STOP) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    apache::thrift::detail::TccStructTraits<BasicTypes>::translateFieldName(_readState.fieldName(), _readState.fieldId, _readState.fieldType);
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I32)) {
        goto _readField_first;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I32)) {
        goto _readField_second;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I64)) {
        goto _readField_third;
      } else {
        goto _skip;
      }
    }
    case 4:
    {
      if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_BOOL)) {
        goto _readField_isTrue;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      iprot->skip(_readState.fieldType);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t BasicTypes::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("BasicTypes");
  xfer += prot_->serializedFieldSize("first", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(*prot_, this->first);
  if (this->__isset.second) {
    xfer += prot_->serializedFieldSize("second", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(*prot_, this->second);
  }
  if (this->__isset.third) {
    xfer += prot_->serializedFieldSize("third", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->third);
  }
  xfer += prot_->serializedFieldSize("isTrue", apache::thrift::protocol::T_BOOL, 4);
  xfer += prot_->serializedSizeBool(this->isTrue);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t BasicTypes::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("BasicTypes");
  xfer += prot_->serializedFieldSize("first", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(*prot_, this->first);
  if (this->__isset.second) {
    xfer += prot_->serializedFieldSize("second", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(*prot_, this->second);
  }
  if (this->__isset.third) {
    xfer += prot_->serializedFieldSize("third", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->third);
  }
  xfer += prot_->serializedFieldSize("isTrue", apache::thrift::protocol::T_BOOL, 4);
  xfer += prot_->serializedSizeBool(this->isTrue);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t BasicTypes::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("BasicTypes");
  xfer += prot_->writeFieldBegin("first", apache::thrift::protocol::T_I32, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::write(*prot_, this->first);
  xfer += prot_->writeFieldEnd();
  if (this->__isset.second) {
    xfer += prot_->writeFieldBegin("second", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int32_t>::write(*prot_, this->second);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.third) {
    xfer += prot_->writeFieldBegin("third", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::write(*prot_, this->third);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldBegin("isTrue", apache::thrift::protocol::T_BOOL, 4);
  xfer += prot_->writeBool(this->isTrue);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void BasicTypes::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t BasicTypes::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t BasicTypes::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t BasicTypes::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void BasicTypes::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t BasicTypes::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t BasicTypes::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t BasicTypes::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
