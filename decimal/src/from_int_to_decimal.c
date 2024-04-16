#include "decimal.h"

int from_int_to_decimal(int src, decimal *dst) {
  decimal_clear(dst);
  if (src < 0) {
    *dst = set_bit(*dst, 127);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}
