#include "../s21_string.h"

void converting_fractions_to_scientific_notation(
    struct fraction_info *number_info) {
  number_info->point_offset = 0;
  if (number_info->is_double == true) {
    converting_fractions_to_scientific_notation_double(number_info);
  } else {
    converting_fractions_to_scientific_notation_long_double(number_info);
  }
}

void converting_fractions_to_scientific_notation_double(
    struct fraction_info *number_info) {
  if (number_info->double_number >= 0) {
    number_info->fraction_sign = '+';
  } else {
    number_info->fraction_sign = '-';
    number_info->double_number = number_info->double_number * (-1.0);
  }

  while (number_info->double_number >= 10 && number_info->double_number != 0) {
    number_info->point_offset = number_info->point_offset + 1;
    number_info->double_number = number_info->double_number / 10;
  }

  while (number_info->double_number < 1 && number_info->double_number != 0) {
    number_info->point_offset = number_info->point_offset - 1;
    number_info->double_number = number_info->double_number * 10;
  }
}

void converting_fractions_to_scientific_notation_long_double(
    struct fraction_info *number_info) {
  if (number_info->long_double_number >= 0) {
    number_info->fraction_sign = '+';
  } else {
    number_info->fraction_sign = '-';
    number_info->long_double_number = number_info->long_double_number * (-1.0);
  }

  while (number_info->long_double_number >= 10 &&
         number_info->long_double_number != 0) {
    number_info->point_offset = number_info->point_offset + 1;
    number_info->long_double_number = number_info->long_double_number / 10;
  }

  while (number_info->long_double_number < 1 &&
         number_info->long_double_number != 0) {
    number_info->point_offset = number_info->point_offset - 1;
    number_info->long_double_number = number_info->long_double_number * 10;
  }
}

// Добавить запись в строку по спецификаторам: e(E), f, g(G)
void write_notation_by_fraction_specifier(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    struct fraction_info *number_info) {
  char inverted_point_offset[20];
  int lenght_inverted_point_offset = 0;
  create_inverted_int(&inverted_point_offset, number_info->point_offset,
                      &lenght_inverted_point_offset);

  int extra_width = calculate_extra_width_line_fraction(
      current_specifier_parameters, *number_info, lenght_inverted_point_offset);

  // Ширина слева ' '
  if (current_specifier_parameters.flag_minus == 0 &&
      current_specifier_parameters.flag_0 == 0) {
    write_extra_width(str, index_str, ' ', extra_width);
  }

  write_a_fraction(str, index_str, current_specifier_parameters, number_info,
                   &extra_width);
  lenght_inverted_point_offset = 0;
  create_inverted_int(&inverted_point_offset, number_info->point_offset,
                      &lenght_inverted_point_offset);

  if (number_info->need_write_point_offset == true) {
    write_point_offset(str, index_str, current_specifier_parameters,
                       inverted_point_offset, lenght_inverted_point_offset);
  }

  // ширина справа ' '
  if (current_specifier_parameters.flag_minus == 1) {
    write_extra_width(str, index_str, ' ', extra_width);
  }
}

int calculate_extra_width_line_fraction(
    struct specifier_parameters current_specifier_parameters,
    struct fraction_info number_info, int lenght_inverted_point_offset) {
  // вычитается целая и дробная часть числа
  int extra_width = current_specifier_parameters.width -
                    (number_info.length_integer_part) -
                    (number_info.length_fractional_part);
  // вычитается точка дроби
  if (number_info.length_fractional_part > 0 ||
      current_specifier_parameters.flag_sharp == 1) {
    extra_width--;
  }
  // вычитается знак перед дробью
  if (current_specifier_parameters.flag_plus == 1 ||
      current_specifier_parameters.flag_space == 1 ||
      number_info.fraction_sign == '-') {
    extra_width--;
  }
  // вычитается место для символов e(E) и +(-)
  if (number_info.need_write_point_offset == true) {
    extra_width = extra_width - 2;
  }
  // вычитается длина степени
  if (number_info.need_write_point_offset == true) {
    if (lenght_inverted_point_offset < 2) {
      extra_width = extra_width - 2;
    } else {
      extra_width = extra_width - lenght_inverted_point_offset;
    }
  }
  return extra_width;
}

