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

public enum SarcasmJudgment implements org.apache.thrift.TEnum {
  POSITIVE(0),
  NEGATIVE(1),
  NONE(2);

  private final int value;

  private SarcasmJudgment(int value) {
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
  public static SarcasmJudgment findByValue(int value) { 
    switch (value) {
      case 0:
        return POSITIVE;
      case 1:
        return NEGATIVE;
      case 2:
        return NONE;
      default:
        return null;
    }
  }
}
