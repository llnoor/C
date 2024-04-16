#include "test_me.h"

START_TEST(memmove_1) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  char s3[] = "Baad";
  size_t n = 4;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_2) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  char s3[] = "";
  size_t n = 0;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_3) {
  char s1[] = "Byeby, litrd?";
  char s2[] = "Byeby, litrd?";
  char s3[] = "forward";
  size_t n = 0;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_4) {
  char s1[] = "100: Checks: 780, Failures: 0, Errors: 0";
  char s2[] = "100: Checks: 780, Failures: 0, Errors: 0";
  size_t n = 6;
  memmove(s1, s1, n);
  memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_5) {
  char s1[] = "L";
  char s2[] = "L";
  char s3[] = "Li";
  size_t n = 2;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_6) {
  char s1[] = "kokokok";
  char s2[] = "kokokok";
  char s3[] = "\0";
  size_t n = 1;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_7) {
  char s1[] = "           ";
  char s2[] = "           ";
  char s3[] = "new_string";
  size_t n = strlen(s3);
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  size_t n = 3;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_9) {
  char s1[] = "87698888";
  char s2[] = "87698888";
  char s3[] = "c";
  size_t n = 1;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_10) {
  char s1[] = "87698888";
  char s2[] = "87698888";
  char s3[] = "com";
  size_t n = 4;
  memmove(s1, s3, n);
  memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

Suite *test_memmove(void) {
  Suite *s = suite_create("\033[45m-=MEMMOVE=-\033[0m");
  TCase *tc = tcase_create("memove_tc");

  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memmove_5);
  tcase_add_test(tc, memmove_6);
  tcase_add_test(tc, memmove_7);
  tcase_add_test(tc, memmove_8);
  tcase_add_test(tc, memmove_9);
  tcase_add_test(tc, memmove_10);

  suite_add_tcase(s, tc);
  return s;
}
