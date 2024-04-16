#include "decimal.h"

int from_float_to_decimal(float src, decimal *dst) {
  decimal_clear(dst);
  if (fabs(src) > 7.9228162514e+28) {
    dst->bits[0] = 0;
    return 1;
  }
  if (fabs(src) < 1e-28) {
    dst->bits[0] = 0;
    return 1;
  }
  if ((src == (long)src) &&
      ((src < 4294967295 && src > 0) || (src > -4294967295 && src < 0))) {
    int mantissa = src;
    if (mantissa < 0) {
      *dst = set_bit(*dst, 127);
      mantissa = -mantissa;
    }
    dst->bits[0] = mantissa;
  } else {
    char str[80];
    char str_mantissa[80];
    char str_exponent[80];
    sprintf(str, "%.7e", src);
    int count = 0;
    int count_mantissa = 0;
    int count_exponent = 0;
    while (str[count] != 'e') {
      if (str[count] != '.')
        str_mantissa[count_mantissa++] = str[count++];
      else
        count++;
    }
    str_mantissa[count_mantissa] = '\0';
    count++;
    while (str[count] != '\0') {
      str_exponent[count_exponent++] = str[count++];
    }
    str_exponent[count_exponent] = '\0';
    int mantissa = atoi(str_mantissa);
    int exponent = atoi(str_exponent) - 7;

    if (mantissa < 0) {
      *dst = set_bit(*dst, 127);
      mantissa = -mantissa;
    }
    dst->bits[0] = mantissa;
    if (exponent > 0) {
      decimal temp_decimal = decimal_init();
      from_int_to_decimal(1000000, &temp_decimal);
      while (exponent > 6) {
        exponent = exponent - 6;
        mul(*dst, temp_decimal, dst);
      }
      from_int_to_decimal(pow(10, exponent), &temp_decimal);
      mul(*dst, temp_decimal, dst);
    } else if (exponent < 0) {
      set_scale(dst, -exponent);
    }
  }
  return 0;
}