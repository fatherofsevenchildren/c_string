#include "s21_string.h"
char* s21_strncpy(char* destination, const char* source, s21_size_t num) {
  char* ptr = destination;
  s21_size_t i;
  for (i = 0; i < num && *source != '\0'; ++i) {
    *destination = *source;
    ++destination;
    ++source;
  }
  for (; i < num; ++i) {
    *destination = '\0';
    ++destination;
  }
  return ptr;
}
