#include "decimal.h"

// печать децимал
int decimal_print(decimal src) {
  for (int i = 128 - 1; i >= 0; i--) {
    printf("%d", get_bit(src, i));
  }
  // Отобразить номер каждого бита в каждом инте:
  printf("\n");
  int count = 1;
  for (int i = 128 - 1; i >= 0; i--) {
    if (i == 31 || i == 63 || i == 95) {
      printf(".");
      count = 1;
    } else if ((111 < i) && (i < 120)) {
      printf("^");
    } else {
      printf("%d", count);
    }
    count--;
    if (count < 0) {
      count = 9;
    }
  }
  printf("\n\n");
  return 0;
}

decimal decimal_init() {
  decimal init_decimal = {{0, 0, 0, 0}};
  return init_decimal;
}

int decimal_clear(decimal *dst) {
  dst->bits[3] = 0;
  dst->bits[2] = 0;
  dst->bits[1] = 0;
  dst->bits[0] = 0;
  return 0;
}

decimal set_bit(decimal decimal_num, int position) {
  int mask = 0;
  if (position >= 0 && position < 32) {
    mask = 1 << position;
    decimal_num.bits[0] = decimal_num.bits[0] | mask;
  } else if (position > 31 && position < 64) {
    mask = 1 << (position - 32);
    decimal_num.bits[1] = decimal_num.bits[1] | mask;
  } else if (position > 63 && position < 96) {
    mask = 1 << (position - 64);
    decimal_num.bits[2] = decimal_num.bits[2] | mask;
  } else if (position > 95 && position < 128) {
    mask = 1 << (position - 96);
    decimal_num.bits[3] = decimal_num.bits[3] | mask;
  }
  return decimal_num;
}

decimal set_zero(decimal decimal_num, int position) {
  int mask = 1;
  if (position >= 0 && position < 32) {
    mask = 1 << position;
    decimal_num.bits[0] = decimal_num.bits[0] & ~mask;
  } else if (position > 31 && position < 64) {
    mask = 1 << (position - 32);
    decimal_num.bits[1] = decimal_num.bits[1] & ~mask;
  } else if (position > 63 && position < 96) {
    mask = 1 << (position - 64);
    decimal_num.bits[2] = decimal_num.bits[2] & ~mask;
  } else if (position > 95 && position < 128) {
    mask = 1 << (position - 96);
    decimal_num.bits[3] = decimal_num.bits[3] & ~mask;
  }
  return decimal_num;
}

int get_bit(decimal decimal_num, int position) {
  int bit = 0;
  if (position >= 0 && position < 32) {
    bit = (decimal_num.bits[0] & (1 << position)) ? 1 : 0;
  } else if (position > 31 && position < 64) {
    bit = (decimal_num.bits[1] & (1 << (position - 32))) ? 1 : 0;
  } else if (position > 63 && position < 96) {
    bit = (decimal_num.bits[2] & (1 << (position - 64))) ? 1 : 0;
  } else if (position > 95 && position < 128) {
    bit = (decimal_num.bits[3] & (1 << (position - 96))) ? 1 : 0;
  }
  return bit;
}

int set_zero_in_int(int num, int position) {
  int mask = 1 << position;
  return num & ~mask;
}

int get_scale(decimal dec) {
  return set_zero_in_int(dec.bits[3], 31) >> 16;
}

void set_scale(decimal *dec, int scale) {
  int sign = get_bit(*dec, 127);
  dec->bits[3] = scale;
  dec->bits[3] <<= 16;
  if (sign) *dec = set_bit(*dec, 127);
}

//сдвигает мантиссу децимал влево на n бит
void step_left(decimal *decimal_num, int n) {
  for (int i = 0; i < n; i++) {
    int tmp_bit_1 = get_bit(*decimal_num, 31);
    int tmp_bit_2 = get_bit(*decimal_num, 63);
    decimal_num->bits[0] <<= 1;
    decimal_num->bits[1] <<= 1;
    decimal_num->bits[2] <<= 1;
    if (tmp_bit_1) *decimal_num = set_bit(*decimal_num, 32);
    if (tmp_bit_2) *decimal_num = set_bit(*decimal_num, 64);
  }
}

