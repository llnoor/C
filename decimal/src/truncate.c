#include "decimal.h"

int truncate(decimal value, decimal *result) {
  int scale = get_scale(value);
  int error = 0;
  if (scale) {
    decimal one = decimal_init();
    from_int_to_decimal(1, &one);
    decimal minus_one = decimal_init();
    from_int_to_decimal(-1, &minus_one);
    if (is_greater_or_equal(value, minus_one) &&
        is_less_or_equal(value, one)) {
      *result = decimal_init();
    } else {
      error = truncate_div_by_10(value, scale, result);
    }
  } else {
    *result = value;
  }
  return error;
}
