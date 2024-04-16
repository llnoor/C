#include "decimal_test.h"

START_TEST(from_float_to_decimal_1) {
  decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;
  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  decimal val;
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;
  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST
START_TEST(from_float_to_decimal_3) {
  decimal val;
  float num = -2.1474836E+09;
  // float num = -2.147483E+09;
  from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  decimal val;
  float fl1 = 22.14836E+03;
  float fl2 = -2.1474836E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  decimal val;
  from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  decimal val;
  float fl1 = -333.2222;
  float fl2 = -2.1474836E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  decimal val;
  float a = 1.0 / 0.0;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  decimal val;
  float a = -1.0 / 0.0;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_10) {
  decimal val;
  float a = 1e-30;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_11) {
  decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  from_float_to_decimal(tmp1, &dec);
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_12) {
  decimal dec;
  from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_13) {
  decimal dec;
  from_float_to_decimal(-2.1474836E+09, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_14) {
  decimal dec;
  from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_15) {
  decimal dec;
  from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_16) {
  decimal dec;
  from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_17) {
  decimal dec;
  float a = 1.0 / 0.0;
  int ret = from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(from_float_to_decimal_18) {
  decimal dec;
  float a = -1.0 / 0.0;
  from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, from_float_to_decimal_1);
  tcase_add_test(tc, from_float_to_decimal_2);
  tcase_add_test(tc, from_float_to_decimal_3);
  tcase_add_test(tc, from_float_to_decimal_4);
  tcase_add_test(tc, from_float_to_decimal_5);
  tcase_add_test(tc, from_float_to_decimal_6);
  tcase_add_test(tc, from_float_to_decimal_7);
  tcase_add_test(tc, from_float_to_decimal_8);
  tcase_add_test(tc, from_float_to_decimal_10);
  tcase_add_test(tc, from_float_to_decimal_11);
  tcase_add_test(tc, from_float_to_decimal_12);
  tcase_add_test(tc, from_float_to_decimal_13);
  tcase_add_test(tc, from_float_to_decimal_14);
  tcase_add_test(tc, from_float_to_decimal_15);
  tcase_add_test(tc, from_float_to_decimal_16);
  tcase_add_test(tc, from_float_to_decimal_17);
  tcase_add_test(tc, from_float_to_decimal_18);

  suite_add_tcase(s, tc);
  return s;
}