//сдвигает мантиссу децимал вправо на n бит
void step_right(decimal *decimal_num, int n) {
  for (int i = 0; i < n; i++) {
    int tmp_bit_1 = get_bit(*decimal_num, 32);
    int tmp_bit_2 = get_bit(*decimal_num, 64);
    decimal_num->bits[0] >>= 1;
    decimal_num->bits[1] >>= 1;
    decimal_num->bits[2] >>= 1;
    if (tmp_bit_1) *decimal_num = set_bit(*decimal_num, 31);
    if (tmp_bit_2) *decimal_num = set_bit(*decimal_num, 63);
  }
}

//логическое И (&) для мантиссы децимал
void bitwise_and_decimal(decimal *res, decimal value_1,
                         decimal value_2) {
  decimal temp = decimal_init();
  for (int i = 0; i < 3; i++) {
    temp.bits[i] = value_1.bits[i] & value_2.bits[i];
  }
  *res = temp;
}

//логическое исключающее ИЛИ (^) для мантиссы децимал
void bitwise_xor_decimal(decimal *res, decimal value_1,
                         decimal value_2) {
  decimal temp = decimal_init();
  for (int i = 0; i < 3; i++) {
    temp.bits[i] = value_1.bits[i] ^ value_2.bits[i];
  }
  *res = temp;
}

void bitwise_inversion_decimal(decimal *res, decimal value) {
  for (int i = 0; i < 3; i++) {
    value.bits[i] = ~value.bits[i];
  }
  *res = value;
}

//проверка мантиссы децимал на ненулевое значение

int dec_is_not_null(decimal decimal_num) {
  return decimal_num.bits[0] || decimal_num.bits[1] || decimal_num.bits[2];
}

//устанавливает знак результата для умножения и деления

void set_result_sign(decimal value_1, decimal value_2,
                     decimal *result) {
  if (get_bit(value_1, 127) ^ get_bit(value_2, 127))
    *result = set_bit(*result, 127);
}

//  Операция сложения целых чисел. Возвращает код ошибки 1,
//  если число при вычислении слишком большое
int addcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result, int error, int sign_value_1,
                        int sign_value_2) {
  error = mantissa_overflow_check_for_add(value_1, value_2);
  decimal res = decimal_init();
  decimal carry = decimal_init();
  bitwise_xor_decimal(&res, value_1, value_2);
  bitwise_and_decimal(&carry, value_1, value_2);
  if (get_bit(carry, 95) && !sign_value_1 && !sign_value_2) {
    error = 1;
  } else if (get_bit(carry, 95) && sign_value_1 && sign_value_2) {
    error = 2;
  } else if (!error) {
    step_left(&carry, 1);
    int i = 0;
    while (dec_is_not_null(carry)) {
      decimal temp = decimal_init();
      temp = res;
      bitwise_xor_decimal(&res, res, carry);
      bitwise_and_decimal(&carry, temp, carry);
      if (get_bit(carry, 95)) {
        error = 1;
      }
      step_left(&carry, 1);
      i++;
    }
    if (!error) *result = res;
  }
  return error;
}

//  вспомогательная функция normalize
//  возвращает код ошибки 1 - если есть переполнение
int mul_normalize(int dif, decimal *value) {
  int error = 0;
  decimal result = decimal_init();
  error = pow_ten_by_x(&result, dif);
  if (!error) {
    int significant_1 = significant_mantiss(*value);
    int significant_2 = significant_mantiss(result);
    int significant_sum = significant_1 + significant_2;
    if (significant_sum > 96) {
      if (!get_bit(*value, 127))
        error = 1;
      else
        error = 2;
    } else {
      error = mul(*value, result, value);
    }
  }
  return error;
}

