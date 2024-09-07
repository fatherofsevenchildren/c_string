#include "s21_string.h"
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *byte_str = (unsigned char *)str;
  if (byte_str != S21_NULL) {
    for (s21_size_t i = 0; i < n; i += 1) {
      byte_str[i] = c;
    }
  }
  return byte_str;
}
