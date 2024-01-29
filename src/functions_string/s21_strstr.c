#include "../s21_string.h"

//Находит первое вхождение всей строки needle (не включая завершающий нулевой
//символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;

  if (haystack != 0 && needle != 0) {
    for (int i = 0; haystack[i] != '\0' && result == s21_NULL; i++) {
      int flag = 1;
      for (int j = 0; needle[j] != '\0' && flag == 1; j++) {
        if (haystack[i + j] == needle[j]) {
          flag = 1;
        } else {
          flag = 0;
        }
      }
      if (flag == 1) result = (char *)(haystack + i);
    }
    if (s21_strlen(haystack) == 0 && s21_strlen(needle) == 0) {
      result = (char *)haystack;
    }
  }
  return result;
}
