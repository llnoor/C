#include <check.h>

#include "../matrix.h"
#define INF (1.0 / 0.0)

START_TEST(create_matrix_1) {
  int res1 = 0;
  int res2 = 0;
  int res3 = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  res1 = create_matrix(4, 4, &X);
  ck_assert_int_eq(res1, 0);
  res2 = create_matrix(4, 0, &Y);
  ck_assert_int_eq(res2, 1);
  res3 = create_matrix(100, 1, &Z);
  ck_assert_int_eq(res3, 0);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&Z);
}
END_TEST

START_TEST(eq_matrix_1) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_2) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(7, 7, &X);
  create_matrix(7, 7, &Y);
  res = eq_matrix(&X, &Y);
  ck_assert_int_eq(res, 1);
  remove_matrix(&X);
  remove_matrix(&Y);
}
END_TEST

START_TEST(eq_matrix_3) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(7, 7, &X);
  create_matrix(7, 7, &Y);
  X.matrix[0][0] = 1.0000000f;
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_4) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(10, 10, &X);
  create_matrix(10, 10, &Y);
  X.matrix[0][0] = 2.0000010f;
  Y.matrix[0][0] = 2.0000001f;
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_5) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(15, 10, &X);
  create_matrix(10, 15, &Y);
  X.matrix[0][0] = 2.0000001f;
  Y.matrix[0][0] = 2.0000001f;
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_6) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(10, 10, &X);
  create_matrix(10, 10, &Y);
  X.matrix[0][0] = 2.0000001f;
  Y.matrix[0][0] = 2.0000001f;
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_7) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(10, 10, &X);
  create_matrix(10, 10, &Y);
  X.matrix[0][0] = 2.0000001f;
  Y.matrix[0][0] = 2.0000001f;
  res = eq_matrix(&X, &Y);
  remove_matrix(&X);
  remove_matrix(&Y);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_8) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(5, 5, &X);
  create_matrix(5, 5, &Y);

  X.matrix[0][0] = 1.4f;
  X.matrix[0][1] = 3.444000f;
  X.matrix[0][2] = 1.44555f;
  X.matrix[0][3] = 1.443789f;
  X.matrix[0][4] = 123.443312f;
  X.matrix[1][0] = 1.4f;
  X.matrix[1][1] = 3.444000f;
  X.matrix[1][2] = 1.44555f;
  X.matrix[1][3] = 1.443789f;
  X.matrix[1][4] = 123.443312f;
  X.matrix[2][0] = 1.4f;
  X.matrix[2][1] = 3.444000f;
  X.matrix[2][2] = 1.44555f;
  X.matrix[2][3] = 1.443789f;
  X.matrix[2][4] = 123.443312f;
  X.matrix[3][0] = 1.4f;
  X.matrix[3][1] = 3.444000f;
  X.matrix[3][2] = 1.44555f;
  X.matrix[3][3] = 1.443789f;
  X.matrix[3][4] = 123.443312f;
  X.matrix[4][0] = 1.4f;
  X.matrix[4][1] = 3.444000f;
  X.matrix[4][2] = 1.44555f;
  X.matrix[4][3] = 1.443789f;
  X.matrix[4][4] = 123.443312f;

  sum_matrix(&X, &Y, &result);

  res = eq_matrix(&X, &result);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_9) {
  int res = 0;
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(5, 5, &X);
  create_matrix(5, 5, &Y);

  int k = 0;

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < Y.columns; j++) {
      Y.matrix[i][j] = 1.0f + X.matrix[i][j] + 1.5f + 0.001f;
    }
    X.matrix[i][k] = 1.5f + 0.001f + Y.matrix[i][k];
    k++;
  }
  sub_matrix(&X, &Y, &result);
  res = eq_matrix(&X, &result);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j;
    }
  }

  for (int i = 0; (i < X.rows); i++) {
    for (int j = 0; j < X.columns; j++) {
      result_full.matrix[i][j] = X.matrix[i][j] + Y.matrix[i][j];
    }
  }

  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);
  ck_assert_int_eq(eq_matrix(&result_full, &result), 1);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(5, 5, &X);
  create_matrix(5, 5, &Y);
  create_matrix(5, 5, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 0.0000001;
      Y.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + X.matrix[i][j] + 0.0000001;
    }
  }

  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 0.0000001;
      Y.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + X.matrix[i][j] + 0.0000001;
    }
  }

  X.columns = 0;
  Y.rows = -1;
  ck_assert_int_eq(eq_matrix(&X, &Y), 0);

  X.columns = 2;
  Y.rows = 2;

  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 0.0000001;
      Y.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + X.matrix[i][j] + 0.0000001;
    }
  }

  X.columns = 0;
  Y.rows = -1;
  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 1);

  X.columns = 1;
  Y.rows = 2;
  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 2);

  X.columns = 2;
  Y.rows = 2;
  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(14, 14, &X);
  create_matrix(14, 14, &Y);
  create_matrix(14, 14, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 0.0000001;
      Y.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + X.matrix[i][j] + 0.0000001;
    }
  }

  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);
  remove_matrix(&Y);

  ck_assert_int_eq(sub_matrix(&X, &result, &Y), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      result_full.matrix[i][j] = X.matrix[i][j] - result.matrix[i][j];
      ck_assert_double_eq(Y.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 81230.0000001;
      Y.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = X.matrix[i][j] + Y.matrix[i][j];
    }
  }

  ck_assert_int_eq(sum_matrix(&X, &Y, &result), 0);
  remove_matrix(&Y);
  ck_assert_int_eq(sub_matrix(&X, &result, &Y), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      result_full.matrix[i][j] = X.matrix[i][j] - result.matrix[i][j];
      ck_assert_double_eq(Y.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 72330.0000001;
      Y.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = X.matrix[i][j] - Y.matrix[i][j];
    }
  }

  ck_assert_int_eq(sub_matrix(&X, &Y, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 3, &X);
  create_matrix(2, 3, &Y);
  create_matrix(2, 3, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = j + 1 + 81230.0000001;
      Y.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = X.matrix[i][j] - Y.matrix[i][j];
    }
  }

  ck_assert_int_eq(sub_matrix(&X, &Y, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &X);
  create_matrix(2, 3, &Y);

  X.rows = 0;
  Y.columns = -1;

  ck_assert_int_eq(sub_matrix(&X, &Y, &result), 1);

  X.rows = 3;
  Y.columns = 3;

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 2, &X);
  create_matrix(3, 3, &Y);

  ck_assert_int_eq(sub_matrix(&X, &Y, &result), 2);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &Y);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = 1.12312320f;
      Y.matrix[i][j] = 1.12312320f;
    }
  }

  ck_assert_int_eq(sub_matrix(&X, &Y, &result), 0);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_0) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = INF;
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &result_full);

  ck_assert_int_eq(mult_number(&X, res, &result), 2);
  remove_matrix(&X);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = 1.12312320f;
      result_full.matrix[i][j] = res * X.matrix[i][j];
    }
  }

  ck_assert_int_eq(mult_number(&X, res, &result), 0);
  remove_matrix(&X);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = 1.12312320f;
      result_full.matrix[i][j] = res * X.matrix[i][j];
    }
  }

  ck_assert_int_eq(mult_number(&X, res, &result), 0);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&X);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < X.rows; i++) {
    for (int j = 0; j < X.columns; j++) {
      X.matrix[i][j] = 1.12312320f;
      result_full.matrix[i][j] = res * X.matrix[i][j];
    }
  }
  X.rows = -1;
  ck_assert_int_eq(mult_number(&X, res, &result), 1);
  X.rows = 4;

  remove_matrix(&X);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(4, 3, &X);
  create_matrix(4, 3, &Y);

  ck_assert_int_eq(mult_matrix(&X, &Y, &result), 2);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 2, &X);
  create_matrix(2, 2, &Y);

  ck_assert_int_eq(mult_matrix(&X, &Y, &result), 0);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full;
  create_matrix(3, 2, &X);
  create_matrix(2, 3, &Y);
  X.matrix[0][0] = 0;
  X.matrix[0][1] = 1;
  X.matrix[1][0] = 2;
  X.matrix[1][1] = 1;
  X.matrix[2][0] = 3;
  X.matrix[2][1] = 3;
  Y.matrix[0][0] = 4;
  Y.matrix[0][1] = 1;
  Y.matrix[0][2] = 2;
  Y.matrix[1][0] = 3;
  Y.matrix[1][1] = 3;
  Y.matrix[1][2] = 3;
  create_matrix(3, 3, &result_full);
  result_full.matrix[0][0] = 3;
  result_full.matrix[0][1] = 3;
  result_full.matrix[0][2] = 3;
  result_full.matrix[1][0] = 11;
  result_full.matrix[1][1] = 5;
  result_full.matrix[1][2] = 7;
  result_full.matrix[2][0] = 21;
  result_full.matrix[2][1] = 12;
  result_full.matrix[2][2] = 15;

  ck_assert_int_eq(mult_matrix(&X, &Y, &result), 0);

  ck_assert_int_eq(eq_matrix(&result_full, &result), 1);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 0, &X);
  create_matrix(2, 2, &Y);

  ck_assert_int_eq(mult_matrix(&X, &Y, &result), 1);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(3, 1, &X);
  create_matrix(2, 3, &Y);

  ck_assert_int_eq(mult_matrix(&X, &Y, &result), 2);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result1 = {NULL, 0, 0};
  matrix_t result2 = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(3, 2, &X);
  create_matrix(2, 3, &Y);
  X.matrix[0][0] = 0;
  X.matrix[0][1] = 1;
  X.matrix[1][0] = 2;
  X.matrix[1][1] = 1;
  X.matrix[2][0] = 3;
  X.matrix[2][1] = 3;

  Y.matrix[0][0] = 4;
  Y.matrix[0][1] = 1;
  Y.matrix[0][2] = 2;
  Y.matrix[1][0] = 3;
  Y.matrix[1][1] = 3;
  Y.matrix[1][2] = 3;

  ck_assert_int_eq(mult_matrix(&X, &Y, &result1), 0);

  create_matrix(3, 3, &result_full);
  result_full.matrix[0][0] = 3;
  result_full.matrix[0][1] = 11;
  result_full.matrix[0][2] = 21;
  result_full.matrix[1][0] = 3;
  result_full.matrix[1][1] = 5;
  result_full.matrix[1][2] = 12;
  result_full.matrix[2][0] = 3;
  result_full.matrix[2][1] = 7;
  result_full.matrix[2][2] = 15;

  ck_assert_int_eq(transpose(&result1, &result2), 0);

  ck_assert_int_eq(eq_matrix(&result_full, &result2), 1);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result1);
  remove_matrix(&result2);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(3, 5, &X);
  X.matrix[0][0] = 121;
  X.matrix[0][1] = 122;
  X.matrix[0][2] = 123;
  X.matrix[0][3] = 124;
  X.matrix[0][4] = 125;
  X.matrix[1][0] = 126;
  X.matrix[1][1] = 127;
  X.matrix[1][2] = 128;
  X.matrix[1][3] = 129;
  X.matrix[1][4] = 1210;
  X.matrix[2][0] = 1211;
  X.matrix[2][1] = 1212;
  X.matrix[2][2] = 1213;
  X.matrix[2][3] = 1214;
  X.matrix[2][4] = 1215;
  ck_assert_int_eq(transpose(&X, &result), 0);
  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(3, 5, &X);
  X.rows = 0;
  X.columns = -1;
  ck_assert_int_eq(transpose(&X, &result), 1);
  X.rows = 3;
  X.columns = 5;
  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 2, &X);
  X.matrix[0][0] = 1.0;
  X.matrix[0][1] = 2.0;
  X.matrix[1][0] = 3.0;
  X.matrix[1][1] = 4.0;
  create_matrix(2, 2, &result);
  result.matrix[0][0] = 4.0;
  result.matrix[0][1] = -3.0;
  result.matrix[1][0] = -2.0;
  result.matrix[1][1] = 1.0;

  calc_complements(&X, &Y);

  for (int i = 0; i < Y.rows; i++) {
    for (int j = 0; j < Y.columns; j++)
      ck_assert_double_eq(Y.matrix[i][j], result.matrix[i][j]);
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  create_matrix(2, 3, &X);
  ck_assert_int_eq(calc_complements(&X, &Y), 2);
  remove_matrix(&X);
  remove_matrix(&Y);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 3, &X);
  create_matrix(3, 2, &result);
  X.rows = 0;
  ck_assert_int_eq(calc_complements(&X, &Y), 1);
  X.rows = 2;
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_0) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res1 = 0.0;
  ck_assert_int_eq(determinant(&X, &res1), 1);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res1 = 0.0;
  double res2 = 0.0;
  create_matrix(2, 2, &X);
  X.matrix[0][0] = 1.0;
  X.matrix[0][1] = 2.0;
  X.matrix[1][0] = 3.0;
  X.matrix[1][1] = 4.0;
  create_matrix(2, 2, &result);
  result.matrix[0][0] = 4.0;
  result.matrix[0][1] = -3.0;
  result.matrix[1][0] = -2.0;
  result.matrix[1][1] = 1.0;
  ck_assert_int_eq(calc_complements(&X, &Y), 0);

  for (int i = 0; i < Y.rows; i++) {
    for (int j = 0; j < Y.columns; j++)
      ck_assert_double_eq(Y.matrix[i][j], result.matrix[i][j]);
  }
  res1 = (X.matrix[0][0] * Y.matrix[0][0]) + (X.matrix[0][1] * Y.matrix[0][1]);
  ck_assert_int_eq(determinant(&X, &res2), 0);
  ck_assert_double_eq(res1, res2);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res = 0.0f;
  create_matrix(1, 1, &X);
  X.matrix[0][0] = 1.0;
  create_matrix(1, 1, &Y);
  Y.matrix[0][0] = 1.0;
  ck_assert_int_eq(calc_complements(&X, &result), 0);
  ck_assert_double_eq(Y.matrix[0][0], result.matrix[0][0]);
  ck_assert_int_eq(determinant(&X, &res), 0);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  // double res1 = 0.0;
  // double res2 = 0.0;
  create_matrix(5, 5, &X);
  X.matrix[0][0] = 342.0;
  X.matrix[0][1] = 342.0;
  X.matrix[0][2] = 344.0;
  X.matrix[0][3] = 345.0001;
  X.matrix[0][4] = 3410.0123;

  X.matrix[1][0] = 3411.0;
  X.matrix[1][1] = 345.0;
  X.matrix[1][2] = 346.00003;
  X.matrix[1][3] = 348.0;
  X.matrix[1][4] = 349.003;

  X.matrix[2][0] = 3412.0;
  X.matrix[2][1] = 345.0;
  X.matrix[2][2] = 340.0;
  X.matrix[2][3] = 343.0;
  X.matrix[2][4] = 342.003;

  X.matrix[3][0] = 343.0;
  X.matrix[3][1] = 345.0;
  X.matrix[3][2] = 349.00003;
  X.matrix[3][3] = 343.0;
  X.matrix[3][4] = 3410.003;

  X.matrix[4][0] = 347.0;
  X.matrix[4][1] = 348.0;
  X.matrix[4][2] = 343.00003;
  X.matrix[4][3] = 344.0;
  X.matrix[4][4] = 348.003;

  ck_assert_int_eq(calc_complements(&X, &result), 0);

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &X);
  X.matrix[0][0] = 3.0;
  X.matrix[0][1] = -2.0;
  X.matrix[0][2] = 4.0;
  X.matrix[1][0] = -2.0;
  X.matrix[1][1] = 3.0;
  X.matrix[1][2] = -1.0;
  X.matrix[2][0] = 2.0;
  X.matrix[2][1] = 2.0;
  X.matrix[2][2] = 5.0;

  create_matrix(3, 3, &Y);
  Y.matrix[0][0] = -3.4;
  Y.matrix[0][1] = -3.6;
  Y.matrix[0][2] = 2.0;
  Y.matrix[1][0] = -1.6;
  Y.matrix[1][1] = -1.4;
  Y.matrix[1][2] = 1.0;
  Y.matrix[2][0] = 2.0;
  Y.matrix[2][1] = 2.0;
  Y.matrix[2][2] = -1.0;
  ck_assert_int_eq(inverse_matrix(&X, &result), 0);

  for (int i = 0; i < Y.rows; i++) {
    for (int j = 0; j < Y.columns; j++)
      ck_assert_double_eq_tol(Y.matrix[i][j], result.matrix[i][j], 0.000001);
  }

  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &X);
  X.matrix[0][0] = 2.0;
  create_matrix(1, 1, &Y);
  Y.matrix[0][0] = 0.5;
  ck_assert_int_eq(inverse_matrix(&X, &result), 0);
  ck_assert_double_eq(Y.matrix[0][0], result.matrix[0][0]);
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t X = {NULL, 0, 0};
  matrix_t Y = {NULL, 0, 0};
  matrix_t result1 = {NULL, 0, 0};
  matrix_t result2 = {NULL, 0, 0};

  create_matrix(5, 5, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 2.0;
  X.matrix[0][2] = 4.0;
  X.matrix[0][3] = 5.0;
  X.matrix[0][4] = 10.0;

  X.matrix[1][0] = 11.0;
  X.matrix[1][1] = 5.0;
  X.matrix[1][2] = 6.0;
  X.matrix[1][3] = 8.0;
  X.matrix[1][4] = 9.0;

  X.matrix[2][0] = 12.0;
  X.matrix[2][1] = 5.0;
  X.matrix[2][2] = 0.0;
  X.matrix[2][3] = 3.0;
  X.matrix[2][4] = 2.0;

  X.matrix[3][0] = 3.0;
  X.matrix[3][1] = 5.0;
  X.matrix[3][2] = 9.0;
  X.matrix[3][3] = 3.0;
  X.matrix[3][4] = 10.0;

  X.matrix[4][0] = 7.0;
  X.matrix[4][1] = 8.0;
  X.matrix[4][2] = 3.0;
  X.matrix[4][3] = 4.0;
  X.matrix[4][4] = 8.0;

  create_matrix(5, 5, &Y);
  Y.matrix[0][0] = 0.0786026;
  Y.matrix[0][1] = -0.0826783;
  Y.matrix[0][2] = 0.2126638;
  Y.matrix[0][3] = 0.0679767;
  Y.matrix[0][4] = -0.1433770;

  Y.matrix[1][0] = -0.1965066;
  Y.matrix[1][1] = 0.0733624;
  Y.matrix[1][2] = -0.1816594;
  Y.matrix[1][3] = -0.0532751;
  Y.matrix[1][4] = 0.2751092;

  Y.matrix[2][0] = -0.1659389;
  Y.matrix[2][1] = 0.1152838;
  Y.matrix[2][2] = -0.0711790;
  Y.matrix[2][3] = 0.1305677;
  Y.matrix[2][4] = -0.0676856;

  Y.matrix[3][0] = -0.1703057;
  Y.matrix[3][1] = 0.3569141;
  Y.matrix[3][2] = -0.3441048;
  Y.matrix[3][3] = -0.2195051;
  Y.matrix[3][4] = 0.1717613;

  Y.matrix[4][0] = 0.2751092;
  Y.matrix[4][1] = -0.2227074;
  Y.matrix[4][2] = 0.1943231;
  Y.matrix[4][3] = 0.0545852;
  Y.matrix[4][4] = -0.0851528;

  ck_assert_int_eq(inverse_matrix(&X, &result1), 0);
  ck_assert_int_eq(inverse_matrix(&Y, &result2), 0);
  for (int i = 0; i < Y.rows; i++) {
    for (int j = 0; j < Y.columns; j++)
      ck_assert_double_eq_tol(X.matrix[i][j], result2.matrix[i][j], 1e-5);
  }
  remove_matrix(&X);
  remove_matrix(&Y);
  remove_matrix(&result1);
  remove_matrix(&result2);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  ck_assert_int_eq(inverse_matrix(&X, &result), 1);

  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 4, &X);

  ck_assert_int_eq(inverse_matrix(&X, &result), 2);

  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &X);
  X.matrix[0][0] = 1.5;

  ck_assert_int_eq(inverse_matrix(&X, &result), 0);

  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &X);

  ck_assert_int_eq(inverse_matrix(&X, &result), 2);

  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_8) {
  matrix_t X = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &X);

  X.matrix[0][0] = 1.0;
  X.matrix[0][1] = 2.0;
  X.matrix[0][2] = 3.0;

  X.matrix[1][0] = 4.0;
  X.matrix[1][1] = 5.0;
  X.matrix[1][2] = 6.0;

  X.matrix[2][0] = 7.0;
  X.matrix[2][1] = 8.0;
  X.matrix[2][2] = 9.0;

  ck_assert_int_eq(inverse_matrix(&X, &result), 2);

  remove_matrix(&X);
  remove_matrix(&result);
}
END_TEST

