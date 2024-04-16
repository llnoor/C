#include "test_me.h"

START_TEST(strtok_test) {
  char str1[100] = "---- test", str2[100] = "1/2/3/4", str3[100] = "1234",
       str4[100] = "AMOGUS! !--PEPPA--! ==ABOBA==", str6[100] = "-! =";
  ck_assert_msg(strtok(str1, str6) == strtok(str1, str6), "1 test failed");
  ck_assert_msg(strtok(str4, str6) == strtok(str4, str6), "2 test failed");
  ck_assert_msg(strtok(str2, str3) == strtok(str2, str3), "3 test failed");
  ck_assert_msg(strtok(str1, str3) == strtok(str1, str3), "3 test failed");
  ck_assert_msg(strtok(str4, str3) == strtok(str4, str3), "3 test failed");
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[45m-=STRTOK=-\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_test);

  suite_add_tcase(s, tc);
  return s;
}