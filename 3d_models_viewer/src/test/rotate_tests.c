
#include "3d_tests.h"

START_TEST(rotate_test_1) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 15.23;
  vertices.vertex[1] = 0.15;
  vertices.vertex[2] = 222.001;

  rotate_matrix(&vertices, 30, 0, 0);
  ck_assert_float_eq(vertices.vertex[0], 15.23);
  ck_assert_float_eq(vertices.vertex[1], 111.130404);
  ck_assert_float_eq(vertices.vertex[2], 192.183506);
  free(vertices.vertex);
}
END_TEST

START_TEST(rotate_test_2) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 775.51;
  vertices.vertex[1] = 0.0001;
  vertices.vertex[2] = 88.6182;

  rotate_matrix(&vertices, 0, 70, 0);
  ck_assert_float_eq(vertices.vertex[0], 348.513910);
  ck_assert_float_eq(vertices.vertex[1], 0.0001);
  ck_assert_float_eq(vertices.vertex[2], -698.431815);
  free(vertices.vertex);
}
END_TEST

START_TEST(rotate_test_3) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = -15.1515;
  vertices.vertex[1] = -999;
  vertices.vertex[2] = 11;

  rotate_matrix(&vertices, 0, 0, 15);
  ck_assert_float_eq(vertices.vertex[0], -273.195451);
  ck_assert_float_eq(vertices.vertex[1], -961.038404);
  ck_assert_float_eq(vertices.vertex[2], 11);
  free(vertices.vertex);
}
END_TEST

START_TEST(rotate_test_4) {
  vertices vertices = {};
  vertices.count = 2;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = -15.1515;
  vertices.vertex[1] = -999;
  vertices.vertex[2] = 11;
  vertices.vertex[3 + 0] = 645.234;
  vertices.vertex[3 + 1] = -923.14123;
  vertices.vertex[3 + 2] = -0.812382;

  rotate_matrix(&vertices, 45, -11, 220);
  ck_assert_float_eq(vertices.vertex[0], 564.848788);
  ck_assert_float_eq(vertices.vertex[1], 438.021189);
  ck_assert_float_eq(vertices.vertex[2], 698.165348);
  ck_assert_float_eq(vertices.vertex[3 + 0], 30.086956);
  ck_assert_float_eq(vertices.vertex[3 + 1], 827.620835);
  ck_assert_float_eq(vertices.vertex[3 + 2], 763.318959);
  free(vertices.vertex);
}
END_TEST

Suite *rotate_tests() {
  Suite *suite = suite_create("---ROTATE---");
  TCase *tcase = tcase_create("3d_viewer_tc");

  tcase_add_test(tcase, rotate_test_1);
  tcase_add_test(tcase, rotate_test_2);
  tcase_add_test(tcase, rotate_test_3);
  tcase_add_test(tcase, rotate_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
