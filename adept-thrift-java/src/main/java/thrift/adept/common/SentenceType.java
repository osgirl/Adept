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

public enum SentenceType implements org.apache.thrift.TEnum {
  NONE(0),
  STATEMENT(1),
  QUESTION(2),
  INCOMPLETE(3),
  CLAUSE(4);

  private final int value;

  private SentenceType(int value) {
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
  public static SentenceType findByValue(int value) { 
    switch (value) {
      case 0:
        return NONE;
      case 1:
        return STATEMENT;
      case 2:
        return QUESTION;
      case 3:
        return INCOMPLETE;
      case 4:
        return CLAUSE;
      default:
        return null;
    }
  }
}