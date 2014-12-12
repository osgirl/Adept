/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package thrift.adept.module;

import org.apache.thrift.scheme.IScheme;
import org.apache.thrift.scheme.SchemeFactory;
import org.apache.thrift.scheme.StandardScheme;

import org.apache.thrift.scheme.TupleScheme;
import org.apache.thrift.protocol.TTupleProtocol;
import org.apache.thrift.protocol.TProtocolException;
import org.apache.thrift.EncodingUtils;
import org.apache.thrift.TException;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.EnumMap;
import java.util.Set;
import java.util.HashSet;
import java.util.EnumSet;
import java.util.Collections;
import java.util.BitSet;
import java.nio.ByteBuffer;
import java.util.Arrays;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class ModuleTraits implements org.apache.thrift.TBase<ModuleTraits, ModuleTraits._Fields>, java.io.Serializable, Cloneable {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("ModuleTraits");

  private static final org.apache.thrift.protocol.TField SCHEMA_FIELD_DESC = new org.apache.thrift.protocol.TField("schema", org.apache.thrift.protocol.TType.STRING, (short)1);
  private static final org.apache.thrift.protocol.TField TRAIT_FIELD_DESC = new org.apache.thrift.protocol.TField("trait", org.apache.thrift.protocol.TType.STRING, (short)2);
  private static final org.apache.thrift.protocol.TField VERSION_FIELD_DESC = new org.apache.thrift.protocol.TField("version", org.apache.thrift.protocol.TType.STRING, (short)3);

  private static final Map<Class<? extends IScheme>, SchemeFactory> schemes = new HashMap<Class<? extends IScheme>, SchemeFactory>();
  static {
    schemes.put(StandardScheme.class, new ModuleTraitsStandardSchemeFactory());
    schemes.put(TupleScheme.class, new ModuleTraitsTupleSchemeFactory());
  }

  public String schema; // required
  public String trait; // required
  public String version; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    SCHEMA((short)1, "schema"),
    TRAIT((short)2, "trait"),
    VERSION((short)3, "version");

    private static final Map<String, _Fields> byName = new HashMap<String, _Fields>();

    static {
      for (_Fields field : EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // SCHEMA
          return SCHEMA;
        case 2: // TRAIT
          return TRAIT;
        case 3: // VERSION
          return VERSION;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    public static _Fields findByName(String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final String _fieldName;

    _Fields(short thriftId, String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.SCHEMA, new org.apache.thrift.meta_data.FieldMetaData("schema", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.TRAIT, new org.apache.thrift.meta_data.FieldMetaData("trait", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.VERSION, new org.apache.thrift.meta_data.FieldMetaData("version", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(ModuleTraits.class, metaDataMap);
  }

  public ModuleTraits() {
  }

  public ModuleTraits(
    String schema,
    String trait,
    String version)
  {
    this();
    this.schema = schema;
    this.trait = trait;
    this.version = version;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public ModuleTraits(ModuleTraits other) {
    if (other.isSetSchema()) {
      this.schema = other.schema;
    }
    if (other.isSetTrait()) {
      this.trait = other.trait;
    }
    if (other.isSetVersion()) {
      this.version = other.version;
    }
  }

  public ModuleTraits deepCopy() {
    return new ModuleTraits(this);
  }

  @Override
  public void clear() {
    this.schema = null;
    this.trait = null;
    this.version = null;
  }

  public String getSchema() {
    return this.schema;
  }

  public ModuleTraits setSchema(String schema) {
    this.schema = schema;
    return this;
  }

  public void unsetSchema() {
    this.schema = null;
  }

  /** Returns true if field schema is set (has been assigned a value) and false otherwise */
  public boolean isSetSchema() {
    return this.schema != null;
  }

  public void setSchemaIsSet(boolean value) {
    if (!value) {
      this.schema = null;
    }
  }

  public String getTrait() {
    return this.trait;
  }

  public ModuleTraits setTrait(String trait) {
    this.trait = trait;
    return this;
  }

  public void unsetTrait() {
    this.trait = null;
  }

  /** Returns true if field trait is set (has been assigned a value) and false otherwise */
  public boolean isSetTrait() {
    return this.trait != null;
  }

  public void setTraitIsSet(boolean value) {
    if (!value) {
      this.trait = null;
    }
  }

  public String getVersion() {
    return this.version;
  }

  public ModuleTraits setVersion(String version) {
    this.version = version;
    return this;
  }

  public void unsetVersion() {
    this.version = null;
  }

  /** Returns true if field version is set (has been assigned a value) and false otherwise */
  public boolean isSetVersion() {
    return this.version != null;
  }

  public void setVersionIsSet(boolean value) {
    if (!value) {
      this.version = null;
    }
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case SCHEMA:
      if (value == null) {
        unsetSchema();
      } else {
        setSchema((String)value);
      }
      break;

    case TRAIT:
      if (value == null) {
        unsetTrait();
      } else {
        setTrait((String)value);
      }
      break;

    case VERSION:
      if (value == null) {
        unsetVersion();
      } else {
        setVersion((String)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case SCHEMA:
      return getSchema();

    case TRAIT:
      return getTrait();

    case VERSION:
      return getVersion();

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case SCHEMA:
      return isSetSchema();
    case TRAIT:
      return isSetTrait();
    case VERSION:
      return isSetVersion();
    }
    throw new IllegalStateException();
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof ModuleTraits)
      return this.equals((ModuleTraits)that);
    return false;
  }

  public boolean equals(ModuleTraits that) {
    if (that == null)
      return false;

    boolean this_present_schema = true && this.isSetSchema();
    boolean that_present_schema = true && that.isSetSchema();
    if (this_present_schema || that_present_schema) {
      if (!(this_present_schema && that_present_schema))
        return false;
      if (!this.schema.equals(that.schema))
        return false;
    }

    boolean this_present_trait = true && this.isSetTrait();
    boolean that_present_trait = true && that.isSetTrait();
    if (this_present_trait || that_present_trait) {
      if (!(this_present_trait && that_present_trait))
        return false;
      if (!this.trait.equals(that.trait))
        return false;
    }

    boolean this_present_version = true && this.isSetVersion();
    boolean that_present_version = true && that.isSetVersion();
    if (this_present_version || that_present_version) {
      if (!(this_present_version && that_present_version))
        return false;
      if (!this.version.equals(that.version))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    return 0;
  }

  public int compareTo(ModuleTraits other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;
    ModuleTraits typedOther = (ModuleTraits)other;

    lastComparison = Boolean.valueOf(isSetSchema()).compareTo(typedOther.isSetSchema());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetSchema()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.schema, typedOther.schema);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetTrait()).compareTo(typedOther.isSetTrait());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetTrait()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.trait, typedOther.trait);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetVersion()).compareTo(typedOther.isSetVersion());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetVersion()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.version, typedOther.version);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    schemes.get(iprot.getScheme()).getScheme().read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    schemes.get(oprot.getScheme()).getScheme().write(oprot, this);
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("ModuleTraits(");
    boolean first = true;

    sb.append("schema:");
    if (this.schema == null) {
      sb.append("null");
    } else {
      sb.append(this.schema);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("trait:");
    if (this.trait == null) {
      sb.append("null");
    } else {
      sb.append(this.trait);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("version:");
    if (this.version == null) {
      sb.append("null");
    } else {
      sb.append(this.version);
    }
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, ClassNotFoundException {
    try {
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class ModuleTraitsStandardSchemeFactory implements SchemeFactory {
    public ModuleTraitsStandardScheme getScheme() {
      return new ModuleTraitsStandardScheme();
    }
  }

  private static class ModuleTraitsStandardScheme extends StandardScheme<ModuleTraits> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, ModuleTraits struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // SCHEMA
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.schema = iprot.readString();
              struct.setSchemaIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // TRAIT
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.trait = iprot.readString();
              struct.setTraitIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // VERSION
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.version = iprot.readString();
              struct.setVersionIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, ModuleTraits struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.schema != null) {
        oprot.writeFieldBegin(SCHEMA_FIELD_DESC);
        oprot.writeString(struct.schema);
        oprot.writeFieldEnd();
      }
      if (struct.trait != null) {
        oprot.writeFieldBegin(TRAIT_FIELD_DESC);
        oprot.writeString(struct.trait);
        oprot.writeFieldEnd();
      }
      if (struct.version != null) {
        oprot.writeFieldBegin(VERSION_FIELD_DESC);
        oprot.writeString(struct.version);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class ModuleTraitsTupleSchemeFactory implements SchemeFactory {
    public ModuleTraitsTupleScheme getScheme() {
      return new ModuleTraitsTupleScheme();
    }
  }

  private static class ModuleTraitsTupleScheme extends TupleScheme<ModuleTraits> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, ModuleTraits struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      BitSet optionals = new BitSet();
      if (struct.isSetSchema()) {
        optionals.set(0);
      }
      if (struct.isSetTrait()) {
        optionals.set(1);
      }
      if (struct.isSetVersion()) {
        optionals.set(2);
      }
      oprot.writeBitSet(optionals, 3);
      if (struct.isSetSchema()) {
        oprot.writeString(struct.schema);
      }
      if (struct.isSetTrait()) {
        oprot.writeString(struct.trait);
      }
      if (struct.isSetVersion()) {
        oprot.writeString(struct.version);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, ModuleTraits struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      BitSet incoming = iprot.readBitSet(3);
      if (incoming.get(0)) {
        struct.schema = iprot.readString();
        struct.setSchemaIsSet(true);
      }
      if (incoming.get(1)) {
        struct.trait = iprot.readString();
        struct.setTraitIsSet(true);
      }
      if (incoming.get(2)) {
        struct.version = iprot.readString();
        struct.setVersionIsSet(true);
      }
    }
  }

}

