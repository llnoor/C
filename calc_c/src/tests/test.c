#include <check.h>
#include <math.h>

#include "../string.h"
#include "../stack.h"
#include "../bank.h"

#define EXS 1.e-7

START_TEST(test_1) {
  int flag = 0;
  double x = sqrt(30) + pow(4, 5);
  ck_assert_double_eq_tol(calc("sqrt(30)+4^5", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_1_1) {
  int flag = 0;
  double x = 0.1*6;
  ck_assert_double_eq_tol(calc("0.1*6", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_1_2) {
  int flag = 0;
  double x = sin(45);
  ck_assert_double_eq_tol(calc("sin(45)", "0.001", &flag), x, 0.00001);
}
END_TEST

START_TEST(test_2) {
  int flag = 0;
  double x = acos(cos(180)) - tan(30);
  ck_assert_double_eq_tol(calc("acos(cos(180))- tan(30)", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_3) {
  int flag = 0;
  double x = asin(sin(180)) - atan(30);
  ck_assert_double_eq_tol(calc("asin(sin(180))- atan(30)", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_4) {
  int flag = 0;
  double x = pow(5, 2) / 4;
  ck_assert_double_eq_tol(calc("5^2/4", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_5) {
  int flag = 0;
  double x = 5.006 * 97.83 + pow(3.7, 8.37) / (-5.6) + log(25.6);
  ck_assert_double_eq_tol(
      calc("5.006* 97.83 +3.7^8.37/(-5.6) + ln(25.6)", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_6) {
  int flag = 0;
  char str[1000] =
      "5.006* 97.83 +3.7^8.37/(-5.6) + ln(25.6) + 5.006* 97.83 + pow(8.37)/(-5.6) + log(25.6)+ 5.006* 97.83 + pow(3.7, 8.37)/(-5.6) + log(25.6)+5.006* 97.83 + pow(3.7, 8.37)/(-5.6) + log(25.6)+5.006* 97.83+3.7^8.37/";
  ck_assert_double_eq(calc(str, "0.001", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_7) {
  int flag = 0;
  ck_assert_double_eq(calc("5.006* 97.83 +3.7^8.37/(-5.6) + ln(", "0.001", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_8) {
  int flag = 0;
  ck_assert_double_eq(calc("5.006* 97.83 +3.7^8.37/(-5.6) + (", "0.001", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_9) {
  int flag = 0;
  double x = (5 + 3) * 6 + 20 * log10(25.6);
  ck_assert_double_eq_tol(calc("(5+3)*6+20*log(25.6)", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_10) {
  int flag = 0;
  double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("5.68*(4+log(4.3+ cos(29.7)))", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_10_1) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("+5.68*(4+log(4.3+ cos(29.7)))", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 14); 
}
END_TEST

START_TEST(test_10_2) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("u", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 1); 
}
END_TEST

START_TEST(test_10_3) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("sinsin(4)", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 4); 
}
END_TEST

START_TEST(test_10_4) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("---1+--2", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 8); 
}
END_TEST

START_TEST(test_10_5) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("x45", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 7); 
}
END_TEST

START_TEST(test_10_6) {
  int flag = 0;
  //double x = 5.68 * (4 + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("0.-", "0.001u", &flag), 0, EXS);
  ck_assert_int_eq(flag, 1); 
}
END_TEST

START_TEST(test_10_7) {
  int flag = 0;
  //double x = (cos(45)+exp(3)+cot(1)+acot(4);
  ck_assert_double_eq_tol(calc("(cos(45)+exp(3)+cot(1)+acot(4))*0", "0", &flag), 0,  EXS); 
}
END_TEST


START_TEST(test_11) {
  int flag = 0;
  ck_assert_double_eq(calc("sin(24.5)**(cos)", "0.001.09", &flag),0);
  ck_assert_int_eq(flag, 3); 
  }
END_TEST

START_TEST(test_12) {
  int flag = 0;
  double x = 5.34 * fmod(45.33, 3.563);
  ck_assert_double_eq_tol(calc("5.34 * (45.33 mod 3.563)", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_13) {
  int flag = 0;
  double x = -0.1+10+10;
  ck_assert_double_eq_tol(calc("-1E-1+1E1+1E+1", "0.001", &flag), x, EXS);
}
END_TEST

START_TEST(test_14) {
  int flag = 0;
  double x = 30.567;
  char str[255];
  sprintf(str, "%f", x);
  double y = sqrt(30.567) + pow(4, 5);
  ck_assert_double_eq_tol(calc("sqrt(x)+4^5", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_15) {
  int flag = 0;
  double x = 180;
  char str[255];
  sprintf(str, "%f", x);
  double y = acos(cos(x)) - tan(30);
  ck_assert_double_eq_tol(calc("acos(cos(x))- tan(30)", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_16) {
  int flag = 0;
  double x = 30;
  char str[255];
  sprintf(str, "%f", x);
  double y = asin(sin(x)) - atan(x);
  ck_assert_double_eq_tol(calc("asin(sin(x))- atan(x)", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_17) {
  int flag = 0;
  double x = 5.8;
  char str[255];
  sprintf(str, "%f", x);
  double y = pow(x, 2) / 4;
  ck_assert_double_eq_tol(calc("x^2/4", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_18) {
  int flag = 0;
  double x = 25.6;
  char str[255];
  sprintf(str, "%f", x);
  double y = 5.006 * 97.83 + pow(3.7, 8.37) / (-5.6) * x + log(x);
  ck_assert_double_eq_tol(calc("5.006* 97.83 +3.7^8.37/(-5.6)* x + ln(x)", str, &flag), y, 0.00001);
}
END_TEST

START_TEST(test_19) {
  int flag = 0;
  ck_assert_double_eq(calc("5.006* 97.83 +x^8.37/(-5.6) + ln(", "0.12", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_20) {
  int flag = 0;
  ck_assert_double_eq(calc("5.006* 97.83 +x^8.37/(-5.6) + (", "0.12io", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_21) {
  int flag = 0;
  double x = 6;
  char str[255];
  sprintf(str, "%f", x);
  double y = (5 + 3) * x + 20 * log10(25.6);
  ck_assert_double_eq_tol(calc("(5+3)*x+20*log(25.6)", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_22) {
  int flag = 0;
  double x = 4;
  char str[255];
  sprintf(str, "%f", x);
  double y = 5.68 * (x + log10(4.3 + cos(29.7)));
  ck_assert_double_eq_tol(calc("5.68*(x+log(4.3+ cos(29.7)))", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_23) {
  int flag = 0;
  ck_assert_double_eq(calc("sin(x)+cos", "0.12", &flag),0);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_24) {
  int flag = 0;
  double x = 45.33;
  char str[255];
  sprintf(str, "%f", x);
  double y = 5.34 * fmod(x, 3.563);
  ck_assert_double_eq_tol(calc("5.34 * (x mod 3.563)", str, &flag), y, EXS);
}
END_TEST

START_TEST(test_25) {
  int flag = 0;
  double x = 45.33;
  char str[255];
  sprintf(str, "%f", x);
  double y = (-5.34) * fmod(x, 3.563) +1;
  ck_assert_double_eq_tol(calc("(-5.34) * (x mod 3.563) ++1 ", str, &flag), y, EXS);
}
END_TEST

START_TEST(a_credit_test) {
  int size = 2550;
  char *string;
  string = (char *)calloc(size, sizeof(char));
  double monthly_payment = 0.0;
  double over_payment = 0.0;
  double total_payment = 0.0;
  annuity (2000000, 40, 12, &monthly_payment, &over_payment, &total_payment, string);
  ck_assert_double_eq_tol(monthly_payment, 60911.20, 1);
  ck_assert_double_eq_tol(over_payment, 436448.00, 1);
  ck_assert_double_eq_tol(total_payment, 2436448, 1);
  free(string);
}
END_TEST

START_TEST(d_credit_test) {
  int size = 2550;
  char *string;
  string = (char *)calloc(size, sizeof(char));
  double monthly_payment_first = 0.0;
  double monthly_payment_last = 0.0;
  double over_payment = 0.0;
  double total_payment = 0.0;
  differentiated (2000000, 40, 12, &monthly_payment_first, &monthly_payment_last, &over_payment, &total_payment, string);
    
  ck_assert_double_eq_tol(monthly_payment_first, 70000, 1);
  ck_assert_double_eq_tol(monthly_payment_last, 50500, 1);
  ck_assert_double_eq_tol(over_payment, 410000, 1);
  ck_assert_double_eq_tol(total_payment, 2410000, 1);
  free(string);
}
END_TEST

Suite *test_suite(void) {
  Suite *suite = suite_create("test");
  TCase *tc_core = tcase_create("test");
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_1_1);
  tcase_add_test(tc_core, test_1_2);  
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  tcase_add_test(tc_core, test_9);
  tcase_add_test(tc_core, test_10);
  tcase_add_test(tc_core, test_10_1);
  tcase_add_test(tc_core, test_10_2);
  tcase_add_test(tc_core, test_10_3);
  tcase_add_test(tc_core, test_10_4);
  tcase_add_test(tc_core, test_10_5);
  tcase_add_test(tc_core, test_10_6);
  tcase_add_test(tc_core, test_10_7);
  tcase_add_test(tc_core, test_11);
  tcase_add_test(tc_core, test_12);
  tcase_add_test(tc_core, test_13);
  tcase_add_test(tc_core, test_14);
  tcase_add_test(tc_core, test_15);
  tcase_add_test(tc_core, test_16);
  tcase_add_test(tc_core, test_17);
  tcase_add_test(tc_core, test_18);
  tcase_add_test(tc_core, test_19);
  tcase_add_test(tc_core, test_20);
  tcase_add_test(tc_core, test_21);
  tcase_add_test(tc_core, test_22);
  tcase_add_test(tc_core, test_23);
  tcase_add_test(tc_core, test_24);
  tcase_add_test(tc_core, test_25);

  tcase_add_test(tc_core, a_credit_test);
  tcase_add_test(tc_core, d_credit_test);

  suite_add_tcase(suite, tc_core);
  return suite;
}

void srunner_test(Suite *s, int *no_failed) {
  SRunner *srunner = srunner_create(s);
  srunner_run_all(srunner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);
}

int main(void) {
  int no_failed = 0;
  srunner_test(test_suite(), &no_failed);
  return (no_failed == 0) ? 0 : 1;
}