int div_normalize(int dif, decimal *value) {
  int error = 0;
  decimal mul_dec = decimal_init();
  error = pow_ten_by_x(&mul_dec, dif - 1);
  if (is_equal_mantiss(mul_dec, *value)) {
    *value = decimal_init();
  } else {
    int sign_value = get_bit(*value, 127);
    if (sign_value) negate(*value, value);
    if (!error) error = divcore_subfunction(*value, mul_dec, value, error);
    if (!error) error = round_subfunction(*value, value, sign_value);
    if (error && sign_value) *value = set_bit(*value, 127);
  }
  return error;
}

//  вспомогательная функция normalize
//  возвращает код ошибки 1 - если есть переполнение
int do_normalize(int lesser_scale, decimal *lesser_value, int larger_scale,
                 decimal *larger_value) {
  int error = 0;
  int dif = (larger_scale - lesser_scale);
  decimal temp = *lesser_value;
  error = mul_normalize(dif, &temp);
  if (!error) {
    *lesser_value = temp;
    set_scale(lesser_value, larger_scale);
  } else if (error) {
    while (error && dif > 0) {  //  пробуем домножить на меньшее число
      temp = *lesser_value;
      dif--;
      error = mul_normalize(dif, &temp);
    }
    if (!error) {
      decimal one = decimal_init();
      from_int_to_decimal(1, &one);
      decimal minus_one = decimal_init();
      from_int_to_decimal(-1, &minus_one);
      *lesser_value = temp;
      int new_scale = dif + lesser_scale;
      set_scale(lesser_value, new_scale);
      dif = (larger_scale - new_scale);
      temp = *larger_value;
      error = div_normalize(dif, &temp);
      if (error) {  //  если не смогли нормализовать, проверяем larger_value
        if (is_greater(*larger_value, minus_one) &&
            is_less(*larger_value, one)) {
          error = 0;
        }
      } else {
        set_scale(&temp, new_scale);
      }
      *larger_value = temp;
    }
  }
  return error;
}

//  тело функции normalize
//  возвращает код ошибки 1 - если есть переполнение
int normalize(decimal *value_1, decimal *value_2) {
  int error = 0;
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);
  if (scale_1 < scale_2) {
    error = do_normalize(scale_1, value_1, scale_2, value_2);
  } else if (scale_1 > scale_2) {
    error = do_normalize(scale_2, value_2, scale_1, value_1);
  }
  return error;
}

