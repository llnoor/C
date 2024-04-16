#include "decimal.h"

int sub(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;
  int scale = 0;
  error = normalize(&value_1, &value_2);
  int sign_value_1 = get_bit(value_1, 127);
  int sign_value_2 = get_bit(value_2, 127);
  if (!error) {
    scale = get_scale(value_1);
    if (!sign_value_1 &&
        sign_value_2) {  //  если второе отрицательное, то складываем
      negate(value_2, &value_2);
      error = addcore_subfunction(value_1, value_2, result, error, sign_value_1,
                                  sign_value_2);
    } else if (sign_value_1 && !sign_value_2) {  //  если первое отрицательное
      error = addcore_subfunction(value_1, value_2, result, error, sign_value_1,
                                  sign_value_2);
      if (!error) negate(*result, result);
    } else {  //  если два положительных или отрицательных числа
      int negate_flag = 0;
      if (is_less(value_1, value_2) && sign_value_1) negate_flag = 1;
      if ((is_less(value_1, value_2) && !sign_value_1) ||
          (is_greater(value_1, value_2) && sign_value_1)) {
        if (!sign_value_1)
          negate_flag = 1;  // если два положительных меняем знак результата
        decimal buffer = decimal_init();
        buffer = value_2;  //  меняем аргументы местами
        value_2 = value_1;
        value_1 = buffer;
      }
      error = subcore_positive(value_1, value_2, result);
      if (negate_flag && !error) {
        negate(*result, result);
      }
    }
    if (error == 1 && (sign_value_1 && !sign_value_2)) {
      error = 2;
    } else if (!error) {
      set_scale(result, scale);
      //  если в результате -0, то меняем знак:
      minus_zero_result(result);
    }
  }
  return error;
}
