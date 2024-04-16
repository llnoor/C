#include "decimal_test.h"

START_TEST(div_test_1) {
  int num1 = 100;
  int num2 = 50;
  int res_origin = 2;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  div(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_2) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -16384;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  div(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_3) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  div(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_4) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  div(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_1) {
  decimal dec1 = {{100, 0, 0, 0}};
  decimal dec2 = {{99999, 0, 0, 0}};

  float res_ = 0;
  float res = 100.0 / 99999.0;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_2) {
  decimal dec1;
  decimal dec2;
  int tmp1 = 100;
  float tmp2 = 999.99;
  float res_ = 0.0;
  float res = 0.100001;
  from_int_to_decimal(tmp1, &dec1);
  from_float_to_decimal(tmp2, &dec2);
  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_3) {
  decimal dec1 = {{1000, 0, 0, 0}};  // 100.0
  set_scale(&dec1, 1);
  decimal dec2 = {{5, 0, 0, 0}};  // 0.5
  set_scale(&dec2, 1);

  float res_ = 0.0;
  float res = 200;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq(res_, res);
}
END_TEST

START_TEST(div_4) {
  decimal dec1;
  decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  float res_ = 0;
  float res = 0.00100001;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_5) {
  decimal dec1 = {{1005, 0, 0, 0}};  // -100.5
  set_scale(&dec1, 1);
  set_bit(dec1, 127);
  decimal dec2 = {{999995, 0, 0, 0}};  // -99999.5
  set_scale(&dec2, 1);
  set_bit(dec2, 127);

  float res_ = 0;
  float res = 0.001005005;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_6) {
  decimal dec1 = {{100, 0, 0, 0}};  // 100
  set_scale(&dec1, 1);
  set_bit(dec1, 127);
  decimal dec2 = {{6, 0, 0, 0}};  // 6
  set_scale(&dec2, 1);
  set_bit(dec2, 127);

  float res_ = 0;
  float res = 100.0 / 6.0;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_float(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_7) {
  decimal dec1 = {{10.0e3, 0, 0, 0}};
  decimal dec2 = {{2.00e2, 0, 0, 0}};

  int res_ = 0;
  int res = 50;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_8) {
  decimal dec1 = {{2, 0, 0, 0b00000000000000010000000000000000}};  // 0.2
  decimal dec2 = {{1, 0, 0, 0b00000000000000110000000000000000}};  // 0.001

  int res_ = 0;
  int res = 200;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_9) {
  decimal dec1 = {
      {2000000, 0, 0, 0b00000000000000010000000000000000}};  // 200 000
  decimal dec2 = {{2, 0, 0, 0b00000000000001000000000000000000}};  // 0.001

  int res_ = 0;
  int res = 1000000000;

  decimal res1;
  div(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_float_eq_tol(res_, res, 6);
}
END_TEST

START_TEST(div_10) {
  decimal a = {{1, 0, 0, -2147483648}};  // -1
  decimal b = {
      {-1, -1, -1, -2147483648}};  // -79228162514264337593543950335
  decimal res_bits = {{0, 0, 0, 0}};

  int res = div(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(div_11) {
  decimal a = {{1, 0, 0, -2147483648}};  // -1
  decimal b = {{-2147483648, -2147483648, 628902378,
                    -2147483648}};  // -11601201223536716331618402304
  decimal res_bits = {{0, 0, 0, 0}};

  int res = div(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1);  //  1*10^28
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)1835008);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(div_12) {
  decimal a = {{-1, -1, -1, 0}};   // 79228162514264337593543950335
  decimal b = {{6, 0, 0, 65536}};  // 0.6
  decimal res_bits = {{0, 0, 0, 0}};

  int res = div(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(div_13) {
  decimal a = {{1, 0, 0, 0}};  // 1
  decimal b = {{-2147483648, -2147483648, 628902378,
                    -2147483648}};  // -11601201223536716331618402304
  decimal res_bits = {{0, 0, 0, 0}};

  int res = div(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1);  //  -1*10^28
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)2149318656);
}
END_TEST

START_TEST(div_null) {
  decimal dec1 = {{1110, 0, 0, 0}};
  decimal dec2 = {{0, 0, 0, 0}};

  decimal res1;
  int res = div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

Suite *test_div(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("div");
  tc = tcase_create("case_div");

  tcase_add_test(tc, div_test_1);
  tcase_add_test(tc, div_test_2);
  tcase_add_test(tc, div_test_3);
  tcase_add_test(tc, div_test_4);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_null);
  suite_add_tcase(s, tc);
  return s;
}

//  * - закомментировано