#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;  //
  int code_error = 0;
  struct specifier_parameters current_specifier_parameters;
  va_list factor;            //указатель va_list
  va_start(factor, format);  // устанавливаем указатель

  for (; *format && code_error == 0; format++) {
    if (*format != '%') {
      str[result] = *format;
      result++;
    } else {
      clearing_specifier_parameters(&current_specifier_parameters);
      format++;
      //Читаем спецификатор
      read_specifier(&format, &current_specifier_parameters, &code_error);
      if (current_specifier_parameters.width == -1) {
        current_specifier_parameters.width = va_arg(factor, int);
      }
      if (current_specifier_parameters.accuracy == -1) {
        current_specifier_parameters.accuracy = va_arg(factor, int);
      }
      // Дополнительно (наверно не нужно): обработка сочетаний флагов
      // спецификаторов и т.д. для вывода ошибок
      if (code_error == 0) {
        //Пишем в строку параметр на основе информации спецификатора
        write_the_parameter_to_a_string(str, &result,
                                        current_specifier_parameters, factor);
      }
    }
  }
  str[result] = '\0';
  va_end(factor);  // завершаем обработку параметров
  return result;
}

void write_the_parameter_to_a_string(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters, va_list factor) {
  switch (current_specifier_parameters.specifier) {
    case 'c':
      write_char(str, index_str, current_specifier_parameters, factor);
      break;
    case 'd':
    case 'i':
      write_int(str, index_str, current_specifier_parameters, factor);
      break;
    case 'e':
    case 'E':
      write_scientific_notation(str, index_str, current_specifier_parameters,
                                factor);
      break;
    case 'f':
      write_fraction(str, index_str, current_specifier_parameters, factor);
      break;
    case 'g':
    case 'G':
      write_short_fraction(str, index_str, current_specifier_parameters,
                           factor);
      break;
    case 's':
      write_line(str, index_str, current_specifier_parameters, factor);
      break;
    case 'u':
    case 'o':
    case 'x':
    case 'X':
      write_number_system(str, index_str, current_specifier_parameters,
                          va_arg(factor, long long unsigned int));
      break;
    case 'p':
      write_pointer(str, index_str, current_specifier_parameters, factor);
      break;
    case 'n':
      write_count_symbols(*index_str, current_specifier_parameters, factor);
      break;
    case '%':
      write_percent(str, index_str);
      break;
  }
}