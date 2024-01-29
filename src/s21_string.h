#ifndef S21_STRING_H
#define S21_STRING_H

// Для функций управления неизвестным количеством переменных
#include <stdarg.h>
// Содержит NULL и size_t
#include <stdlib.h>
#include <wchar.h>

typedef unsigned int s21_size_t;
#define s21_NULL (void *)0
typedef char bool;
#define true 1
#define false 0

#ifdef __APPLE__
#define COUNT_ERRORS 107
#define error                                         \
  {"Undefined error: 0",                              \
   "Operation not permitted",                         \
   "No such file or directory",                       \
   "No such process",                                 \
   "Interrupted system call",                         \
   "Input/output error",                              \
   "Device not configured",                           \
   "Argument list too long",                          \
   "Exec format error",                               \
   "Bad file descriptor",                             \
   "No child processes",                              \
   "Resource deadlock avoided",                       \
   "Cannot allocate memory",                          \
   "Permission denied",                               \
   "Bad address",                                     \
   "Block device required",                           \
   "Resource busy",                                   \
   "File exists",                                     \
   "Cross-device link",                               \
   "Operation not supported by device",               \
   "Not a directory",                                 \
   "Is a directory",                                  \
   "Invalid argument",                                \
   "Too many open files in system",                   \
   "Too many open files",                             \
   "Inappropriate ioctl for device",                  \
   "Text file busy",                                  \
   "File too large",                                  \
   "No space left on device",                         \
   "Illegal seek",                                    \
   "Read-only file system",                           \
   "Too many links",                                  \
   "Broken pipe",                                     \
   "Numerical argument out of domain",                \
   "Result too large",                                \
   "Resource temporarily unavailable",                \
   "Operation now in progress",                       \
   "Operation already in progress",                   \
   "Socket operation on non-socket",                  \
   "Destination address required",                    \
   "Message too long",                                \
   "Protocol wrong type for socket",                  \
   "Protocol not available",                          \
   "Protocol not supported",                          \
   "Socket type not supported",                       \
   "Operation not supported",                         \
   "Protocol family not supported",                   \
   "Address family not supported by protocol family", \
   "Address already in use",                          \
   "Can't assign requested address",                  \
   "Network is down",                                 \
   "Network is unreachable",                          \
   "Network dropped connection on reset",             \
   "Software caused connection abort",                \
   "Connection reset by peer",                        \
   "No buffer space available",                       \
   "Socket is already connected",                     \
   "Socket is not connected",                         \
   "Can't send after socket shutdown",                \
   "Too many references: can't splice",               \
   "Operation timed out",                             \
   "Connection refused",                              \
   "Too many levels of symbolic links",               \
   "File name too long",                              \
   "Host is down",                                    \
   "No route to host",                                \
   "Directory not empty",                             \
   "Too many processes",                              \
   "Too many users",                                  \
   "Disc quota exceeded",                             \
   "Stale NFS file handle",                           \
   "Too many levels of remote in path",               \
   "RPC struct is bad",                               \
   "RPC version wrong",                               \
   "RPC prog. not avail",                             \
   "Program version wrong",                           \
   "Bad procedure for program",                       \
   "No locks available",                              \
   "Function not implemented",                        \
   "Inappropriate file type or format",               \
   "Authentication error",                            \
   "Need authenticator",                              \
   "Device power is off",                             \
   "Device error",                                    \
   "Value too large to be stored in data type",       \
   "Bad executable (or shared library)",              \
   "Bad CPU type in executable",                      \
   "Shared library version mismatch",                 \
   "Malformed Mach-o file",                           \
   "Operation canceled",                              \
   "Identifier removed",                              \
   "No message of desired type",                      \
   "Illegal byte sequence",                           \
   "Attribute not found",                             \
   "Bad message",                                     \
   "EMULTIHOP (Reserved)",                            \
   "No message available on STREAM",                  \
   "ENOLINK (Reserved)",                              \
   "No STREAM resources",                             \
   "Not a STREAM",                                    \
   "Protocol error",                                  \
   "STREAM ioctl timeout",                            \
   "Operation not supported on socket",               \
   "Policy not found",                                \
   "State not recoverable",                           \
   "Previous owner died",                             \
   "Interface output queue is full"};
