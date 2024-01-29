#include "../s21_string.h"

void clearing_specifier_parameters(
    struct specifier_parameters *current_specifier_parameters) {
  current_specifier_parameters->specifier = '\0';

  current_specifier_parameters->specifier_c = 0;
  current_specifier_parameters->specifier_d = 0;
  current_specifier_parameters->specifier_i = 0;
  current_specifier_parameters->specifier_e = 0;
  current_specifier_parameters->specifier_E = 0;
  current_specifier_parameters->specifier_f = 0;
  current_specifier_parameters->specifier_g = 0;
  current_specifier_parameters->specifier_G = 0;
  current_specifier_parameters->specifier_o = 0;
  current_specifier_parameters->specifier_s = 0;
  current_specifier_parameters->specifier_u = 0;
  current_specifier_parameters->specifier_x = 0;
  current_specifier_parameters->specifier_X = 0;
  current_specifier_parameters->specifier_p = 0;
  current_specifier_parameters->specifier_n = 0;
  current_specifier_parameters->specifier_percent = 0;

  current_specifier_parameters->flag_minus = 0;
  current_specifier_parameters->flag_plus = 0;
  current_specifier_parameters->flag_space = 0;
  current_specifier_parameters->flag_sharp = 0;
  current_specifier_parameters->flag_0 = 0;
  current_specifier_parameters->flag_size = 0;

  current_specifier_parameters->width = 0;
  current_specifier_parameters->flag_point = 0;
  current_specifier_parameters->accuracy = 6;

  current_specifier_parameters->longitude = '\0';
}

void read_specifier(const char **format,
                    struct specifier_parameters *current_specifier_parameters,
                    int *code_error) {
  //%[флаги][ширина][.точность][длина]спецификатор
  read_flags(format, current_specifier_parameters);
  read_width(format, current_specifier_parameters);
  read_accuracy(format, current_specifier_parameters);
  read_longitude(format, current_specifier_parameters);
  read_one_specifier(format, current_specifier_parameters, code_error);
}

// Считывание флага
void read_flags(const char **format,
                struct specifier_parameters *current_specifier_parameters) {
  bool finish_read = false;
  while (finish_read == false) {
    switch (**format) {
      case '-':
        current_specifier_parameters->flag_minus = 1;
        break;
      case '+':
        current_specifier_parameters->flag_plus = 1;
        break;
      case ' ':
        current_specifier_parameters->flag_space = 1;
        break;
      case '#':
        current_specifier_parameters->flag_sharp = 1;
        break;
      case '0':
        current_specifier_parameters->flag_0 = 1;
        break;
      default:
        finish_read = true;
    }
    if (finish_read == false) {
      *format = *format + 1;
    }
  }
}

// Считывание ширины
void read_width(const char **format,
                struct specifier_parameters *current_specifier_parameters) {
  if (**format == '*') {
    current_specifier_parameters->width = -1;
    *format = *format + 1;
    current_specifier_parameters->specifier_n = -1;
    current_specifier_parameters->specifier_percent = -1;
  } else {
    int new_width = read_int(format);
    ;
    current_specifier_parameters->width = new_width;
    if (new_width != 0) {
      current_specifier_parameters->specifier_n = -1;
      current_specifier_parameters->specifier_percent = -1;
    }
  }
}

// Считывание числа из фломата
int read_int(const char **format) {
  int result = 0;
  while (**format >= '0' && **format <= '9') {
    result = result * 10 + (**format - '0');
    *format = *format + 1;
  }
  return result;
}

// Считывание точности
void read_accuracy(const char **format,
                   struct specifier_parameters *current_specifier_parameters) {
  if (**format == '.') {
    current_specifier_parameters->flag_point = 1;
    current_specifier_parameters->accuracy = 0;
    *format = *format + 1;
    if (**format == '*') {
      current_specifier_parameters->accuracy = -1;
      *format = *format + 1;
    } else {
      current_specifier_parameters->accuracy = read_int(format);
    }
    current_specifier_parameters->specifier_c = -1;
    current_specifier_parameters->specifier_p = -1;
    current_specifier_parameters->specifier_n = -1;
    current_specifier_parameters->specifier_percent = -1;
  }
}

// Считывание "длины"
void read_longitude(const char **format,
                    struct specifier_parameters *current_specifier_parameters) {
  bool finish_read = false;
  while (finish_read == false) {
    switch (**format) {
      case 'h':
        current_specifier_parameters->longitude = **format;
        current_specifier_parameters->specifier_c = -1;
        current_specifier_parameters->specifier_e = -1;
        current_specifier_parameters->specifier_E = -1;
        current_specifier_parameters->specifier_f = -1;
        current_specifier_parameters->specifier_g = -1;
        current_specifier_parameters->specifier_G = -1;
        current_specifier_parameters->specifier_s = -1;
        current_specifier_parameters->specifier_p = -1;
        current_specifier_parameters->specifier_percent = -1;
        break;
      case 'l':
        current_specifier_parameters->longitude = **format;
        current_specifier_parameters->specifier_p = -1;
        current_specifier_parameters->specifier_percent = -1;
        break;
      case 'L':
        current_specifier_parameters->longitude = **format;
        current_specifier_parameters->specifier_c = -1;
        current_specifier_parameters->specifier_s = -1;
        current_specifier_parameters->specifier_p = -1;
        current_specifier_parameters->specifier_n = -1;
        current_specifier_parameters->specifier_percent = -1;
        break;
      default:
        finish_read = true;
    }
    if (finish_read == false) {
      *format = *format + 1;
    }
  }
}

// Считывание спецификатора
void read_one_specifier(
    const char **format,
    struct specifier_parameters *current_specifier_parameters,
    int *code_error) {
  if (**format == 'c' || **format == 'd' || **format == 'i' ||
      **format == 'e' || **format == 'E' || **format == 'f' ||
      **format == 'g' || **format == 'G' || **format == 'o' ||
      **format == 's' || **format == 'u' || **format == 'x' ||
      **format == 'X' || **format == 'p' || **format == 'n' ||
      **format == '%') {
    current_specifier_parameters->specifier = **format;
    current_specifier_parameters->flag_size = -1;
    if (**format == 'u') {
      current_specifier_parameters->number_system = 10;
    }
    if (**format == 'o') {
      current_specifier_parameters->number_system = 8;
    }
    if (**format == 'x') {
      current_specifier_parameters->number_system = 16;
    }
    if (**format == 'X') {
      current_specifier_parameters->number_system = 16;
      current_specifier_parameters->flag_size = 1;
    }
  } else {
    *code_error = 1;
  }
}