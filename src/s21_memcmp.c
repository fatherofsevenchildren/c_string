#include "s21_string.h"
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *byte_str1 = (char *)str1;
  char *byte_str2 = (char *)str2;
  s21_size_t neutral = 0;
  for (s21_size_t i = 0; i < n && !neutral; i += 1) {
    if (byte_str1[i] != byte_str2[i]) {
      neutral = byte_str1[i] - byte_str2[i];
    }
  }
  return (int)neutral;
}