#endif

#ifdef __linux__
#define COUNT_ERRORS 134
#define error                                           \
  {"Success",                                           \
   "Operation not permitted",                           \
   "No such file or directory",                         \
   "No such process",                                   \
   "Interrupted system call",                           \
   "Input/output error",                                \
   "No such device or address",                         \
   "Argument list too long",                            \
   "Exec format error",                                 \
   "Bad file descriptor",                               \
   "No child processes",                                \
   "Resource temporarily unavailable",                  \
   "Cannot allocate memory",                            \
   "Permission denied",                                 \
   "Bad address",                                       \
   "Block device required",                             \
   "Device or resource busy",                           \
   "File exists",                                       \
   "Invalid cross-device link",                         \
   "No such device",                                    \
   "Not a directory",                                   \
   "Is a directory",                                    \
   "Invalid argument",                                  \
   "Too many open files in system",                     \
   "Too many open files",                               \
   "Inappropriate ioctl for device",                    \
   "Text file busy",                                    \
   "File too large",                                    \
   "No space left on device",                           \
   "Illegal seek",                                      \
   "Read-only file system",                             \
   "Too many links",                                    \
   "Broken pipe",                                       \
   "Numerical argument out of domain",                  \
   "Numerical result out of range",                     \
   "Resource deadlock avoided",                         \
   "File name too long",                                \
   "No locks available",                                \
   "Function not implemented",                          \
   "Directory not empty",                               \
   "Too many levels of symbolic links",                 \
   "Unknown error 41",                                  \
   "No message of desired type",                        \
   "Identifier removed",                                \
   "Channel number out of range",                       \
   "Level 2 not synchronized",                          \
   "Level 3 halted",                                    \
   "Level 3 reset",                                     \
   "Link number out of range",                          \
   "Protocol driver not attached",                      \
   "No CSI structure available",                        \
   "Level 2 halted",                                    \
   "Invalid exchange",                                  \
   "Invalid request descriptor",                        \
   "Exchange full",                                     \
   "No anode",                                          \
   "Invalid request code",                              \
   "Invalid slot",                                      \
   "Unknown error 58",                                  \
   "Bad font file format",                              \
   "Device not a stream",                               \
   "No data available",                                 \
   "Timer expired",                                     \
   "Out of streams resources",                          \
   "Machine is not on the network",                     \
   "Package not installed",                             \
   "Object is remote",                                  \
   "Link has been severed",                             \
   "Advertise error",                                   \
   "Srmount error",                                     \
   "Communication error on send",                       \
   "Protocol error",                                    \
   "Multihop attempted",                                \
   "RFS specific error",                                \
   "Bad message",                                       \
   "Value too large for defined data type",             \
   "Name not unique on network",                        \
   "File descriptor in bad state",                      \
   "Remote address changed",                            \
   "Can not access a needed shared library",            \
   "Accessing a corrupted shared library",              \
   ".lib section in a.out corrupted",                   \
   "Attempting to link in too many shared libraries",   \
   "Cannot exec a shared library directly",             \
   "Invalid or incomplete multibyte or wide character", \
   "Interrupted system call should be restarted",       \
   "Streams pipe error",                                \
   "Too many users",                                    \
   "Socket operation on non-socket",                    \
   "Destination address required",                      \
   "Message too long",                                  \
   "Protocol wrong type for socket",                    \
   "Protocol not available",                            \
   "Protocol not supported",                            \
   "Socket type not supported",                         \
   "Operation not supported",                           \
   "Protocol family not supported",                     \
   "Address family not supported by protocol",          \
   "Address already in use",                            \
   "Cannot assign requested address",                   \
   "Network is down",                                   \
   "Network is unreachable",                            \
   "Network dropped connection on reset",               \
   "Software caused connection abort",                  \
   "Connection reset by peer",                          \
   "No buffer space available",                         \
   "Transport endpoint is already connected",           \
   "Transport endpoint is not connected",               \
   "Cannot send after transport endpoint shutdown",     \
   "Too many references: cannot splice",                \
   "Connection timed out",                              \
   "Connection refused",                                \
   "Host is down",                                      \
   "No route to host",                                  \
   "Operation already in progress",                     \
   "Operation now in progress",                         \
   "Stale file handle",                                 \
   "Structure needs cleaning",                          \
   "Not a XENIX named type file",                       \
   "No XENIX semaphores available",                     \
   "Is a named type file",                              \
   "Remote I/O error",                                  \
   "Disk quota exceeded",                               \
   "No medium found",                                   \
   "Wrong medium type",                                 \
   "Operation canceled",                                \
   "Required key not available",                        \
   "Key has expired",                                   \
   "Key has been revoked",                              \
   "Key was rejected by service",                       \
   "Owner died",                                        \
   "State not recoverable",                             \
   "Operation not possible due to RF-kill",             \
   "Memory page has hardware error"};
