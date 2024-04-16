#include "decimal.h"

int add(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;
  int scale = 0;
  int scale_2 = 0;
  error = normalize(&value_1, &value_2);
  if (!error) scale = get_scale(value_1);
  if (!error) scale_2 = get_scale(value_2);
  int minus_zero_flag =
      0;  //  если одно из слагаемых -0, то не меняем знак результата:
  if ((!value_1.bits[0] && !value_1.bits[1] && !value_1.bits[2] && !scale &&
       get_bit(value_1, 127)) ||
      (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2] && !scale_2 &&
       get_bit(value_2, 127)))
    minus_zero_flag = 1;
  int sign_value_1 = get_bit(value_1, 127);
  int sign_value_2 = get_bit(value_2, 127);
  if (sign_value_2) {  //  если второе слагаемое отрицательное, то вычитаем
    negate(value_2, &value_2);  //  нужно, чтобы sub не начал прибавлять
    if (!sign_value_1) {
      if (!error) error = sub(value_1, value_2, result);
    } else {  //  если оба слагаемых отрицательные
      sign_value_2 = 0;
      if (!error)
        error = addcore_subfunction(value_1, value_2, result, error,
                                    sign_value_1, sign_value_2);
      if (error) error = 2;
      negate(*result, result);
    }
  } else if (sign_value_1 &&
             !sign_value_2) {  //  если первое слагаемое отрицательное
    negate(value_1, &value_1);  //  нужно, чтобы sub не вычитал
    error = sub(value_1, value_2, result);
    negate(*result, result);
  } else if (!sign_value_1 &&
             !sign_value_2) {  //  если оба слагаемых положительные
    // error = 1;
    // while (error) {
    if (!error)
      error = addcore_subfunction(value_1, value_2, result, error, sign_value_1,
                                  sign_value_2);
  }
  set_scale(result, scale);
  //  если в результате -0, то меняем знак:
  if (!minus_zero_flag) minus_zero_result(result);
  return error;
}
