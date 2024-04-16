#include "decimal.h"

int mul(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;
  decimal zero = decimal_init();
  decimal one = decimal_init();
  from_int_to_decimal(1, &one);
  decimal minus_one = decimal_init();
  from_int_to_decimal(-1, &minus_one);
  if (is_equal(value_1, one) ||
      is_equal(value_1, minus_one)) {  //  если value_1 == 1 или -1
    *result = value_2;
    if (is_equal(value_1, minus_one)) negate(*result, result);
  } else if (is_equal(value_2, one) ||
             is_equal(value_2, minus_one)) {  //  если value_2 == 1 или -1
    *result = value_1;
    if (is_equal(value_2, minus_one)) negate(*result, result);
  } else if (is_equal(value_1, zero) || is_equal(value_2, zero)) {
    *result = zero;
  } else {
    error = mul_subfunction(value_1, value_2, result);
  }
  return error;
}
