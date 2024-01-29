#include "../s21_string.h"

// Добавление символа в строку
void write_char(char *str, int *index_str,
                struct specifier_parameters current_specifier_parameters,
                va_list factor) {
  char symbol_for_width = ' ';
  if (current_specifier_parameters.flag_0 == 1 &&
      current_specifier_parameters.flag_minus == 0) {
    symbol_for_width = '0';
  }

  int extra_width = current_specifier_parameters.width - 1;
  if (current_specifier_parameters.flag_minus == 0) {
    write_extra_width(str, index_str, symbol_for_width, extra_width);
    str[*index_str] = get_char(current_specifier_parameters, factor);
    *index_str = *index_str + 1;
  } else {
    str[*index_str] = get_char(current_specifier_parameters, factor);
    *index_str = *index_str + 1;
    write_extra_width(str, index_str, symbol_for_width, extra_width);
  }
}

// Добавление строки в строку
void write_line(char *str, int *index_str,
                struct specifier_parameters current_specifier_parameters,
                va_list factor) {
  int lenght_line;
  char *new_line;
  int lenght_new_line = 0;
  if (current_specifier_parameters.longitude == 'l') {
    wchar_t *line1 = va_arg(factor, wchar_t *);
    lenght_line = w_strlen(line1);
    char line2[lenght_line];
    for (int i = 0; i < lenght_line; i++) {
      line2[i] = (char)line1[i];
    }
    new_line = exact_line(current_specifier_parameters, line2, &lenght_new_line,
                          lenght_line);
  } else {
    char *line = va_arg(factor, char *);
    if (line == s21_NULL) {
      line = "(null)";
    }
    lenght_line = s21_strlen(line);
    new_line = exact_line(current_specifier_parameters, line, &lenght_new_line,
                          lenght_line);
  }
  if (current_specifier_parameters.width < (int)s21_strlen(new_line)) {
    current_specifier_parameters.width = s21_strlen(new_line);
  }
  int width = current_specifier_parameters.width - (int)s21_strlen(new_line);
  // Ширина слева
  if (current_specifier_parameters.flag_minus != 1) {
    if (current_specifier_parameters.flag_0 == 1) {
      write_extra_width(str, index_str, '0', width);
    } else {
      write_extra_width(str, index_str, ' ', width);
    }
  }
  for (int i = 0; i < lenght_new_line; i++) {
    str[*index_str] = new_line[i];
    *index_str = *index_str + 1;
  }
  // Ширина справа
  if (current_specifier_parameters.flag_minus == 1) {
    write_extra_width(str, index_str, ' ', width);
  }
  free(new_line);
}

// Добавление '%' в строку
void write_percent(char *str, int *index_str) {
  str[*index_str] = '%';
  *index_str = *index_str + 1;
}

int w_strlen(const wchar_t *line) {
  const wchar_t *s;
  for (s = line; *s; ++s) {
  }
  return (s - line);
}

char *exact_line(struct specifier_parameters current_specifier_parameters,
                 char *line, int *lenght_new_line, int lenght_line) {
  char *new_line;
  if (current_specifier_parameters.flag_point == 1 &&
      current_specifier_parameters.accuracy < lenght_line) {
    *lenght_new_line = current_specifier_parameters.accuracy;
    new_line =
        malloc((current_specifier_parameters.accuracy + 1) * sizeof(char));
    for (int i = 0; i < *lenght_new_line; i++) {
      new_line[i] = line[i];
    }
  } else {
    *lenght_new_line = lenght_line;
    new_line = malloc((*lenght_new_line + 1) * sizeof(char));
    for (int i = 0; i < *lenght_new_line; i++) {
      new_line[i] = line[i];
    }
  }
  new_line[*lenght_new_line] = '\0';
  return new_line;
}

char get_char(struct specifier_parameters current_specifier_parameters,
              va_list factor) {
  char result;

  if (current_specifier_parameters.longitude == 'l') {
    result = (char)(va_arg(factor, wchar_t));
  } else {
    result = va_arg(factor, int);
  }

  return result;
}