#include "../s21_string.h"

//Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest != s21_NULL && src != s21_NULL) {
    s21_size_t i = 0;
    while (i < n && ((char *)src)[i] != '\0') {
      ((char *)dest)[i] = ((char *)src)[i];
      i++;
    }
    for (; i < n; i++) {
      dest[i] = '\0';
    }
  } else
    dest = s21_NULL;
  return dest;
}
