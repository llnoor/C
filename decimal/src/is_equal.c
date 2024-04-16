#include "decimal.h"

int is_equal(decimal value_1, decimal value_2) {
  int result = 0;
  decimal value_1_temp = value_1;
  decimal value_2_temp = value_2;
  normalize(&value_1_temp, &value_2_temp);
  if (value_1_temp.bits[2] == 0 && value_2_temp.bits[2] == 0 &&
      value_1_temp.bits[1] == 0 && value_2_temp.bits[1] == 0 &&
      value_1_temp.bits[0] == 0 &&
      value_2_temp.bits[0] == 0) {  //  сравнение -0 и 0
    result = 1;
  } else {
    int sign_value_1 = get_bit(value_1_temp, 127);
    int sign_value_2 = get_bit(value_2_temp, 127);
    if (sign_value_1 == sign_value_2) {
      if (value_1_temp.bits[3] == value_2_temp.bits[3]) {
        if (value_1_temp.bits[2] == value_2_temp.bits[2]) {
          if (value_1_temp.bits[1] == value_2_temp.bits[1]) {
            if (value_1_temp.bits[0] == value_2_temp.bits[0]) {
              result = 1;
            } else {
              result = 0;
            }
          } else {
            result = 0;
          }
        } else {
          result = 0;
        }
      }
    } else {
      result = 0;
    }
  }
  return result;
}
