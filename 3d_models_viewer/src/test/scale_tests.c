#include "3d_tests.h"

START_TEST(scale_test_1) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 15.23;
  vertices.vertex[1] = 0.15;
  vertices.vertex[2] = 222.001;

  scale_matrix(&vertices, 0.555, 0.555, 0.555);
  ck_assert_float_eq(vertices.vertex[0], 8.45265);
  ck_assert_float_eq(vertices.vertex[1], 0.08325);
  ck_assert_float_eq(vertices.vertex[2], 123.210555);
  free(vertices.vertex);
}
END_TEST

START_TEST(scale_test_2) {
  vertices vertices = {};
  vertices.count = 1;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = 775.51;
  vertices.vertex[1] = 0.0001;
  vertices.vertex[2] = 88.6182;

  scale_matrix(&vertices, 6.89812, 0.1182, 0.48);
  ck_assert_float_eq(vertices.vertex[0], 5349.5610412);
  ck_assert_float_eq(vertices.vertex[1], 0.00001182);
  ck_assert_float_eq(vertices.vertex[2], 42.536736);
  free(vertices.vertex);
}
END_TEST

START_TEST(scale_test_3) {
  vertices vertices = {};
  vertices.count = 2;
  vertices.vertex = malloc(vertices.count * 3 * sizeof(double));
  vertices.vertex[0] = -15.1515;
  vertices.vertex[1] = -999;
  vertices.vertex[2] = 11;
  vertices.vertex[3 + 0] = 645.234;
  vertices.vertex[3 + 1] = -923.14123;
  vertices.vertex[3 + 2] = -0.812382;

  scale_matrix(&vertices, 0.02, 11, 7.777);
  ck_assert_float_eq(vertices.vertex[0], -0.30303);
  ck_assert_float_eq(vertices.vertex[1], -10989);
  ck_assert_float_eq(vertices.vertex[2], 85.547);
  ck_assert_float_eq(vertices.vertex[3 + 0], 12.90468);
  ck_assert_float_eq(vertices.vertex[3 + 1], -10154.55353);
  ck_assert_float_eq(vertices.vertex[3 + 2], -6.317894814);
  free(vertices.vertex);
}
END_TEST

START_TEST(scale_test_4) {
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

  scale_matrix(&vertices, 1, 1, 1);
  ck_assert_float_eq(vertices.vertex[0], -15.1515);
  ck_assert_float_eq(vertices.vertex[1], -999);
  ck_assert_float_eq(vertices.vertex[2], 11);
  ck_assert_float_eq(vertices.vertex[3 + 0], 645.234);
  ck_assert_float_eq(vertices.vertex[3 + 1], -923.14123);
  ck_assert_float_eq(vertices.vertex[3 + 2], -0.812382);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 0], 984.1891);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 1], 9112.131);
  ck_assert_float_eq(vertices.vertex[3 * 2 + 2], -434.523423);
  free(vertices.vertex);
}
END_TEST

Suite *scale_tests() {
  Suite *suite = suite_create("---SCALE---");
  TCase *tcase = tcase_create("3d_viewer_tc");

  tcase_add_test(tcase, scale_test_1);
  tcase_add_test(tcase, scale_test_2);
  tcase_add_test(tcase, scale_test_3);
  tcase_add_test(tcase, scale_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}