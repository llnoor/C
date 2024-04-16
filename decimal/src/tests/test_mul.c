#include "decimal_test.h"

START_TEST(mul_test_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  decimal a = {0};
  decimal b = {0};
  from_int_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  int res_int = 0;
  mul(a, b, &res_dec);
  from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_int_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0;
  mul(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(mul_test_8) {
  float num1 = 9403.0e2;
  float num2 = 9403.0e2;
  float res_origin = 884164090000;
  decimal a = {0};
  decimal b = {0};
  from_float_to_decimal(num1, &a);
  from_float_to_decimal(num2, &b);
  decimal res_dec = {0};
  float res_float = 0;
  mul(a, b, &res_dec);
  from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(mul_1) {
  decimal dec1 = {{4, 0, 0, 0}};
  decimal dec2 = {{10, 0, 0, 0}};

  decimal d22;
  mul(dec1, dec2, &d22);

  int qqqq = 0;
  from_decimal_to_int(d22, &qqqq);
  ck_assert_int_eq(qqqq, 40);
}
END_TEST

START_TEST(mul_big_1) {
  decimal dst1;
  dst1.bits[0] = 0b01110000000000000000000000000000;
  dst1.bits[1] = 0b10110011000000110001000010100111;
  dst1.bits[2] = 0b11100010001011101010010010010011;
  dst1.bits[3] = 0b00000000000000000000000000000000;
  decimal dst2;
  dst2.bits[0] = 0b00000000000000000000000000000001;
  dst2.bits[1] = 0b10000000000000100000000000000000;
  dst2.bits[2] = 0b00000000000000000000000000000000;
  dst2.bits[3] = 0b00000000000000000000000000000000;

  decimal d22;
  int error = mul(dst1, dst2, &d22);

  // int qqqq = 0;
  // from_decimal_to_int(d22, &qqqq);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(mul_big_2) {
  decimal dst1;
  dst1.bits[0] = 0b01110000000000000000000000000000;
  dst1.bits[1] = 0b10110011000000110001000010100111;
  dst1.bits[2] = 0b11100010001011101010010010010011;
  dst1.bits[3] = 0b00000000000000000000000000000000;
  decimal dst2;
  dst2.bits[0] = 0b00000000000000000000000000000001;
  dst2.bits[1] = 0b10000000000000100000000000000000;
  dst2.bits[2] = 0b00000000000000000000000000000000;
  dst2.bits[3] = 0b10000000000000000000000000000000;

  decimal d22;
  int error = mul(dst1, dst2, &d22);

  // int qqqq = 0;
  // from_decimal_to_int(d22, &qqqq);
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(mul_2) {
  decimal dec1 = {{100, 0, 0, 0}};     // 100
  decimal dec2 = {{999999, 0, 0, 0}};  // 9999.99
  set_scale(&dec2, 2);
  decimal res1;
  mul(dec1, dec2, &res1);
  float g;
  from_decimal_to_float(res1, &g);
  ck_assert_float_eq(g, 999999);
}
END_TEST

START_TEST(mul_3) {
  decimal dec1 = {{100, 0, 0, 0}};  // -100
  dec1 = set_bit(dec1, 127);
  decimal dec2 = {{999999, 0, 0, 0}};  // 9999.99
  set_scale(&dec2, 2);
  decimal res1;
  mul(dec1, dec2, &res1);

  float g;
  from_decimal_to_float(res1, &g);
  ck_assert_float_eq(g, -999999);
}
END_TEST

START_TEST(mul_4) {
  decimal dec1 = {{1002, 0, 0, 0}};  // -100.2
  set_scale(&dec1, 1);
  dec1 = set_bit(dec1, 127);

  decimal dec2 = {{999999, 0, 0, 0}};  // -9999.99
  set_scale(&dec2, 2);
  dec2 = set_bit(dec2, 127);

  decimal res1;
  mul(dec1, dec2, &res1);
  float g;
  from_decimal_to_float(res1, &g);
  ck_assert_float_eq_tol(g, 1001998.998, 1e-06);
}
END_TEST

START_TEST(mul_5) {
  decimal dec1 = {{0, 0, 0, 0}};  // -0.0
  set_scale(&dec1, 1);
  dec1 = set_bit(dec1, 127);

  decimal dec2 = {{999999, 0, 0, 0}};  // -9999.99
  set_scale(&dec2, 2);
  dec2 = set_bit(dec2, 127);

  decimal res1;
  mul(dec1, dec2, &res1);
  int g;
  from_decimal_to_int(res1, &g);
  float r = (float)g * pow(10, -get_scale(res1));
  ck_assert_float_eq(r, 0.0);
}
END_TEST

START_TEST(mul_6) {
  decimal a = {{72342342, 0, 0, 524288}};  // 0.72342342
  decimal b = {{1, 0, 0, 1703936}};        // 0.00000000000000000000000001
  decimal res_bits = {{0, 0, 0, 0}};

  int res = mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)72);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)1835008);
}
END_TEST

