#include "decimal.h"

int floor(decimal value, decimal *result) {
  int error = 0;
  int sign = 0;
  int scale = get_scale(value);
  if (scale) {
    decimal *res = result;
    sign = get_bit(value, 127);
    if (sign) {
      error = truncate(value, res);
      decimal *copy = res;
      if (get_bit(*copy, 127)) negate(*copy, copy);
      decimal one = decimal_init();
      one.bits[0] = 1;
      if (!error) error = add(*copy, one, copy);
      if (error) {
        *copy = value;
        error = 0;
      }
      *copy = set_bit(*copy, 127);
      copy = result;
    } else {
      error = truncate(value, res);
      *res = *result;
    }
  } else {
    *result = value;
  }
  return error;
}
