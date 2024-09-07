#ifndef SRC_S21_STRERROR_H_
#define SRC_S21_STRERROR_H_

#include "s21_string.h"

#ifdef __linux__
#define ALL_ERRORS 134
#elif __APPLE__
#define ALL_ERRORS 107
#endif

char *s21_strerror(int errnum);

#endif
