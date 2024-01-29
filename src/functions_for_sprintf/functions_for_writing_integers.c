#include "../s21_string.h"

void write_int(char *str, int *index_str,
               struct specifier_parameters current_specifier_parameters,
               va_list factor) {
  int lenght_int = 0;
  int lack_of_precision = 0;
  // Первый символ для знака.
  char inverted_int[20];
  bool need_write = define_int(&current_specifier_parameters, factor,
                               &inverted_int, &lenght_int);

  lack_of_precision = current_specifier_parameters.accuracy - lenght_int;
  int extra_width = calculate_extra_width_for_int(
      current_specifier_parameters, inverted_int[0], lack_of_precision,
      lenght_int, need_write);

  char symbol_for_emptiness = ' ';
  if (current_specifier_parameters.flag_0 == 1 &&
      current_specifier_parameters.flag_minus == 0 &&
      current_specifier_parameters.flag_point == 0) {
    symbol_for_emptiness = '0';
  }

  // ширина слева
  if (current_specifier_parameters.flag_minus == 0 &&
      !(symbol_for_emptiness == '0' &&
        (current_specifier_parameters.flag_sharp == 1 ||
         inverted_int[0] == '-' ||
         current_specifier_parameters.flag_space == 1))) {
    write_extra_width(str, index_str, symbol_for_emptiness, extra_width);
  }
  // знак перед числом (+ - ' ')
  write_a_sign(str, index_str, inverted_int[0], current_specifier_parameters);
  // ширина слева
  if (symbol_for_emptiness == '0' &&
      (current_specifier_parameters.flag_sharp == 1 || inverted_int[0] == '-' ||
       current_specifier_parameters.flag_space == 1)) {
    write_extra_width(str, index_str, symbol_for_emptiness, extra_width);
  }
  // Недостающая точность числа
  write_extra_width(str, index_str, '0', lack_of_precision);
  // Само число
  if (need_write == true) {
    for (int i = 0; i < lenght_int; i++) {
      str[*index_str] =
          inverted_int[lenght_int -
                       i];  // lenght_int - точное количество цифр, но -1 не
                            // нужен из-за знака в 0-ом индексе в inverted_int;
      *index_str = *index_str + 1;
    }
  }
  // ширина справа
  if (current_specifier_parameters.flag_minus == 1) {
    write_extra_width(str, index_str, symbol_for_emptiness, extra_width);
  }
}

bool define_int(struct specifier_parameters *current_specifier_parameters,
                va_list factor, char (*inverted_int)[20], int *lenght_int) {
  bool need_write = true;
  if (current_specifier_parameters->flag_point == 0) {
    current_specifier_parameters->accuracy = 0;
  }

  if (current_specifier_parameters->longitude == 'L') {
    long long this_int = va_arg(factor, long long);
    need_write = need_write_int(*current_specifier_parameters, this_int);
    create_inverted_int(inverted_int, this_int, lenght_int);
  } else if (current_specifier_parameters->longitude == 'l') {
    long this_int = va_arg(factor, long);
    need_write = need_write_int(*current_specifier_parameters, this_int);
    create_inverted_int(inverted_int, this_int, lenght_int);
  } else {
    int this_int = va_arg(factor, int);
    need_write = need_write_int(*current_specifier_parameters, this_int);
    create_inverted_int(inverted_int, this_int, lenght_int);
  }
  return need_write;
}

int calculate_extra_width_for_int(
    struct specifier_parameters current_specifier_parameters, char symbol_int,
    int lack_of_precision, int lenght_int, bool need_write) {
  int extra_width = current_specifier_parameters.width;
  if (current_specifier_parameters.flag_space == 1 ||
      current_specifier_parameters.flag_plus == 1 || symbol_int == '-') {
    extra_width = extra_width - 1;
  }
  if (lack_of_precision > 0) {
    extra_width = extra_width - lack_of_precision;
  }
  if (need_write) {
    extra_width = extra_width - lenght_int;
  }
  return extra_width;
}

