#include "test_me.h"

START_TEST(strchr_1) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = '!';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Goodbuy my friendlr! Have a nice day!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "Hello, World !";
  int ch = 'W';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = 'v';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "Goodbuy my friend! Have a nice day!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), strchr(s, ch));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[45m-=STRCHR=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);

  suite_add_tcase(s, tc);
  return s;
}
