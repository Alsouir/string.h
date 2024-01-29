#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != s21_NULL && src != s21_NULL) {
    s21_size_t i = 0;
    for (; i < n; i++) {
      ((char *)dest)[i] = ((char *)src)[i];
    }
  }
  return dest;
}