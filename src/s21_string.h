#ifndef S21_STRING
#define S21_STRING
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
typedef unsigned long int s21_size_t;

/////////////////// SSCANF ///////////////////

struct flags {
  int number;
  bool asterisk;
  bool h;
  bool l;
  bool L;
};

struct flags parsing_flags(char **format);
void dflag(char **str1, int *d, struct flags Flags);
void dlflag(char **str1, long int *d, struct flags Flags);
void dhflag(char **str1, short int *d, struct flags Flags);
long unsigned int sscanf_str_to_int(char **str1, struct flags Flags);
long int octal_to_decimal(char **str1, struct flags Flags);
long int hex_to_decimal(char **str1, struct flags Flags);
void dflag_asterisk(char **str1, struct flags Flags);
int sflag(char **str1, char *d, struct flags Flags);
void sflag_asterisk(char **str1, struct flags Flags);
long double fflag(char **str1, struct flags Flags);
char *parsing_o(char *str1, va_list va, struct flags Flags);
char *parsing_x(char *str1, va_list va, struct flags Flags);
char *parsing_i(char *str1, va_list va, struct flags Flags);
char *parsing_u(char *str1, va_list va, struct flags Flags);
char *parsing_f(char *str1, va_list va, struct flags Flags);
char *parsing_d(char *str1, va_list va, struct flags Flags);
char *parsing_c(char *str1, va_list va, struct flags Flags, int *result,
                char **format1);
char *parsing_s(char *str1, va_list va, struct flags Flags, int *result);
char *percent(char *str1, int *flag_end);

int s21_sscanf(const char *str, const char *format, ...);

///////////   main    //////////

void *s21_memchr(const void *str, int c, s21_size_t n);            // ok
void *s21_memcpy(void *dest, const void *src, s21_size_t n);       // ok
void *s21_memset(void *str, int c, s21_size_t n);                  // ok
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);  // ok
void *s21_memmove(void *dest, const void *src, s21_size_t n);      // ok
char *s21_strcat(char *dest, const char *src);                     // ok
char *s21_strncat(char *dest, const char *src, s21_size_t n);      // ok
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *destination, const char *source, s21_size_t num);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void s21_errnum_tostring(char str[], int num);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_upper(const char *string);
void *s21_to_lower(const char *string);
int s21_sscanf(const char *str, const char *format, ...);

typedef struct TypeFormat {
  int flag_c;
  int flag_d;
  int flag_i;
  int flag_e;
  int flag_E;
  int flag_f;
  int flag_g;
  int flag_G;
  int flag_o;
  int flag_s;
  int flag_u;
  int flag_x;
  int flag_X;
  int flag_p;
  int flag_n;
  int flag_proc;
  int flag_number;
  int flag_star;
  int flag_h;
  int flag_l;
  int flag_L;
} TypeFormat;

void set_flags(TypeFormat *typeFormat, char format);
char *parse_star(char *str);
int parse_form(TypeFormat *typeFormat, char *str, va_list args,
               char *full_form);
int parse_length(TypeFormat *typeFormat, const char *str, const char *format,
                 char *full_form, va_list args);
long long int *parse_digit(TypeFormat *typeFormat, char *str, char *full_form);
void parse_weight(char *str, char *full_form);
void is_ein_point(char *str, int *number_pow, int *flag_e);
long double parse_float_point(TypeFormat *typeFormat, const char *str,
                              char *buffered, char *full_form);
s21_size_t parse_address(char *str);
int parse_n(char *full_form, va_list args);
long long int getHex(char *point_buf, int part_ten);
long long int getEight(char *point_buf, int part_ten);

#endif  // S21_STRING