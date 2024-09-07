#include "s21_string.h"
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; ++i) {
    if (*str1 != *str2) {
      return (*str1 - *str2);
    }
    if (*str1 == '\0' || *str2 == '\0') {
      break;
    }

    ++str1;
    ++str2;
  }
  return 0;
}
