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
 * The Class SentenceSimilarity.
 */
public class SentenceSimilarity implements org.apache.thrift.TBase<SentenceSimilarity, SentenceSimilarity._Fields>, java.io.Serializable, Cloneable {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("SentenceSimilarity");

  private static final org.apache.thrift.protocol.TField SIMILARITY_FIELD_DESC = new org.apache.thrift.protocol.TField("similarity", org.apache.thrift.protocol.TType.DOUBLE, (short)1);
  private static final org.apache.thrift.protocol.TField SENTENCE1_FIELD_DESC = new org.apache.thrift.protocol.TField("sentence1", org.apache.thrift.protocol.TType.STRUCT, (short)2);
  private static final org.apache.thrift.protocol.TField SENTENCE2_FIELD_DESC = new org.apache.thrift.protocol.TField("sentence2", org.apache.thrift.protocol.TType.STRUCT, (short)3);
  private static final org.apache.thrift.protocol.TField ID_FIELD_DESC = new org.apache.thrift.protocol.TField("id", org.apache.thrift.protocol.TType.STRUCT, (short)4);
  private static final org.apache.thrift.protocol.TField VALUE_FIELD_DESC = new org.apache.thrift.protocol.TField("value", org.apache.thrift.protocol.TType.STRING, (short)5);
  private static final org.apache.thrift.protocol.TField ALGORITHM_NAME_FIELD_DESC = new org.apache.thrift.protocol.TField("algorithmName", org.apache.thrift.protocol.TType.STRING, (short)6);

  private static final Map<Class<? extends IScheme>, SchemeFactory> schemes = new HashMap<Class<? extends IScheme>, SchemeFactory>();
  static {
    schemes.put(StandardScheme.class, new SentenceSimilarityStandardSchemeFactory());
    schemes.put(TupleScheme.class, new SentenceSimilarityTupleSchemeFactory());
  }

