#include "test_me.h"

START_TEST(memset_1) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  int ch = ' ';
  size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

START_TEST(memset_2) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  int ch = ' ';
  size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

START_TEST(memset_3) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  int ch = ' ';
  size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

START_TEST(memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char s1[] = "Byeby";
  char s2[] = "Byeby";
  int ch = '\0';
  size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  int ch = 80;
  size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), memset(s2, ch, n));
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[45m-=MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);

  suite_add_tcase(s, tc);
  return s;
}
