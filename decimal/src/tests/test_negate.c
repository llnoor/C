#include "decimal_test.h"

START_TEST(negate_1) {
  int a = 15;
  int res_a = 0;
  decimal src;
  decimal res;
  from_int_to_decimal(a, &src);
  negate(src, &res);
  from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(negate_2) {
  float a = 10.12345;
  float res_a = 0;
  decimal src;
  decimal res;
  from_float_to_decimal(a, &src);
  negate(src, &res);
  from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(negate_3) {
  float a = 10.1234e5;
  float res_a = 0;
  decimal src;
  decimal res;
  from_float_to_decimal(a, &src);
  negate(src, &res);
  from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(negate_4) {
  float a = -10.1234e5;
  float res_a = 0;
  decimal src;
  decimal res;
  from_float_to_decimal(a, &src);
  negate(src, &res);
  from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(10.1234e5, res_a);
}
END_TEST

START_TEST(negate_5) {
  int a = -15;
  int res_a = 0;
  decimal src;
  decimal res;
  from_int_to_decimal(a, &src);
  negate(src, &res);
  from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(test_negate_0) {
  decimal b = {{0, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
  int negate = negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(test_negate_1) {
  decimal a = {{1, 0, 0, 0}};
  decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_2) {
  decimal a = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{1, 0, 0, 0}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_3) {
  decimal a = {{100, 0, 0, 0}};
  decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_4) {
  decimal a = {{100, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{100, 0, 0, 0}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_5) {
  decimal a = {{MAX_UINT, 0, 0, 0}};
  decimal etalon = {{MAX_UINT, 0, 0, ~(INT_MAX)}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_6) {
  decimal a = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal etalon = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(test_negate_7) {
  decimal a = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal etalon = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(INT_MAX)}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(test_negate_8) {
  decimal a = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(INT_MAX)}};
  decimal etalon = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal b = {{0, 0, 0, 0}};
  decimal* ptr_b = &b;
  int add = negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_0) {
  decimal val = {{2, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
  decimal val = {{2, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
  decimal val = {{0, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
  decimal val = {0};
  decimal res = {0};
  ck_assert_int_eq(0, negate(val, &res));
}
END_TEST

Suite* test_negate(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("negate");
  tc = tcase_create("case_negate");
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_4);
  tcase_add_test(tc, negate_5);
  tcase_add_test(tc, test_negate_0);
  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  tcase_add_test(tc, test_negate_3);
  tcase_add_test(tc, test_negate_4);
  tcase_add_test(tc, test_negate_5);
  tcase_add_test(tc, test_negate_6);
  tcase_add_test(tc, test_negate_7);
  tcase_add_test(tc, test_negate_8);
  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  suite_add_tcase(s, tc);
  return s;
}