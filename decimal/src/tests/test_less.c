#include "decimal_test.h"

START_TEST(less_1) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_2) {
  float num1 = 1.39;
  float num2 = 1.39;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_4) {
  int num1 = 0;
  int num2 = 0;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_5) {
  int num1 = 3;
  int num2 = 9;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_6) {
  int num1 = -3;
  int num2 = -3;
  decimal dec1, dec2;
  from_int_to_decimal(num1, &dec1);
  from_int_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_7) {
  float num1 = -34534534.232446543232446543;
  float num2 = -3.232323233232323233;
  decimal dec1, dec2;
  from_float_to_decimal(num1, &dec1);
  from_float_to_decimal(num2, &dec2);
  int res = is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_8) {
  decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2
  ck_assert_int_eq(is_less(dec5, dec6), 0);
  ck_assert_int_eq(is_less(dec6, dec5), 1);

  decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less(dec7, dec8), 1);
  ck_assert_int_eq(is_less(dec8, dec7), 0);

  decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(is_less(dec1, dec2), 0);
  ck_assert_int_eq(is_less(dec2, dec1), 1);

  decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(is_less(dec3, dec4), 1);
  ck_assert_int_eq(is_less(dec4, dec3), 0);

  decimal dec9 = {{12345, 0, 0, 0}};
  decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(is_less(dec9, dec10), 0);
  ck_assert_int_eq(is_less(dec10, dec9), 0);

  decimal dec11 = {{0, 0, 0, 0}};
  decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_less(dec11, dec12), 0);
  ck_assert_int_eq(is_less(dec12, dec11), 0);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("is_less");
  tc = tcase_create("case_is_less");
  tcase_add_test(tc, less_1);
  tcase_add_test(tc, less_2);
  tcase_add_test(tc, less_3);
  tcase_add_test(tc, less_4);
  tcase_add_test(tc, less_5);
  tcase_add_test(tc, less_6);
  tcase_add_test(tc, less_7);
  tcase_add_test(tc, less_8);
  suite_add_tcase(s, tc);
  return s;
}