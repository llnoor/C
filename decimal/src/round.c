#include "decimal.h"

int round(decimal value, decimal *result) {
  int error = 0;
  int scale = get_scale(value);
  int sign_value = get_bit(value, 127);
  if (scale) {
    decimal ten = decimal_init();
    from_int_to_decimal(10, &ten);
    if (sign_value) negate(value, &value);
    set_scale(&value, 0);
    while (scale > 1 && !is_less(value, ten)) {
      error = divcore_subfunction(value, ten, &value, error);
      scale--;
    }
    if (scale == 1)
      if (!error) error = round_subfunction(value, result, sign_value);
  } else {
    *result = value;
  }
  return error;
}
