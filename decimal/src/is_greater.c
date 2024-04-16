#include "decimal.h"

int is_greater(decimal value_1, decimal value_2) {
  int result = 0;
  decimal value_1_temp = value_1;
  decimal value_2_temp = value_2;
  int sign_value_1 = get_bit(value_1_temp, 127);
  int sign_value_2 = get_bit(value_2_temp, 127);
  if (is_equal(value_1_temp, value_2_temp)) {
    result = 0;
  } else {
    normalize(&value_1_temp, &value_2_temp);
    if (sign_value_1 ==
        sign_value_2) {  //  если оба положительные или оба отрицательные
      if (value_1_temp.bits[3] == value_2_temp.bits[3]) {
        result = is_greater_mantiss(value_1_temp, value_2_temp);
      }
      if (sign_value_1 == 1 && result == 1) {  //  если оба отрицательные
        result = 0;
      } else if (sign_value_1 == 1 && result == 0) {
        result = 1;
      }
    } else if (sign_value_1 == 1 &&
               sign_value_2 == 0) {  //  если первое отрицательное
      result = 0;
    } else if (sign_value_1 == 0 &&
               sign_value_2 == 1) {  //  если второе отрицательное
      result = 1;
    }
  }
  return result;
}
