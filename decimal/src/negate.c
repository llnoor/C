#include "decimal.h"

int negate(decimal value, decimal *result) {
  if (get_bit(value, 127) != 1) {
    value = set_bit(value, 127);
  } else {
    value.bits[3] = ~value.bits[3];
    value = set_bit(value, 127);
    value.bits[3] = ~value.bits[3];
  }
  *result = value;
  return 0;
}