Suite *create_matrix(void) {
  Suite *suite = suite_create("ts_create_matrix");
  TCase *test_case = tcase_create("tc_create_matrix");
  tcase_add_test(test_case, create_matrix_1);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *eq_matrix(void) {
  Suite *suite = suite_create("ts_eq_matrix");
  TCase *test_case = tcase_create("tc_eq_matrix");
  tcase_add_test(test_case, eq_matrix_1);
  tcase_add_test(test_case, eq_matrix_2);
  tcase_add_test(test_case, eq_matrix_3);
  tcase_add_test(test_case, eq_matrix_4);
  tcase_add_test(test_case, eq_matrix_5);
  tcase_add_test(test_case, eq_matrix_6);
  tcase_add_test(test_case, eq_matrix_7);
  tcase_add_test(test_case, eq_matrix_8);
  tcase_add_test(test_case, eq_matrix_9);
  tcase_add_test(test_case, eq_matrix_10);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *sum_matrix(void) {
  Suite *suite = suite_create("ts_sum_matrix");
  TCase *test_case = tcase_create("tc_sum_matrix");
  tcase_add_test(test_case, sum_matrix_1);
  tcase_add_test(test_case, sum_matrix_2);
  tcase_add_test(test_case, sum_matrix_3);
  tcase_add_test(test_case, sum_matrix_4);
  tcase_add_test(test_case, sum_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *sub_matrix(void) {
  Suite *suite = suite_create("ts_sub_matrix");
  TCase *test_case = tcase_create("tc_sub_matrix");
  tcase_add_test(test_case, sub_matrix_1);
  tcase_add_test(test_case, sub_matrix_2);
  tcase_add_test(test_case, sub_matrix_3);
  tcase_add_test(test_case, sub_matrix_4);
  tcase_add_test(test_case, sub_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *mult_number(void) {
  Suite *suite = suite_create("ts_mult_number");
  TCase *test_case = tcase_create("tc_mult_number");
  tcase_add_test(test_case, mult_number_0);
  tcase_add_test(test_case, mult_number_1);
  tcase_add_test(test_case, mult_number_2);
  tcase_add_test(test_case, mult_number_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *mult_matrix(void) {
  Suite *suite = suite_create("ts_mult_matrix");
  TCase *test_case = tcase_create("tc_mult_matrix");
  tcase_add_test(test_case, mult_matrix_1);
  tcase_add_test(test_case, mult_matrix_2);
  tcase_add_test(test_case, mult_matrix_3);
  tcase_add_test(test_case, mult_matrix_4);
  tcase_add_test(test_case, mult_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *transpose(void) {
  Suite *suite = suite_create("ts_transpose");
  TCase *test_case = tcase_create("tc_transpose");
  tcase_add_test(test_case, transpose_1);
  tcase_add_test(test_case, transpose_2);
  tcase_add_test(test_case, transpose_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *calc_complements(void) {
  Suite *suite = suite_create("ts_calc_complements");
  TCase *test_case = tcase_create("tc_calc_complements");
  tcase_add_test(test_case, calc_complements_1);
  tcase_add_test(test_case, calc_complements_2);
  tcase_add_test(test_case, calc_complements_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *determinant(void) {
  Suite *suite = suite_create("ts_determinant");
  TCase *test_case = tcase_create("tc_determinant");
  tcase_add_test(test_case, determinant_0);
  tcase_add_test(test_case, determinant_1);
  tcase_add_test(test_case, determinant_2);
  tcase_add_test(test_case, determinant_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *inverse_matrix(void) {
  Suite *suite = suite_create("ts_inverse_matrix");
  TCase *test_case = tcase_create("tc_inverse_matrix");
  tcase_add_test(test_case, inverse_matrix_1);
  tcase_add_test(test_case, inverse_matrix_2);
  tcase_add_test(test_case, inverse_matrix_3);
  tcase_add_test(test_case, inverse_matrix_4);
  tcase_add_test(test_case, inverse_matrix_5);
  tcase_add_test(test_case, inverse_matrix_6);
  tcase_add_test(test_case, inverse_matrix_7);
  tcase_add_test(test_case, inverse_matrix_8);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *test_suites[] = {
      create_matrix(),    eq_matrix(),   sum_matrix(), sub_matrix(),
      mult_number(),      mult_matrix(), transpose(),  inverse_matrix(),
      calc_complements(), determinant(), NULL};
  int failed = 0;

  for (Suite **s = test_suites; *s != NULL; s++) {
    SRunner *runner = srunner_create(*s);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}
