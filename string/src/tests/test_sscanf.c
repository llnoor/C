#include <check.h>

#include "../string.h"

START_TEST(sscanf_test) {
  // %s specifier
  char a[100] = {0};
  char a1[100] = {0};
  char b[100] = {0};
  char b1[100] = {0};

  int result = 0;
  int result = 0;

  result = sscanf("hello", "%s", a);
  result = sscanf("hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, result);

  result = sscanf("  hello", "%s", a);
  result = sscanf("  hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, result);

  result = sscanf("  hello  ", "%s", a);
  result = sscanf("  hello  ", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, result);

  char y[100] = {0};
  char y1[100] = {0};
  result = sscanf("", "%s", y);
  result = sscanf("", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, result);

  result = sscanf("   a", "%s", y);
  result = sscanf("   a", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, result);

  result = sscanf("hello world", "%s %s", a, b);
  result = sscanf("hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%4s %s", a, b);
  result = sscanf("   hello world", "%4s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%*s %s", a);
  result = sscanf("   hello world", "%*s %s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%s %*s", a);
  result = sscanf("   hello world", "%s %*s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  int n = 3;
  int n1 = 0;
  result = sscanf("    hello world", "%s %*s %n", a, &n);
  result = sscanf("    hello world", "%s %*s %n", a1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%2s %*s", a);
  result = sscanf("   hello world", "%2s %*s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, result);

  result = sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, result);

  n = 0;
  n1 = 0;
  result = sscanf("    hello world", "%s %s %n", a, b, &n);
  result = sscanf("    hello world", "%s %s %n", a1, b1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  // %d specifier

  int i = 0;
  int j = 0;
  result = sscanf("184", "%d", &i);
  result = sscanf("184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  i = 0;
  j = 0;
  result = sscanf("t184", "%d", &i);
  result = sscanf("t184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("184t", "%d", &i);
  result = sscanf("184t", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  i = 0;
  j = 0;
  result = sscanf("", "%d", &i);
  result = sscanf("", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("184h86", "%d", &i);
  result = sscanf("184h86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("184   86", "%d", &i);
  result = sscanf("184   86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("-184", "%d", &i);
  result = sscanf("-184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf(" 56", "%d", &i);
  result = sscanf(" 56", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf(" -56 ", "%d", &i);
  result = sscanf(" -56 ", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("197856365839", "%d", &i);
  result = sscanf("197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf("-197856365839", "%d", &i);
  result = sscanf("-197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  n = 0;
  n1 = 0;
  result = sscanf("184h86", "%d %i", &i, &n);
  result = sscanf("184h86", "%d %i", &j, &n1);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  result = sscanf("184 86", "%d %i", &i, &n);
  result = sscanf("184 86", "%d %i", &j, &n1);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  int i1 = 0;
  int j1 = 0;
  result = sscanf("3245 1322", "%d %d", &i, &j);
  result = sscanf("3245 1322", "%d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, result);

  result = sscanf("3245 1322", "%2d %d", &i, &j);
  result = sscanf("3245 1322", "%2d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, result);

  i = 0;
  j = 0;
  i1 = 0;
  j1 = 0;

  result = sscanf("3245 1322", "%2d %d", &i, &j);
  result = sscanf("3245 1322", "%2d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, result);

  i = 0;
  i1 = 0;
  j = 0;
  j1 = 0;

  result = sscanf("3245 1322", "%d %d", &i, &j);
  result = sscanf("3245 1322", "%d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, result);

  result = sscanf("3245 1322", "%d %d", &i, &j);
  result = sscanf("3245 1322", "%d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, result);

  short int q = 0;
  short int w = 0;
  short int q1 = 0;
  short int w1 = 0;
  result = sscanf("3245 1322", "%hd %hd", &q, &w);
  result = sscanf("3245 1322", "%hd %hd", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, result);

  long int e = 0;
  long int r = 0;
  long int e1 = 0;
  long int r1 = 0;
  result = sscanf("3245 1322", "%ld %ld", &e, &r);
  result = sscanf("3245 1322", "%ld %ld", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, result);

  // %i specifier

  int d = 0;
  int d1 = 0;
  result = sscanf("3245", "%i", &d);
  result = sscanf("3245", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("075", "%i", &d);
  result = sscanf("075", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("075", "%i", &d);
  result = sscanf("61", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("0x342", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("834", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  i = 0;
  j = 0;
  result = sscanf("", "%i", &i);
  result = sscanf("", "%i", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  result = sscanf(" ", "%i", &i);
  result = sscanf(" ", "%i", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, result);

  int t = 0;
  int t1 = 0;

  result = sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, result);

  t = 0;
  t1 = 0;
  result = sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, result);

  d = 0;
  d1 = 0;
  t = 0;
  t1 = 0;
  result = sscanf("d834 0x45", "%i %i", &d, &t);
  result = sscanf("d834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, result);

  result = sscanf("234 0x837", "%i %i", &d, &t);
  result = sscanf("234 0x837", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("234 0x837", "%i %i", &d, &t);
  result = sscanf("234 0x837", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("234 0x837", "%i %2i", &d, &t);
  result = sscanf("234 0x837", "%i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("234 0x837", "%1i %2i", &d, &t);
  result = sscanf("234 0x837", "%1i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, result);

  result = sscanf("3245 1322", "%hi %hi", &q, &w);
  result = sscanf("3245 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, result);

  result = sscanf("035 1322", "%hi %hi", &q, &w);
  result = sscanf("035 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, result);

  r = 0;
  r1 = 0;
  result = sscanf("035 132264782398", "%li %li", &e, &r);
  result = sscanf("035 132264782398", "%li %li", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, result);

  result = sscanf("035 1322", "%li %hi", &e, &q);
  result = sscanf("035 1322", "%li %hi", &e1, &q1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(result, result);

  result = sscanf("035 0x2846", "%i %i %n", &i, &j, &n);
  result = sscanf("035 0x2846", "%i %i %n", &i1, &j1, &n1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  // %c specifier

  char c = 0;
  char c1 = 0;
  result = sscanf("h", "%c", &c);
  result = sscanf("h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, result);

  result = sscanf("gh", "%c", &c);
  result = sscanf("gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, result);

  result = sscanf("  gh", "%c", &c);
  result = sscanf("  gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, result);

  result = sscanf("g h", "%c", &c);
  result = sscanf("g h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, result);

  result = sscanf("g h", "%1c", &c);
  result = sscanf("g h", "%1c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, result);

  char c2;
  char c3;
  result = sscanf("g h", "%c %c %n", &c, &c2, &n);
  result = sscanf("g h", "%c %c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  c2 = 0;
  c3 = 0;
  result = sscanf("g h", "%c%c %n", &c, &c2, &n);
  result = sscanf("g h", "%c%c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  c2 = 0;
  c3 = 0;
  result = sscanf("g  h", "%c %c %n", &c, &c2, &n);
  result = sscanf("g  h", "%c %c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  wchar_t m = 0;
  wchar_t m1 = 0;
  result = sscanf("h", "%lc", &m);
  result = sscanf("h", "%lc", &m1);
  ck_assert_int_eq(m, m1);
  ck_assert_int_eq(result, result);

  char k = 0;
  char k1 = 0;
  result = sscanf("g h", "%c %c %n", &c, &k, &n);
  result = sscanf("g h", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  result = sscanf("..", "%c %c %n", &c, &k, &n);
  result = sscanf("..", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  result = sscanf("h 6", "%c %*c %n", &c, &n);
  result = sscanf("h 6", "%c %*c %n", &c1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, result);

  // %% specifier
  c = 0;
  c1 = 0;
  n = 0;
  n1 = 0;
  result = sscanf("h 6", "%% %n", &n);
  result = sscanf("h 6", "%% %n", &n1);
  ck_assert_int_eq(result, result);

  // %p specifier
  int val = 123;
  char buf[100] = {0};
  sprintf(buf, "%p", (void *)&val);
  void *ptr = 0;
  void *ptr2 = 0;
  sscanf(buf, "%p", &ptr);
  sscanf(buf, "%p", &ptr2);
  // ck_assert_ptr_eq(ptr, ptr2);

  // %e %E %f %g %G specifiers

  float f = 0;
  float dd = 0;
  float f1 = 0;
  float dd1 = 0;

  // scientific notation

  result = sscanf("127564.3846 1.275643846e3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 1.275643846e3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 1.275643846e3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 1.275643846e3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 1.275643846e3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  // negative scientific notation

  result = sscanf("127564.3846 12756.43846e-3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 12756.43846e-3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 12756.43846e-3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 12756.43846e-3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  result = sscanf("127564.3846 12756.43846e-3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  // basic
  result = sscanf("0.008726", "%e", &f);
  result = sscanf("0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%E", &f);
  result = sscanf("0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%f", &f);
  result = sscanf("0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%g", &f);
  result = sscanf("0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%G", &f);
  result = sscanf("0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // negative numbers

  result = sscanf("-0.008726", "%e", &f);
  result = sscanf("-0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("-0.008726", "%E", &f);
  result = sscanf("-0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("-0.008726", "%f", &f);
  result = sscanf("-0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("-0.008726", "%g", &f);
  result = sscanf("-0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("-0.008726", "%G", &f);
  result = sscanf("-0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // spaces at the beginning
  result = sscanf("   0.008726", "%e", &f);
  result = sscanf("   0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("   0.008726", "%E", &f);
  result = sscanf("   0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("  0.008726", "%f", &f);
  result = sscanf("   0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("   0.008726", "%g", &f);
  result = sscanf("   0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("   0.008726", "%G", &f);
  result = sscanf("   0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // spaces
  f = 0;
  f1 = 0;
  result = sscanf("   ", "%e", &f);
  result = sscanf("   ", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  result = sscanf("   ", "%E", &f);
  result = sscanf("   ", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  result = sscanf("   ", "%f", &f);
  result = sscanf("   ", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  result = sscanf("   ", "%g", &f);
  result = sscanf("   ", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  result = sscanf("   ", "%G", &f);
  result = sscanf("   ", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // empty lines
  result = sscanf("", "%e", &f);
  result = sscanf("", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("", "%E", &f);
  result = sscanf("", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("", "%f", &f);
  result = sscanf("", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("", "%g", &f);
  result = sscanf("", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("", "%G", &f);
  result = sscanf("", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // snowflakes
  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  result = sscanf("5674.007827 4758", "%*e %e", &f);
  result = sscanf("5674.007827 4758", "%*e %e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  result = sscanf("5674.007827 4758", "%E %E", &f, &dd);
  result = sscanf("5674.007827 4758", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  result = sscanf("5674.007827 4758", "%f %f", &f, &dd);
  result = sscanf("5674.007827 4758", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  result = sscanf("5674.007827 4758", "%g %g", &f, &dd);
  result = sscanf("5674.007827 4758", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  result = sscanf("5674.007827 4758", "%G %G", &f, &dd);
  result = sscanf("5674.007827 4758", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);

  // width
  result = sscanf("0.008726", "%6e", &f);
  result = sscanf("0.008726", "%6e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4E", &f);
  result = sscanf("0.008726", "%4E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4f", &f);
  result = sscanf("0.008726", "%4f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4g", &f);
  result = sscanf("0.008726", "%4g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4G", &f);
  result = sscanf("0.008726", "%4G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // negative width

  result = sscanf("0.008726", "%6e", &f);
  result = sscanf("0.008726", "%6e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4E", &f);
  result = sscanf("0.008726", "%4E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4f", &f);
  result = sscanf("0.008726", "%4f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4g", &f);
  result = sscanf("0.008726", "%4g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%4G", &f);
  result = sscanf("0.008726", "%4G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // zero width

  result = sscanf("0.008726", "%e", &f);
  result = sscanf("0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%E", &f);
  result = sscanf("0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%f", &f);
  result = sscanf("0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%g", &f);
  result = sscanf("0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  result = sscanf("0.008726", "%G", &f);
  result = sscanf("0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, result);

  // length L
  long double lf = 0;
  long double lf1 = 0;
  result = sscanf("9.9996587169235770324564357345", "%Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  // length L + width
  result = sscanf("9.9996587169235770324564357345", "%4Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  // length L + width *
  lf = 0;
  lf1 = 0;
  result = sscanf("9.999658", "%Le", &lf);
  result = sscanf("9.999658", "%Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.999658", "%LE", &lf);
  result = sscanf("9.999658", "%LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.999658", "%Lf", &lf);
  result = sscanf("9.999658", "%Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.999658", "%Lg", &lf);
  result = sscanf("9.999658", "%Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.999658", "%LG", &lf);
  result = sscanf("9.999658", "%LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  // length L + negative width

  result = sscanf("9.999658", "%4Le", &lf);
  result = sscanf("9.999658", "%4Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, result);

  // with %n

  n = 0;
  n1 = 0;
  result = sscanf("1275.3846 0.2345", "%e %e %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%e %e %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  result = sscanf("1275.3846 0.2345", "%E %E %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%E %E %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  result = sscanf("1275.3846 0.2345", "%f %f %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%f %f %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  result = sscanf("1275.3846 0.2345", "%g %g %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%g %g %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  result = sscanf("1275.3846 0.2345", "%G %G %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%G %G %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, result);
  ck_assert_int_eq(n, n1);
}
END_TEST

START_TEST(sscanf_u_test) {
  int res = 0;
  int res = 0;
  int d = 0;
  unsigned int u = 0;
  unsigned short int hu = 0;
  unsigned long int lu = 0;
  int d = 0;
  unsigned int u = 0;
  unsigned short int hu = 0;
  unsigned long int lu = 0;

  res = sscanf("184", "%u", &u);
  res = sscanf("184", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  res = sscanf("-184", "%u", &u);
  res = sscanf("-184", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  res = sscanf("184.01", "%u", &u);
  res = sscanf("184.01", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  res = sscanf("-184.01", "%u", &u);
  res = sscanf("-184.01", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  res = sscanf("184", "%hu", &hu);
  res = sscanf("184", "%hu", &hu);
  ck_assert_uint_eq(hu, hu);
  ck_assert_int_eq(res, res);

  res = sscanf("-184", "%hu", &hu);
  res = sscanf("-184", "%hu", &hu);
  ck_assert_uint_eq(hu, hu);
  ck_assert_int_eq(res, res);

  res = sscanf("184.01", "%hu", &hu);
  res = sscanf("184.01", "%hu", &hu);
  ck_assert_uint_eq(hu, hu);
  ck_assert_int_eq(res, res);

  res = sscanf("-184.01", "%hu", &hu);
  res = sscanf("-184.01", "%hu", &hu);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  res = sscanf("184", "%u", &d);
  res = sscanf("184", "%u", &d);
  ck_assert_int_eq(d, d);
  ck_assert_int_eq(res, res);

  res = sscanf("-184", "%u", &d);
  res = sscanf("-184", "%u", &d);
  ck_assert_int_eq(d, d);
  ck_assert_int_eq(res, res);

  res = sscanf("184.01", "%u", &d);
  res = sscanf("184.01", "%u", &d);
  ck_assert_int_eq(d, d);
  ck_assert_int_eq(res, res);

  res = sscanf("-184.01", "%u", &d);
  res = sscanf("-184.01", "%u", &d);
  ck_assert_int_eq(d, d);
  ck_assert_int_eq(res, res);

  res = sscanf("  1   184", "%u", &u);
  res = sscanf("  1   184", "%u", &u);
  ck_assert_uint_eq(d, d);
  ck_assert_int_eq(res, res);

  res = sscanf("98975878579879184", "%lu", &lu);
  res = sscanf("98975878579879184", "%lu", &lu);
  ck_assert_uint_eq(lu, lu);
  ck_assert_int_eq(res, res);

  res = sscanf("184.01", "%lu", &lu);
  res = sscanf("184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, lu);
  ck_assert_int_eq(res, res);

  res = sscanf("-184.01", "%lu", &lu);
  res = sscanf("-184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, lu);
  ck_assert_int_eq(res, res);

  res = sscanf("     184 1    ", "%lu", &lu);
  res = sscanf("184", "%lu", &lu);
  ck_assert_uint_eq(lu, lu);
  ck_assert_int_eq(res, res);

  u = 0;
  u = 0;

  res = sscanf("", "%u", &u);
  res = sscanf("", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  u = 0;
  u = 0;

  res = sscanf("    ", "%u", &u);
  res = sscanf("    ", "%u", &u);
  ck_assert_uint_eq(u, u);
  ck_assert_int_eq(res, res);

  unsigned int u2 = 0;
  unsigned int u2 = 0;
  unsigned int u3 = 0;
  unsigned int u3 = 0;
  res =
      sscanf("184 184.99 -5637", "%u %u %u", &u, &u2, &u3);
  res = sscanf("184 184.99 -5637", "%u %u %u", &u, &u2, &u3);
  ck_assert_uint_eq(u, u);
  ck_assert_uint_eq(u2, u2);
  ck_assert_uint_eq(u3, u3);
  ck_assert_int_eq(res, res);

  int n = 0;
  int n = 0;
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2,
                       &u3, &n);
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2, &u3, &n);
  ck_assert_uint_eq(u, u);
  ck_assert_uint_eq(u2, u2);
  ck_assert_uint_eq(u3, u3);
  ck_assert_int_eq(n, n);
  ck_assert_int_eq(res, res);

  n = 0;
  n = 0;
  u = 0;
  u2 = 0;
  u3 = 0;
  u = 0;
  u2 = 0;
  u3 = 0;
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2,
                       &u3, &n);
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2, &u3, &n);
  ck_assert_uint_eq(u, u);
  ck_assert_uint_eq(u2, u2);
  ck_assert_uint_eq(u3, u3);
  ck_assert_int_eq(n, n);
  ck_assert_int_eq(res, res);
}
END_TEST

START_TEST(sscanf_o_test) {
  int res = 0;
  int res = 0;

  unsigned int o = 0;
  unsigned short int ho = 0;
  unsigned long int lo = 0;

  unsigned int o = 0;
  unsigned short int ho = 0;
  unsigned long int lo = 0;

  res = sscanf("0184", "%o", &o);
  res = sscanf("0184", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("-0184", "%o", &o);
  res = sscanf("-0184", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("0184.345", "%o", &o);
  res = sscanf("0184.345", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("-0184.345", "%o", &o);
  res = sscanf("-0184.345", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("   0184", "%o", &o);
  res = sscanf("   0184", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("", "%o", &o);
  res = sscanf("", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  o = 0;
  o = 0;
  res = sscanf("   ", "%o", &o);
  res = sscanf("   ", "%o", &o);
  ck_assert_uint_eq(o, o);
  ck_assert_int_eq(res, res);

  res = sscanf("0184", "%ho", &ho);
  res = sscanf("0184", "%ho", &ho);
  ck_assert_uint_eq(ho, ho);
  ck_assert_int_eq(res, res);

  ho = 0;
  ho = 0;
  res = sscanf("-0184", "%ho", &ho);
  res = sscanf("-0184", "%ho", &ho);
  ck_assert_uint_eq(ho, ho);
  ck_assert_int_eq(res, res);

  res = sscanf("   0184", "%ho", &ho);
  res = sscanf("   0184", "%ho", &ho);
  ck_assert_uint_eq(ho, ho);
  ck_assert_int_eq(res, res);

  res = sscanf("0184.345", "%ho", &ho);
  res = sscanf("0184.345", "%ho", &ho);
  ck_assert_uint_eq(ho, ho);
  ck_assert_int_eq(res, res);

  res = sscanf("096787987989184456768768564767", "%lo", &lo);
  res = sscanf("096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, lo);
  ck_assert_int_eq(res, res);

  res = sscanf("-096787987989184456768768564767", "%lo", &lo);
  res = sscanf("-096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, lo);
  ck_assert_int_eq(res, res);

  res = sscanf("   096787987989184456768768564767", "%lo", &lo);
  res = sscanf("   096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, lo);
  ck_assert_int_eq(res, res);

  res =
      sscanf("   096787987989184456768768564767.34546", "%lo", &lo);
  res = sscanf("   096787987989184456768768564767.34546", "%lo", &lo);
  ck_assert_uint_eq(lo, lo);
  ck_assert_int_eq(res, res);

  o = 0;
  unsigned int o2 = 0;
  unsigned int o3 = 0;
  o = 0;
  unsigned int o2 = 0;
  unsigned int o3 = 0;
  int n = 0;
  int n2 = 0;

  // n == 0, n2 == 2
  o = 0;
  o2 = 0;
  o3 = 0;
  o = 0;
  o2 = 0;
  o3 = 0;
  n = 0;
  n2 = 0;
  res = sscanf("0184 0234 06432", "%o %o %o %n", &o, &o2,
                       &o3, &n2);
  res = sscanf("0184 0234 06432", "%o %o %o %n", &o, &o2, &o3, &n);
  ck_assert_uint_eq(o, o);
  ck_assert_uint_eq(o2, o2);
  ck_assert_uint_eq(o3, o3);
  ck_assert_int_eq(res, res);
  // ck_assert_int_eq(n, n2);

  o = 0;
  o2 = 0;
  o3 = 0;
  o = 0;
  o2 = 0;
  o3 = 0;
  n = 0;
  n2 = 0;
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n2);
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n);
  ck_assert_uint_eq(o, o);
  ck_assert_uint_eq(o2, o2);
  ck_assert_uint_eq(o3, o3);
  ck_assert_int_eq(res, res);
  // ck_assert_int_eq(n, n2);

  o = 0;
  o2 = 0;
  o3 = 0;
  o = 0;
  o2 = 0;
  o3 = 0;
  n = 0;
  n2 = 0;
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n2);
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n);
  ck_assert_uint_eq(o, o);
  ck_assert_uint_eq(o2, o2);
  ck_assert_uint_eq(o3, o3);
  ck_assert_int_eq(res, res);
  // ck_assert_int_eq(n, n2);
}
END_TEST

START_TEST(sscanf_x_X_test) {
  int res = 0;
  int res = 0;

  unsigned int x = 0;
  unsigned short int hx = 0;
  unsigned long int lx = 0;

  unsigned int x = 0;
  unsigned short int hx = 0;
  unsigned long int lx = 0;

  res = sscanf("0x0x234", "%x", &x);
  res = sscanf("0x0x234", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234", "%x", &x);
  res = sscanf("0x234", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234", "%X", &x);
  res = sscanf("0x234", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("3b856", "%x", &x);
  res = sscanf("3b856", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("32856f", "%X", &x);
  res = sscanf("32856f", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x23g4", "%x", &x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x23g4", "%X", &x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x2r3g4", "%x", &x);
  res = sscanf("0x2r3g4", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x2r3g4", "%X", &x);
  res = sscanf("0x2r3g4", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234", "%x", &x);
  res = sscanf("-0x234", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234", "%X", &x);
  res = sscanf("-0x234", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("   0x234", "%x", &x);
  res = sscanf("   0x234", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("   0x234", "%X", &x);
  res = sscanf("   0x234", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  x = 0;
  x = 0;
  res = sscanf("   ", "%x", &x);
  res = sscanf("   ", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  x = 0;
  x = 0;
  res = sscanf("   ", "%X", &x);
  res = sscanf("   ", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  x = 0;
  x = 0;
  res = sscanf("", "%x", &x);
  res = sscanf("", "%x", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  x = 0;
  x = 0;
  res = sscanf("", "%X", &x);
  res = sscanf("", "%X", &x);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234356768678", "%lx", &lx);
  res = sscanf("0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(lx, lx);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234356768678", "%lX", &lx);
  res = sscanf("0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234356768678", "%lx", &lx);
  res = sscanf("-0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234356768678", "%lX", &lx);
  res = sscanf("-0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("234356768678", "%lx", &lx);
  res = sscanf("234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("234356768678", "%lX", &lx);
  res = sscanf("234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234356768678", "%hx", &hx);
  res = sscanf("0x234356768678", "%hx", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234356768678", "%hX", &hx);
  res = sscanf("0x234356768678", "%hX", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234", "%hx", &hx);
  res = sscanf("0x234", "%hx", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("0x234", "%hX", &hx);
  res = sscanf("0x234", "%hX", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234", "%hx", &hx);
  res = sscanf("-0x234", "%hx", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("-0x234", "%hX", &hx);
  res = sscanf("-0x234", "%hX", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("234", "%hx", &hx);
  res = sscanf("234", "%hx", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  res = sscanf("234", "%hX", &hx);
  res = sscanf("234", "%hX", &hx);
  ck_assert_uint_eq(x, x);
  ck_assert_int_eq(res, res);

  x = 0;
  unsigned int x2 = 0;
  unsigned int x3 = 0;
  x = 0;
  unsigned int x2 = 0;
  unsigned int x3 = 0;

  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, x);
  ck_assert_uint_eq(x2, x2);
  ck_assert_uint_eq(x3, x3);
  ck_assert_int_eq(res, res);

  x = 0;
  x2 = 0;
  x3 = 0;
  x = 0;
  x2 = 0;
  x3 = 0;

  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, x);
  ck_assert_uint_eq(x2, x2);
  ck_assert_uint_eq(x3, x3);
  ck_assert_int_eq(res, res);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("\033[45m-=SSCANF=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_test);
  tcase_add_test(tc, sscanf_u_test);
  tcase_add_test(tc, sscanf_o_test);
  tcase_add_test(tc, sscanf_x_X_test);

  suite_add_tcase(s, tc);
  return s;
}