// Записать в строку дробное число
void write_a_fraction(char *str, int *index_str,
                      struct specifier_parameters current_specifier_parameters,
                      struct fraction_info *number_info, int *extra_width) {
  bool need_offset = false;
  // знак перед числом ('+', '-', ' ')
  write_a_sign(str, index_str, number_info->fraction_sign,
               current_specifier_parameters);

  // Ширина слева '0'
  if (current_specifier_parameters.flag_minus == 0 &&
      current_specifier_parameters.flag_0 == 1) {
    write_extra_width(str, index_str, '0', *extra_width);
  }

  // Целая часть
  write_integer_part_a_fraction(str, index_str, number_info, &need_offset);
  // Точка
  if (number_info->length_fractional_part > 0 ||
      current_specifier_parameters.flag_sharp == 1) {
    str[*index_str] = '.';
    *index_str = *index_str + 1;
  }
  // Дробная часть
  write_fractional_part_a_fraction(str, index_str, number_info, &need_offset);
  if (need_offset == true) {
    line_offset(str, index_str, current_specifier_parameters, number_info,
                extra_width);
  }
  if (current_specifier_parameters.specifier == 'g' ||
      current_specifier_parameters.specifier == 'G') {
    line_offset_for_g(str, index_str, current_specifier_parameters, number_info,
                      extra_width);
  }
}

void write_integer_part_a_fraction(char *str, int *index_str,
                                   struct fraction_info *number_info,
                                   bool *need_offset) {
  for (int i = 0; i < number_info->length_integer_part; i++) {
    if (i == number_info->length_integer_part - 1 &&
        number_info->length_fractional_part == 0) {
      if (write_digit_fraction(str, index_str, number_info, true) == true)
        *need_offset =
            rounding_with_nine(str, *index_str, i + 1, 0, number_info);
    } else {
      write_digit_fraction(str, index_str, number_info, false);
    }
  }
}

void write_fractional_part_a_fraction(char *str, int *index_str,
                                      struct fraction_info *number_info,
                                      bool *need_offset) {
  for (int i = 0; i < number_info->length_fractional_part; i++) {
    if (i == number_info->length_fractional_part - 1) {
      if (write_digit_fraction(str, index_str, number_info, true) == true)
        *need_offset = rounding_with_nine(str, *index_str,
                                          number_info->length_integer_part,
                                          i + 1, number_info);
    } else {
      write_digit_fraction(str, index_str, number_info, false);
    }
  }
}

// Записать цифру из дроби
bool write_digit_fraction(char *str, int *index_str,
                          struct fraction_info *number_info,
                          bool need_rounding) {
  bool need_rounding_with_nine = false;
  if (number_info->is_double == true) {
    need_rounding_with_nine =
        write_digit_fraction_double(str, index_str, number_info, need_rounding);
  } else {
    need_rounding_with_nine = write_digit_fraction_long_double(
        str, index_str, number_info, need_rounding);
  }

  *index_str = *index_str + 1;
  return need_rounding_with_nine;
}

bool write_digit_fraction_double(char *str, int *index_str,
                                 struct fraction_info *number_info,
                                 bool need_rounding) {
  bool need_rounding_with_nine = false;
  if (number_info->need_write_point_offset == false &&
      number_info->point_offset < 0) {
    if (number_info->point_offset < -1) {
      need_rounding = false;
    }
    number_info->point_offset = number_info->point_offset + 1;
    str[*index_str] = '0';
  } else {
    str[*index_str] = (int)(number_info->double_number) + '0';
    number_info->double_number = (number_info->double_number) * 10 -
                                 ((int)(number_info->double_number) * 10);
  }
  if (need_rounding == true && (int)(number_info->double_number) >= 5 &&
      str[*index_str] != '9') {
    str[*index_str] = str[*index_str] + 1;
  } else if (need_rounding == true && (int)(number_info->double_number) >= 5 &&
             str[*index_str] == '9') {
    need_rounding_with_nine = true;
  }
  return need_rounding_with_nine;
}

