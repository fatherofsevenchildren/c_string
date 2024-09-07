#include "s21_string.h"
// #include <string.h>

/// @brief main finction
/// @param flag_end если символ не равен символу в строке программа дальше не

int s21_sscanf(const char* str, const char* format, ...) {
  if (!str || !format) return -1;
  if (!s21_strlen(str)) return -1;
  int result = 0, flag_end = 0;
  va_list va;
  char* str1 = (char*)str;
  va_start(va, format);
  char* format1 = (char*)format;
  while (*format1 != '\0' && !flag_end && *str1 != '\0') {
    if (*format1 == '%') {
      format1++;
      struct flags Flags = parsing_flags(&format1);
      char current = *format1;
      if (current == '%') str1 = percent(str1, &flag_end);
      if (current == 'c') {
        str1 = parsing_c(str1, va, Flags, &result, &format1);
        continue;  // %c в отличии от остальных % обрабатывает пробел
      }
      if (current == 'n')
        *va_arg(va, int*) =
            str1 - str;  // counting how many symbols processed before
      while (*str1 == ' ' || *str1 == '\n' || *str1 == '\r' || *str1 == '\t')
        str1++;
      char* teststr =
          str1;  // для проверки сместитлся ли наша строка после спецификатора
      if (current == 's') str1 = parsing_s(str1, va, Flags, &result);
      if (current == 'd') str1 = parsing_d(str1, va, Flags);
      if (current == 'f' || current == 'e' || current == 'E' ||
          current == 'g' || current == 'G')
        str1 = parsing_f(str1, va, Flags);
      if (current == 'o') str1 = parsing_o(str1, va, Flags);
      if (current == 'x' || current == 'X') str1 = parsing_x(str1, va, Flags);
      if (current == 'u') str1 = parsing_u(str1, va, Flags);
      if (current == 'i') str1 = parsing_i(str1, va, Flags);
      if (current == 'p') {
        unsigned long int* d = va_arg(va, void*);
        *d = hex_to_decimal(&str1, Flags);
      }
      if (teststr != str1 && !Flags.asterisk)
        result++;  // проверка на то, что мы что-то записали в функцию => строка
                   // сместилась
    } else if (*format1 == *str1)
      str1++;
    else if (*format1 != ' ' && *format1 != '\n' && *format1 != '\r' &&
             *format1 != '\t')
      flag_end++;  // если в формате лежит не такой символ как в строке то end
    format1++;
  }
  if (!s21_strncmp(format1, "%n", 2)) *va_arg(va, int*) = str1 - str;
  va_end(va);
  return result;
}

struct flags parsing_flags(char** format) {
  struct flags Flags = {0, 0, 0, 0, 0};
  while (**format > 47 && **format < 58) {
    int curchar = **format - 48;
    Flags.number = (Flags.number * 10) + curchar;
    (*format)++;
  }
  if (**format == '*') {
    Flags.asterisk = 1;
    (*format)++;
  }
  if (**format == 'l') {
    Flags.l = 1;
    (*format)++;
  }
  if (**format == 'h') {
    Flags.h = 1;
    (*format)++;
  }
  if (**format == 'L') {
    Flags.L = 1;
    (*format)++;
  }
  if (Flags.number == 0) Flags.number = 9999;

  return Flags;
}

void dflag(char** str1, int* d, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    (*str1)++;
  }
  *d = 0;
  while (**str1 > 47 && **str1 < 58 && Flags.number) {
    int curchar = **str1 - 48;
    *d = (*d * 10) + curchar;
    (*str1)++;
    Flags.number--;
  }
  *d *= negative;
  *d =
      *d % 2147483647;  //во-первых это придумал АЛЕКСАНДР, "типа число делится
                        //делится делится, находится остаток и записывается" (c)
  if (Flags.number < 9980 && Flags.number > 9000)
    *d = -1;  // если в va_arg пытаться засунуть число где кол-во знаков > 18,
              // то ориг функция возвращает тоже самое
}

