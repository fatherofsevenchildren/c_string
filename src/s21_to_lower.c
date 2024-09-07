#include <stdio.h>

#include "s21_string.h"
void* s21_to_lower(const char* str) {
  char* string = NULL;

  if (str != NULL) {
    int i = 0;
    int length = s21_strlen(str) + 1;
    string = (char*)malloc(length * sizeof(char));
    while (i < length) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        string[i] = str[i] + 32;
      } else {
        string[i] = str[i];
      }
      ++i;
    }
  }

  return string;
}
