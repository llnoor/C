#ifndef DECIMAL_TEST_H_
#define DECIMAL_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../decimal.h"

#define TRUE 1
#define FALSE 0
#define CONVERTERS_TRUE 0
#define CONVERTERS_FALSE 1
#define U_MAX_INT 4294967295          // 0b11111111111111111111111111111111
#define MAX_INT 2147483647            // 0b01111111111111111111111111111111
#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000
#define MINUS 2147483648              // 0b10000000000000000000000000000000
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F
#define MAX_UINT 4294967295
#define BIT_SIZE 4294967295

Suite *test_add(void);
Suite *test_div(void);
Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_from_decimal_to_float(void);
Suite *test_from_decimal_to_int(void);
Suite *test_from_float_to_decimal(void);
Suite *test_from_int_to_decimal(void);
Suite *test_is_less(void);
Suite *test_is_equal(void);
Suite *test_is_less_or_equal(void);
Suite *test_is_greater(void);
Suite *test_is_greater_or_equal(void);
Suite *test_is_not_equal(void);
Suite *test_round(void);
Suite *test_truncate(void);
Suite *test_negate(void);
Suite *test_floor(void);

#endif  // DECIMAL_TEST_H_