#include "3d_tests.h"

int main() {
  Suite *tests[] = {move_tests(), scale_tests(), rotate_tests(),
                        parse_tests(), NULL};

  int failed = 0;
  for (int i = 0; tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(tests[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}