void dlflag(char** str1, long int* d, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    // else negative = 1;
    (*str1)++;
  }
  *d = 0;
  while (**str1 > 47 && **str1 < 58 && Flags.number) {
    int curchar = **str1 - 48;
    *d = (*d * 10) + curchar;
    (*str1)++;
    Flags.number--;
  }
  *d *= negative;
  *d = *d % 9223372036854775807;  //во-первых это придумал АЛЕКСАНДР, "типа
                                  //число делится делится делится, находится
                                  //остаток и записывается" (c)
  if (Flags.number < 9980 && Flags.number > 9000) *d = 9223372036854775807;
}

long unsigned int sscanf_str_to_int(char** str1, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    // else negative = 1;
    (*str1)++;
  }
  long long unsigned int d = 0;
  while (**str1 > 47 && **str1 < 58 && Flags.number != 9980) {
    int curchar = **str1 - 48;
    d = (d * 10) + curchar;
    (*str1)++;
    Flags.number--;
  }
  d *= negative;
  if (Flags.h) d = d % USHRT_MAX - (d / USHRT_MAX);
  if (Flags.l && d >= 1844674407370955161) d = ULONG_MAX;
  if (!Flags.l && !Flags.h) d = d % 4294967295 - (d / 4294967295);
  return d;
}

void dhflag(char** str1, short int* d, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    // else negative = 1;
    (*str1)++;
  }
  *d = 0;
  while (**str1 > 47 && **str1 < 58 && Flags.number) {
    int curchar = **str1 - 48;
    *d = (*d * 10) + curchar;
    (*str1)++;
    Flags.number--;
  }
  *d *= negative;
  *d =
      *d % 2147483647;  //во-первых это придумал АЛЕКСАНДР, "типа число делится
                        //делится делится, находится остаток и записывается" (c)
  if (Flags.number < 9980 && Flags.number > 9000)
    *d = -1;  // если в va_arg пытаться засунуть число где кол-во знаков > 18,
              // то ориг функция возвращает тоже самое
}

long int octal_to_decimal(char** str1, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    (*str1)++;
  }
  long unsigned int d = 0;
  while (**str1 > 47 && **str1 < 56 && Flags.number) {
    int curchar = **str1 - 48;
    d = (d * 8) + curchar;
    (*str1)++;
    Flags.number--;
  }
  d *= negative;
  return d;
}

long int hex_to_decimal(char** str1, struct flags Flags) {
  int negative = 1;
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    negative = -1;
    (*str1)++;
  }
  if (**str1 == '0') {
    (*str1)++;
    Flags.number--;
  }
  if (**str1 == 'x' || **str1 == 'X') {
    (*str1)++;
    Flags.number--;
  }
  long unsigned int d = 0;
  while (((**str1 > 47 && **str1 < 58) || (**str1 > 64 && **str1 < 71) ||
          (**str1 > 96 && **str1 < 103)) &&
         Flags.number) {
    int curchar = **str1 - 48;
    if (**str1 > 64 && **str1 < 71) curchar = **str1 - 55;
    if (**str1 > 96 && **str1 < 103) curchar = **str1 - 87;
    d = (d * 16) + curchar;
    (*str1)++;
    Flags.number--;
  }
  d *= negative;
  return d;
}

void dflag_asterisk(char** str1, struct flags Flags) {
  while (**str1 == ' ' || **str1 == '\n' || **str1 == '\t')
    (*str1)++;  // checking for a negativ namber and skip non namber
  if (**str1 == '-') {
    // else negative = 1;
    (*str1)++;
  }
  while (**str1 > 47 && **str1 < 58 && Flags.number) {
    (*str1)++;
    Flags.number--;
  }
}

int sflag(char** str1, char* d, struct flags Flags) {
  int flag = 0;
  while (**str1 == ' ') (*str1)++;
  while (**str1 != 0 && **str1 != '\n' && Flags.number &&
         **str1 != ' ') {  // need more "char of and"
    *d = **str1;
    d++;
    (*str1)++;
    Flags.number--;
    flag++;
  }
  return flag;
}

void sflag_asterisk(char** str1, struct flags Flags) {
  while (**str1 == ' ') (*str1)++;
  while (**str1 != 0 && **str1 != '\n' && Flags.number &&
         **str1 != ' ') {  // need more "char of end"
    (*str1)++;
    Flags.number--;
  }
}

