#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
typedef struct {
  int minus;
  int plus;
  int space;
  int sharp;
  int null;
  int width;
  int precision;
  char length;
  char spec;
} Flags;
char *double_to_string(long double num, Flags *flags);

int radix(char c);
void cat(int *i, char *str, char const *result, Flags flags, int null);
void s21_round(char *string);
char *wchar_to_str(wchar_t *str, Flags flags);
char *width(Flags flags, char *string);
const char *str_to_int(const char *format, int *digit);
char *int_to_str(unsigned long int num, int radix, Flags flags);
const char *s21_parser(const char *format, Flags *flags, va_list arg);
void pars_num(Flags flags, unsigned long int *num, int *sign, char *s);
char *double_to_string(long double num, Flags *flags);
int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  int i = 0;
  for (; *format != '\0'; format++, i++) {
    int null = 0;
    if (*format != '%') {
      str[i] = *format;
    } else {
      Flags flags = {0, 0, 0, 0, 0, 0, -1, ' ', ' '};
      format = s21_parser(format, &flags, arg);
      if (flags.spec == 'n') {
        int *d = va_arg(arg, int *);
        *d = i;
      } else {
        char *result = 0;
        if (flags.spec == 'f' || flags.spec == 'e' || flags.spec == 'E' ||
            flags.spec == 'g' || flags.spec == 'G') {
          long double num = 0;
          if (flags.length == 'L')
            num = va_arg(arg, long double);
          else
            num = va_arg(arg, double);

          result = double_to_string(num, &flags);
        } else if (flags.spec == 'x' || flags.spec == 'X' ||
                   flags.spec == 'p' || flags.spec == 'u' ||
                   flags.spec == 'd' || flags.spec == 'i' ||
                   flags.spec == 'o') {
          unsigned long int digit = va_arg(arg, unsigned long int);
          result = int_to_str(digit, radix(flags.spec), flags);
        } else if (flags.spec == 's') {
          if (flags.length == 'l') {
            wchar_t *raw_result = va_arg(arg, wchar_t *);
            result = wchar_to_str(raw_result, flags);
          } else {
            char *raw_result = va_arg(arg, char *);
            if (raw_result != 0) {
              if (flags.precision > -1) {
                result = calloc(flags.precision + 1, sizeof(char));
                s21_strncpy(result, raw_result, flags.precision);
              } else {
                result = calloc(s21_strlen(raw_result) + 1, sizeof(char));
                s21_strcpy(result, raw_result);
              }
            } else {
              result = calloc(1, sizeof(char));
              *result = '\0';
            }
          }
        } else if (flags.spec == 'c') {
          result = calloc(2, sizeof(char));
          *result = (char)va_arg(arg, int);
          if (*result == 0) null = 1;
          result[1] = (char)'\0';
        } else if (flags.spec == '%') {
          result = calloc(2, sizeof(char));
          *result = '%';
          result[1] = (char)'\0';
        }
        result = width(flags, result);
        cat(&i, str, result, flags, null);
        free(result);
      }
    }
  }
  str[i] = '\0';
  va_end(arg);
  return i;
}
char *wchar_to_str(wchar_t *str, Flags flags) {
  char *result = 0;
  int len = 0;
  for (; str[len] != '\0'; len++)
    ;
  if (flags.precision == -1) flags.precision = len;
  result = malloc(len + 1);
  for (int i = 0; i < flags.precision; i++) {
    result[i] = str[i];
  }
  return result;
}
const char *s21_parser(const char *format, Flags *flags, va_list arg) {
  format++;
  char len[] = "hlL";
  char spec[] = "cdieEfgGosuxXpn%";
  while (1) {
    if (*format == '0')
      flags->null = 1;
    else if (*format == '-')
      flags->minus = 1;
    else if (*format == '+')
      flags->plus = 1;
    else if (*format == '#')
      flags->sharp = 1;
    else if (*format == ' ')
      flags->space = 1;
    else {
      break;
    }
    format++;
  }
  if (flags->minus) flags->null = 0;
  if (*format == '*') {
    flags->width = va_arg(arg, int);
    format++;
  }
  if (*format > 48 && *format < 58) {
    format = str_to_int(format, &flags->width);
  }
  if (*format == '.') {
    format++;
    if (*format == '*') {
      flags->precision = va_arg(arg, int);
      format++;
    } else
      format = str_to_int(format, &flags->precision);
  }
  for (int i = 0; i < 3; i++) {
    if (*format == len[i]) {
      flags->length = *format;
      format++;
      break;
    }
  }
  for (int i = 0; i < 16; i++) {
    if (*format == spec[i]) {
      flags->spec = *format;
      break;
    }
  }
  return format;
}

const char *str_to_int(const char *format, int *digit) {
  int result = 0;
  for (; *format > 47 && *format < 58; format++) {
    result = result * 10 + (*format - 48);
  }
  *digit = result;
  return format;
}

char *width(Flags flags, char *string) {
  char *result = 0;
  int length = s21_strlen(string);
  int length2 = length;
  // if (*string = '\0' && flags)
  if (length < flags.width) {
    result = calloc(flags.width + 1, sizeof(char));
    int a = ((*string == '-' || *string == '+' || *string == ' ') &&
             (flags.spec != 's' || flags.spec != 'c')) &&
            flags.null;
    for (int i = 0; i < flags.width; i++) {
      char c = ' ';
      if (flags.null) c = '0';
      if (flags.minus) length2 = flags.width;
      result[i] = c;
    }
    for (int j = 0; j < length; j++) {
      result[j + (flags.width - length2)] = string[j];
      if (a && j == 0) {
        result[0] = string[0];
        result[j + (flags.width - length2)] = '0';
      }
    }
    free(string);
  } else {
    result = string;
  }
  return result;
}

