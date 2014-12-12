/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package thrift.adept.common;

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

/**
 * The Class Topic.
 */
public class Topic implements org.apache.thrift.TBase<Topic, Topic._Fields>, java.io.Serializable, Cloneable {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("Topic");

  private static final org.apache.thrift.protocol.TField TOPIC_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("topicId", org.apache.thrift.protocol.TType.I64, (short)1);
  private static final org.apache.thrift.protocol.TField NAME_FIELD_DESC = new org.apache.thrift.protocol.TField("name", org.apache.thrift.protocol.TType.STRING, (short)2);
  private static final org.apache.thrift.protocol.TField BELIEF_FIELD_DESC = new org.apache.thrift.protocol.TField("belief", org.apache.thrift.protocol.TType.STRING, (short)3);
  private static final org.apache.thrift.protocol.TField POLARITY_FIELD_DESC = new org.apache.thrift.protocol.TField("polarity", org.apache.thrift.protocol.TType.I32, (short)4);
  private static final org.apache.thrift.protocol.TField VIEWPOINTS_FIELD_DESC = new org.apache.thrift.protocol.TField("viewpoints", org.apache.thrift.protocol.TType.LIST, (short)5);

  private static final Map<Class<? extends IScheme>, SchemeFactory> schemes = new HashMap<Class<? extends IScheme>, SchemeFactory>();
  static {
    schemes.put(StandardScheme.class, new TopicStandardSchemeFactory());
    schemes.put(TupleScheme.class, new TopicTupleSchemeFactory());
  }