void write_number_system(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    long long unsigned int original_number) {
  char buffer[1000];
  int i = 0;
  long long unsigned int copy_number = original_number;

  if (copy_number == 0 && current_specifier_parameters.flag_point != 1) {
    buffer[i] = '0';
    i++;
  }
  //в обратном порядке
  while (copy_number != 0) {
    int number = copy_number % current_specifier_parameters.number_system;
    buffer[i] =
        converting_number_to_symbol(number, current_specifier_parameters);
    i++;
    copy_number /= current_specifier_parameters.number_system;
  }

#ifdef __linux__
  if ((current_specifier_parameters.flag_plus == 1 ||
       current_specifier_parameters.flag_space == 1) &&
      current_specifier_parameters.specifier == 'p') {
    write_a_sign(str, index_str, '+', current_specifier_parameters);
    current_specifier_parameters.width = current_specifier_parameters.width - 1;
  }
#endif
  // дописываем нули до точности
  if (current_specifier_parameters.accuracy - i > 0 &&
      current_specifier_parameters.flag_point == 1) {
    int print_0 = current_specifier_parameters.accuracy;
    if (current_specifier_parameters.flag_sharp == 1 &&
        current_specifier_parameters.number_system == 8) {
      print_0--;
    }
    write_extra_width(buffer, &i, '0', print_0 - i);
  }
  // для 8 и 16 системы дописываем 0 или 0x если включен #
  write_a_number_system(buffer, &i, current_specifier_parameters,
                        original_number);
  // ширина слева
  while (current_specifier_parameters.flag_minus == 0 &&
         i < current_specifier_parameters.width) {
    if (current_specifier_parameters.flag_0 == 1) {
      buffer[i] = '0';
    } else {
      buffer[i] = ' ';
    }
    i++;
  }
  // Недостающая точность;
  for (int j = i - 1; j >= 0; j--) {
    str[*index_str] = buffer[j];
    *index_str = *index_str + 1;
  }
  while (current_specifier_parameters.flag_minus == 1 &&
         i < current_specifier_parameters.width) {
    str[*index_str] = ' ';
    *index_str = *index_str + 1;
    current_specifier_parameters.width = current_specifier_parameters.width - 1;
  }
}

void write_a_number_system(
    char *str, int *index,
    struct specifier_parameters current_specifier_parameters,
    int original_number) {
  if (current_specifier_parameters.flag_sharp == 1 &&
      current_specifier_parameters.number_system == 8 && original_number != 0) {
    str[*index] = '0';
    *index = *index + 1;
  } else if (current_specifier_parameters.flag_sharp == 1 &&
             current_specifier_parameters.number_system == 16 &&
             current_specifier_parameters.flag_size == 1 &&
             original_number != 0) {
    str[*index] = 'X';
    *index = *index + 1;
    str[*index] = '0';
    *index = *index + 1;
  } else if ((current_specifier_parameters.flag_sharp == 1 &&
              current_specifier_parameters.number_system == 16 &&
              original_number != 0) ||
             current_specifier_parameters.specifier == 'p') {
    str[*index] = 'x';
    *index = *index + 1;
    str[*index] = '0';
    *index = *index + 1;
  }
}

char converting_number_to_symbol(
    int number, struct specifier_parameters current_specifier_parameters) {
  char result;
  if (number >= 0 && number <= 9) {
    result = '0' + number;
  } else if (number >= 10 && number <= 15 &&
             current_specifier_parameters.flag_size != 1) {
    result = 'a' + number - 10;
  } else if (number >= 10 && number <= 15 &&
             current_specifier_parameters.flag_size == 1) {
    result = 'A' + number - 10;
  }
  return result;
}

void write_pointer(char *str, int *index_str,
                   struct specifier_parameters current_specifier_parameters,
                   va_list factor) {
  current_specifier_parameters.number_system = 16;
  write_number_system(str, index_str, current_specifier_parameters,
                      va_arg(factor, long long unsigned int));
}

void write_count_symbols(
    int index_str, struct specifier_parameters current_specifier_parameters,
    va_list factor) {
  switch (current_specifier_parameters.longitude) {
    case 'h':
      *va_arg(factor, short int *) = index_str;
      break;
    case 'l':
      *va_arg(factor, long int *) = index_str;
      break;
    default:
      *va_arg(factor, int *) = index_str;
      break;
  }
}

bool need_write_int(struct specifier_parameters current_specifier_parameters,
                    long long int original_number) {
  bool result = true;
  if (original_number == 0 && current_specifier_parameters.flag_point == 1 &&
      current_specifier_parameters.accuracy == 0) {
    result = false;
  }
  return result;
}