char *int_to_str(unsigned long int num, int radix, Flags flags) {
  int j = 0;
  char str[100];
  int sharp_for_o = 1;
  int sign = 0;
  char s = '-';
  pars_num(flags, &num, &sign, &s);
  if (num == 0 && flags.precision != 0) {
    str[0] = '0';
    j = 1;
  }
  while (num != 0) {
    if (num % radix < 10)
      str[j] = num % radix + 48;
    else
      str[j] = (num % radix) + (flags.spec == 'X' ? 55 : 87);
    j++;
    num /= radix;
  }
  str[j + 1] = '\0';
  char *result = 0;
  if (flags.precision > j) {
    sharp_for_o = 0;
    result = calloc(flags.precision + sign + 1, sizeof(char));
    for (int i = 0 + sign; i < flags.precision + sign; i++) result[i] = '0';
  } else {
    result = calloc(j + 1 + sign, sizeof(char));
    flags.precision = j;
  }
  if (sign) result[0] = s;
  for (int i = 0; i < j; i++) {
    result[flags.precision - j + i + sign] = str[j - i - 1];
  }
  result[flags.precision + sign] = '\0';
  if ((flags.sharp &&
       (flags.spec == 'x' || flags.spec == 'X' || flags.spec == 'p' ||
        (flags.spec == 'o' && sharp_for_o))) ||
      flags.spec == 'p') {
    char *res_sharp =
        calloc(s21_strlen(result) + (flags.spec == 'o' ? 2 : 3), sizeof(char));
    if (flags.spec == 'o') {
      s21_strcpy(res_sharp, "0");
    } else
      s21_strcpy(res_sharp, flags.spec == 'X' ? "0X" : "0x");
    s21_strcat(res_sharp, result);
    free(result);
    result = res_sharp;
  }

  return result;
}

void pars_num(Flags flags, unsigned long int *num, int *sign, char *s) {
  if (flags.length == 'h' && flags.spec != 'p')
    *num = (unsigned short int)*num;
  else if (flags.length != 'l' && flags.spec != 'p')
    *num = (unsigned int)*num;
  if ((flags.spec == 'd' || flags.spec == 'i')) {
    long int int_num;
    if (flags.length == 'h')
      int_num = (short int)*num;
    else if (flags.length == 'l')
      int_num = (long int)*num;
    else
      int_num = (int)*num;
    *num = int_num;
    if (int_num < 0) {
      int_num *= -1;
      *num = int_num;
      *sign = 1;
    }
    if (!*sign && flags.space) *s = ' ';
    if (!*sign && flags.plus) *s = '+';
    if (flags.plus || flags.space) *sign = 1;
  }
}

int radix(char c) {
  int radix = 0;
  if (c == 'x' || c == 'X' || c == 'p')
    radix = 16;
  else if (c == 'o')
    radix = 8;
  else if (c == 'u' || c == 'd' || c == 'i')
    radix = 10;
  return radix;
}

char *double_to_string(long double num, Flags *flags) {
  Flags int_flags = {0, flags->plus, flags->space, 0, 0, 0, -1, ' ', 'd'};
  char *e_result = 0;
  if (flags->precision == -1) flags->precision = 6;
  int e = 0;
  if ((flags->spec == 'e' || flags->spec == 'E')) {
    while (num < 10 && num > -10 && num != 0) {
      num *= 10;
      e--;
    }
    while (num > 10 || num < -10) {
      num /= 10;
      e++;
    }
    int_flags.precision = 2;
    int_flags.plus = 1;
    e_result = int_to_str(e, 10, int_flags);
    int_flags.precision = 0;
    int_flags.plus = flags->plus;
  }
  char *result = 0;
  unsigned long int int_num = (long int)num;
  long double double_num = num - (long int)int_num;
  if (double_num < 0) double_num *= -1;
  result = int_to_str(int_num, 10, int_flags);
  int len = s21_strlen(result) + flags->precision + 2;
  if (flags->spec == 'e' || flags->spec == 'E')
    result = realloc(result, len + s21_strlen(e_result) + 1);
  else
    result = realloc(result, len);
  if (flags->precision > 0 || flags->sharp) s21_strcat(result, ".\0");
  for (int i = 1; i <= flags->precision; i++) {
    double_num *= 10;
    result[len - flags->precision + i - 2] = (long int)double_num % 10 + 48;
  }
  result[len - 1] = '\0';
  double_num *= 10;
  if ((long int)double_num % 10 >= 5) s21_round(result);
  if (flags->spec == 'e' || flags->spec == 'E') {
    s21_strcat(result, flags->spec == 'e' ? "e" : "E");
    s21_strcat(result, e_result);
    free(e_result);
  }
  return result;
}

void cat(int *i, char *str, char const *result, Flags flags, int null) {
  int j = 0;
  for (; *result != '\0'; result++, j++) {
    str[*i + j] = *result;
  }
  if (null) {
    if (flags.width) *i -= 1;
    if (flags.minus)
      str[*i + j] = '\0';
    else
      str[*i] = '\0';
    *i += 1;
  }
  *i += j - 1;
}

void s21_round(char *string) {
  int len = s21_strlen(string) - 1;
  for (; 0 <= len; len--) {
    if (string[len] == '.') continue;
    string[len] += 1;
    if (string[len] == ':') {
      string[len] = 48;
    } else
      break;
  }
}