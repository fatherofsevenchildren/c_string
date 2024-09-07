#include "s21_string.h"

void* s21_to_upper(const char* str) {
  char* string = S21_NULL;

  if (str != S21_NULL) {
    int i = 0;
    int length = s21_strlen(str) + 1;
    string = (char*)malloc(length * sizeof(char));
    while (i < length) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        string[i] = str[i] - 32;
      } else {
        string[i] = str[i];
      }
      ++i;
    }
  }

  return string;
}
