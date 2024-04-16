#include "test_me.h"

START_TEST(strstr_test) {
  char src1[7] = "Lol";
  char src2[4] = "ol";
  char src3[7] = "";
  char src4[4] = "";
  char *res1, *res2;

  res1 = strstr(src1, src2);
  res2 = strstr(src1, src2);
  ck_assert_str_eq(res1, res2);

  res1 = strstr(src3, src4);
  res2 = strstr(src3, src4);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m-=STRSTR=-\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_test);

  suite_add_tcase(s, tc);
  return s;
}