#endif

struct specifier_parameters {
  // главное значение спецификатора
  char specifier;

  // 1) При использовании флагов нельзя использовать некоторые спецификаторы
  // 2) Флаги ниже предназначены для отслеживания "доступности" спецификатора
  // 3) Отрицательное - "блокировано", 0 - "доступно", положительное -
  // "используется". В перспективе есть возможноть понять чем блокировано 4) При
  // возникновении ошибки выводится предупреждение и спецификатор выполняется
  // без флага (проверено не на всём)
  int specifier_c;
  int specifier_d;
  int specifier_i;
  int specifier_e;
  int specifier_E;
  int specifier_f;
  int specifier_g;
  int specifier_G;
  int specifier_o;
  int specifier_s;
  int specifier_u;
  int specifier_x;
  int specifier_X;
  int specifier_p;
  int specifier_n;
  int specifier_percent;

  // "Активность" флагов
  // Возможно лучше перейти на bool.
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_sharp;
  int flag_0;
  int flag_size;

  // Параметры ширины и точности
  // ширина
  int width;
  int flag_point;
  // точность
  int accuracy;
  int number_system;

  // Параметр длины числа (h, l, или L)
  char longitude;
};

struct fraction_info {
  // флаг для различия double и long double
  bool is_double;

  // значение дроби
  long double double_number;
  long double long_double_number;

  // Символ числа (+ или -)
  char fraction_sign;

  // Количество символов в целой части
  int length_integer_part;
  // Количество символов в дробной части
  int length_fractional_part;
  // Количество смещений точки. point_offset < 0 при смещении вправо.
  // point_offset > 0 при смещении влево.
  int point_offset;

  // Флаг для записи point_offset
  bool need_write_point_offset;
};

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);
void write_the_parameter_to_a_string(
    char *str, int *intdex_str,
    struct specifier_parameters current_specifier_parameters, va_list factor);

// Функции для чтения спецификатора
void clearing_specifier_parameters(
    struct specifier_parameters *current_specifier_parameters);
void read_specifier(const char **format,
                    struct specifier_parameters *current_specifier_parameters,
                    int *code_error);
void read_flags(const char **format,
                struct specifier_parameters *current_specifier_parameters);
void read_width(const char **format,
                struct specifier_parameters *current_specifier_parameters);
int read_int(const char **format);
void read_accuracy(const char **format,
                   struct specifier_parameters *current_specifier_parameters);
void read_longitude(const char **format,
                    struct specifier_parameters *current_specifier_parameters);
void read_one_specifier(
    const char **format,
    struct specifier_parameters *current_specifier_parameters, int *code_error);

// Записи символов
void write_char(char *str, int *index_str,
                struct specifier_parameters current_specifier_parameters,
                va_list factor);
void write_line(char *str, int *intdex_str,
                struct specifier_parameters current_specifier_parameters,
                va_list factor);
void write_percent(char *str, int *index_str);
char *exact_line(struct specifier_parameters current_specifier_parameters,
                 char *line, int *lenght_new_line, int lenght_line);
int w_strlen(const wchar_t *line);
char get_char(struct specifier_parameters current_specifier_parameters,
              va_list factor);

// Общие вспомогательные функции
void write_extra_width(char *str, int *index_str, char symbol_for_emptiness,
                       int count_symbols);
