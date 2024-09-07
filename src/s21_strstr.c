#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  if (*needle == '\0') {
    return (char*)haystack;
  }

  char* p1 = (char*)haystack;

  while (*p1) {
    char* p1_start = p1;
    char* p2 = (char*)needle;

    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }

    if (*p2 == '\0') {
      return p1_start;
    }

    p1 = p1_start + 1;
  }

  return S21_NULL;
}