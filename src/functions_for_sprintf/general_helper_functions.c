#include "../s21_string.h"

void write_extra_width(char *str, int *index_str, char symbol_for_emptiness,
                       int count_symbols) {
  for (int i = 0; i < count_symbols; i++) {
    str[*index_str] = symbol_for_emptiness;
    *index_str = *index_str + 1;
  }
}

void create_inverted_int(char (*inverted_int)[20], long long this_int,
                         int *lenght_int) {
  bool need_increased = false;
  (*inverted_int)[0] = '+';
  if (this_int < 0) {
    (*inverted_int)[0] = '-';
    this_int = this_int * (-1);
  }

  if (this_int < 0) {
    this_int = (this_int + 1) * (-1);
    need_increased = true;
  }

  do {
    (*inverted_int)[(1 + (*lenght_int))] = this_int % 10 + '0';
    *lenght_int = *lenght_int + 1;
    this_int = this_int / 10;
  } while (this_int != 0);

  if (need_increased == true) {
    (*inverted_int)[1] = (*inverted_int)[1] + 1;
  }
}

void write_a_sign(char *str, int *index_str, char symbol,
                  struct specifier_parameters current_specifier_parameters) {
  if (symbol == '-' || current_specifier_parameters.flag_plus == 1) {
    str[*index_str] = symbol;
    *index_str = *index_str + 1;
  } else if (current_specifier_parameters.flag_space == 1) {
    str[*index_str] = ' ';
    *index_str = *index_str + 1;
  }
}