long double fflag(char** str1, struct flags Flags) {
  long double d = 0.00;
  int negative = 1;
  if (**str1 == '-') {  // minus sing check
    negative = -1;
    (*str1)++;
  }
  if (!s21_strncmp(*str1, "nan", 3)) {  // nan check
    (*str1) += 3;
    d = NAN;
    return d;
  }
  if (!s21_strncmp(*str1, "inf", 3)) {  // inf check
    (*str1) += 3;
    d = INFINITY * negative;
    return d;
  }
  int flag = 0;  // флаг что после минуса вошло число
  if (**str1 != '.' && **str1 != 'e' && **str1 != 'E') {
    while (**str1 > 47 && **str1 < 58 && Flags.number) {
      int curchar = **str1 - 48;
      d = (d * 10) + curchar;
      (*str1)++;
      Flags.number--;
      flag++;
    }
  }
  if (negative == -1 && !flag) (*str1)--;
  if (**str1 == '.') {
    (*str1)++;
    int i = 0;
    long double thertpart = 0.00;
    while (**str1 > 47 && **str1 < 58 && Flags.number) {
      double curchar = **str1 - 48;
      thertpart = (thertpart * 10) + curchar;
      (*str1)++;
      Flags.number--;
      i++;
    }
    d = d + thertpart / pow(10, i);
  }
  long double exp = 0;
  if (**str1 == 'e' || **str1 == 'E') {
    int exp_sign = 1, exp_digits = 0;
    (*str1)++;
    if (**str1 == '+' || **str1 == '-') {
      exp_sign = (**str1 == '-') ? -1 : 1;
      (*str1)++;
    }
    while (**str1 >= '0' && **str1 <= '9') {
      exp = exp * 10 + (**str1 - '0');
      exp_digits++;
      (*str1)++;
    }
    exp *= exp_sign;
  }
  d *= powl(10, exp);
  if (d != 0.000000000000000) d *= negative;
  return d;
}

/// @brief main finction
/// @param flag_end если символ не равен символу в строке программа дальше не
/// идет

char* parsing_o(char* str1, va_list va, struct flags Flags) {
  if (Flags.asterisk)
    octal_to_decimal(&str1, Flags);
  else if (Flags.l) {
    *va_arg(va, long unsigned int*) = octal_to_decimal(&str1, Flags);
  } else if (Flags.h) {
    *va_arg(va, short unsigned int*) =
        (short unsigned int)octal_to_decimal(&str1, Flags);
  } else {
    *va_arg(va, unsigned int*) = (unsigned int)octal_to_decimal(&str1, Flags);
  }
  // printf("%s", str1);
  return str1;
}

char* parsing_x(char* str1, va_list va, struct flags Flags) {
  if (Flags.asterisk)
    hex_to_decimal(&str1, Flags);
  else if (Flags.l) {
    *va_arg(va, long unsigned int*) = hex_to_decimal(&str1, Flags);
  } else if (Flags.h) {
    *va_arg(va, short unsigned int*) =
        (short unsigned int)hex_to_decimal(&str1, Flags);
  } else {
    *va_arg(va, unsigned int*) = (unsigned int)hex_to_decimal(&str1, Flags);
  }
  return str1;
}

