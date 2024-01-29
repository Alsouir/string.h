#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    if (len_src >= start_index) {
      s21_size_t len_str = s21_strlen(str);
      result = malloc((len_src + len_str + 1) * sizeof(char));
      s21_size_t i = 0;
      for (; i < start_index; i++) {
        result[i] = (src[i]);
      }
      for (s21_size_t j = 0; j < len_str; j++, i++) {
        result[i] = (str[j]);
      }
      for (s21_size_t j = start_index; j < len_src; j++, i++) {
        result[i] = (src[j]);
      }
      if (len_src == 0 && len_str == 0) {
        result[0] = '\0';
      } else {
        result[len_src + len_str] = '\0';
      }
    }
  }
  return result;
}