bool write_digit_fraction_long_double(char *str, int *index_str,
                                      struct fraction_info *number_info,
                                      bool need_rounding) {
  bool need_rounding_with_nine = false;
  if (number_info->need_write_point_offset == false &&
      number_info->point_offset < 0) {
    if (number_info->point_offset < -1) {
      need_rounding = false;
    }
    number_info->point_offset = number_info->point_offset + 1;
    str[*index_str] = '0';
  } else {
    str[*index_str] = (int)(number_info->long_double_number) + '0';
    number_info->long_double_number =
        (number_info->long_double_number) * 10 -
        ((int)(number_info->long_double_number) * 10);
  }
  if (need_rounding == true && (int)(number_info->long_double_number) >= 5 &&
      str[*index_str] != '9') {
    str[*index_str] = str[*index_str] + 1;
  } else if (need_rounding == true &&
             (int)(number_info->long_double_number) >= 5 &&
             str[*index_str] == '9') {
    need_rounding_with_nine = true;
  }
  return need_rounding_with_nine;
}

void write_point_offset(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    char *inverted_point_offset, int lenght_inverted_point_offset) {
  // символ e(E)
  if (current_specifier_parameters.specifier == 'e' ||
      current_specifier_parameters.specifier == 'g') {
    str[*index_str] = 'e';
  } else if (current_specifier_parameters.specifier == 'E' ||
             current_specifier_parameters.specifier == 'G') {
    str[*index_str] = 'E';
  }
  *index_str = *index_str + 1;

  // Знак +(-) перед степенью
  str[*index_str] = inverted_point_offset[0];
  *index_str = *index_str + 1;

  // Степень
  if (lenght_inverted_point_offset < 2) {
    str[*index_str] = '0';
    *index_str = *index_str + 1;
    str[*index_str] = inverted_point_offset[1];
    *index_str = *index_str + 1;
  } else {
    for (int i = 0; i < lenght_inverted_point_offset; i++) {
      str[*index_str] = inverted_point_offset[lenght_inverted_point_offset - i];
      *index_str = *index_str + 1;
    }
  }
}

struct fraction_info create_fraction_info(
    struct specifier_parameters current_specifier_parameters, va_list factor) {
  struct fraction_info number_info;
  if (current_specifier_parameters.longitude == 'L') {
    number_info.is_double = false;
    number_info.long_double_number = va_arg(factor, long double);
  } else {
    number_info.is_double = true;
    number_info.double_number = va_arg(factor, double);
  }
  return number_info;
}

// Обработка флага e(E)
void write_scientific_notation(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters, va_list factor) {
  struct fraction_info number_info =
      create_fraction_info(current_specifier_parameters, factor);
  converting_fractions_to_scientific_notation(&number_info);

  number_info.length_integer_part = 1;
  number_info.length_fractional_part = current_specifier_parameters.accuracy;
  number_info.need_write_point_offset = true;

  write_notation_by_fraction_specifier(
      str, index_str, current_specifier_parameters, &number_info);
}

// Обработка флага f
void write_fraction(char *str, int *index_str,
                    struct specifier_parameters current_specifier_parameters,
                    va_list factor) {
  struct fraction_info number_info =
      create_fraction_info(current_specifier_parameters, factor);
  converting_fractions_to_scientific_notation(&number_info);

  if (number_info.point_offset >= 0) {
    number_info.length_integer_part = 1 + number_info.point_offset;
    number_info.length_fractional_part = current_specifier_parameters.accuracy;
  } else {
    number_info.length_integer_part = 1;
    number_info.length_fractional_part = current_specifier_parameters.accuracy;
  }
  number_info.need_write_point_offset = false;

  write_notation_by_fraction_specifier(
      str, index_str, current_specifier_parameters, &number_info);
}

