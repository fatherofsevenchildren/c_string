#include "s21_string.h"

int s21_strcmp(const char* str1, const char* str2);

char* s21_strtok(char* str, const char* delimiters) {
  if (str == S21_NULL && s21_strcmp(delimiters, "") == 0) {
    return S21_NULL;
  }
  static char* token = S21_NULL;
  static char* nextToken = S21_NULL;
  if (str != S21_NULL) {
    nextToken = str;
  } else if (nextToken == S21_NULL) {
    return S21_NULL;
  }
  token = nextToken;
  if (*token == '\0') {
    return S21_NULL;
  }
  while (*token != '\0' && s21_strchr(delimiters, *token) != S21_NULL) {
    token++;
  }
  if (*token == '\0') {
    return S21_NULL;
  }
  nextToken = token + 1;
  while (*nextToken != '\0' && s21_strchr(delimiters, *nextToken) == S21_NULL) {
    nextToken++;
  }
  if (*nextToken != '\0') {
    *nextToken = '\0';
    nextToken++;
  } else {
    nextToken = S21_NULL;
  }
  return token;
}

int s21_strcmp(const char* str1, const char* str2) {
  while (*str1 && *str1 == *str2) {
    str1 += 1;
    str2 += 1;
    if (*str1 == '\0' || *str2 == '\0') break;
  }
  return (*str1 - *str2);
}