//  вспомогательная функция is_less
//  сравнение "меньше ли" мантисса
int is_less_mantiss(decimal value_1, decimal value_2) {
  int result = 0;
  if (value_1.bits[2] == value_2.bits[2]) {
    if (value_1.bits[1] == value_2.bits[1]) {
      if (value_1.bits[0] == value_2.bits[0]) {
        result = 0;
      } else if (value_1.bits[0] < value_2.bits[0]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (value_1.bits[1] < value_2.bits[1]) {
      result = 1;
    } else {
      result = 0;
    }
  } else if (value_1.bits[2] < value_2.bits[2]) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

int is_greater_mantiss(decimal value_1, decimal value_2) {
  int result = 0;
  if (value_1.bits[2] == value_2.bits[2]) {
    if (value_1.bits[1] == value_2.bits[1]) {
      if (value_1.bits[0] == value_2.bits[0]) {
        result = 0;
      } else if (value_1.bits[0] > value_2.bits[0]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (value_1.bits[1] > value_2.bits[1]) {
      result = 1;
    } else {
      result = 0;
    }
  } else if (value_1.bits[2] > value_2.bits[2]) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

int is_equal_mantiss(decimal value_1, decimal value_2) {
  int result = 0;
  if (value_1.bits[2] == value_2.bits[2]) {
    if (value_1.bits[1] == value_2.bits[1]) {
      if (value_1.bits[0] == value_2.bits[0]) {
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
  return result;
}

//  вспомогательная функция sub
//  Операция вычитания целых чисел. Знак и степень value_1 теряется
int subcore_positive(decimal value_1, decimal value_2,
                     decimal *result) {
  decimal borrow = decimal_init();
  int i = 0;
  int error = 0;
  while (dec_is_not_null(value_2) && !error) {
    decimal inverted_1 = decimal_init();
    bitwise_inversion_decimal(&inverted_1, value_1);
    bitwise_and_decimal(&borrow, inverted_1, value_2);
    bitwise_xor_decimal(&value_1, value_1, value_2);
    if (get_bit(borrow, 95)) error = 1;
    step_left(&borrow, 1);
    value_2 = borrow;
    i++;
  }
  if (!error) *result = value_1;
  return error;
}

// вспомогательная функция деления мантиссы
int divcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result, int error) {
  int sign_value_1 = get_bit(value_1, 127);
  int sign_value_2 = get_bit(value_2, 127);
  decimal res = decimal_init();
  if (is_greater_mantiss(value_2, value_1)) {
    error = 1;
    from_int_to_decimal(1, &res);
  } else if (is_equal_mantiss(value_2, value_1)) {
    from_int_to_decimal(1, &res);
  } else {
    while ((is_less_mantiss(value_2, value_1) ||
            is_equal_mantiss(value_1, value_2)) &&
           !error) {
      int i = -1;
      decimal shifter = {{1, 0, 0, 0}};
      decimal tmp_value_2 = value_2;
      while ((is_less_mantiss(tmp_value_2, value_1) ||
              is_equal_mantiss(value_1, tmp_value_2)) &&
             !get_bit(tmp_value_2, 95) && !error) {
        step_left(&tmp_value_2, 1);
        i++;
      }
      step_left(&shifter, i);
      if (!error) {
        addcore_subfunction(res, shifter, &res, error, 0,
                            0);  //  прибавляем shifter к res
        decimal shifted_value_2 = value_2;
        if (get_bit(shifted_value_2, 95 - i + 1)) error = 1;
        step_left(&shifted_value_2,
                  i);  //  смещаем value_2 на i и записываем в shifted_value_2
        //  отнимаем из value_1 shifted_value_2
        if (!error)
          error = subcore_positive(value_1, shifted_value_2, &value_1);
      }
    }
  }
  if ((sign_value_1 + sign_value_2) == 1) res = set_bit(res, 127);
  *result = res;
  return error;
}

//  если децимал равен -0, то меняет знак:
int minus_zero_result(decimal *result) {
  int scale = get_scale(*result);
  if (!result->bits[0] && !result->bits[1] && !result->bits[2] && !scale &&
      get_bit(*result, 127))
    negate(*result, result);
  return 0;
}

// Вспомогательная функция truncate
//  Функция деления мантиссы на 10 со сдвигом плавающей точки на 1
//  Сохраняет исходный знак
int div_by_10(decimal value_1, decimal *result) {
  int error = 0;
  decimal res = decimal_init();
  decimal sub_1 = value_1;
  int scale = get_scale(value_1);
  int sign = get_bit(value_1, 127);
  if (scale) set_scale(&sub_1, 0);
  step_right(&sub_1, 2);
  double mul_temp = 10;
  decimal sub_2 = decimal_init();
  from_int_to_decimal(mul_temp, &sub_2);
  decimal sub_mul = decimal_init();
  error = divcore_subfunction(sub_1, sub_2, &sub_mul, error);
  step_right(&sub_1, 1);
  if (!error) error = sub(sub_1, sub_mul, &res);
  if (scale) set_scale(&res, scale - 1);
  if (sign) res = set_bit(res, 127);
  *result = res;
  return error;
}

//  Вычисляет значимую часть мантиссы децимал
int significant_mantiss(decimal value) {
  int significant = 96;
  for (; significant > 0; significant--) {
    if (get_bit(value, significant)) {
      significant++;
      break;
    }
  }
  return significant;
}

//  Вспомогательная функция truncate
//  Делит мантиссу на 10 в степени scale без округления
//  Исходная степень в результате не сохраняется
int truncate_div_by_10(decimal value, int scale, decimal *result) {
  int error = 1;
  while (error) {
    decimal res = decimal_init();
    decimal scale_div_dec = decimal_init();
    error = pow_ten_by_x(&scale_div_dec, scale);
    if (!error) error = divcore_subfunction(value, scale_div_dec, &res, error);
    if (error) {  //  для большой мантиссы
      div_by_10(value, &res);
      scale--;
      value = res;
    }
    *result = res;
    if (!scale) break;
  }
  return error;
}

//  записывает в *value результат возведения числа 10 в положительную степень x
int pow_ten_by_x(decimal *value, int x) {
  int error = 0;
  *value = decimal_init();
  if (x == 0) {
    from_int_to_decimal(1, value);
  } else if (x == 1) {
    from_int_to_decimal(10, value);
  } else if (x > 1) {
    from_int_to_decimal(10, value);
    decimal ten = {{10, 0, 0, 0}};
    for (int i = 0; i < x - 1; i++) {
      if (!error) error = mul(*value, ten, value);
    }
  }
  return error;
}

// возвращает 1, если при сложении value_1 и value_2 будет переполнение мантиссы
int mantissa_overflow_check_for_add(decimal value_1, decimal value_2) {
  int error = 0;
  if (get_bit(value_1, 95) && get_bit(value_2, 95)) {
    error = 1;
  } else if (get_bit(value_1, 95) ^ get_bit(value_2, 95)) {
    int i = 94;
    while (i != -1 && (get_bit(value_1, i) || get_bit(value_2, i))) {
      if (get_bit(value_1, i) && get_bit(value_2, i)) {
        error = 1;
        break;
      }
      i--;
    }
  }
  return error;
}

//  вспомогательная функция умножения
int mul_subfunction(decimal value_1, decimal value_2,
                    decimal *result) {
  int error = 0;
  int sign_value_1 = get_bit(value_1, 127);
  int sign_value_2 = get_bit(value_2, 127);
  int significant_1 = significant_mantiss(value_1);
  int significant_2 = significant_mantiss(value_2);
  int significant_sum = significant_1 + significant_2;
  if (significant_sum > 96) {  //  вычисляем возможность переполнения мантиссы
    error = mul_big(value_1, value_2, significant_sum, result);
    if (error) {
      if (sign_value_1 == sign_value_2)
        error = 1;
      else
        error = 2;
    }
  } else {
    error = mulcore_subfunction(value_1, value_2, result);
  }
  return error;
}

//  вспомогательная функция умножения в случае, если нет переполнения мантиссы
int mulcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result) {
  int error = 0;
  int sign_value_1 = get_bit(value_1, 127);
  int sign_value_2 = get_bit(value_2, 127);
  int scale_1 = get_scale(value_1);
  int scale_2 = get_scale(value_2);
  decimal zero = decimal_init();
  decimal one = decimal_init();
  from_int_to_decimal(1, &one);
  decimal minus_one = decimal_init();
  from_int_to_decimal(-1, &minus_one);
  decimal val_1_temp = value_1;
  decimal val_2_temp = value_2;
  decimal res = decimal_init();
  while (dec_is_not_null(val_2_temp) && !error) {  //  умножение мантисс
    if (get_bit(val_2_temp, 0))
      error = addcore_subfunction(res, val_1_temp, &res, error, sign_value_1,
                                  sign_value_2);
    if (get_bit(val_1_temp, 95)) {
      if (sign_value_1 == sign_value_2)
        error = 1;
      else
        error = 2;
    }
    step_left(&val_1_temp, 1);
    step_right(&val_2_temp, 1);
  }
  if ((scale_1 + scale_2) > 28) {  //  если итоговая степень превышает 28
    int diff = (scale_1 + scale_2) - 28;
    error = div_normalize(diff, &res);  //  сокращаем результат до степени 28
    set_scale(&res, 28);
  } else {
    set_scale(&res, scale_1 + scale_2);
  }
  set_result_sign(val_1_temp, val_2_temp, &res);
  if (!error) *result = res;
  //  если множитель дробное число от -1 до 1
  if (((is_greater(
            value_2,
            minus_one)  //  проверка если value_2 == число с плавающей точкой
        && is_less(value_2, one) && is_not_equal(value_2, zero))) ||
      ((is_greater(
            value_1,
            minus_one)  //  проверка если value_1 == число с плавающей точкой
        && is_less(value_1, one) && is_not_equal(value_1, zero)))) {
    error = mul_fractional(value_1, value_2, result);
  }
  return error;
}

//  вспомогательная функция умножения, если одно из множителей == единица с
//  плавающей точкой
int mul_fractional(decimal value_1, decimal value_2,
                   decimal *result) {
  int error = 0;
  decimal one = decimal_init();
  from_int_to_decimal(1, &one);
  decimal minus_one = decimal_init();
  from_int_to_decimal(-1, &minus_one);
  decimal zero = decimal_init();
  if ((is_greater(
           value_2,
           minus_one)  //  проверка если value_2 == число с плавающей точкой
       && is_less(value_2, one) && is_not_equal(value_2, zero))) {
    error = mul_fractional_1(value_1, value_2, result);
  } else if ((is_greater(value_1, minus_one)  //  проверка если value_1 ==
                                                  //  число с плавающей точкой
              && is_less(value_1, one) &&
              is_not_equal(value_1, zero))) {
    error = mul_fractional_1(value_2, value_1, result);
  }
  return error;
}

//  вспомогательная функция умножения, если value_2 == единица с плавающей
//  точкой либо пермещает точку, либо делит мантиссу value_1
int mul_fractional_1(decimal value_1, decimal value_2,
                     decimal *result) {
  int error = 0;
  int scale_1 = get_scale(value_1);
  int scale_2 = get_scale(value_2);
  int sign_value_1 = get_bit(value_1, 127);
  decimal one = decimal_init();
  from_int_to_decimal(1, &one);
  decimal minus_one = decimal_init();
  from_int_to_decimal(-1, &minus_one);
  int new_scale = scale_2;
  decimal temp = value_2;
  int i = 0;
  while (is_greater(temp, minus_one) && is_less(temp, one) &&
         new_scale > 0) {
    new_scale--;
    set_scale(&temp, new_scale);
    i++;
  }
  if ((is_equal(temp, one)) || (is_equal(temp, minus_one))) {
    *result = value_1;
    if ((scale_1 + i) > 28) {
      int diff = (scale_1 + i) - 28;
      error = div_normalize(diff, result);
      set_scale(result, 28);
    } else {
      set_scale(result, scale_1 + i);
    }
    if (sign_value_1) *result = set_bit(*result, 127);
  }
  return error;
}

//  функция для умножения больших чисел
int mul_big(decimal value_1, decimal value_2, int significant_sum,
            decimal *result) {
  int error = 0;
  decimal res = decimal_init();
  int scale_1 = get_scale(value_1);
  int scale_2 = get_scale(value_2);
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  int sign_val_1 = get_bit(value_1, 127);
  int sign_val_2 = get_bit(value_2, 127);
  if (sign_val_1) negate(value_1, &value_1);
  if (sign_val_2) negate(value_2, &value_2);
  int x = significant_sum - 96;
  decimal ten = decimal_init();
  from_int_to_decimal(10, &ten);
  decimal value_1_large = decimal_init();

  decimal mul_dec = decimal_init();
  error = pow_ten_by_x(&mul_dec, x);

  if (!error)
    error = divcore_subfunction(value_1, mul_dec, &value_1_large, error);
  decimal value_1_small = decimal_init();
  decimal value_1_large_mod = decimal_init();
  if (!error) error = mul(value_1_large, mul_dec, &value_1_large_mod);

  if (!error) error = sub(value_1, value_1_large_mod, &value_1_small);

  decimal value_2_small = decimal_init();
  decimal value_2_large = decimal_init();
  if (!error)
    error = divcore_subfunction(value_2, mul_dec, &value_2_large, error);

  decimal value_2_large_mod = decimal_init();
  if (!error) error = mul(value_2_large, mul_dec, &value_2_large_mod);
  if (!error) error = sub(value_2, value_2_large_mod, &value_2_small);

  decimal add_1 = decimal_init();
  if (!error) error = mul(value_1_large, value_2_large, &add_1);
  if (!error) error = mul(add_1, mul_dec, &add_1);
  decimal add_2 = decimal_init();
  if (!error) error = mul(value_1_large, value_2_small, &add_2);
  decimal add_3 = decimal_init();
  if (!error) error = mul(value_2_large, value_1_small, &add_3);

  decimal add_4 = decimal_init();
  int significant_1 = significant_mantiss(value_1_small);
  int significant_2 = significant_mantiss(value_2_small);
  int significant_sum_small = significant_1 + significant_2;
  if (!error) error = mul(value_1_small, value_2_small, &add_4);
  if (significant_sum_small > 96) {
    int y = significant_sum_small - 96;
    int diff = x - y;
    if (diff >= 0) {
      if (!error) error = pow_ten_by_x(&mul_dec, diff);
      if (!error) error = divcore_subfunction(add_4, mul_dec, &add_4, error);
    } else {
      if (!error) error = pow_ten_by_x(&mul_dec, -diff);
      if (!error) error = mul(add_4, mul_dec, &add_4);
    }
  } else {
    if (!error) error = divcore_subfunction(add_4, mul_dec, &add_4, error);
  }

  if (!error) error = add(add_1, add_2, &res);
  if (!error) error = add(res, add_3, &res);
  if (!error) error = add(res, add_4, &res);
  int result_scale = scale_1 + scale_2 - x;
  if ((result_scale > 28) &&
      (result_scale >= 0)) {  //  если итоговая степень превышает 28
    int diff = result_scale - 28;
    error = div_normalize(diff, &res);  //  сокращаем результат до степени 28
    set_scale(&res, 28);
  } else if (result_scale >= 0) {
    set_scale(&res, result_scale);
  } else if (result_scale < 0) {
    if (!error) error = pow_ten_by_x(&mul_dec, -result_scale);
    if (!error) error = mul(res, mul_dec, &res);
  }
  if (((sign_val_1 + sign_val_2) == 1) && !error) res = set_bit(res, 127);
  if (!error) *result = res;
  return error;
}

// вспомогательная функция round с банковским округлением
int round_subfunction(decimal value, decimal *result, int sign_value) {
  int error = 0;
  decimal five = decimal_init();
  decimal temp_div = decimal_init();
  decimal temp_mul = decimal_init();
  decimal mod = decimal_init();  //  остаток от деления на 10
  decimal one = decimal_init();
  decimal ten = decimal_init();
  from_int_to_decimal(10, &ten);
  from_int_to_decimal(5, &five);
  from_int_to_decimal(1, &one);
  if (!error) error = divcore_subfunction(value, ten, &temp_div, error);
  if (!error) error = mul(temp_div, ten, &temp_mul);
  if (!error) subcore_positive(value, temp_mul, &mod);
  if (!error && !is_less(mod, five)) {
    if (is_equal(mod, five)) {  //  если остаток равен 5
      if (get_bit(temp_div,
                      0)) {  //  если остаток нечетный, увеличиваем на 1
        error =
            addcore_subfunction(temp_div, one, result, error, sign_value, 0);
      } else {  //  если остаток четный, не увеличиваем
        *result = temp_div;
      }
    } else if (is_greater(
                   mod, five)) {  //  если остаток больше 5, увеличиваем на 1
      error = addcore_subfunction(temp_div, one, result, error, sign_value, 0);
    }
  } else {  //  если остаток меньше 5, не увеличиваем
    *result = temp_div;
  }
  if (sign_value) *result = set_bit(*result, 127);
  return error;
}
