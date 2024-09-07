#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memset(void);
Suite *test_strncat(void);
Suite *test_strchr(void);
Suite *test_strncmp(void);
Suite *test_strncpy(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strspn(void);
Suite *test_strstr(void);
Suite *test_strtok(void);

Suite *test_to_upper(void);
Suite *test_to_lower(void);
Suite *test_insert(void);
Suite *test_trim(void);

Suite *test_sprintf_c(void);
Suite *test_sprintf_d(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_string(void);
Suite *test_sprintf_unsigned(void);
Suite *suite_sscanf(void);

#endif  // SRC_TESTS_ME_H