// Обработка флага g(G)
void write_short_fraction(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters, va_list factor) {
  struct fraction_info number_info =
      create_fraction_info(current_specifier_parameters, factor);
  converting_fractions_to_scientific_notation(&number_info);

  if (number_info.point_offset <= -5) {
    number_info.length_integer_part = 1;
    number_info.length_fractional_part =
        current_specifier_parameters.accuracy - 1;
    number_info.need_write_point_offset = true;
  } else if (number_info.point_offset >= -4 && number_info.point_offset <= 0) {
    number_info.length_integer_part = 1;
    number_info.length_fractional_part = -1 * number_info.point_offset;
    if (current_specifier_parameters.accuracy > 0) {
      number_info.length_fractional_part =
          number_info.length_fractional_part +
          (current_specifier_parameters.accuracy - 1);
    }
    number_info.need_write_point_offset = false;
  } else if (current_specifier_parameters.accuracy -
                 (number_info.point_offset + 1) <
             0) {
    number_info.length_integer_part = 1;
    number_info.length_fractional_part =
        current_specifier_parameters.accuracy - 1;
    number_info.need_write_point_offset = true;
  } else {
    number_info.length_integer_part = 1 + number_info.point_offset;
    number_info.length_fractional_part =
        current_specifier_parameters.accuracy - (1 + number_info.point_offset);
    number_info.need_write_point_offset = false;
  }
  number_info.length_fractional_part = find_last_no_zero(number_info);

  write_notation_by_fraction_specifier(
      str, index_str, current_specifier_parameters, &number_info);
}

int find_last_no_zero(struct fraction_info number_info) {
  int result = 0;
  if (number_info.need_write_point_offset == false &&
      number_info.point_offset < 0) {
    number_info.length_integer_part =
        number_info.length_integer_part - number_info.point_offset;
    number_info.length_fractional_part =
        number_info.length_fractional_part + number_info.point_offset;
  }

  if (number_info.is_double == true) {
    for (int i = 0; i < number_info.length_integer_part; i++) {
      number_info.double_number = (number_info.double_number) * 10 -
                                  ((int)(number_info.double_number) * 10);
    }
    for (int i = 0; i < number_info.length_fractional_part; i++) {
      if ((int)(number_info.double_number) != 0) {
        result = i + 1;
      }
      number_info.double_number = (number_info.double_number) * 10 -
                                  ((int)(number_info.double_number) * 10);
    }
  } else {
    for (int i = 0; i < number_info.length_integer_part; i++) {
      number_info.long_double_number =
          (number_info.long_double_number) * 10 -
          ((int)(number_info.long_double_number) * 10);
    }
    for (int i = 0; i < number_info.length_fractional_part; i++) {
      if ((int)(number_info.long_double_number) != 0) {
        result = i + 1;
      }
      number_info.long_double_number =
          (number_info.long_double_number) * 10 -
          ((int)(number_info.long_double_number) * 10);
    }
  }

  return result;
}

bool rounding_with_nine(char *str, int index_str, int length_integer_part,
                        int length_fractional_part,
                        struct fraction_info *number_info) {
  bool need_offset = false;
  bool need_rounding = true;
  index_str--;

  rounding_with_nine_fractional_part(str, &index_str, length_fractional_part,
                                     &need_rounding);

  if (need_rounding == true && str[index_str] == '.') {
    index_str--;
  }
  need_offset = rounding_with_nine_integer_part(
      str, &index_str, length_integer_part, &need_rounding, number_info);
  return need_offset;
}

void rounding_with_nine_fractional_part(char *str, int *index_str,
                                        int length_fractional_part,
                                        bool *need_rounding) {
  int i = 0;
  while (*need_rounding == true && i < length_fractional_part) {
    if (str[*index_str] == '9') {
      str[*index_str] = '0';
      *index_str = *index_str - 1;
    } else {
      str[*index_str] = str[*index_str] + 1;
      *need_rounding = false;
    }
    i++;
  }
}

bool rounding_with_nine_integer_part(char *str, int *index_str,
                                     int length_integer_part,
                                     bool *need_rounding,
                                     struct fraction_info *number_info) {
  bool need_offset = false;
  int i = 0;
  while (*need_rounding == true && i < length_integer_part) {
    if (str[*index_str] == '9') {
      if (i == length_integer_part - 1 &&
          number_info->need_write_point_offset == 1) {
        str[*index_str] = '1';
        number_info->point_offset = number_info->point_offset + 1;
      } else {
        str[*index_str] = '0';
      }
      if (i == length_integer_part - 1 &&
          number_info->need_write_point_offset == false) {
        need_offset = true;
      }
      *index_str = *index_str - 1;
    } else {
      str[*index_str] = str[*index_str] + 1;
      *need_rounding = false;
    }
    i++;
  }
  return need_offset;
}

