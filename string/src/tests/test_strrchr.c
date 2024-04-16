#include "test_me.h"

START_TEST(strrchr_test) {
  char str1[100] = "123412341234", str2[100] = "Congratulations!",
       str3[100] = "00000000", str4[100] = "-1-2-3-4-5", str5[100] = "",
       str6[100] = " ", str7[100] = "1f2t3_4:5^6`=t_retro";
  ck_assert_msg(strrchr(str1, '0') == strrchr(str1, '0'), "test 1 failed");
  ck_assert_msg(strrchr(str2, 'i') == strrchr(str2, 'i'), "test 2 failed");
  ck_assert_msg(strrchr(str3, '0') == strrchr(str3, '0'), "test 3 failed");
  ck_assert_msg(strrchr(str4, '-') == strrchr(str4, '-'), "test 4 failed");
  ck_assert_msg(strrchr(str5, '1') == strrchr(str5, '1'), "test 5 failed");
  ck_assert_msg(strrchr(str6, '^') == strrchr(str6, '^'), "test 6 failed");
  ck_assert_msg(strrchr(str7, ' ') == strrchr(str7, ' '), "test 7 failed");
  ck_assert_msg(strrchr(str7, '_') == strrchr(str7, '_'), "test 8 failed");
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45m-=STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, strrchr_test);

  suite_add_tcase(s, tc);
  return s;
}