#include "test_me.h"

START_TEST(strpbrk_test) {
  char str1[100] = "1234", str2[100] = "Nice", str3[100] = "00000000",
       str4[100] = "-1-2-3-4-5", str5[100] = "", str6[100] = "1768",
       str7[100] = "c", str8[100] = "0";

  ck_assert_ptr_eq(strpbrk(str1, str6), strpbrk(str1, str6));
  ck_assert_ptr_eq(strpbrk(str2, str7), strpbrk(str2, str7));
  ck_assert_ptr_eq(strpbrk(str1, str7), strpbrk(str1, str7));
  ck_assert_ptr_eq(strpbrk(str3, str8), strpbrk(str3, str8));
  ck_assert_ptr_eq(strpbrk(str4, str6), strpbrk(str4, str6));
  ck_assert_ptr_eq(strpbrk(str5, str1), strpbrk(str5, str1));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=STRPBRK=-\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, strpbrk_test);

  suite_add_tcase(s, tc);
  return s;
}