  /**
   * The topic id
   */
  public long topicId; // required
  /**
   * The name
   */
  public String name; // required
  /**
   * The belief
   */
  public String belief; // optional
  /**
   * The topic polarity
   * 
   * @see TopicPolarity
   */
  public TopicPolarity polarity; // optional
  /**
   * The viewpoints
   */
  public List<Viewpoint> viewpoints; // optional

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    /**
     * The topic id
     */
    TOPIC_ID((short)1, "topicId"),
    /**
     * The name
     */
    NAME((short)2, "name"),
    /**
     * The belief
     */
    BELIEF((short)3, "belief"),
    /**
     * The topic polarity
     * 
     * @see TopicPolarity
     */
    POLARITY((short)4, "polarity"),
    /**
     * The viewpoints
     */
    VIEWPOINTS((short)5, "viewpoints");

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
        case 1: // TOPIC_ID
          return TOPIC_ID;
        case 2: // NAME
          return NAME;
        case 3: // BELIEF
          return BELIEF;
        case 4: // POLARITY
          return POLARITY;
        case 5: // VIEWPOINTS
          return VIEWPOINTS;
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
  private static final int __TOPICID_ISSET_ID = 0;
  private byte __isset_bitfield = 0;
  private _Fields optionals[] = {_Fields.BELIEF,_Fields.POLARITY,_Fields.VIEWPOINTS};
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.TOPIC_ID, new org.apache.thrift.meta_data.FieldMetaData("topicId", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    tmpMap.put(_Fields.NAME, new org.apache.thrift.meta_data.FieldMetaData("name", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.BELIEF, new org.apache.thrift.meta_data.FieldMetaData("belief", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.POLARITY, new org.apache.thrift.meta_data.FieldMetaData("polarity", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.EnumMetaData(org.apache.thrift.protocol.TType.ENUM, TopicPolarity.class)));
    tmpMap.put(_Fields.VIEWPOINTS, new org.apache.thrift.meta_data.FieldMetaData("viewpoints", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.ListMetaData(org.apache.thrift.protocol.TType.LIST, 
            new org.apache.thrift.meta_data.StructMetaData(org.apache.thrift.protocol.TType.STRUCT, Viewpoint.class))));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(Topic.class, metaDataMap);
  }

  public Topic() {
  }

  public Topic(
    long topicId,
    String name)
  {
    this();
    this.topicId = topicId;
    setTopicIdIsSet(true);
    this.name = name;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Topic(Topic other) {
    __isset_bitfield = other.__isset_bitfield;
    this.topicId = other.topicId;
    if (other.isSetName()) {
      this.name = other.name;
    }
    if (other.isSetBelief()) {
      this.belief = other.belief;
    }
    if (other.isSetPolarity()) {
      this.polarity = other.polarity;
    }
    if (other.isSetViewpoints()) {
      List<Viewpoint> __this__viewpoints = new ArrayList<Viewpoint>();
      for (Viewpoint other_element : other.viewpoints) {
        __this__viewpoints.add(new Viewpoint(other_element));
      }
      this.viewpoints = __this__viewpoints;
    }
  }

  public Topic deepCopy() {
    return new Topic(this);
  }

  @Override
  public void clear() {
    setTopicIdIsSet(false);
    this.topicId = 0;
    this.name = null;
    this.belief = null;
    this.polarity = null;
    this.viewpoints = null;
  }

  /**
   * The topic id
   */
  public long getTopicId() {
    return this.topicId;
  }

  /**
   * The topic id
   */
  public Topic setTopicId(long topicId) {
    this.topicId = topicId;
    setTopicIdIsSet(true);
    return this;
  }

  public void unsetTopicId() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __TOPICID_ISSET_ID);
  }

  /** Returns true if field topicId is set (has been assigned a value) and false otherwise */
  public boolean isSetTopicId() {
    return EncodingUtils.testBit(__isset_bitfield, __TOPICID_ISSET_ID);
  }

  public void setTopicIdIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __TOPICID_ISSET_ID, value);
  }

  /**
   * The name
   */
  public String getName() {
    return this.name;
  }

  /**
   * The name
   */
  public Topic setName(String name) {
    this.name = name;
    return this;
  }

  public void unsetName() {
    this.name = null;
  }

  /** Returns true if field name is set (has been assigned a value) and false otherwise */
  public boolean isSetName() {
    return this.name != null;
  }

  public void setNameIsSet(boolean value) {
    if (!value) {
      this.name = null;
    }
  }

  /**
   * The belief
   */
  public String getBelief() {
    return this.belief;
  }

  /**
   * The belief
   */
  public Topic setBelief(String belief) {
    this.belief = belief;
    return this;
  }

  public void unsetBelief() {
    this.belief = null;
  }

  /** Returns true if field belief is set (has been assigned a value) and false otherwise */
  public boolean isSetBelief() {
    return this.belief != null;
  }

  public void setBeliefIsSet(boolean value) {
    if (!value) {
      this.belief = null;
    }
  }

  /**
   * The topic polarity
   * 
   * @see TopicPolarity
   */
  public TopicPolarity getPolarity() {
    return this.polarity;
  }

  /**
   * The topic polarity
   * 
   * @see TopicPolarity
   */
  public Topic setPolarity(TopicPolarity polarity) {
    this.polarity = polarity;
    return this;
  }

  public void unsetPolarity() {
    this.polarity = null;
  }

  /** Returns true if field polarity is set (has been assigned a value) and false otherwise */
  public boolean isSetPolarity() {
    return this.polarity != null;
  }

  public void setPolarityIsSet(boolean value) {
    if (!value) {
      this.polarity = null;
    }
  }

  public int getViewpointsSize() {
    return (this.viewpoints == null) ? 0 : this.viewpoints.size();
  }

  public java.util.Iterator<Viewpoint> getViewpointsIterator() {
    return (this.viewpoints == null) ? null : this.viewpoints.iterator();
  }

  public void addToViewpoints(Viewpoint elem) {
    if (this.viewpoints == null) {
      this.viewpoints = new ArrayList<Viewpoint>();
    }
    this.viewpoints.add(elem);
  }

  /**
   * The viewpoints
   */
  public List<Viewpoint> getViewpoints() {
    return this.viewpoints;
  }

  /**
   * The viewpoints
   */
  public Topic setViewpoints(List<Viewpoint> viewpoints) {
    this.viewpoints = viewpoints;
    return this;
  }

  public void unsetViewpoints() {
    this.viewpoints = null;
  }

  /** Returns true if field viewpoints is set (has been assigned a value) and false otherwise */
  public boolean isSetViewpoints() {
    return this.viewpoints != null;
  }

  public void setViewpointsIsSet(boolean value) {
    if (!value) {
      this.viewpoints = null;
    }
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case TOPIC_ID:
      if (value == null) {
        unsetTopicId();
      } else {
        setTopicId((Long)value);
      }
      break;

    case NAME:
      if (value == null) {
        unsetName();
      } else {
        setName((String)value);
      }
      break;

    case BELIEF:
      if (value == null) {
        unsetBelief();
      } else {
        setBelief((String)value);
      }
      break;

    case POLARITY:
      if (value == null) {
        unsetPolarity();
      } else {
        setPolarity((TopicPolarity)value);
      }
      break;

    case VIEWPOINTS:
      if (value == null) {
        unsetViewpoints();
      } else {
        setViewpoints((List<Viewpoint>)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case TOPIC_ID:
      return Long.valueOf(getTopicId());

    case NAME:
      return getName();

    case BELIEF:
      return getBelief();

    case POLARITY:
      return getPolarity();

    case VIEWPOINTS:
      return getViewpoints();

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case TOPIC_ID:
      return isSetTopicId();
    case NAME:
      return isSetName();
    case BELIEF:
      return isSetBelief();
    case POLARITY:
      return isSetPolarity();
    case VIEWPOINTS:
      return isSetViewpoints();
    }
    throw new IllegalStateException();
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof Topic)
      return this.equals((Topic)that);
    return false;
  }

  public boolean equals(Topic that) {
    if (that == null)
      return false;

    boolean this_present_topicId = true;
    boolean that_present_topicId = true;
    if (this_present_topicId || that_present_topicId) {
      if (!(this_present_topicId && that_present_topicId))
        return false;
      if (this.topicId != that.topicId)
        return false;
    }

    boolean this_present_name = true && this.isSetName();
    boolean that_present_name = true && that.isSetName();
    if (this_present_name || that_present_name) {
      if (!(this_present_name && that_present_name))
        return false;
      if (!this.name.equals(that.name))
        return false;
    }

    boolean this_present_belief = true && this.isSetBelief();
    boolean that_present_belief = true && that.isSetBelief();
    if (this_present_belief || that_present_belief) {
      if (!(this_present_belief && that_present_belief))
        return false;
      if (!this.belief.equals(that.belief))
        return false;
    }

    boolean this_present_polarity = true && this.isSetPolarity();
    boolean that_present_polarity = true && that.isSetPolarity();
    if (this_present_polarity || that_present_polarity) {
      if (!(this_present_polarity && that_present_polarity))
        return false;
      if (!this.polarity.equals(that.polarity))
        return false;
    }

    boolean this_present_viewpoints = true && this.isSetViewpoints();
    boolean that_present_viewpoints = true && that.isSetViewpoints();
    if (this_present_viewpoints || that_present_viewpoints) {
      if (!(this_present_viewpoints && that_present_viewpoints))
        return false;
      if (!this.viewpoints.equals(that.viewpoints))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    return 0;
  }

  public int compareTo(Topic other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;
    Topic typedOther = (Topic)other;

    lastComparison = Boolean.valueOf(isSetTopicId()).compareTo(typedOther.isSetTopicId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetTopicId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.topicId, typedOther.topicId);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetName()).compareTo(typedOther.isSetName());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetName()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.name, typedOther.name);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetBelief()).compareTo(typedOther.isSetBelief());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetBelief()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.belief, typedOther.belief);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetPolarity()).compareTo(typedOther.isSetPolarity());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetPolarity()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.polarity, typedOther.polarity);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetViewpoints()).compareTo(typedOther.isSetViewpoints());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetViewpoints()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.viewpoints, typedOther.viewpoints);
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
    StringBuilder sb = new StringBuilder("Topic(");
    boolean first = true;

    sb.append("topicId:");
    sb.append(this.topicId);
    first = false;
    if (!first) sb.append(", ");
    sb.append("name:");
    if (this.name == null) {
      sb.append("null");
    } else {
      sb.append(this.name);
    }
    first = false;
    if (isSetBelief()) {
      if (!first) sb.append(", ");
      sb.append("belief:");
      if (this.belief == null) {
        sb.append("null");
      } else {
        sb.append(this.belief);
      }
      first = false;
    }
    if (isSetPolarity()) {
      if (!first) sb.append(", ");
      sb.append("polarity:");
      if (this.polarity == null) {
        sb.append("null");
      } else {
        sb.append(this.polarity);
      }
      first = false;
    }
    if (isSetViewpoints()) {
      if (!first) sb.append(", ");
      sb.append("viewpoints:");
      if (this.viewpoints == null) {
        sb.append("null");
      } else {
        sb.append(this.viewpoints);
      }
      first = false;
    }
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // alas, we cannot check 'topicId' because it's a primitive and you chose the non-beans generator.
    if (name == null) {
      throw new org.apache.thrift.protocol.TProtocolException("Required field 'name' was not present! Struct: " + toString());
    }
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
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class TopicStandardSchemeFactory implements SchemeFactory {
    public TopicStandardScheme getScheme() {
      return new TopicStandardScheme();
    }
  }

  private static class TopicStandardScheme extends StandardScheme<Topic> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, Topic struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // TOPIC_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.topicId = iprot.readI64();
              struct.setTopicIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // NAME
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.name = iprot.readString();
              struct.setNameIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // BELIEF
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.belief = iprot.readString();
              struct.setBeliefIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // POLARITY
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.polarity = TopicPolarity.findByValue(iprot.readI32());
              struct.setPolarityIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // VIEWPOINTS
            if (schemeField.type == org.apache.thrift.protocol.TType.LIST) {
              {
                org.apache.thrift.protocol.TList _list170 = iprot.readListBegin();
                struct.viewpoints = new ArrayList<Viewpoint>(_list170.size);
                for (int _i171 = 0; _i171 < _list170.size; ++_i171)
                {
                  Viewpoint _elem172; // required
                  _elem172 = new Viewpoint();
                  _elem172.read(iprot);
                  struct.viewpoints.add(_elem172);
                }
                iprot.readListEnd();
              }
              struct.setViewpointsIsSet(true);
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
      if (!struct.isSetTopicId()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'topicId' was not found in serialized data! Struct: " + toString());
      }
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, Topic struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(TOPIC_ID_FIELD_DESC);
      oprot.writeI64(struct.topicId);
      oprot.writeFieldEnd();
      if (struct.name != null) {
        oprot.writeFieldBegin(NAME_FIELD_DESC);
        oprot.writeString(struct.name);
        oprot.writeFieldEnd();
      }
      if (struct.belief != null) {
        if (struct.isSetBelief()) {
          oprot.writeFieldBegin(BELIEF_FIELD_DESC);
          oprot.writeString(struct.belief);
          oprot.writeFieldEnd();
        }
      }
      if (struct.polarity != null) {
        if (struct.isSetPolarity()) {
          oprot.writeFieldBegin(POLARITY_FIELD_DESC);
          oprot.writeI32(struct.polarity.getValue());
          oprot.writeFieldEnd();
        }
      }
      if (struct.viewpoints != null) {
        if (struct.isSetViewpoints()) {
          oprot.writeFieldBegin(VIEWPOINTS_FIELD_DESC);
          {
            oprot.writeListBegin(new org.apache.thrift.protocol.TList(org.apache.thrift.protocol.TType.STRUCT, struct.viewpoints.size()));
            for (Viewpoint _iter173 : struct.viewpoints)
            {
              _iter173.write(oprot);
            }
            oprot.writeListEnd();
          }
          oprot.writeFieldEnd();
        }
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class TopicTupleSchemeFactory implements SchemeFactory {
    public TopicTupleScheme getScheme() {
      return new TopicTupleScheme();
    }
  }

  private static class TopicTupleScheme extends TupleScheme<Topic> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, Topic struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      oprot.writeI64(struct.topicId);
      oprot.writeString(struct.name);
      BitSet optionals = new BitSet();
      if (struct.isSetBelief()) {
        optionals.set(0);
      }
      if (struct.isSetPolarity()) {
        optionals.set(1);
      }
      if (struct.isSetViewpoints()) {
        optionals.set(2);
      }
      oprot.writeBitSet(optionals, 3);
      if (struct.isSetBelief()) {
        oprot.writeString(struct.belief);
      }
      if (struct.isSetPolarity()) {
        oprot.writeI32(struct.polarity.getValue());
      }
      if (struct.isSetViewpoints()) {
        {
          oprot.writeI32(struct.viewpoints.size());
          for (Viewpoint _iter174 : struct.viewpoints)
          {
            _iter174.write(oprot);
          }
        }
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, Topic struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      struct.topicId = iprot.readI64();
      struct.setTopicIdIsSet(true);
      struct.name = iprot.readString();
      struct.setNameIsSet(true);
      BitSet incoming = iprot.readBitSet(3);
      if (incoming.get(0)) {
        struct.belief = iprot.readString();
        struct.setBeliefIsSet(true);
      }
      if (incoming.get(1)) {
        struct.polarity = TopicPolarity.findByValue(iprot.readI32());
        struct.setPolarityIsSet(true);
      }
      if (incoming.get(2)) {
        {
          org.apache.thrift.protocol.TList _list175 = new org.apache.thrift.protocol.TList(org.apache.thrift.protocol.TType.STRUCT, iprot.readI32());
          struct.viewpoints = new ArrayList<Viewpoint>(_list175.size);
          for (int _i176 = 0; _i176 < _list175.size; ++_i176)
          {
            Viewpoint _elem177; // required
            _elem177 = new Viewpoint();
            _elem177.read(iprot);
            struct.viewpoints.add(_elem177);
          }
        }
        struct.setViewpointsIsSet(true);
      }
    }
  }

}