char* parsing_i(char* str1, va_list va, struct flags Flags) {
  int negative = 1;
  if (*str1 == '-') {
    negative = -1;
    str1++;
  }
  if (Flags.asterisk) {
    if (*str1 == '0') {
      str1++;
      Flags.number--;
      if (*str1 == 'x' || *str1 == 'X') {
        hex_to_decimal(&str1, Flags);
      } else {
        octal_to_decimal(&str1, Flags);
      }
    } else {
      sscanf_str_to_int(&str1, Flags);
    }
  } else if (Flags.l) {
    if (*str1 == '0') {
      str1++;
      Flags.number--;
      if (*str1 == 'x' || *str1 == 'X') {
        *va_arg(va, unsigned long int*) =
            (unsigned long int)hex_to_decimal(&str1, Flags) * negative;
      } else {
        *va_arg(va, unsigned long int*) =
            (unsigned long int)octal_to_decimal(&str1, Flags) * negative;
      }
    } else {
      *va_arg(va, unsigned long int*) =
          (unsigned long int)sscanf_str_to_int(&str1, Flags) * negative;
    }
  } else if (Flags.h) {
    if (*str1 == '0') {
      str1++;
      Flags.number--;
      if (*str1 == 'x' || *str1 == 'X') {
        *va_arg(va, unsigned short int*) =
            (unsigned short int)hex_to_decimal(&str1, Flags) * negative;
      } else {
        *va_arg(va, unsigned short int*) =
            (unsigned short int)octal_to_decimal(&str1, Flags) * negative;
      }
    } else {
      *va_arg(va, unsigned short int*) =
          (unsigned short int)sscanf_str_to_int(&str1, Flags) * negative;
    }
  } else {
    if (*str1 == '0') {
      str1++;
      Flags.number--;
      if (*str1 == 'x' || *str1 == 'X') {
        *va_arg(va, unsigned int*) =
            (unsigned int)hex_to_decimal(&str1, Flags) * negative;
      } else {
        *va_arg(va, unsigned int*) =
            (unsigned int)octal_to_decimal(&str1, Flags) * negative;
      }
    } else {
      *va_arg(va, unsigned int*) =
          (unsigned int)sscanf_str_to_int(&str1, Flags) * negative;
    }
  }
  return str1;
}

char* parsing_u(char* str1, va_list va, struct flags Flags) {
  if (Flags.asterisk) sscanf_str_to_int(&str1, Flags);
  if (Flags.l) {
    *va_arg(va, long unsigned int*) = sscanf_str_to_int(&str1, Flags);
  } else if (Flags.h) {
    *va_arg(va, short unsigned int*) =
        (short unsigned int)sscanf_str_to_int(&str1, Flags);
  } else {
    *va_arg(va, unsigned int*) = (unsigned int)sscanf_str_to_int(&str1, Flags);
  }
  return str1;
}

char* parsing_f(char* str1, va_list va, struct flags Flags) {
  if (Flags.asterisk)
    fflag(&str1, Flags);
  else if (Flags.l) {
    *va_arg(va, double*) = (double)fflag(&str1, Flags);
  } else if (Flags.L) {
    *va_arg(va, long double*) = fflag(&str1, Flags);
  } else {
    *va_arg(va, float*) = (float)fflag(&str1, Flags);
  }
  return str1;
}

char* parsing_d(char* str1, va_list va, struct flags Flags) {
  if (Flags.asterisk)
    dflag_asterisk(&str1, Flags);
  else if (Flags.l) {
    long int* d = va_arg(va, long int*);
    dlflag(&str1, d, Flags);
  } else if (Flags.h) {
    short int* d = va_arg(va, short int*);
    dhflag(&str1, d, Flags);
  } else {
    int* d = va_arg(va, int*);
    if (d != 0) dflag(&str1, d, Flags);
  }
  return str1;
}

char* parsing_c(char* str1, va_list va, struct flags Flags, int* result,
                char** format1) {
  while (*str1 == '\t') str1++;
  if (!Flags.asterisk) {
    *va_arg(va, char*) = *str1;
    (*result)++;
  }
  str1++;
  (*format1)++;
  return str1;
}

char* parsing_s(char* str1, va_list va, struct flags Flags, int* result) {
  if (Flags.asterisk)
    sflag_asterisk(&str1, Flags);
  else {
    char* d = va_arg(va, char*);
    int i = sflag(&str1, d, Flags);
    if (!i) (*result)--;
  }
  return str1;
}

char* percent(char* str1, int* flag_end) {
  if (*str1 == '%')
    str1++;
  else
    (*flag_end)++;
  return str1;
}

// int main () {

//   char format[100] = "%s %% %s %s";
//   char str[100] = "test1 % test2 test3 test4";
//   char o1[100] = {100}, o2[100] = {100}, o3[100] = {0};
//   char s1[100] = {0}, s2[100] = {0}, s3[100] = {0};
//   int original = sscanf(str, format, &o1, &o2, &o3);
//   int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
//   printf("%s\n%s", o2, s2);
//   return 0;
// }