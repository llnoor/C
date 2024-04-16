#ifndef DECIMAL_H_
#define DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // int n = 1; // это число длиной 4 байта или 32 бита. По сути - массив из 32
  // битов.
  unsigned int bits[4];  // четырехэлементный массив 32-разрядных целых чисел
} decimal;

#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

int add(decimal value_1, decimal value_2, decimal *result);
int sub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);
int div(decimal value_1, decimal value_2, decimal *result);

int is_less(decimal value_1, decimal value_2);
int is_less_or_equal(decimal value_1, decimal value_2);
int is_greater(decimal value_1, decimal value_2);
int is_greater_or_equal(decimal value_1, decimal value_2);
int is_equal(decimal value_1, decimal value_2);
int is_not_equal(decimal value_1, decimal value_2);

int from_int_to_decimal(int src, decimal *dst);
int from_float_to_decimal(float src, decimal *dst);
int from_decimal_to_int(decimal src, int *dst);
int from_decimal_to_float(decimal src, float *dst);

int floor(decimal value, decimal *result);
int round(decimal value, decimal *result);
int truncate(decimal value, decimal *result);
int negate(decimal value, decimal *result);

int get_bit(decimal decimal_num, int position);
decimal set_bit(decimal decimal_num, int position);
decimal set_zero(decimal decimal_num, int position);
int get_bit_from_int(int num, int position);
int set_bit_in_int(int num, int position);
int set_zero_in_int(int num, int position);
decimal decimal_init();
decimal max_decimal_init();
int decimal_print(decimal src);
int decimal_clear(decimal *dst);
void step_left(decimal *decimal_num, int n);
void step_right(decimal *decimal_num, int n);
void bitwise_and_decimal(decimal *res, decimal value_1,
                         decimal value_2);
void bitwise_xor_decimal(decimal *res, decimal value_1,
                         decimal value_2);
void bitwise_or_decimal(decimal *res, decimal value_1,
                        decimal value_2);
void bitwise_inversion_decimal(decimal *res, decimal value);
int dec_is_not_null(decimal decimal_num);
void set_result_sign(decimal value_1, decimal value_2,
                     decimal *result);
int addcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result, int error, int sign_value_1,
                        int sign_value_2);
int get_scale(decimal src);
void set_scale(decimal *dec, int scale);
int mul_normalize(int dif, decimal *value);
int div_normalize(int dif, decimal *value);
int do_normalize(int lesser_scale, decimal *lesser_value, int larger_scale,
                 decimal *larger_value);
int normalize(decimal *value_1, decimal *value_2);
int is_less_mantiss(decimal value_1, decimal value_2);
int is_greater_mantiss(decimal value_1, decimal value_2);
int subcore_positive(decimal value_1, decimal value_2,
                     decimal *result);
int divcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result, int error);
int minus_zero_result(decimal *result);
int module(decimal value_1, decimal value_2, decimal res,
           decimal *mod);
int is_equal_mantiss(decimal value_1, decimal value_2);
int div_by_10(decimal value_1, decimal *result);
int significant_mantiss(decimal value);
int truncate_div_by_10(decimal value, int scale, decimal *result);
int pow_ten_by_x(decimal *value, int x);
int mantissa_overflow_check_for_add(decimal value_1, decimal value_2);
int mul_subfunction(decimal value_1, decimal value_2,
                    decimal *result);
int mulcore_subfunction(decimal value_1, decimal value_2,
                        decimal *result);
int mul_fractional(decimal value_1, decimal value_2,
                   decimal *result);
int mul_fractional_1(decimal value_1, decimal value_2,
                     decimal *result);
int round_subfunction(decimal value, decimal *result, int sign_value);
int mul_big(decimal value_1, decimal value_2, int significant_sum,
            decimal *result);
void normalize_for_div(decimal *value_1, decimal value_2, int *error);
int mod_div(decimal value_1, decimal value_2, decimal *res,
            int *res_scale);

#endif  // DECIMAL_H_
