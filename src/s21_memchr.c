#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *b = (unsigned char *)str;
  while (n > 0) {
    if (*b == c) return b;
    n -= 1;
    b += 1;
  }
  return S21_NULL;
}