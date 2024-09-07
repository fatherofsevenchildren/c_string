#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int lenght = 0;
  while (!s21_strchr(str2, *str1) && *str1 != '\0') {
    str1++;
    lenght += 1;
  }
  return lenght;
}