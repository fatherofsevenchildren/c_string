#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  int i = 0;
  for (; str[i] != '\0'; i++) {
    if (str[i] == c) result = ((char *)&str[i]);
  }
  if ((char)c == '\0' && str[i] == (char)c) result = ((char *)str + i);
  return result;
}
