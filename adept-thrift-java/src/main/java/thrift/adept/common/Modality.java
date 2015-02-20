/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package thrift.adept.common;


import java.util.Map;
import java.util.HashMap;
import org.apache.thrift.TEnum;

public enum Modality implements org.apache.thrift.TEnum {
  ABILITY(0),
  EFFORT(1),
  INTENTION(2),
  SUCCESS(3),
  WANT(4),
  COMMITTED_BELIEF(5),
  NON_COMMITTED_BELIEF(6),
  NON_ATTRIBUTABLE_BELIEF(7);

  private final int value;

  private Modality(int value) {
    this.value = value;
  }

  /**
   * Get the integer value of this enum value, as defined in the Thrift IDL.
   */
  public int getValue() {
    return value;
  }

  /**
   * Find a the enum type by its integer value, as defined in the Thrift IDL.
   * @return null if the value is not found.
   */
  public static Modality findByValue(int value) { 
    switch (value) {
      case 0:
        return ABILITY;
      case 1:
        return EFFORT;
      case 2:
        return INTENTION;
      case 3:
        return SUCCESS;
      case 4:
        return WANT;
      case 5:
        return COMMITTED_BELIEF;
      case 6:
        return NON_COMMITTED_BELIEF;
      case 7:
        return NON_ATTRIBUTABLE_BELIEF;
      default:
        return null;
    }
  }
}
