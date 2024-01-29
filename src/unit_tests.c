#include "unit_tests.h"

int main() {
  Suite *suite_list[] = {test_memchr(),   test_memcpy(),   test_strncat(),
                         test_strncmp(),  test_strcspn(),  test_strlen(),
                         test_strrchr(),  test_strtok(),   test_memcmp(),
                         test_memset(),   test_strchr(),   test_strncpy(),
                         test_strerror(), test_strpbrk(),  test_strstr(),
                         test_sprintf(),  test_to_upper(), test_to_lower(),
                         test_insert(),   test_trim(),     NULL};

  for (int i = 0; suite_list[i] != NULL; i++) {
    SRunner *suite_runner = srunner_create(suite_list[i]);

    srunner_run_all(suite_runner, CK_NORMAL);

    srunner_free(suite_runner);
  }
  return 0;
}