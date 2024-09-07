#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t patern_str1 = s21_strlen(str1);
  s21_size_t patern_str2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < patern_str1; i++) {
    for (s21_size_t j = 0; j < patern_str2; j++) {
      if (str1[i] == str2[j]) {
        return ((char *)&str1[i]);
      }
    }
  }
  return NULL;
}
