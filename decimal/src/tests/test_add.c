#include "decimal_test.h"

START_TEST(add_test_1) {
  // printf("add_test_1 = \n");  //  test
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  decimal a, b;
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  add(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  decimal a, b;
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  add(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  decimal a, b;
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  add(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  decimal a, b;
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  add(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  // printf("add_test_6 = \n");  //  test
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  decimal a, b;
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  add(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  decimal res_dec = {0};
  int res_int = 0;
  add(src1, src2, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  decimal res_dec = {0};
  int res_int = 0;
  add(src1, src2, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  decimal res_dec = {0};
  int res_int = 0;
  add(src1, src2, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  decimal res_dec = {0};
  int res_int = 0;
  add(src1, src2, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_12) {
  // printf("add_test_12 = \n");  //  test
  decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  from_int_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_13) {
  // printf("add_test_13 = \n");  //  test
  decimal src1, src2;
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  from_int_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_14) {
  // printf("add_test_14 = \n");  //  test
  decimal src1, src2;
  float num1 = -94;
  float num2 = 0.00234;
  float res_origin = num1 + num2;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_15) {
  // printf("add_test_15 = \n");  //  test
  decimal src1, src2;
  float num1 = -940.3;
  float num2 = 0.000234;
  float res_origin = -940.299766;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq_tol(res_float, res_origin, 0.0000001);
}
END_TEST

START_TEST(add_test_16) {
  // printf("add_test_16 = \n");  //  test
  decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 0.000234;
  float res_origin = -0.940066;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_17) {
  // printf("add_test_17 = \n");  //  test
  decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 2.0234;
  float res_origin = num1 + num2;
  from_float_to_decimal(num1, &src1);
  // // printf("src1 = \n");  //  test
  // decimal_print(src1);  //  test
  from_float_to_decimal(num2, &src2);
  // // printf("src2 = \n");  //  test
  // decimal_print(src2);  //  test
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  //           // printf("res_dec = \n");  //  test
  // decimal_print(res_dec);  //  test
  from_decimal_to_float(res_dec, &res_float);
  //   // printf("res_float = %f\n", res_float);  //  test
  // // printf("res_origin = %f\n", res_origin);  //  test
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_18) {
  // printf("add_test_18 = \n");  //  test
  decimal src1, src2;
  float num1 = -0.9403;
  float num2 = -112.0234;
  float res_origin = -112.9637;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_19) {
  // printf("add_test_19 = \n");  //  test
  decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_20) {
  // printf("add_test_20 = \n");  //  test
  decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  from_float_to_decimal(num1, &src1);
  from_float_to_decimal(num2, &src2);
  decimal res_dec = {0};
  float res_float = 0.0;
  add(src1, src2, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_21) {
  // printf("add_test_21 = \n");  //  test
  decimal dec1, dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_ = 0;
  int res = 100099;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  add(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(add_test_22) {
  // printf("add_test_22 = \n");  //  test
  decimal dec1, dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_ = 0;
  int res = -100099;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  add(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(add_test_23) {
  // printf("add_test_23 = \n");  //  test
  decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_ = 0;
  int res = 0;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  add(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(add_test_24) {
  // printf("add_test_24 = \n");  //  test
  decimal dec1, dec2;
  dec1.bits[3] = 0x300000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xF;
  dec1.bits[0] = 0x67E4FEEF;
  dec2.bits[3] = 0x300000;
  dec2.bits[2] = 0;
  dec2.bits[1] = 0xFF;
  dec2.bits[0] = 0x67E4FFFF;
  decimal res;
  res.bits[3] = 0x300000;
  res.bits[2] = 0;
  res.bits[1] = 0x10E;
  res.bits[0] = 0xCFC9FEEE;
  decimal res1;
  add(dec1, dec2, &res1);
  ck_assert_int_eq(res.bits[3], res1.bits[3]);
  ck_assert_int_eq(res.bits[2], res1.bits[2]);
  ck_assert_int_eq(res.bits[1], res1.bits[1]);
  ck_assert_int_eq(res.bits[0], res1.bits[0]);
}
END_TEST

START_TEST(add_test_25) {
  // printf("add_test_25 = \n");  //  test
  decimal dec1, dec2;
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_ = 0;
  int res = 0;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  add(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(add_test_26) {
  // printf("add_test_26 = \n");  //  test
  decimal dec1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, 0}};
  decimal dec2 = {{1, 0, 0, 0}};
  decimal res1;
  int ret_ = add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_);
}
END_TEST

START_TEST(add_test_27) {
  // printf("add_test_27 = \n");  //  test
  float tmp2 = pow(2, 31);
  decimal dec1 = {{U_MAX_INT, U_MAX_INT, U_MAX_INT, tmp2}};
  decimal dec2 = {{1, 0, 0, tmp2}};
  decimal res1;
  int ret_ = add(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_);
}
END_TEST

START_TEST(add_test_28) {
  // printf("add_test_28 = \n");  //  test
  float float_a = -10758.218750;
  float float_b = 6268.843750;

  float float_res = float_a + float_b;

  decimal expected = {0};
  from_float_to_decimal(float_res, &expected);
  //       printf("expected = \n");  //  test
  // decimal_print(expected);  //  test

  decimal dec_a = {0};
  from_float_to_decimal(float_a, &dec_a);
  //       printf("dec_a = \n");  //  test
  // decimal_print(dec_a);  //  test

  decimal dec_b = {0};
  from_float_to_decimal(float_b, &dec_b);
  //       printf("dec_b = \n");  //  test
  // decimal_print(dec_b);  //  test

  decimal result = {0};
  int code = add(dec_a, dec_b, &result);
  //     printf("result = \n");  //  test
  // decimal_print(result);  //  test
  float got_float = 0;
  from_decimal_to_float(result, &got_float);

  ck_assert_int_eq(code, 0);
  ck_assert_float_eq_tol(got_float, float_res, 1e-06);
}

START_TEST(add_test_29) {
  // printf("add_test_29 = \n");  //  test
  decimal src1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal src2 = {0};
  float a = 0.01448;
  from_float_to_decimal(a, &src2);
  decimal res_dec = {0};
  add(src1, src2, &res_dec);
  ck_assert_int_eq(add(src1, src2, &res_dec), 1);
}
END_TEST

START_TEST(add_test_30) {
  // printf("add_test_30 = \n");  //  test
  decimal src1 = {{MAX_UINT, MAX_UINT, MAX_UINT, ~(INT_MAX)}};
  decimal src2 = {0};
  float a = -0.01448;
  from_float_to_decimal(a, &src2);
  decimal res_dec = {0};
  add(src1, src2, &res_dec);
  ck_assert_int_eq(add(src1, src2, &res_dec), 2);
}
END_TEST

START_TEST(add_0) {
  // printf("add_0 = \n");  //  test
  decimal val1 = {{15, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  decimal val1 = {{15, 0, 0, 0}};
  decimal val2 = {{15, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal val2 = {{1, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(1, add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  decimal val1 = {
      {MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  decimal val2 = {{2, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(2, add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  // printf("add_6 = \n");  //  test
  decimal val1 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  decimal val1 = {{2, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {{8, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  decimal val1 = {0};
  decimal val2 = {0};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  decimal val1 = {{8, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {0};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  decimal val1 = {
      {MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  decimal val2 = {{4, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  // printf("add_12 = \n");  //  test
  decimal val1 = {
      {MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  decimal val2 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(2, add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  decimal val1 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal val2 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  decimal val1 = {{4, 0, 0, 0}};
  decimal val2 = {
      {MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  decimal val1 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  // printf("add_16 = \n");  //  test
  decimal val1 = {{4, 0, 0, ~(MAX_UINT / 2)}};
  decimal val2 = {
      {MAX_UINT, MAX_UINT, MAX_UINT, ~(MAX_UINT / 2)}};
  decimal res = {0};
  ck_assert_int_eq(2, add(val1, val2, &res));
}
END_TEST

START_TEST(test_decimal_add_0) {
  // printf("test_decimal_add_0 = \n");  //  test
  decimal c = {{5, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{10, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_1) {
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{100, 0, 0, 0}};
  decimal etalon = {{100, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ;
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, FALSE);
}
END_TEST

START_TEST(test_decimal_add_2) {
  decimal c = {{2147483647, 0, 0, 0}};
  decimal d = {{2147483647, 0, 0, 0}};
  decimal etalon = {{4294967294, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal* p_result = &result;

  int add = add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  ;
  int equal = is_equal(result, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_3) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal* p_result = &result;

  int add = add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  ;
  int equal = is_equal(result, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_4) {
  decimal c = {{1000, 0, 0, ~(INT_MAX)}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};
  decimal result = {{0, 0, 0, 0}};
  decimal* p_result = &result;

  int add = add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  ;
  int equal = is_equal(result, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_5) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
  decimal result = {{0, 0, 0, 0}};
  decimal* p_result = &result;

  int add = add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  ;
  int equal = is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_6) {
  decimal c = {{0, 0, 0, 0}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_7) {
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{2, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_8) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_8_1) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{4294967294, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_9) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_10) {
  // printf("test_decimal_add_10 = \n");  //  test
  decimal c = {{UINT32_MAX, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 1, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_11) {
  decimal c = {{0, MAX_UINT - 1, 0, 0}};
  decimal d = {{0, 1, 0, 0}};
  decimal etalon = {{0, MAX_UINT, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_12) {
  decimal c = {{0, 0, MAX_UINT - 1, 0}};
  decimal d = {{0, 0, 1, 0}};
  decimal etalon = {{0, 0, MAX_UINT, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_13) {
  decimal c = {{0, 0, 0, ~(INT_MAX)}};
  decimal d = {{0, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_14) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_15) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_16) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_17) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_18) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_19) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_20) {
  // printf("test_decimal_add_20 = \n");  //  test
  decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_21) {
  decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_25) {
  decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_26) {
  decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_27) {
  decimal c = {{MAX_UINT, MAX_UINT, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0, 0, 1, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_28) {
  decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_29) {
  decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  decimal d = {
      {0b01001000000110110001111110011000, 0b11111011111111011000100101101101,
       0b00000000000001000110110101110111, 0b10000000000110000000000000000000}};
  decimal etalon = {
      {0b10110110001010011011010111011010, 0b11111001111010100000110001111111,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_30) {
  // printf("test_decimal_add_30 = \n");  //  test
  decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  decimal* p_res = &result;
  int add = add(src1, src2, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = is_equal(result, origin);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_0) {
  // printf("test_decimal_add_simple_0 = \n");  //  test
  decimal c = {{0, 0, 0, 0}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_1) {
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{2, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_2) {
  decimal c = {{1000, 0, 0, 0}};
  decimal d = {{1000, 0, 0, 0}};
  decimal etalon = {{2000, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_3) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{4294967294, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_4) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{INT_MAX, 0, 0, 0}};
  decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_5) {
  decimal c = {{MAX_UINT, 0, 0, 0}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 1, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_6) {
  decimal c = {{0, MAX_UINT - 1, 0, 0}};
  decimal d = {{0, 1, 0, 0}};
  decimal etalon = {{0, MAX_UINT, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_7) {
  decimal c = {{0, 0, MAX_UINT - 1, 0}};
  decimal d = {{0, 0, 1, 0}};
  decimal etalon = {{0, 0, MAX_UINT, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_8) {
  decimal c = {{0, 0, 0, ~(INT_MAX)}};
  decimal d = {{0, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_9) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{0, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_10) {
  // printf("test_decimal_add_simple_10 = \n");  //  test
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_11) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{0, 0, 0, 0}};
  decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_12) {
  decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_13) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_14) {
  decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  decimal d = {{1, 0, 0, 0}};
  decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_20) {
  // printf("test_decimal_add_simple_20 = \n");  //  test
  decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_21) {
  decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_22) {
  decimal c = {{MAX_UINT, MAX_UINT, 0, 0}};
  decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  decimal etalon = {{0, 0, 1, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;

  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_add_simple_23) {
  // printf("test_decimal_add_simple_23 = \n");  //  test
  decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(add_max_31) {
  // printf("add_max_31 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  decimal res = {0};
  ck_assert_int_eq(add(src1, src2, &res), 1);
}
END_TEST

START_TEST(add_max_32) {
  // printf("add_max_32 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  decimal res = {0};
  ck_assert_int_eq(add(src1, src2, &res), 1);
}
END_TEST

START_TEST(add_max_33) {
  // printf("add_max_33 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  ck_assert_int_eq(add(src1, src2, &res), 1);
}
END_TEST

START_TEST(add_max_34) {
  // printf("add_max_34 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  decimal res = {0};
  add(src1, src2, &res);
  ck_assert_int_eq(add(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_max_35) {
  // printf("add_max_35 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  decimal res = {0};
  add(src1, src2, &res);
  ck_assert_int_eq(add(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_max_36) {
  // printf("add_max_36 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  decimal res = {0};
  add(src1, src2, &res);
  ck_assert_int_eq(add(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_test_37) {
  // printf("add_max_37 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b00000000000000000000001111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000001111111111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b00000000000000000010101111110101;
  original_res.bits[1] = 0b00000000000000000000000000000000;
  original_res.bits[2] = 0b00000000000000000000000000000000;
  original_res.bits[3] = 0b00000000000000100000000000000000;
  decimal res = {0};
  add(src1, src2, &res);
  ck_assert_int_eq(add(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_max_38) {
  // printf("add_max_34 = \n");  //  test
  decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000110000000000000000;
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  add(src1, src2, &res);
  ck_assert_int_eq(add(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_test_overflow) {
  decimal a = {.bits = {-1, -1, -1, 0}};  // 79228162514264337593543950335
  decimal b = {.bits = {-1, -1, -1, 0}};  // 79228162514264337593543950335
  decimal res_bits = {.bits = {0, 0, 0, 0}};
  int res = add(a, b, &res_bits);
  ck_assert_uint_eq(res, 1);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

Suite* test_add(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("add");
  tc = tcase_create("case_add");

  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_12);
  tcase_add_test(tc, add_test_13);
  tcase_add_test(tc, add_test_14);  //  infinite loop
  tcase_add_test(tc, add_test_15);
  tcase_add_test(tc, add_test_16);
  tcase_add_test(tc, add_test_17);  //  infinite loop
  tcase_add_test(tc, add_test_18);
  tcase_add_test(tc, add_test_19);
  tcase_add_test(tc, add_test_20);
  tcase_add_test(tc, test_decimal_add_0);
  tcase_add_test(tc, test_decimal_add_1);
  tcase_add_test(tc, test_decimal_add_2);
  tcase_add_test(tc, test_decimal_add_3);
  tcase_add_test(tc, test_decimal_add_4);
  tcase_add_test(tc, test_decimal_add_5);
  tcase_add_test(tc, test_decimal_add_6);
  tcase_add_test(tc, test_decimal_add_7);
  tcase_add_test(tc, test_decimal_add_8);
  tcase_add_test(tc, test_decimal_add_8_1);
  tcase_add_test(tc, test_decimal_add_9);
  tcase_add_test(tc, test_decimal_add_10);
  tcase_add_test(tc, test_decimal_add_11);
  tcase_add_test(tc, test_decimal_add_12);
  tcase_add_test(tc, test_decimal_add_13);
  tcase_add_test(tc, test_decimal_add_14);
  tcase_add_test(tc, test_decimal_add_15);
  tcase_add_test(tc, test_decimal_add_16);
  tcase_add_test(tc, test_decimal_add_17);
  tcase_add_test(tc, test_decimal_add_18);
  tcase_add_test(tc, test_decimal_add_19);
  tcase_add_test(tc, test_decimal_add_20);
  tcase_add_test(tc, test_decimal_add_21);
  tcase_add_test(tc, test_decimal_add_25);
  tcase_add_test(tc, test_decimal_add_26);
  tcase_add_test(tc, test_decimal_add_27);
  tcase_add_test(tc, test_decimal_add_28);
  tcase_add_test(tc, test_decimal_add_29);
  tcase_add_test(tc, test_decimal_add_30);
  tcase_add_test(tc, add_0);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, test_decimal_add_simple_0);
  tcase_add_test(tc, test_decimal_add_simple_1);
  tcase_add_test(tc, test_decimal_add_simple_2);
  tcase_add_test(tc, test_decimal_add_simple_3);
  tcase_add_test(tc, test_decimal_add_simple_4);
  tcase_add_test(tc, test_decimal_add_simple_5);
  tcase_add_test(tc, test_decimal_add_simple_6);
  tcase_add_test(tc, test_decimal_add_simple_7);
  tcase_add_test(tc, test_decimal_add_simple_8);
  tcase_add_test(tc, test_decimal_add_simple_9);
  tcase_add_test(tc, test_decimal_add_simple_10);
  tcase_add_test(tc, test_decimal_add_simple_11);
  tcase_add_test(tc, test_decimal_add_simple_12);
  tcase_add_test(tc, test_decimal_add_simple_13);
  tcase_add_test(tc, test_decimal_add_simple_14);
  tcase_add_test(tc, test_decimal_add_simple_20);
  tcase_add_test(tc, test_decimal_add_simple_21);
  tcase_add_test(tc, test_decimal_add_simple_22);
  tcase_add_test(tc, test_decimal_add_simple_23);
  tcase_add_test(tc, add_test_21);
  tcase_add_test(tc, add_test_22);
  tcase_add_test(tc, add_test_23);
  tcase_add_test(tc, add_test_24);
  tcase_add_test(tc, add_test_25);
  tcase_add_test(tc, add_test_26);
  tcase_add_test(tc, add_test_27);
  tcase_add_test(tc, add_test_28);
  tcase_add_test(tc, add_test_29);  //  infinite loop
  tcase_add_test(tc, add_test_30);
  tcase_add_test(tc, add_max_31);  //  нужно деление со степенями
  tcase_add_test(tc, add_max_32);  //  infinite loop
  tcase_add_test(tc, add_max_33);
  tcase_add_test(tc, add_max_34);  //  infinite loop
  tcase_add_test(tc, add_max_35);  //  infinite loop
  tcase_add_test(tc, add_max_36);
  tcase_add_test(tc, add_test_37);
  tcase_add_test(tc, add_max_38);
  tcase_add_test(tc, add_test_overflow);
  suite_add_tcase(s, tc);
  return s;
}