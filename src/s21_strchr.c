#include "s21_string.h"
char *s21_strchr(const char *str, int c) {
  char *byte_str = (char *)str;
  while (*byte_str != '\0') {
    if (*byte_str == c) return byte_str;
    byte_str += 1;
  }

  if (*byte_str == '\0' && *byte_str == c) return byte_str;
  return S21_NULL;
}