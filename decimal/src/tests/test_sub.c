#include "decimal_test.h"

START_TEST(sub_test_1) {
  int num1 = -10;
  int num2 = -10;
  int dif_int = 0;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_2) {
  int num1 = 10;
  int num2 = 20;
  int dif_int = -10;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_3) {
  int num1 = -10;
  int num2 = 20;
  int dif_int = -30;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int dif_int = 9201;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_5) {
  int num1 = 100;
  int num2 = -200;
  int dif_int = 300;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_6) {
  int num1 = 100;
  int num2 = -10;
  int dif_int = 110;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_7) {
  int num1 = -900;
  int num2 = -100;
  int dif_int = -800;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_8) {
  int num1 = 900;
  int num2 = 100;
  int dif_int = 800;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_9) {
  int num1 = 900;
  int num2 = -100;
  int dif_int = 1000;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_10) {
  int num1 = -900;
  int num2 = 100;
  int dif_int = -1000;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  sub(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_11) {
  int num1 = 123;
  float num2 = 12.5;
  float origin_float = 110.5;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, origin_float);
}
END_TEST

START_TEST(sub_test_12) {
  int num1 = -123;
  float num2 = 12.5;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_13) {
  float num1 = 12.9;
  float num2 = 12.5;
  float original_res = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float our_res = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &our_res);
  ck_assert_float_eq_tol(our_res, original_res, 7);
}
END_TEST

