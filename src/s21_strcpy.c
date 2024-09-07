#include <stdio.h>

#include "s21_string.h"
char *s21_strcpy(char *dest, const char *src) {
  char *point_dest = dest;
  unsigned char *point_src = (unsigned char *)src;
  if (point_dest != S21_NULL) {
    while (*point_src != '\0') {
      *point_dest = *point_src;
      point_dest += 1;
      point_src += 1;
    }
    *point_dest = '\0';
  }
  return dest;
}