START_TEST(mul_too_big) {
  decimal dec1 = {{BIT_SIZE - 1, BIT_SIZE - 1, BIT_SIZE - 1, 0}};
  decimal dec2 = {{2, 0, 0, 0}};

  decimal res;
  int ret = mul(dec1, dec2, &res);

  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(mul_rounding) {
  decimal dec1 = {{123456789, 0, 0, 0}};
  set_scale(&dec1, 10);
  decimal dec2 = {{123456789, 0, 0, 0}};
  set_scale(&dec2, 10);

  decimal res;
  mul(dec1, dec2, &res);
  float g;
  from_decimal_to_float(res, &g);
  ck_assert_float_eq(g, 0.00015241578512359410524368286132812);
}
END_TEST

START_TEST(mul_too_big_neg) {
  decimal dec1 = {{BIT_SIZE - 1, BIT_SIZE - 1, BIT_SIZE - 1, 0}};
  dec1 = set_bit(dec1, 127);
  decimal dec2 = {{2, 0, 0, 0}};

  decimal res;
  int ret = mul(dec1, dec2, &res);

  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(mul_big_3) {
  decimal a = {
      {809805404, 16957601, 0, -2147483648}};            // -72832342523422300
  decimal b = {.bits = {-1998155945, 28268, 0, 0}};  // 121412432334679
  decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = mul(a, b, &res_bits);

  ck_assert_int_eq(res, 2);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(mul_big_4) {
  decimal a = {.bits = {1015837740, 287445, 0, 0}};  // 1234567890236460
  decimal b = {.bits = {-2045900063, 28744, 0, 0}};  // 123456789023457
  decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(mul_big_5) {
  decimal a = {
      {809805404, 16957601, 0, -2147483648}};  // -72832342523422300
  decimal b = {
      .bits = {652204261, 150968, 0, -2147483648}};  // -648403274946789
  decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(mul_big_6) {
  decimal a = {
      {809805404, 16957601, 0, -2147483648}};  // -72832342523.422300
  set_scale(&a, 6);
  decimal b = {
      .bits = {652204261, 150968, 0, -2147483648}};  // -648403274.946789
  set_scale(&b, 6);
  decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)4113259932);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)2579459058);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)25);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)65536);
}
END_TEST

Suite *test_mul(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("mul");
  tc = tcase_create("case_mul");

  tcase_add_test(tc, mul_test_1);
  tcase_add_test(tc, mul_test_2);
  tcase_add_test(tc, mul_test_3);
  tcase_add_test(tc, mul_test_4);
  tcase_add_test(tc, mul_test_5);
  tcase_add_test(tc, mul_test_6);
  tcase_add_test(tc, mul_test_7);
  tcase_add_test(tc, mul_test_8);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_big_1);
  tcase_add_test(tc, mul_big_2);
  tcase_add_test(tc, mul_2);  //  *
  tcase_add_test(tc, mul_3);  //  *
  tcase_add_test(tc, mul_4);  //  *
  tcase_add_test(tc, mul_5);  //  *
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_too_big);      //  *
  tcase_add_test(tc, mul_too_big_neg);  //  *
  tcase_add_test(tc, mul_rounding);     //  *
  tcase_add_test(tc, mul_big_3);
  tcase_add_test(tc, mul_big_4);
  tcase_add_test(tc, mul_big_5);
  tcase_add_test(tc, mul_big_6);

  suite_add_tcase(s, tc);
  return s;
}

//  * - закомментировано