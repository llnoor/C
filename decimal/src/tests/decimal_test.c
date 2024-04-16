#include "decimal_test.h"

int main(void) {
  int failed = 0;
  Suite *decimal_test[] = {test_add(),
                               test_div(),
                               test_sub(),
                               test_mul(),
                               test_is_less(),
                               test_is_equal(),
                               test_is_less_or_equal(),
                               test_is_greater(),
                               test_is_greater_or_equal(),
                               test_is_not_equal(),
                               test_round(),
                               test_truncate(),
                               test_negate(),
                               test_floor(),
                               test_from_decimal_to_float(),
                               test_from_decimal_to_int(),
                               test_from_float_to_decimal(),
                               test_from_int_to_decimal(),
                               NULL};

  for (int i = 0; decimal_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}