#include "../s21_string.h"

//Возвращает копию строки (str), преобразованной в верхний регистр. В случае
//какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    result = malloc((len_str + 1) * sizeof(char));
    for (s21_size_t i = 0; ((char *)str)[i] != '\0'; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
    }
    result[len_str] = '\0';
  }
  return result;
}
