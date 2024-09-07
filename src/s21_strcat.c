#include "s21_string.h"
char *s21_strcat(char *dest, const char *src) {
  unsigned char *byte_dest = (unsigned char *)dest;
  const char *byte_src = src;
  int flag_end = 0;
  while (1) {
    if (*byte_dest == '\0') {
      flag_end += 1;
      break;
    }
    byte_dest += 1;
  }

  if (flag_end) {
    while (*byte_src != '\0') {
      *byte_dest = *byte_src;
      byte_src += 1;
      byte_dest += 1;
    }
    *byte_dest = '\0';
  }

  return dest;
}
