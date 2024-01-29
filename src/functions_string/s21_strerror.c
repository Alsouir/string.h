// #include <stdio.h>

#include "../s21_string.h"

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.
char* s21_strerror(int errnum) {
  // static char error_message[100];

  static char* error_messages[COUNT_ERRORS] = error;
  static char result[256];
  if (errnum >= 0 && errnum < COUNT_ERRORS) {
    s21_strncpy(result, error_messages[errnum],
                s21_strlen(error_messages[errnum]) + 1);
  } else {
#ifdef __APPLE__
    s21_sprintf(result, "Unknown error: %d", errnum);
#endif

#ifdef __linux__
    s21_sprintf(result, "Unknown error %d", errnum);
#endif
  }
  return result;
}