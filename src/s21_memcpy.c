#include "s21_string.h"
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *byte_dest = (unsigned char *)dest;
  const unsigned char *byte_str = (const unsigned char *)src;
  for (; n > 0; n -= 1) {
    *byte_dest = *byte_str;
    byte_dest += 1;
    byte_str += 1;
  }
  return dest;
}