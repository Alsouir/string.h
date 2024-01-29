#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (int i = 0; str1[i] != '\0' && result == s21_NULL; i++) {
      for (int j = 0; str2[j] != '\0' && result == s21_NULL; j++) {
        if (str1[i] == str2[j]) result = (char *)(str1 + i);
      }
    }
  }
  return result;
}
