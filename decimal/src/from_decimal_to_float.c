#include "decimal.h"

int from_decimal_to_float(decimal src, float *dst) {
  int error = 0;
  // проверка, что число не NAN и не бесконечность
  if (is_inf(*dst) || is_nan(*dst)) error = 1;
  decimal temp_decimal = decimal_init();
  from_int_to_decimal(100000000, &temp_decimal);
  int exponent = get_scale(src) * (-1);
  while (src.bits[2] != 0) {
    error = divcore_subfunction(src, temp_decimal, &src, error);
    if (!error) exponent = exponent + 8;
  }
  from_int_to_decimal(100, &temp_decimal);
  while (src.bits[1] != 0) {
    error = divcore_subfunction(src, temp_decimal, &src, error);
    if (!error) exponent = exponent + 2;
  }
  *dst = src.bits[0] * pow(10, exponent);
  if (get_bit(src, 127) == 1) {
    *dst = -(*dst);
  }
  return error;
}
