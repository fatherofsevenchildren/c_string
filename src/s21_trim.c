#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;

  if (src) {
    int size = s21_strlen(src);
    int start = 0;
    int end = size - 1;
    if (trim_chars) {
      while (src[start] && s21_strrchr(trim_chars, src[start])) start++;
      while (end >= start && s21_strrchr(trim_chars, src[end])) end--;
    }
    int trimmed_length = end - start + 1;
    result = (char *)malloc((trimmed_length + 1) * sizeof(char));
    int i;
    for (i = 0; i < trimmed_length; i++) result[i] = src[start + i];
    result[trimmed_length] = '\0';
  }
  return result;
}
