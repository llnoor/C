#include "3d_tests.h"

START_TEST(move_test_1) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 15.23;
  vertices.vertex[1] = 0.15;
  vertices.vertex[2] = 222.001;

  move_matrix(&vertices, 55.777, 14.8812, 66.1232);
  ck_assert_float_eq(vertices.vertex[0], 71.007);
  ck_assert_float_eq(vertices.vertex[1], 15.0312);
  ck_assert_float_eq(vertices.vertex[2], 288.1242);
  free(vertices.vertex);
}
END_TEST

START_TEST(move_test_2) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 775.51;
  vertices.vertex[1] = 0.0001;
  vertices.vertex[2] = 88.6182;

  move_matrix(&vertices, -92.0192, -111, -0.555);
  ck_assert_float_eq(vertices.vertex[0], 683.4908);
  ck_assert_float_eq(vertices.vertex[1], -110.9999);
  ck_assert_float_eq(vertices.vertex[2], 88.0632);
  free(vertices.vertex);
}
END_TEST

START_TEST(move_test_3) {
  vertices vertices = {};
  vertices.count = 2;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = -15.1515;
  vertices.vertex[1] = -999;
  vertices.vertex[2] = 11;
  vertices.vertex[3 + 0] = 645.234;
  vertices.vertex[3 + 1] = -923.14123;
  vertices.vertex[3 + 2] = -0.812382;

  move_matrix(&vertices, 5345.12312, -95.113665, 6.1882);
  ck_assert_float_eq(vertices.vertex[0], 5329.97162);
  ck_assert_float_eq(vertices.vertex[1], -1094.113665);
  ck_assert_float_eq(vertices.vertex[2], 17.1882);
  ck_assert_float_eq(vertices.vertex[3 + 0], 5990.35712);
  ck_assert_float_eq(vertices.vertex[3 + 1], -1018.254895);
  ck_assert_float_eq(vertices.vertex[3 + 2], 5.375818);
  free(vertices.vertex);
}
END_TEST

START_TEST(move_test_4) {
  vertices vertices = {};
  vertices.count = 3;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = -15.1515;
  vertices.vertex[1] = -999;
  vertices.vertex[2] = 11;
  vertices.vertex[3 + 0] = 645.234;
  vertices.vertex[3 + 1] = -923.14123;
  vertices.vertex[3 + 2] = -0.812382;
  vertices.vertex[3 * 2 + 0] = 984.1891;
  vertices.vertex[3 * 2 + 1] = 9112.131;
  vertices.vertex[3 * 2 + 2] = -434.523423;

  move_matrix(&vertices, -11.1111, -55.55, 87.4823);
  ck_assert_float_eq(vertices.vertex[0], -26.2626);
  ck_assert_float_eq(vertices.vertex[1], -1054.55);
  ck_assert_float_eq(vertices.vertex[2], 98.4823);
  ck_assert_float_eq(vertices.vertex[3 + 0], 634.1229);
  ck_assert_float_eq(vertices.vertex[3 + 1], -978.69123);
  ck_assert_float_eq(vertices.vertex[3 + 2], 86.669918);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 0], 973.078);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 1], 9056.581);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 2], -347.041123);
  free(vertices.vertex);
}
END_TEST

Suite *move_tests() {
  Suite *suite = suite_create("---MOVE---");
  TCase *tcase = tcase_create("3d_viewer_tc");

  tcase_add_test(tcase, move_test_1);
  tcase_add_test(tcase, move_test_2);
  tcase_add_test(tcase, move_test_3);
  tcase_add_test(tcase, move_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}