#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *true_str = s21_NULL;
  if (str != s21_NULL) {
    true_str = str;
  }
  char *result = s21_NULL;
  if (true_str != s21_NULL && *true_str != '\0') {
    char *start_string = true_str;
    while (s21_strchr(delim, *start_string) && *start_string != '\0') {
      start_string++;
    }
    if (*start_string != '\0') {
      result = start_string;
      while (*start_string && (s21_strchr(delim, *start_string) == s21_NULL)) {
        start_string++;
      }
      if (*start_string == '\0') {
        true_str = start_string;
      } else {
        *start_string = '\0';
        true_str = start_string + 1;
      }
    }

  } else {
    true_str = s21_NULL;
  }
  return result;
}