void line_offset(char *str, int *index_str,
                 struct specifier_parameters current_specifier_parameters,
                 struct fraction_info *number_info, int *extra_width) {
  if (*extra_width > 0 && current_specifier_parameters.flag_minus == 0) {
    int index_for_one = *index_str - 1 - number_info->length_integer_part -
                        number_info->length_fractional_part;
    if (number_info->length_fractional_part > 0 ||
        current_specifier_parameters.flag_sharp == 1) {
      index_for_one--;
    }
    if (str[index_for_one] != '0') {
      str[index_for_one - 1] = str[index_for_one];
    }
    str[index_for_one] = '1';
  } else {
    int count_sympols_for_offset =
        number_info->length_integer_part + number_info->length_fractional_part;
    if (number_info->length_fractional_part > 0 ||
        current_specifier_parameters.flag_sharp == 1) {
      count_sympols_for_offset++;
    }
    for (int i = 0, j = *index_str; i < count_sympols_for_offset; i++, j--) {
      str[j] = str[j - 1];
    }
    str[*index_str - count_sympols_for_offset] = '1';
    *index_str = *index_str + 1;
  }
  *extra_width = *extra_width - 1;
}

void line_offset_for_g(char *str, int *index_str,
                       struct specifier_parameters current_specifier_parameters,
                       struct fraction_info *number_info, int *extra_width) {
  int count_zero = 0;
  int another_index_str = *index_str - 1;
  while ((str[another_index_str] == '0' &&
          count_zero < number_info->length_fractional_part &&
          current_specifier_parameters.flag_sharp == 0) ||
         (current_specifier_parameters.flag_sharp == 1 &&
          str[another_index_str] == '0' &&
          number_info->length_fractional_part +
                  number_info->length_integer_part - count_zero >
              current_specifier_parameters.accuracy)) {
    count_zero++;
    another_index_str = another_index_str - 1;
  }
  *extra_width = *extra_width + count_zero;
  if (*extra_width > 0 && current_specifier_parameters.flag_minus == 0) {
    line_offset_for_g_to_left(str, &another_index_str, &count_zero, extra_width,
                              number_info, current_specifier_parameters);
  } else {
    if (str[another_index_str] == '.' &&
        number_info->length_fractional_part - count_zero == 0 &&
        current_specifier_parameters.flag_sharp == 0) {
      *index_str = another_index_str;
    } else {
      *index_str = another_index_str + 1;
    }
  }
}

void line_offset_for_g_to_left(
    char *str, int *another_index_str, int *count_zero, int *extra_width,
    struct fraction_info *number_info,
    struct specifier_parameters current_specifier_parameters) {
  for (int i = 0; i < (number_info->length_fractional_part - *count_zero);
       i++) {
    str[*another_index_str + *count_zero] = str[*another_index_str];
    *another_index_str = *another_index_str - 1;
  }
  if (str[*another_index_str] == '.') {
    if (number_info->length_fractional_part - *count_zero > 0 ||
        current_specifier_parameters.flag_sharp == 1) {
      str[*another_index_str + *count_zero] = str[*another_index_str];
    } else {
      *extra_width = *extra_width + 1;
      *count_zero = *count_zero + 1;
    }
    *another_index_str = *another_index_str - 1;
  }
  for (int i = 0; (i < number_info->length_integer_part &&
                   number_info->need_write_point_offset == 1) ||
                  (i < number_info->length_integer_part + 1 &&
                   number_info->need_write_point_offset == 0);
       i++) {
    str[*another_index_str + *count_zero] = str[*another_index_str];
    *another_index_str = *another_index_str - 1;
  }
  if (current_specifier_parameters.flag_0 == 1) {
    *another_index_str = *another_index_str + 1;
    write_extra_width(str, another_index_str, '0', *count_zero);
    // *another_index_str = *another_index_str - 1;
  }
  if (str[*another_index_str + *count_zero] == '-' ||
      current_specifier_parameters.flag_plus == 1 ||
      current_specifier_parameters.flag_space == 1) {
    str[*another_index_str + *count_zero] = str[*another_index_str];
  }
  if (current_specifier_parameters.flag_0 == 0) {
    // *another_index_str = *another_index_str - (*extra_width - *count_zero);
    *another_index_str = *another_index_str + 1;
    write_extra_width(str, another_index_str, ' ', *count_zero);
  }
}