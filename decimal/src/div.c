#include "decimal.h"

int div(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;  // код ошибки
  if (!dec_is_not_null(value_2)) {
    error = 3;  // если делитель равен нулю, возвращаем код ошибки 3
  } else {
    if (!dec_is_not_null(value_1)) {  // если делимое рано нулю, результат
      *result = decimal_init();  // приравниваем к нулю
    } else {
      int sign_val_1 = get_bit(value_1, 127);
      int sign_val_2 = get_bit(value_2, 127);
      value_1 = set_zero(value_1, 127);
      value_2 = set_zero(value_2, 127);
      normalize_for_div(&value_1, value_2, &error);
      decimal res = decimal_init();
      decimal ten = {{10, 0, 0, 0}};
      int res_scale = get_scale(value_1) -
                      get_scale(value_2);  // вычисляем итоговую степень
      if (!error)
        error = divcore_subfunction(value_1, value_2, &res,
                                    error);  // делим мантиссы целочисленно
      if (!error)
        error = mod_div(value_1, value_2, &res,
                        &res_scale);  // делим остаток целочисленного деления
      while (res_scale < 0) {  // если степень отрицательная
        res_scale++;  //доводим ее до положительной
        if (!error) error = mul(res, ten, &res);
      }
      set_scale(&res, res_scale);  //устанавливаем итоговую степень
      if ((sign_val_1 + sign_val_2) == 1) {
        res = set_bit(res, 127);
        if (error == 1) error = 2;
      }
      if (error == 4) {  // в случае, если результат стремится к 0
        while (error) {
          div_by_10(value_2, &value_2);  // делим мантиссы
          error = 0;
          error = divcore_subfunction(value_1, value_2, &res, error);
        }
        if (res.bits[0] >= 5) {
          res = decimal_init();
          from_int_to_decimal(1, &res);
          set_scale(&res, 28);
          if ((sign_val_1 + sign_val_2) == 1) {
            res = set_bit(res, 127);
            if (error == 1) error = 2;
          }
        } else {
          res = decimal_init();
        }
        error = 0;
      }
      if (!error) *result = res;
    }
  }
  return error;
}

//функция вычисляет остаток от деления
int module(decimal value_1, decimal value_2, decimal res,
           decimal *mod) {
  int error = 0;
  decimal x = decimal_init();
  error = mul(res, value_2, &x);
  if (!error) error = subcore_positive(value_1, x, mod);
  if (error) {
    *mod = decimal_init();
    error = 0;
  }
  return error;
}

//функция увеличивает мантиссу делимого на х10, пока она не будет больше
//мантиссы делителя
void normalize_for_div(decimal *value_1, decimal value_2, int *error) {
  int scale = get_scale(*value_1);
  while (is_less_mantiss(*value_1, value_2) && !*error) {
    decimal ten = {{10, 0, 0, 0}};
    if (!*error) *error = mulcore_subfunction(*value_1, ten, value_1);
    scale = get_scale(*value_1);
    if (scale < 28) {
      scale++;
      set_scale(value_1, scale);
    } else {
      *error = 4;  //  test_1:396 получается очень малое число,
                   //  стремящееся к 0
      break;
    }
  }
}

//функция деления остатка
int mod_div(decimal value_1, decimal value_2, decimal *res,
            int *res_scale) {
  decimal mod = decimal_init();
  int error = 0;
  decimal ten = {{10, 0, 0, 0}};
  error = module(value_1, value_2, *res, &mod);  // узнаем остаток от деления
  int significant_bits_res = significant_mantiss(
      *res);  // вычисляем количество значимых битов в рез-те
  while (dec_is_not_null(mod) &&
         get_bit(*res, 95) == 0  // делим остаток на делитель
         && *res_scale < 28 && significant_bits_res <= 92 && !error) {
    decimal number = decimal_init();
    if (!error) error = mul(mod, ten, &mod);  // умножаем остаток на 10
    while (is_less_mantiss(mod, value_2) &&
           significant_bits_res <= 92) {  // пока остаток меньше делителя,
      if (!error) error = mul(mod, ten, &mod);
      if (!error) error = mul(*res, ten, res);  // умножаем его на 10,
      (*res_scale)++;  // увеличивая при этом степень
      significant_bits_res = significant_mantiss(*res);
    }
    if (significant_bits_res <= 92) {
      if (!error) error = divcore_subfunction(mod, value_2, &number, error);
      number = set_zero(number, 127);  //добавляем цифру в результат
      if (!error) error = mul(*res, ten, res);
      if (!error) error = addcore_subfunction(*res, number, res, 0, 0, 0);
      if (!error)
        error = module(
            mod, value_2, number,
            &mod);  // вычиляем новый остаток от деления предыдущего остатка
      if (!error) (*res_scale)++;
      significant_bits_res = significant_mantiss(*res);
    }
  }
  return error;
}