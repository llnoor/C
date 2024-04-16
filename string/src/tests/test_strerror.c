#include "test_me.h"

START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  char *res1 = strerror(n);
  char *res2 = strerror(n);
  ck_assert_str_eq(res1, res2);
  if (res1) free(res1);
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  suite_add_tcase(s, tc);
  return s;
}