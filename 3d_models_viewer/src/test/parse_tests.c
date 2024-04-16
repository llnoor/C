#include "3d_tests.h"

START_TEST(parse_test_1) {
  object_t *obj;
  obj = parseObj("test/objects/1.ob");
  ck_assert_ptr_ne(obj, NULL);
  ck_assert_int_eq(obj->count_polygons, 3442);
  ck_assert_int_eq(obj->vert->count, 3618);
  ck_assert_int_eq(obj->polygons[1001].value, 8);
  free_all(obj);
}
END_TEST

START_TEST(parse_test_2) {
  object_t *obj;
  obj = parseObj("test/objects/2.ob");
  ck_assert_ptr_ne(obj, NULL);
  ck_assert_int_eq(obj->count_polygons, 9537);
  ck_assert_int_eq(obj->vert->count, 6122);
  ck_assert_int_eq(obj->polygons[1001].value, 6);
  free_all(obj);
}
END_TEST

START_TEST(parse_test_3) {
  object_t *obj;
  obj = parseObj("test/objects/3.ob");
  ck_assert_ptr_ne(obj, NULL);
  ck_assert_int_eq(obj->count_polygons, 2443);
  ck_assert_int_eq(obj->vert->count, 1436);
  ck_assert_int_eq(obj->polygons[11].value, 6);
  free_all(obj);
}
END_TEST

START_TEST(parse_test_4) {
  object_t *obj = parseObj("Nan");
  ck_assert_ptr_eq(obj, NULL);
}
END_TEST

Suite *parse_tests() {
  Suite *suite = suite_create("---PARSE---");
  TCase *tcase = tcase_create("3d_viewer_tc");

  tcase_add_test(tcase, parse_test_1);
  tcase_add_test(tcase, parse_test_2);
  tcase_add_test(tcase, parse_test_3);
  tcase_add_test(tcase, parse_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}