void create_inverted_int(char (*inverted_int)[20], long long this_int,
                         int *lenght_int);
void write_a_sign(char *str, int *index_str, char symbol,
                  struct specifier_parameters current_specifier_parameters);

// Запись целых чисел
void write_int(char *str, int *index_str,
               struct specifier_parameters current_specifier_parameters,
               va_list factor);
bool define_int(struct specifier_parameters *current_specifier_parameters,
                va_list factor, char (*inverted_int)[20], int *lenght_int);
int calculate_extra_width_for_int(
    struct specifier_parameters current_specifier_parameters, char symbol_int,
    int lack_of_precision, int lenght_int, bool need_write);
void write_number_system(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    long long unsigned int original_number);
void write_a_number_system(
    char *str, int *index,
    struct specifier_parameters current_specifier_parameters,
    int original_number);
char converting_number_to_symbol(
    int number, struct specifier_parameters current_specifier_parameters);
void write_pointer(char *str, int *index_str,
                   struct specifier_parameters current_specifier_parameters,
                   va_list factor);
void write_count_symbols(
    int index_str, struct specifier_parameters current_specifier_parameters,
    va_list factor);
bool need_write_int(struct specifier_parameters current_specifier_parameters,
                    long long int original_number);

// Функции для записи дробей
void converting_fractions_to_scientific_notation(
    struct fraction_info *number_info);
void converting_fractions_to_scientific_notation_double(
    struct fraction_info *number_info);
void converting_fractions_to_scientific_notation_long_double(
    struct fraction_info *number_info);
void write_notation_by_fraction_specifier(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    struct fraction_info *number_info);
int calculate_extra_width_line_fraction(
    struct specifier_parameters current_specifier_parameters,
    struct fraction_info number_info, int lenght_inverted_point_offset);
void write_a_fraction(char *str, int *index_str,
                      struct specifier_parameters current_specifier_parameters,
                      struct fraction_info *number_info, int *extra_width);
void write_integer_part_a_fraction(char *str, int *index_str,
                                   struct fraction_info *number_info,
                                   bool *need_offset);
void write_fractional_part_a_fraction(char *str, int *index_str,
                                      struct fraction_info *number_info,
                                      bool *need_offset);
bool write_digit_fraction(char *str, int *index_str,
                          struct fraction_info *number_info,
                          bool need_rounding);
bool write_digit_fraction_double(char *str, int *index_str,
                                 struct fraction_info *number_info,
                                 bool need_rounding);
bool write_digit_fraction_long_double(char *str, int *index_str,
                                      struct fraction_info *number_info,
                                      bool need_rounding);
void write_point_offset(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters,
    char *inverted_point_offset, int lenght_inverted_point_offset);
struct fraction_info create_fraction_info(
    struct specifier_parameters current_specifier_parameters, va_list factor);
void write_scientific_notation(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters, va_list factor);
void write_fraction(char *str, int *index_str,
                    struct specifier_parameters current_specifier_parameters,
                    va_list factor);
void write_short_fraction(
    char *str, int *index_str,
    struct specifier_parameters current_specifier_parameters, va_list factor);
int find_last_no_zero(struct fraction_info number_info);
bool rounding_with_nine(char *str, int index_str, int length_integer_part,
                        int length_fractional_part,
                        struct fraction_info *number_info);
void rounding_with_nine_fractional_part(char *str, int *index_str,
                                        int length_fractional_part,
                                        bool *need_rounding);
bool rounding_with_nine_integer_part(char *str, int *index_str,
                                     int length_integer_part,
                                     bool *need_rounding,
                                     struct fraction_info *number_info);
void line_offset(char *str, int *index_str,
                 struct specifier_parameters current_specifier_parameters,
                 struct fraction_info *number_info, int *extra_width);
void line_offset_for_g(char *str, int *index_str,
                       struct specifier_parameters current_specifier_parameters,
                       struct fraction_info *number_info, int *extra_width);
void line_offset_for_g_to_left(
    char *str, int *another_index_str, int *count_zero, int *extra_width,
    struct fraction_info *number_info,
    struct specifier_parameters current_specifier_parameters);

// Функции C#
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
