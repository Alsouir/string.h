#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src != s21_NULL) {
    s21_size_t first_not_space = 0;
    s21_size_t last_not_space = 0;
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_trim_chars;
    if (trim_chars != s21_NULL) len_trim_chars = s21_strlen(trim_chars);
    for (s21_size_t i = 0; i < len_src; i++) {
      if (((src[i] != ' ' && src[0] != ' ') ||
           (src[i] != ' ' && src[len_src] != ' '))) {
        if (first_not_space == 0) {
          first_not_space = i;
        }
        last_not_space = i;
      }
    }
    if (len_trim_chars == 0 || trim_chars == s21_NULL) {
      first_not_space = 0;
      last_not_space = len_src - 1;
    }
    result = malloc((last_not_space - first_not_space + 1 + 1) * sizeof(char));
    s21_size_t index_result = 0;
    if (last_not_space != first_not_space ||
        (last_not_space == first_not_space && src[first_not_space] != ' ')) {
      for (s21_size_t i = first_not_space; i < last_not_space + 2; i++) {
        char string[2];
        string[0] = *src;
        string[1] = '\0';
        if (s21_strpbrk(trim_chars, string) == s21_NULL ||
            trim_chars == s21_NULL) {
          result[index_result] = *src;
          index_result++;
        }
        src++;
      }
    }
    result[index_result] = '\0';
  }
  return result;
}
