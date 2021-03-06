/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.includes;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@ThriftStruct(value="MyStruct", builder=MyStruct.Builder.class)
public final class MyStruct {
    @ThriftConstructor
    public MyStruct(
        @ThriftField(value=1, name="MyIncludedField", requiredness=Requiredness.NONE) final test.fixtures.includes.includes.Included myIncludedField,
        @ThriftField(value=2, name="MyOtherIncludedField", requiredness=Requiredness.NONE) final test.fixtures.includes.includes.Included myOtherIncludedField,
        @ThriftField(value=3, name="MyIncludedInt", requiredness=Requiredness.NONE) final long myIncludedInt
    ) {
        this.myIncludedField = myIncludedField;
        this.myOtherIncludedField = myOtherIncludedField;
        this.myIncludedInt = myIncludedInt;
    }
    
    @ThriftConstructor
    protected MyStruct() {
      this.myIncludedField = null;
      this.myOtherIncludedField = null;
      this.myIncludedInt = 0L;
    }
    
    public static class Builder {
        private test.fixtures.includes.includes.Included myIncludedField;
        @ThriftField(value=1, name="MyIncludedField", requiredness=Requiredness.NONE)
        public Builder setMyIncludedField(test.fixtures.includes.includes.Included myIncludedField) {
            this.myIncludedField = myIncludedField;
            return this;
        }
        private test.fixtures.includes.includes.Included myOtherIncludedField;
        @ThriftField(value=2, name="MyOtherIncludedField", requiredness=Requiredness.NONE)
        public Builder setMyOtherIncludedField(test.fixtures.includes.includes.Included myOtherIncludedField) {
            this.myOtherIncludedField = myOtherIncludedField;
            return this;
        }
        private long myIncludedInt;
        @ThriftField(value=3, name="MyIncludedInt", requiredness=Requiredness.NONE)
        public Builder setMyIncludedInt(long myIncludedInt) {
            this.myIncludedInt = myIncludedInt;
            return this;
        }
    
        public Builder() { }
        public Builder(MyStruct other) {
            this.myIncludedField = other.myIncludedField;
            this.myOtherIncludedField = other.myOtherIncludedField;
            this.myIncludedInt = other.myIncludedInt;
        }
    
        @ThriftConstructor
        public MyStruct build() {
            return new MyStruct (
                this.myIncludedField,
                this.myOtherIncludedField,
                this.myIncludedInt
            );
        }
    }
    
    private static final TStruct STRUCT_DESC = new TStruct("MyStruct");
    private final test.fixtures.includes.includes.Included myIncludedField;
    public static final int _MYINCLUDEDFIELD = 1;
    private static final TField MY_INCLUDED_FIELD_FIELD_DESC = new TField("myIncludedField", TType.STRUCT, (short)1);
    private final test.fixtures.includes.includes.Included myOtherIncludedField;
    public static final int _MYOTHERINCLUDEDFIELD = 2;
    private static final TField MY_OTHER_INCLUDED_FIELD_FIELD_DESC = new TField("myOtherIncludedField", TType.STRUCT, (short)2);
    private final long myIncludedInt;
    public static final int _MYINCLUDEDINT = 3;
    private static final TField MY_INCLUDED_INT_FIELD_DESC = new TField("myIncludedInt", TType.I64, (short)3);

    
    @ThriftField(value=1, name="MyIncludedField", requiredness=Requiredness.NONE)
    public test.fixtures.includes.includes.Included getMyIncludedField() { return myIncludedField; }
        
    @ThriftField(value=2, name="MyOtherIncludedField", requiredness=Requiredness.NONE)
    public test.fixtures.includes.includes.Included getMyOtherIncludedField() { return myOtherIncludedField; }
        
    @ThriftField(value=3, name="MyIncludedInt", requiredness=Requiredness.NONE)
    public long getMyIncludedInt() { return myIncludedInt; }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("myIncludedField", myIncludedField);
        helper.add("myOtherIncludedField", myOtherIncludedField);
        helper.add("myIncludedInt", myIncludedInt);
        return helper.toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyStruct other = (MyStruct)o;
    
        return
            Objects.equals(myIncludedField, other.myIncludedField) &&
            Objects.equals(myOtherIncludedField, other.myOtherIncludedField) &&
            Objects.equals(myIncludedInt, other.myIncludedInt) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            myIncludedField,
            myOtherIncludedField,
            myIncludedInt
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static MyStruct read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      MyStruct.Builder builder = new MyStruct.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MYINCLUDEDFIELD:
          if (__field.type == TType.STRUCT) {
            test.fixtures.includes.includes.Included myIncludedField = test.fixtures.includes.includes.Included.read0(oprot);
            builder.setMyIncludedField(myIncludedField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _MYOTHERINCLUDEDFIELD:
          if (__field.type == TType.STRUCT) {
            test.fixtures.includes.includes.Included myOtherIncludedField = test.fixtures.includes.includes.Included.read0(oprot);
            builder.setMyOtherIncludedField(myOtherIncludedField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _MYINCLUDEDINT:
          if (__field.type == TType.I64) {
            long myIncludedInt = oprot.readI64();
            builder.setMyIncludedInt(myIncludedInt);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.myIncludedField != null) {
        oprot.writeFieldBegin(MY_INCLUDED_FIELD_FIELD_DESC);
        this.myIncludedField.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (this.myOtherIncludedField != null) {
        oprot.writeFieldBegin(MY_OTHER_INCLUDED_FIELD_FIELD_DESC);
        this.myOtherIncludedField.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(MY_INCLUDED_INT_FIELD_DESC);
      oprot.writeI64(this.myIncludedInt);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