START_TEST(sub_test_14) {
  int num1 = 9403;
  float num2 = 202.098;
  float dif_float = 9200.902;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_15) {
  int num1 = -9403;
  float num2 = 202.098;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_16) {
  float num1 = 9403.0;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_17) {
  float num1 = 9403.0e2;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_18) {
  float num1 = -9403.0e2;
  int num2 = -202;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_19) {
  float num1 = -94;
  float num2 = -202;
  float dif_float = num1 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_20) {
  float num1 = -1.0 / 0.0;
  int num2 = 202;
  double dif_float = 0 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_21) {
  float num1 = 1.0 / 0.0;
  int num2 = 20;
  double dif_float = 0 - num2;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0.0;
  sub(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_int_22) {
  decimal dec1;
  decimal dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_ = 0;
  int res = -99899;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  sub(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(sub_int_23) {
  decimal dec1;
  decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_ = 0;
  int res = 99899;
  decimal res1;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  sub(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(sub_int_24) {
  decimal dec1;
  decimal dec2;
  int tmp1 = -2147483647;
  int tmp2 = -2147483647;
  int res_ = 0;
  int res = 0;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  decimal res1;
  sub(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(sub_int_25) {
  decimal dec1;
  decimal dec2;
  int tmp1 = -214748347;
  int tmp2 = 217483647;
  int res_ = 0;
  int res = -214748347 - 217483647;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  decimal res1;
  sub(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(sub_int_26) {
  decimal dec1;
  decimal dec2;
  int tmp1 = 214748347;
  int tmp2 = -217483647;
  int res_ = 0;
  int res = 214748347 - -217483647;
  from_int_to_decimal(tmp1, &dec1);
  from_int_to_decimal(tmp2, &dec2);
  decimal res1;
  sub(dec1, dec2, &res1);
  from_decimal_to_int(res1, &res_);
  ck_assert_int_eq(res_, res);
}
END_TEST

START_TEST(sub_inf_27) {
  float tmp = pow(2, 31);
  decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
  decimal dec2 = {{1, 0, 0, tmp}};
  decimal res1;
  int ret_ = sub(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_);
}
END_TEST

START_TEST(sub_neg_inf_28) {
  float tmp = pow(2, 31);
  decimal dec1 = {{4294967295, 4294967295, 4294967295, tmp}};
  decimal dec2 = {{1, 0, 0, 0}};
  decimal res1;
  int ret_ = sub(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_);
}
END_TEST

START_TEST(sub_test_29) {
  //   // float num1 = 79228162514264337593543950335.0;
  //        79228162514264337593543950335
  // float num2 = 0.6;
  decimal a = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0b00000000000000000000000000000000;
  decimal b = {0};
  b.bits[0] = 0b00000000000000000000000000000110;
  b.bits[1] = 0b00000000000000000000000000000000;
  b.bits[2] = 0b00000000000000000000000000000000;
  b.bits[3] = 0b00000000000000010000000000000000;
  decimal res_dec = {0};
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  int error = sub(a, b, &res_dec);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(original_res.bits[0], res_dec.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res_dec.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res_dec.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res_dec.bits[3]);
}
END_TEST

START_TEST(sub_max_30) {
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
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  sub(src1, src2, &res);
  ck_assert_int_eq(sub(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_max_31) {
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
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  sub(src1, src2, &res);
  ck_assert_int_eq(sub(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_max_32) {
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
  decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  decimal res = {0};
  sub(src1, src2, &res);
  ck_assert_int_eq(sub(src1, src2, &res), 0);
  ck_assert_int_eq(original_res.bits[0], res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_max_33) {
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
  decimal res = {0};
  ck_assert_int_eq(sub(src1, src2, &res), 2);
}
END_TEST

START_TEST(sub_max_34) {
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
  decimal res = {0};
  ck_assert_int_eq(sub(src1, src2, &res), 2);
}
END_TEST

START_TEST(sub_max_35) {
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
  decimal res = {0};
  ck_assert_int_eq(sub(src1, src2, &res), 2);
}
END_TEST

START_TEST(subTest1) {
  // 863
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest2) {
  // 889
  decimal src1, src2, origin;
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest3) {
  // 915
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest4) {
  // 941
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest5) {
  // 967
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest6) {
  // 993
  decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest7) {
  // 1019
  decimal src1, src2, origin;
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000010000100000010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest8) {
  // 1045
  decimal src1, src2, origin;
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000101110100011001110100010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest9) {
  // 1071
  decimal src1, src2, origin;
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 95;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 5;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest10) {
  // 1097
  decimal src1, src2, origin;
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest11) {
  // 1123
  decimal src1, src2, origin;
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11111101101100110001110000110000;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest12) {
  // 1149
  decimal src1, src2, origin;
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b01001100110100101000000111000010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest13) {
  // 1175
  decimal src1, src2, origin;
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b10001001111001111111111111111110;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest14) {
  // 1201
  decimal src1, src2, origin;
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest15) {
  // 1227
  decimal src1, src2, origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11000000100010111000101000100010;
  origin.bits[1] = 0b11111111111111111111111111111101;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest16) {
  // 1253
  decimal src1, src2, origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b10010100100110011101101011101101;
  origin.bits[1] = 0b11000101100100110110100101100010;
  origin.bits[2] = 0b10110000001111101111000110111100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

// START_TEST(subTest17) {
//   // 1279
//   decimal src1, src2, origin;
//   // src1 = -545454512454545.35265454545645;
//   // src2 = -5.352654545456454545645464;

//   // -545454512454545.35265454545645 exp 14
//   src1.bits[0] = 0b10000010111000100101101011101101;
//   src1.bits[1] = 0b11111001111010000010010110101101;
//   src1.bits[2] = 0b10110000001111101111000010010100;
//   src1.bits[3] = 0b10000000000011100000000000000000;

//   // -5.352654545456454545645464 exp 24
//   src2.bits[0] = 0b01001000000110110001111110011000;
//   src2.bits[1] = 0b11111011111111011000100101101101;
//   src2.bits[2] = 0b00000000000001000110110101110111;
//   src2.bits[3] = 0b10000000000110000000000000000000;
//   decimal result = {{0, 0, 0, 0}};
//   // -54545451245453999999999999999 exp 14  должно быть
//   -54545451245454000000000000000? sub(src1, src2, &result);

//   // -54545451245453999999999999999 exp 14
//   origin.bits[0] = 0b01001111100110101111111111111111;
//   origin.bits[1] = 0b11111001111001100011111011011011;
//   origin.bits[2] = 0b10110000001111101111000010010100;
//   origin.bits[3] = 0b10000000000011100000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

START_TEST(subTest18) {
  // 1305
  decimal src1, src2, origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

// START_TEST(subTest19) {
//   // 1331
//   decimal src1, src2, origin;
//   // src1 = 12345677.987654345678987654346;
//   // src2 = 87654323456.9876545678987653;
//   src1.bits[0] = 0b10010001000010101111010011001010;
//   src1.bits[1] = 0b11000000010001011101010111110010;
//   src1.bits[2] = 0b00100111111001000001101100000000;
//   src1.bits[3] = 0b00000000000101010000000000000000;

//   src2.bits[0] = 0b00010001110011011101000110000101;
//   src2.bits[1] = 0b11110101101111000110111111000000;
//   src2.bits[2] = 0b00000010110101010000111100111111;
//   src2.bits[3] = 0b00000000000100000000000000000000;
//   decimal result = {{0, 0, 0, 0}};
//   sub(src1, src2, &result);
//   // 87641977779.00000022221977764 exp 17
//   origin.bits[0] = 0b10010010000001100111100010100100;
//   origin.bits[1] = 0b10001011011010100100100011011111;
//   origin.bits[2] = 0b00011100010100011001001100010001;
//   origin.bits[3] = 0b10000000000100010000000000000000;
//   // 87641977779.00000022221977765 exp 17
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

START_TEST(subTest20) {
  // 1357
  decimal src1, src2, origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest21) {
  // 1383
  decimal src1, src2, origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

// START_TEST(subTest22) {
//   // 1409
//   decimal src1, src2, origin;
//   // src1 = -12345677.987654345678987654346;
//   // src2 = -87654323456.9876545678987653;

//   src1.bits[0] = 0b10010001000010101111010011001010;
//   src1.bits[1] = 0b11000000010001011101010111110010;
//   src1.bits[2] = 0b00100111111001000001101100000000;
//   src1.bits[3] = 0b10000000000101010000000000000000;

//   src2.bits[0] = 0b00010001110011011101000110000101;
//   src2.bits[1] = 0b11110101101111000110111111000000;
//   src2.bits[2] = 0b00000010110101010000111100111111;
//   src2.bits[3] = 0b10000000000100000000000000000000;
//   decimal result = {{0, 0, 0, 0}};
//   sub(src1, src2, &result);

//   origin.bits[0] = 0b10010010000001100111100010100100;
//   origin.bits[1] = 0b10001011011010100100100011011111;
//   origin.bits[2] = 0b00011100010100011001001100010001;
//   origin.bits[3] = 0b00000000000100010000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

START_TEST(subTest23) {
  // 1435
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest24) {
  // 1461
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest25) {
  // 1487
  decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest26) {
  // 1513
  decimal src1, src2, origin;
  // src1 = 792281625142643375935439503;
  // src2 = -1;

  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00101000111101011100001010010000;
  origin.bits[1] = 0b11110101110000101000111101011100;
  origin.bits[2] = 0b00000010100011110101110000101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest27) {
  // 1539
  decimal src1, src2, origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest28) {
  // 1565
  decimal src1, src2, origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11101000101010001011011101111000;
  origin.bits[1] = 0b00000000000111110100000111110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest29) {
  // 1591
  decimal src1, src2, origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest30) {
  // 1617
  decimal src1, src2, origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b11010010100100100111101010001100;
  origin.bits[1] = 0b10011110100111100111000100000100;
  origin.bits[2] = 0b00011111101010011000000100111000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest31) {
  // 1643
  decimal src1, src2, origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest32) {
  // 1669
  decimal src1, src2, origin;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b10111000010101011100100001001001;
  origin.bits[1] = 0b01100110100011011000001100010111;
  origin.bits[2] = 0b00011100011001100111011011000001;
  origin.bits[3] = 0b10000000000010000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(subTest33) {
  // 1695
  decimal src1, src2, origin;
  // src1 = -7922816251426433759354395033;
  // src2 = 1;

  src1.bits[0] = 0b10011001100110011001100110011001;
  src1.bits[1] = 0b10011001100110011001100110011001;
  src1.bits[2] = 0b00011001100110011001100110011001;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  sub(src1, src2, &result);

  origin.bits[0] = 0b10011001100110011001100110011010;
  origin.bits[1] = 0b10011001100110011001100110011001;
  origin.bits[2] = 0b00011001100110011001100110011001;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_decimal_sub_simple_0) {
  decimal c = {{10, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{5, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_sub_simple_1) {
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{5, 0, 0, 0}};

  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, FALSE);
}
END_TEST

START_TEST(test_decimal_sub_simple_2) {
  decimal c = {{INT_MAX, 0, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{2147483642, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_sub_simple_3) {
  decimal c = {{INT_MAX, INT_MAX, 0, 0}};
  decimal d = {{5, 0, 0, 0}};
  decimal etalon = {{INT_MAX - 5, INT_MAX, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}

START_TEST(test_decimal_sub_simple_7) {
  decimal c = {{1, 0, 0, 0}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{2, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_sub_simple_8) {
  decimal c = {{1, 0, 0, ~(INT_MAX)}};
  decimal d = {{1, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{0, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_sub_simple_10) {
  decimal c = {{100, 0, 0, 0}};
  decimal d = {{100, 0, 0, ~(INT_MAX)}};
  decimal etalon = {{200, 0, 0, 0}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
  int equal = is_equal(res, etalon);
  ck_assert_int_eq(equal, TRUE);
}
END_TEST

START_TEST(test_decimal_sub_simple_11) {
  decimal c = {{100, 0, 0, ~(INT_MAX)}};
  decimal d = {{100, 0, 0, ~(INT_MAX)}};
  decimal res = {{0, 0, 0, 0}};
  decimal* p_res = &res;
  int add = sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
}
END_TEST

Suite* test_sub(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("sub");
  tc = tcase_create("case_sub");

  tcase_add_test(tc, sub_test_1);
  tcase_add_test(tc, sub_test_2);
  tcase_add_test(tc, sub_test_3);
  tcase_add_test(tc, sub_test_4);
  tcase_add_test(tc, sub_test_5);
  tcase_add_test(tc, sub_test_6);
  tcase_add_test(tc, sub_test_7);
  tcase_add_test(tc, sub_test_8);
  tcase_add_test(tc, sub_test_9);
  tcase_add_test(tc, sub_test_10);
  tcase_add_test(tc, subTest1);
  tcase_add_test(tc, subTest2);
  tcase_add_test(tc, subTest3);
  tcase_add_test(tc, subTest4);
  tcase_add_test(tc, subTest5);
  tcase_add_test(tc, subTest6);
  tcase_add_test(tc, subTest7);
  tcase_add_test(tc, subTest8);
  tcase_add_test(tc, subTest9);
  tcase_add_test(tc, subTest10);
  tcase_add_test(tc, subTest11);
  tcase_add_test(tc, subTest12);
  tcase_add_test(tc, subTest13);
  tcase_add_test(tc, subTest14);
  tcase_add_test(tc, subTest15);
  tcase_add_test(tc, subTest16);
  // tcase_add_test(tc, subTest17);
  tcase_add_test(tc, subTest18);
  // tcase_add_test(tc, subTest19);
  tcase_add_test(tc, subTest20);
  tcase_add_test(tc, subTest21);
  // tcase_add_test(tc, subTest22);
  tcase_add_test(tc, subTest23);
  tcase_add_test(tc, subTest24);
  tcase_add_test(tc, subTest25);
  tcase_add_test(tc, subTest26);
  tcase_add_test(tc, subTest27);
  tcase_add_test(tc, subTest28);
  tcase_add_test(tc, subTest29);
  tcase_add_test(tc, subTest30);
  tcase_add_test(tc, subTest31);
  tcase_add_test(tc, subTest32);
  tcase_add_test(tc, subTest33);
  tcase_add_test(tc, test_decimal_sub_simple_0);
  tcase_add_test(tc, test_decimal_sub_simple_1);
  tcase_add_test(tc, test_decimal_sub_simple_2);
  tcase_add_test(tc, test_decimal_sub_simple_3);
  tcase_add_test(tc, test_decimal_sub_simple_7);
  tcase_add_test(tc, test_decimal_sub_simple_8);
  tcase_add_test(tc, test_decimal_sub_simple_10);
  tcase_add_test(tc, test_decimal_sub_simple_11);
  tcase_add_test(tc, sub_test_11);
  tcase_add_test(tc, sub_test_12);
  tcase_add_test(tc, sub_test_13);
  tcase_add_test(tc, sub_test_14);
  tcase_add_test(tc, sub_test_15);
  tcase_add_test(tc, sub_test_16);
  tcase_add_test(tc, sub_test_17);
  tcase_add_test(tc, sub_test_18);  //  infinite loop
  tcase_add_test(tc, sub_test_19);  //  infinite loop
  tcase_add_test(tc, sub_test_20);
  tcase_add_test(tc, sub_test_21);  //  infinite loop
  tcase_add_test(tc, sub_int_22);
  tcase_add_test(tc, sub_int_23);
  tcase_add_test(tc, sub_int_24);
  tcase_add_test(tc, sub_int_25);
  tcase_add_test(tc, sub_int_26);
  tcase_add_test(tc, sub_inf_27);
  tcase_add_test(tc, sub_neg_inf_28);
  tcase_add_test(tc, sub_test_29);
  tcase_add_test(tc, sub_max_30);
  tcase_add_test(tc, sub_max_31);
  tcase_add_test(tc, sub_max_32);
  tcase_add_test(tc, sub_max_33);
  tcase_add_test(tc, sub_max_34);
  tcase_add_test(tc, sub_max_35);

  suite_add_tcase(s, tc);
  return s;
}