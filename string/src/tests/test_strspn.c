#include "test_me.h"

START_TEST(strspn_test) {
  char str11[100] = "1234", str12[100] = "776832768178",
       str13[100] = "-1213002%s", str14[100] = "";
  char str21[100] = "", str22[100] = "776", str23[100] = "-1213002%s",
       str24[100] = "1234";
  ck_assert_int_eq(strspn(str11, str21), strspn(str11, str21));
  ck_assert_int_eq(strspn(str12, str22), strspn(str12, str22));
  ck_assert_int_eq(strspn(str13, str23), strspn(str13, str23));
  ck_assert_int_eq(strspn(str14, str24), strspn(str14, str24));
  ck_assert_int_eq(strspn(str12, str23), strspn(str12, str23));
}
END_TEST

Suite *test_strspn(void) {
  Suite *s = suite_create("\033[45m-=STRSPN=-\033[0m");
  TCase *tc = tcase_create("strspn_tc");

  tcase_add_test(tc, strspn_test);

  suite_add_tcase(s, tc);
  return s;
}