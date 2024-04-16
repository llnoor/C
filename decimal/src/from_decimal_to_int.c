#include "decimal.h"

int from_decimal_to_int(decimal src, int *dst) {
  int result = 0;
  *dst = 0;
  int exponent = get_scale(src);
  if (exponent == 28 && src.bits[2] == 0 && src.bits[1] == 0) {
    *dst = 0;
    return 0;
  }
  if (src.bits[3] == 0 && src.bits[2] == 0 && src.bits[1] == 0) {
    *dst = (int)src.bits[0];
    return 0;
  }
  if (exponent > 0 && exponent < 28) {
    decimal temp_decimal = decimal_init();
    from_int_to_decimal(10, &temp_decimal);
    int error = 0;
    while (exponent > 0) {
      error = divcore_subfunction(src, temp_decimal, &src, error);
      exponent = exponent - 1;
    }
  }
  if (exponent == 0 && src.bits[2] == 0 && src.bits[1] == 0) {
    if (get_bit(src, 127) == 1 && src.bits[0] <= 2147483648) {
      *dst = -1 * src.bits[0];
      result = 0;
    } else if (get_bit(src, 127) == 0 && src.bits[0] <= 2147483647) {
      *dst = src.bits[0];
      result = 0;
    } else {
      *dst = 0;
      result = 1;
    }
  } else {
    *dst = 0;
    result = 1;
  }
  return result;
}
