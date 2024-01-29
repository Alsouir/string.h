#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  bool match_found = false;
  for (s21_size_t i = 0; i < len_str1; i++) {
    match_found = false;
    for (s21_size_t j = 0; j < len_str2; j++) {
      if (str1[i] == str2[j]) {
        match_found = true;
      }
    }
    if (match_found) {
      break;
    }
    result++;
  }
  return result;
}