  /**
   * The similarity
   */
  public double similarity; // required
  /**
   * The sentence 1
   */
  public Sentence sentence1; // required
  /**
   * The sentence 2
   */
  public Sentence sentence2; // required
  /**
   * The id
   */
  public ID id; // optional
  /**
   * The value
   */
  public String value; // optional
  /**
   * The algorithmName
   */
  public String algorithmName; // optional

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    /**
     * The similarity
     */
    SIMILARITY((short)1, "similarity"),
    /**
     * The sentence 1
     */
    SENTENCE1((short)2, "sentence1"),
    /**
     * The sentence 2
     */
    SENTENCE2((short)3, "sentence2"),
    /**
     * The id
     */
    ID((short)4, "id"),
    /**
     * The value
     */
    VALUE((short)5, "value"),
    /**
     * The algorithmName
     */
    ALGORITHM_NAME((short)6, "algorithmName");

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
        case 1: // SIMILARITY
          return SIMILARITY;
        case 2: // SENTENCE1
          return SENTENCE1;
        case 3: // SENTENCE2
          return SENTENCE2;
        case 4: // ID
          return ID;
        case 5: // VALUE
          return VALUE;
        case 6: // ALGORITHM_NAME
          return ALGORITHM_NAME;
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
  private static final int __SIMILARITY_ISSET_ID = 0;
  private byte __isset_bitfield = 0;
  private _Fields optionals[] = {_Fields.ID,_Fields.VALUE,_Fields.ALGORITHM_NAME};
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.SIMILARITY, new org.apache.thrift.meta_data.FieldMetaData("similarity", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.DOUBLE)));
    tmpMap.put(_Fields.SENTENCE1, new org.apache.thrift.meta_data.FieldMetaData("sentence1", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.StructMetaData(org.apache.thrift.protocol.TType.STRUCT, Sentence.class)));
    tmpMap.put(_Fields.SENTENCE2, new org.apache.thrift.meta_data.FieldMetaData("sentence2", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.StructMetaData(org.apache.thrift.protocol.TType.STRUCT, Sentence.class)));
    tmpMap.put(_Fields.ID, new org.apache.thrift.meta_data.FieldMetaData("id", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.StructMetaData(org.apache.thrift.protocol.TType.STRUCT, ID.class)));
    tmpMap.put(_Fields.VALUE, new org.apache.thrift.meta_data.FieldMetaData("value", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.ALGORITHM_NAME, new org.apache.thrift.meta_data.FieldMetaData("algorithmName", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(SentenceSimilarity.class, metaDataMap);
  }

  public SentenceSimilarity() {
  }

  public SentenceSimilarity(
    double similarity,
    Sentence sentence1,
    Sentence sentence2)
  {
    this();
    this.similarity = similarity;
    setSimilarityIsSet(true);
    this.sentence1 = sentence1;
    this.sentence2 = sentence2;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public SentenceSimilarity(SentenceSimilarity other) {
    __isset_bitfield = other.__isset_bitfield;
    this.similarity = other.similarity;
    if (other.isSetSentence1()) {
      this.sentence1 = new Sentence(other.sentence1);
    }
    if (other.isSetSentence2()) {
      this.sentence2 = new Sentence(other.sentence2);
    }
    if (other.isSetId()) {
      this.id = new ID(other.id);
    }
    if (other.isSetValue()) {
      this.value = other.value;
    }
    if (other.isSetAlgorithmName()) {
      this.algorithmName = other.algorithmName;
    }
  }

  public SentenceSimilarity deepCopy() {
    return new SentenceSimilarity(this);
  }

  @Override
  public void clear() {
    setSimilarityIsSet(false);
    this.similarity = 0.0;
    this.sentence1 = null;
    this.sentence2 = null;
    this.id = null;
    this.value = null;
    this.algorithmName = null;
  }

  /**
   * The similarity
   */
  public double getSimilarity() {
    return this.similarity;
  }

  /**
   * The similarity
   */
  public SentenceSimilarity setSimilarity(double similarity) {
    this.similarity = similarity;
    setSimilarityIsSet(true);
    return this;
  }

  public void unsetSimilarity() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __SIMILARITY_ISSET_ID);
  }

  /** Returns true if field similarity is set (has been assigned a value) and false otherwise */
  public boolean isSetSimilarity() {
    return EncodingUtils.testBit(__isset_bitfield, __SIMILARITY_ISSET_ID);
  }

  public void setSimilarityIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __SIMILARITY_ISSET_ID, value);
  }

  /**
   * The sentence 1
   */
  public Sentence getSentence1() {
    return this.sentence1;
  }

  /**
   * The sentence 1
   */
  public SentenceSimilarity setSentence1(Sentence sentence1) {
    this.sentence1 = sentence1;
    return this;
  }

  public void unsetSentence1() {
    this.sentence1 = null;
  }

  /** Returns true if field sentence1 is set (has been assigned a value) and false otherwise */
  public boolean isSetSentence1() {
    return this.sentence1 != null;
  }

  public void setSentence1IsSet(boolean value) {
    if (!value) {
      this.sentence1 = null;
    }
  }

  /**
   * The sentence 2
   */
  public Sentence getSentence2() {
    return this.sentence2;
  }

  /**
   * The sentence 2
   */
  public SentenceSimilarity setSentence2(Sentence sentence2) {
    this.sentence2 = sentence2;
    return this;
  }

  public void unsetSentence2() {
    this.sentence2 = null;
  }

  /** Returns true if field sentence2 is set (has been assigned a value) and false otherwise */
  public boolean isSetSentence2() {
    return this.sentence2 != null;
  }

  public void setSentence2IsSet(boolean value) {
    if (!value) {
      this.sentence2 = null;
    }
  }

  /**
   * The id
   */
  public ID getId() {
    return this.id;
  }

  /**
   * The id
   */
  public SentenceSimilarity setId(ID id) {
    this.id = id;
    return this;
  }

  public void unsetId() {
    this.id = null;
  }

  /** Returns true if field id is set (has been assigned a value) and false otherwise */
  public boolean isSetId() {
    return this.id != null;
  }

  public void setIdIsSet(boolean value) {
    if (!value) {
      this.id = null;
    }
  }

  /**
   * The value
   */
  public String getValue() {
    return this.value;
  }

  /**
   * The value
   */
  public SentenceSimilarity setValue(String value) {
    this.value = value;
    return this;
  }

  public void unsetValue() {
    this.value = null;
  }

  /** Returns true if field value is set (has been assigned a value) and false otherwise */
  public boolean isSetValue() {
    return this.value != null;
  }

  public void setValueIsSet(boolean value) {
    if (!value) {
      this.value = null;
    }
  }

  /**
   * The algorithmName
   */
  public String getAlgorithmName() {
    return this.algorithmName;
  }

  /**
   * The algorithmName
   */
  public SentenceSimilarity setAlgorithmName(String algorithmName) {
    this.algorithmName = algorithmName;
    return this;
  }

  public void unsetAlgorithmName() {
    this.algorithmName = null;
  }

  /** Returns true if field algorithmName is set (has been assigned a value) and false otherwise */
  public boolean isSetAlgorithmName() {
    return this.algorithmName != null;
  }

  public void setAlgorithmNameIsSet(boolean value) {
    if (!value) {
      this.algorithmName = null;
    }
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case SIMILARITY:
      if (value == null) {
        unsetSimilarity();
      } else {
        setSimilarity((Double)value);
      }
      break;

    case SENTENCE1:
      if (value == null) {
        unsetSentence1();
      } else {
        setSentence1((Sentence)value);
      }
      break;

    case SENTENCE2:
      if (value == null) {
        unsetSentence2();
      } else {
        setSentence2((Sentence)value);
      }
      break;

    case ID:
      if (value == null) {
        unsetId();
      } else {
        setId((ID)value);
      }
      break;

    case VALUE:
      if (value == null) {
        unsetValue();
      } else {
        setValue((String)value);
      }
      break;

    case ALGORITHM_NAME:
      if (value == null) {
        unsetAlgorithmName();
      } else {
        setAlgorithmName((String)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case SIMILARITY:
      return Double.valueOf(getSimilarity());

    case SENTENCE1:
      return getSentence1();

    case SENTENCE2:
      return getSentence2();

    case ID:
      return getId();

    case VALUE:
      return getValue();

    case ALGORITHM_NAME:
      return getAlgorithmName();

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case SIMILARITY:
      return isSetSimilarity();
    case SENTENCE1:
      return isSetSentence1();
    case SENTENCE2:
      return isSetSentence2();
    case ID:
      return isSetId();
    case VALUE:
      return isSetValue();
    case ALGORITHM_NAME:
      return isSetAlgorithmName();
    }
    throw new IllegalStateException();
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof SentenceSimilarity)
      return this.equals((SentenceSimilarity)that);
    return false;
  }

  public boolean equals(SentenceSimilarity that) {
    if (that == null)
      return false;

    boolean this_present_similarity = true;
    boolean that_present_similarity = true;
    if (this_present_similarity || that_present_similarity) {
      if (!(this_present_similarity && that_present_similarity))
        return false;
      if (this.similarity != that.similarity)
        return false;
    }

    boolean this_present_sentence1 = true && this.isSetSentence1();
    boolean that_present_sentence1 = true && that.isSetSentence1();
    if (this_present_sentence1 || that_present_sentence1) {
      if (!(this_present_sentence1 && that_present_sentence1))
        return false;
      if (!this.sentence1.equals(that.sentence1))
        return false;
    }

    boolean this_present_sentence2 = true && this.isSetSentence2();
    boolean that_present_sentence2 = true && that.isSetSentence2();
    if (this_present_sentence2 || that_present_sentence2) {
      if (!(this_present_sentence2 && that_present_sentence2))
        return false;
      if (!this.sentence2.equals(that.sentence2))
        return false;
    }

    boolean this_present_id = true && this.isSetId();
    boolean that_present_id = true && that.isSetId();
    if (this_present_id || that_present_id) {
      if (!(this_present_id && that_present_id))
        return false;
      if (!this.id.equals(that.id))
        return false;
    }

    boolean this_present_value = true && this.isSetValue();
    boolean that_present_value = true && that.isSetValue();
    if (this_present_value || that_present_value) {
      if (!(this_present_value && that_present_value))
        return false;
      if (!this.value.equals(that.value))
        return false;
    }

    boolean this_present_algorithmName = true && this.isSetAlgorithmName();
    boolean that_present_algorithmName = true && that.isSetAlgorithmName();
    if (this_present_algorithmName || that_present_algorithmName) {
      if (!(this_present_algorithmName && that_present_algorithmName))
        return false;
      if (!this.algorithmName.equals(that.algorithmName))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    return 0;
  }

  public int compareTo(SentenceSimilarity other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;
    SentenceSimilarity typedOther = (SentenceSimilarity)other;

    lastComparison = Boolean.valueOf(isSetSimilarity()).compareTo(typedOther.isSetSimilarity());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetSimilarity()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.similarity, typedOther.similarity);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetSentence1()).compareTo(typedOther.isSetSentence1());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetSentence1()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.sentence1, typedOther.sentence1);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetSentence2()).compareTo(typedOther.isSetSentence2());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetSentence2()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.sentence2, typedOther.sentence2);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetId()).compareTo(typedOther.isSetId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.id, typedOther.id);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetValue()).compareTo(typedOther.isSetValue());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetValue()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.value, typedOther.value);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = Boolean.valueOf(isSetAlgorithmName()).compareTo(typedOther.isSetAlgorithmName());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetAlgorithmName()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.algorithmName, typedOther.algorithmName);
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
    StringBuilder sb = new StringBuilder("SentenceSimilarity(");
    boolean first = true;

    sb.append("similarity:");
    sb.append(this.similarity);
    first = false;
    if (!first) sb.append(", ");
    sb.append("sentence1:");
    if (this.sentence1 == null) {
      sb.append("null");
    } else {
      sb.append(this.sentence1);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("sentence2:");
    if (this.sentence2 == null) {
      sb.append("null");
    } else {
      sb.append(this.sentence2);
    }
    first = false;
    if (isSetId()) {
      if (!first) sb.append(", ");
      sb.append("id:");
      if (this.id == null) {
        sb.append("null");
      } else {
        sb.append(this.id);
      }
      first = false;
    }
    if (isSetValue()) {
      if (!first) sb.append(", ");
      sb.append("value:");
      if (this.value == null) {
        sb.append("null");
      } else {
        sb.append(this.value);
      }
      first = false;
    }
    if (isSetAlgorithmName()) {
      if (!first) sb.append(", ");
      sb.append("algorithmName:");
      if (this.algorithmName == null) {
        sb.append("null");
      } else {
        sb.append(this.algorithmName);
      }
      first = false;
    }
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // alas, we cannot check 'similarity' because it's a primitive and you chose the non-beans generator.
    if (sentence1 == null) {
      throw new org.apache.thrift.protocol.TProtocolException("Required field 'sentence1' was not present! Struct: " + toString());
    }
    if (sentence2 == null) {
      throw new org.apache.thrift.protocol.TProtocolException("Required field 'sentence2' was not present! Struct: " + toString());
    }
    // check for sub-struct validity
    if (sentence1 != null) {
      sentence1.validate();
    }
    if (sentence2 != null) {
      sentence2.validate();
    }
    if (id != null) {
      id.validate();
    }
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

  private static class SentenceSimilarityStandardSchemeFactory implements SchemeFactory {
    public SentenceSimilarityStandardScheme getScheme() {
      return new SentenceSimilarityStandardScheme();
    }
  }

  private static class SentenceSimilarityStandardScheme extends StandardScheme<SentenceSimilarity> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, SentenceSimilarity struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // SIMILARITY
            if (schemeField.type == org.apache.thrift.protocol.TType.DOUBLE) {
              struct.similarity = iprot.readDouble();
              struct.setSimilarityIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // SENTENCE1
            if (schemeField.type == org.apache.thrift.protocol.TType.STRUCT) {
              struct.sentence1 = new Sentence();
              struct.sentence1.read(iprot);
              struct.setSentence1IsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // SENTENCE2
            if (schemeField.type == org.apache.thrift.protocol.TType.STRUCT) {
              struct.sentence2 = new Sentence();
              struct.sentence2.read(iprot);
              struct.setSentence2IsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // ID
            if (schemeField.type == org.apache.thrift.protocol.TType.STRUCT) {
              struct.id = new ID();
              struct.id.read(iprot);
              struct.setIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // VALUE
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.value = iprot.readString();
              struct.setValueIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 6: // ALGORITHM_NAME
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.algorithmName = iprot.readString();
              struct.setAlgorithmNameIsSet(true);
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
      if (!struct.isSetSimilarity()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'similarity' was not found in serialized data! Struct: " + toString());
      }
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, SentenceSimilarity struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(SIMILARITY_FIELD_DESC);
      oprot.writeDouble(struct.similarity);
      oprot.writeFieldEnd();
      if (struct.sentence1 != null) {
        oprot.writeFieldBegin(SENTENCE1_FIELD_DESC);
        struct.sentence1.write(oprot);
        oprot.writeFieldEnd();
      }
      if (struct.sentence2 != null) {
        oprot.writeFieldBegin(SENTENCE2_FIELD_DESC);
        struct.sentence2.write(oprot);
        oprot.writeFieldEnd();
      }
      if (struct.id != null) {
        if (struct.isSetId()) {
          oprot.writeFieldBegin(ID_FIELD_DESC);
          struct.id.write(oprot);
          oprot.writeFieldEnd();
        }
      }
      if (struct.value != null) {
        if (struct.isSetValue()) {
          oprot.writeFieldBegin(VALUE_FIELD_DESC);
          oprot.writeString(struct.value);
          oprot.writeFieldEnd();
        }
      }
      if (struct.algorithmName != null) {
        if (struct.isSetAlgorithmName()) {
          oprot.writeFieldBegin(ALGORITHM_NAME_FIELD_DESC);
          oprot.writeString(struct.algorithmName);
          oprot.writeFieldEnd();
        }
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class SentenceSimilarityTupleSchemeFactory implements SchemeFactory {
    public SentenceSimilarityTupleScheme getScheme() {
      return new SentenceSimilarityTupleScheme();
    }
  }

  private static class SentenceSimilarityTupleScheme extends TupleScheme<SentenceSimilarity> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, SentenceSimilarity struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      oprot.writeDouble(struct.similarity);
      struct.sentence1.write(oprot);
      struct.sentence2.write(oprot);
      BitSet optionals = new BitSet();
      if (struct.isSetId()) {
        optionals.set(0);
      }
      if (struct.isSetValue()) {
        optionals.set(1);
      }
      if (struct.isSetAlgorithmName()) {
        optionals.set(2);
      }
      oprot.writeBitSet(optionals, 3);
      if (struct.isSetId()) {
        struct.id.write(oprot);
      }
      if (struct.isSetValue()) {
        oprot.writeString(struct.value);
      }
      if (struct.isSetAlgorithmName()) {
        oprot.writeString(struct.algorithmName);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, SentenceSimilarity struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      struct.similarity = iprot.readDouble();
      struct.setSimilarityIsSet(true);
      struct.sentence1 = new Sentence();
      struct.sentence1.read(iprot);
      struct.setSentence1IsSet(true);
      struct.sentence2 = new Sentence();
      struct.sentence2.read(iprot);
      struct.setSentence2IsSet(true);
      BitSet incoming = iprot.readBitSet(3);
      if (incoming.get(0)) {
        struct.id = new ID();
        struct.id.read(iprot);
        struct.setIdIsSet(true);
      }
      if (incoming.get(1)) {
        struct.value = iprot.readString();
        struct.setValueIsSet(true);
      }
      if (incoming.get(2)) {
        struct.algorithmName = iprot.readString();
        struct.setAlgorithmNameIsSet(true);
      }
    }
  }

}
