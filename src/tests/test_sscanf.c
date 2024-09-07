
#include "test_me.h"
#define BUFF_SIZE 512
#include <check.h>
#include <stdbool.h>

START_TEST(test_1) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("123", "%d", &a);
  int st = sscanf("123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_2) {
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int my = s21_sscanf("123 123", "%d %d", &a1, &b1);
  int st = sscanf("123 123", "%d %d", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  END_TEST
}
START_TEST(test_3) {
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int my = s21_sscanf("123", "%d %d", &a1, &b1);
  int st = sscanf("123", "%d %d", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_4) {
  int a1 = 0;
  int b1 = 123;
  int a2 = 0;
  int b2 = 123;
  int my = s21_sscanf("123 123", "%d %d", &a1, &b1);
  int st = sscanf("123 123", "%d %d", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_5) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("     123", "%d", &a);
  int st = sscanf("     123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_6) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("  \n   123", "%d", &a);
  int st = sscanf("  \n   123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_7) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("  \n a  123", "%d", &a);
  int st = sscanf("  \n a  123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_8) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("  \n \t \r  123", "%d", &a);
  int st = sscanf("  \n \t \r 123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_9) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("-0", "%d", &a);
  int st = sscanf("-0", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_10) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("-123", "%d", &a);
  int st = sscanf("-123", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_11) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("123456789123456789", "%d", &a);
  int st = sscanf("123456789123456789", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_12) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("100000000000000", "%d", &a);
  int st = sscanf("100000000000000", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_13) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("99999999999999999999", "%d", &a);
  int st = sscanf("99999999999999999999", "%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_14) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("9999999999999999999999", "%d%d", &a, &a1);
  int st = sscanf("9999999999999999999999", "%d%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_15) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("9999999999 999999999999", "%d%d", &a, &a1);
  int st = sscanf("9999999999 999999999999", "%d%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_16) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("1000000000000000000", "%d%d", &a, &a1);
  int st = sscanf("1000000000000000000", "%d%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_17) {
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int c1 = 0;
  int c2 = 0;
  int d1 = 0;
  int d2 = 0;
  int my = s21_sscanf("1 2 d 3", "%d %d %d %d", &a1, &b1, &c1, &d1);
  int st = sscanf("1 2 d 3", "%d %d %d %d", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_18) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("123", "%2d", &a);
  int st = sscanf("123", "%2d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_19) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("123", "%10d", &a);
  int st = sscanf("123", "%10d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_20) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("123456", "%2d%d", &a, &a1);
  int st = sscanf("123456", "%2d%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_21) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("123   456", "%2d%d", &a, &a1);
  int st = sscanf("123   456", "%2d%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_22) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("123 c  456", "%2dc%d", &a, &a1);
  int st = sscanf("123 c  456", "%2dc%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_23) {
  int a = 0;
  int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("123 \n  456", "%2d\n%d", &a, &a1);
  int st = sscanf("123 \n  456", "%2d\n%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_24) {
  int a = 0;
  int b = 0;
  int my = s21_sscanf("123 456", "%*d%d", &a);
  int st = sscanf("123 456", "%*d%d", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_26) {
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int my = s21_sscanf("1 2 d 3", "%*d %*d %d %d", &a1, &b1);
  int st = sscanf("1 2 d 3", "%*d %*d %d %d", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

//------------ | long int |
//-----------------------------------------------------------------------------------

START_TEST(test_27) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("123", "%ld", &a);
  int st = sscanf("123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_28) {
  long int a1 = 0;
  long int b1 = 0;
  long int a2 = 0;
  long int b2 = 0;
  int my = s21_sscanf("123 123", "%ld %ld", &a1, &b1);
  int st = sscanf("123 123", "%ld %ld", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_29) {
  long int a1 = 0;
  long int b1 = 0;
  long int a2 = 0;
  long int b2 = 0;
  int my = s21_sscanf("123", "%ld %ld", &a1, &b1);
  int st = sscanf("123", "%ld %ld", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_30) {
  long int a1 = 0;
  long int b1 = 123;
  long int a2 = 0;
  long int b2 = 123;
  int my = s21_sscanf("123 123", "%ld %ld", &a1, &b1);
  int st = sscanf("123 123", "%ld %ld", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_31) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("     123", "%ld", &a);
  int st = sscanf("     123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_32) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("  \n   123", "%ld", &a);
  int st = sscanf("  \n   123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_33) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("  \n a  123", "%ld", &a);
  int st = sscanf("  \n a  123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_34) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("  \n \t \r  123", "%ld", &a);
  int st = sscanf("  \n \t \r 123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_35) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("-0", "%ld", &a);
  int st = sscanf("-0", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_36) {
  long long int a = 0;
  long int b = 0;
  int my = s21_sscanf("-123", "%ld", &a);
  int st = sscanf("-123", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_37) {
  long long int a = 0;
  long int b = 0;
  int my = s21_sscanf("123456789123456789", "%ld", &a);
  int st = sscanf("123456789123456789", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_38) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("100000000000000", "%ld", &a);
  int st = sscanf("100000000000000", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_39) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("99999999999999999999", "%ld", &a);
  int st = sscanf("99999999999999999999", "%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_40) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("9999999999999999999999", "%ld%ld", &a, &a1);
  int st = sscanf("9999999999999999999999", "%ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_41) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("9999999999 999999999999", "%ld%ld", &a, &a1);
  int st = sscanf("9999999999 999999999999", "%ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_42) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("1000000000000000000", "%ld%ld", &a, &a1);
  int st = sscanf("1000000000000000000", "%ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_43) {
  long int a1 = 0;
  long int b1 = 0;
  long int a2 = 0;
  long int b2 = 0;
  long int c1 = 0;
  long int c2 = 0;
  long int d1 = 0;
  long int d2 = 0;
  int my = s21_sscanf("1 2 d 3", "%ld %ld %ld %ld", &a1, &b1, &c1, &d1);
  int st = sscanf("1 2 d 3", "%ld %ld %ld %ld", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_44) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("123", "%2ld", &a);
  int st = sscanf("123", "%2ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_45) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("123", "%10ld", &a);
  int st = sscanf("123", "%10ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_46) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("123456", "%2ld%ld", &a, &a1);
  int st = sscanf("123456", "%2ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_47) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("123   456", "%2ld%ld", &a, &a1);
  int st = sscanf("123   456", "%2ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_48) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("123 c  456", "%2ldc%ld", &a, &a1);
  int st = sscanf("123 c  456", "%2ldc%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_49) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf("123 \n  456", "%2ld\n%ld", &a, &a1);
  int st = sscanf("123 \n  456", "%2ld\n%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_50) {
  long int a = 0;
  long int b = 0;
  int my = s21_sscanf("123 456", "%*d%ld", &a);
  int st = sscanf("123 456", "%*d%ld", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_51) {
  long int a = 0;
  long int b = 0;
  long int a1 = 0;
  long int b1 = 0;
  int my = s21_sscanf(
      "99999999999999999999999999999999999999999999999999999999999999",
      "%ld%ld", &a, &a1);
  int st =
      sscanf("99999999999999999999999999999999999999999999999999999999999999",
             "%ld%ld", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

//------------ | short int |
//-----------------------------------------------------------------------------------

START_TEST(test_52) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("123", "%hd", &a);
  int st = sscanf("123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_53) {
  short int a1 = 0;
  short int b1 = 0;
  short int a2 = 0;
  short int b2 = 0;
  int my = s21_sscanf("123 123", "%hd %hd", &a1, &b1);
  int st = sscanf("123 123", "%hd %hd", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_54) {
  short int a1 = 0;
  short int b1 = 0;
  short int a2 = 0;
  short int b2 = 0;
  int my = s21_sscanf("123", "%hd %hd", &a1, &b1);
  int st = sscanf("123", "%hd %hd", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_55) {
  short int a1 = 0;
  short int b1 = 123;
  short int a2 = 0;
  short int b2 = 123;
  int my = s21_sscanf("123 123", "%hd %hd", &a1, &b1);
  int st = sscanf("123 123", "%hd %hd", &a2, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(test_56) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("     123", "%hd", &a);
  int st = sscanf("     123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_57) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("  \n   123", "%hd", &a);
  int st = sscanf("  \n   123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_58) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("  \n a  123", "%hd", &a);
  int st = sscanf("  \n a  123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_59) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("  \n \t \r  123", "%hd", &a);
  int st = sscanf("  \n \t \r 123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_60) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("-0", "%hd", &a);
  int st = sscanf("-0", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_61) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("-123", "%hd", &a);
  int st = sscanf("-123", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_62) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("123456789123456789", "%hd", &a);
  int st = sscanf("123456789123456789", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_63) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("100000000000000", "%hd", &a);
  int st = sscanf("100000000000000", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_64) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("99999999999999999999", "%hd", &a);
  int st = sscanf("99999999999999999999", "%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_65) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("9999999999999999999999", "%hd%hd", &a, &a1);
  int st = sscanf("9999999999999999999999", "%hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_66) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("9999999999 999999999999", "%hd%hd", &a, &a1);
  int st = sscanf("9999999999 999999999999", "%hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_67) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("1000000000000000000", "%hd%hd", &a, &a1);
  int st = sscanf("1000000000000000000", "%hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_68) {
  short int a1 = 0;
  short int b1 = 0;
  short int a2 = 0;
  short int b2 = 0;
  short int c1 = 0;
  short int c2 = 0;
  short int d1 = 0;
  short int d2 = 0;
  int my = s21_sscanf("1 2 d 3", "%hd %hd %hd %hd", &a1, &b1, &c1, &d1);
  int st = sscanf("1 2 d 3", "%hd %hd %hd %hd", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_69) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("123", "%2Ld", &a);
  int st = sscanf("123", "%2hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_70) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("123", "%10hd", &a);
  int st = sscanf("123", "%10hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_71) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("123456", "%2hd%hd", &a, &a1);
  int st = sscanf("123456", "%2hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_72) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("123   456", "%2hd%hd", &a, &a1);
  int st = sscanf("123   456", "%2hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_73) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("123 c  456", "%2hdc%hd", &a, &a1);
  int st = sscanf("123 c  456", "%2hdc%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_74) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf("123 \n  456", "%2hd\n%hd", &a, &a1);
  int st = sscanf("123 \n  456", "%2hd\n%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_75) {
  short int a = 0;
  short int b = 0;
  int my = s21_sscanf("123 456", "%*d%hd", &a);
  int st = sscanf("123 456", "%*d%hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_76) {
  short int a = 0;
  short int b = 0;
  short int a1 = 0;
  short int b1 = 0;
  int my = s21_sscanf(
      "99999999999999999999999999999999999999999999999999999999999999",
      "%hd%hd", &a, &a1);
  int st =
      sscanf("99999999999999999999999999999999999999999999999999999999999999",
             "%hd%hd", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_77) {
  short int a = 0;
  short int b = 0;
  // short int a1 = 0;
  // short int b1 = 0;
  int my = s21_sscanf("00009", "%3hd", &a);
  int st = sscanf("00009", "%3hd", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  // ck_assert_int_eq(a1, b1);
}
END_TEST

//------------------  char ------------------------

START_TEST(test_char_1) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 5;
  char b2 = 5;
  int my = s21_sscanf("  c", "%c%c%c", &a, &a1, &a2);
  int st = sscanf("  c", "%c%c%c", &b, &b1, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_char_2) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 5;
  char b2 = 5;
  int my = s21_sscanf("123", "%c%c%c", &a, &a1, &a2);
  int st = sscanf("123", "%c%c%c", &b, &b1, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_char_3) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 5;
  char b2 = 5;
  int my = s21_sscanf("12 ", "%c%c%c", &a, &a1, &a2);
  int st = sscanf("12 ", "%c%c%c", &b, &b1, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_char_4) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 5;
  char b2 = 5;
  int my = s21_sscanf("   ", "%c%c%c", &a, &a1, &a2);
  int st = sscanf("   ", "%c%c%c", &b, &b1, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_char_5) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 5;
  char b2 = 5;
  int my = s21_sscanf(" \nt", "%c%c%c", &a, &a1, &a2);
  int st = sscanf(" \nt", "%c%c%c", &b, &b1, &b2);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_char_6) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf(" \nt", "%c%*c%c", &a, &a1);
  int st = sscanf(" \nt", "%c%*c%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_char_7) {
  char a = 0;
  char b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf(" t234", "%c%d", &a, &a1);
  int st = sscanf(" t234", "%c%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_char_8) {
  char a = 0;
  char b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("t234", "%c%d", &a, &a1);
  int st = sscanf("t234", "%c%d", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_char_9) {
  char a = 0;
  char b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf(" 234t", "%d%c", &a1, &a);
  int st = sscanf(" 234t", "%d%c", &b1, &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_char_10) {
  char a = 0;
  char b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf(" 234t", "%d%c", &a1, &a);
  int st = sscanf(" 234t", "%d%c", &b1, &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_char_11) {
  char a = 0;
  char b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("lc", "%*c%c%c", &a, &a1);
  int st = sscanf("lc", "%*c%c%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

// -------------------  %f ----------------

START_TEST(test_float_1) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("2.0", "%f", &a);
  int st = sscanf("2.0", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_2) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("0.0", "%f", &a);
  int st = sscanf("0.0", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_3) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("12434.56", "%f", &a);
  int st = sscanf("12434.56", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_4) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("12345678.123456", "%f", &a);
  int st = sscanf("12345678.123456", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_5) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("0.123456789", "%f", &a);
  int st = sscanf("0.123456789", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_6) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf(".123", "%f", &a);
  int st = sscanf(".123", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_7) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("  .123", "%f", &a);
  int st = sscanf("  .123", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_8) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("0000.0000", "%f", &a);
  int st = sscanf("0000.0000", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_9) {
  float a = 0;
  float b = 0;
  float a1 = 0;
  float b1 = 0;
  int my = s21_sscanf("123.122 123.122", "%f%f", &a, &a1);
  int st = sscanf("123.122 123.122", "%f%f", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_float_10) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123.122222", "%f", &a);
  int st = sscanf("123.122222", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_11) {
  float a = 0;
  float b = 0;
  float a1 = 0;
  float b1 = 0;
  int my = s21_sscanf("123.122222", "%f%f", &a, &a1);
  int st = sscanf("123.122222", "%f%f", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_float_12) {
  float a = 0;
  float b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("123.122222 c", "%f%c", &a, &a1);
  int st = sscanf("123.122222 c", "%f%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_13) {
  float a = 0;
  float b = 0;
  float a1 = 0;
  float b1 = 0;
  int my = s21_sscanf("123.122222  23", "%f%f", &a, &a1);
  int st = sscanf("123.122222  23", "%f%f", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_float_14) {
  float a = 0;
  float b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("123.122222. c", "%f%c", &a, &a1);
  int st = sscanf("123.122222. c", "%f%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_16) {
  float a = 0;
  float b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("-123.122222. c", "%f%c", &a, &a1);
  int st = sscanf("-123.122222. c", "%f%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_17) {
  float a = 0;
  float b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 0;
  char b2 = 0;
  int my = s21_sscanf("- -123.122222. c", "%c%f%c", &a2, &a, &a1);
  int st = sscanf("- -123.122222. c", "%c%f%c", &b2, &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_float_18) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("inf", "%f", &a);
  int st = sscanf("inf", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_19) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("nan", "%f", &a);
  int st = sscanf("nan", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(isnan(a), isnan(b));
}
END_TEST

START_TEST(test_float_20) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("-nan", "%f", &a);
  int st = sscanf("-nan", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(isnan(a), isnan(b));
}
END_TEST

START_TEST(test_float_21) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("-inf", "%f", &a);
  int st = sscanf("-inf", "%f", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_22) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("0.0", "%Lf", &a);
  int st = sscanf("0.0", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_23) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("12434.56", "%Lf", &a);
  int st = sscanf("12434.56", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_24) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("12345678.123456", "%Lf", &a);
  int st = sscanf("12345678.123456", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_25) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("0.123456789", "%Lf", &a);
  int st = sscanf("0.123456789", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_26) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf(".123", "%Lf", &a);
  int st = sscanf(".123", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_27) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("  .123", "%Lf", &a);
  int st = sscanf("  .123", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_28) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("0000.0000", "%Lf", &a);
  int st = sscanf("0000.0000", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_29) {
  long double a = 0;
  long double b = 0;
  long double a1 = 0;
  long double b1 = 0;
  int my = s21_sscanf("123.122 123.122", "%Lf%Lf", &a, &a1);
  int st = sscanf("123.122 123.122", "%Lf%Lf", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_ldouble_eq(a1, b1);
}
END_TEST

START_TEST(test_float_30) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("123.122222", "%Lf", &a);
  int st = sscanf("123.122222", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_31) {
  long double a = 0;
  long double b = 0;
  long double a1 = 0;
  long double b1 = 0;
  int my = s21_sscanf("123.122222", "%Lf%Lf", &a, &a1);
  int st = sscanf("123.122222", "%Lf%Lf", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_ldouble_eq(a1, b1);
}
END_TEST

START_TEST(test_float_32) {
  long double a = 0;
  long double b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("123.122222 c", "%Lf%c", &a, &a1);
  int st = sscanf("123.122222 c", "%Lf%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_33) {
  long double a = 0;
  long double b = 0;
  long double a1 = 0;
  long double b1 = 0;
  int my = s21_sscanf("123.122222  23", "%Lf%Lf", &a, &a1);
  int st = sscanf("123.122222  23", "%Lf%Lf", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_ldouble_eq(a1, b1);
}
END_TEST

START_TEST(test_float_34) {
  long double a = 0;
  long double b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("123.122222. c", "%Lf%c", &a, &a1);
  int st = sscanf("123.122222. c", "%Lf%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_36) {
  long double a = 0;
  long double b = 0;
  char a1 = 0;
  char b1 = 0;
  int my = s21_sscanf("-123.122222. c", "%Lf%c", &a, &a1);
  int st = sscanf("-123.122222. c", "%Lf%c", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_float_37) {
  long double a = 0;
  long double b = 0;
  char a1 = 0;
  char b1 = 0;
  char a2 = 0;
  char b2 = 0;
  int my = s21_sscanf("- -123.122222. c", "%c%Lf%c", &a2, &a, &a1);
  int st = sscanf("- -123.122222. c", "%c%Lf%c", &b2, &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_float_38) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("inf", "%Lf", &a);
  int st = sscanf("inf", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_float_39) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("nan", "%Lf", &a);
  int st = sscanf("nan", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_int_eq(isnan(a), isnan(b));
}
END_TEST

START_TEST(test_float_40) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("-nan", "%Lf", &a);
  int st = sscanf("-nan", "%Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(isnan(a), isnan(b));
}
END_TEST

START_TEST(test_float_41) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("12345678.123456", "%5Lf", &a);
  int st = sscanf("12345678.123456", "%5Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_42) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("12345678.123456", "%20Lf", &a);
  int st = sscanf("12345678.123456", "%20Lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_43) {
  double a = 0;
  double b = 0;
  int my = s21_sscanf("123456789.123456789", "%lf", &a);
  int st = sscanf("123456789.123456789", "%lf", &b);
  ck_assert_int_eq(my, st);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_float_44) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123e9", "%e", &a);
  int st = sscanf("123e9", "%e", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_45) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123E9", "%e", &a);
  int st = sscanf("123E9", "%e", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_46) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123e9", "%E", &a);
  int st = sscanf("123e9", "%E", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_47) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123E9", "%E", &a);
  int st = sscanf("123E9", "%E", &b);
  ck_assert_int_eq(my, st);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_float_48) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("123e9", "%Le", &a);
  int st = sscanf("123e9", "%Le", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

START_TEST(test_float_49) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123E9", "%e", &a);
  int st = sscanf("123E9", "%e", &b);
  ck_assert_int_eq(my, st);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_float_50) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123e9", "%E", &a);
  int st = sscanf("123e9", "%E", &b);
  ck_assert_int_eq(my, st);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_float_51) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123E9", "%E", &a);
  int st = sscanf("123E9", "%E", &b);
  ck_assert_int_eq(my, st);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_float_52) {
  float a = 0;
  float b = 0;
  int my = s21_sscanf("123E-9", "%E", &a);
  int st = sscanf("123E-9", "%E", &b);
  ck_assert_int_eq(my, st);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_float_53) {
  long double a = 0;
  long double b = 0;
  int my = s21_sscanf("12367809e78", "%Le", &a);
  int st = sscanf("12367809e78", "%Le", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ldouble_eq(a, b);
}
END_TEST

//------------------ %s --------------------------

START_TEST(test_str_1) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("qwerty", "%s", a);
  int st = sscanf("qwerty", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_2) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("   qwerty", "%s", a);
  int st = sscanf("   qwerty", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_3) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("\nqwerty", "%s", a);
  int st = sscanf("\nqwerty", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_4) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("", "%s", a);
  int st = sscanf("", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_5) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("\n\n\n", "%s", a);
  int st = sscanf("\n\n\n", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_6) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("q. w. erty", "%s", a);
  int st = sscanf("q. w. erty", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_7) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("qwertyui", "%5s", a);
  int st = sscanf("qwertyui", "%5s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_8) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("....", "%s", a);
  int st = sscanf("....", "%s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_9) {
  char a[100] = {0};
  char b[100] = {0};
  int my = s21_sscanf("qwerty", "%30s", a);
  int st = sscanf("qwerty", "%30s", b);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_str_10) {
  char a[100] = {0};
  char b[100] = {0};
  char a1[100] = {0};
  char b1[100] = {0};
  int my = s21_sscanf("qwerty qwe", "%s%s", a, a1);
  int st = sscanf("qwerty qwe", "%s%s", b, b1);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_str_11) {
  char a[100] = {0};
  char b[100] = {0};
  char a1[100] = {0};
  char b1[100] = {0};
  int my = s21_sscanf("qwerty   qwe", "%s%s", a, a1);
  int st = sscanf("qwerty   qwe", "%s%s", b, b1);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_str_12) {
  char a[100] = {0};
  char b[100] = {0};
  char a1[100] = {0};
  char b1[100] = {0};
  int my = s21_sscanf("qwerty qweee", "%s%s", a, a1);
  int st = sscanf("qwerty qweee", "%s%s", b, b1);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_str_13) {
  char a[100] = {0};
  char b[100] = {0};
  char a1[100] = {0};
  char b1[100] = {0};
  int my = s21_sscanf("qwerty qwertyuio", "%s%s", a, a1);
  int st = sscanf("qwerty qwertyuio", "%s%s", b, b1);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_str_14) {
  char a[100] = {0};
  char b[100] = {0};
  char a1[100] = {0};
  char b1[100] = {0};
  int my = s21_sscanf("qwer 1 \b ty qwertyuio", "%*s%s%s", a, a1);
  int st = sscanf("qwer 1 \b ty qwertyuio", "%*s%s%s", b, b1);
  ck_assert_int_eq(my, st);
  ck_assert_str_eq(a, b);
  ck_assert_str_eq(a1, b1);
}
END_TEST

//-------------- %o ----------------

START_TEST(test_octal_1) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("123", "%o", &a);
  int st = sscanf("123", "%o", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_2) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("123456789123", "%o", &a);
  int st = sscanf("123456789123", "%o", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_3) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("-123", "%o", &a);
  int st = sscanf("-123", "%o", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_4) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("0", "%o", &a);
  int st = sscanf("0", "%o", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_5) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("12912", "%2o", &a);
  int st = sscanf("12912", "%2o", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_7) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("12912", "%ho", &a);
  int st = sscanf("12912", "%ho", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_8) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("12912045465465454123456", "%lo", &a);
  int st = sscanf("12912045465465454123456", "%lo", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_octal_9) {
  unsigned int a;
  unsigned int b;
  char a1 = 0;
  char b1 = 0;
  char a2[100] = {0};
  char b2[100] = {0};
  int my = s21_sscanf("912912 asdf", "%c%o%s", &a1, &a, a2);
  int st = sscanf("912912 asdf", "%c%o%s", &b1, &b, b2);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
  ck_assert_uint_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_octal_10) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("-1212045465465454123456", "%lo", &a);
  int st = sscanf("-1212045465465454123456", "%lo", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

//------------- %u ------------------

START_TEST(test_unsignet_1) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("123456", "%u", &a);
  int st = sscanf("123456", "%u", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_2) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("-123456", "%u", &a);
  int st = sscanf("-123456", "%u", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_3) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("123456", "%lu", &a);
  int st = sscanf("123456", "%lu", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_4) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("123456", "%hu", &a);
  int st = sscanf("123456", "%hu", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_5) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("10000000000", "%u", &a);
  int st = sscanf("10000000000", "%u", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_6) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("9223372036854775807023543450", "%lu", &a);
  int st = sscanf("922337203685477580725345234500", "%lu", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_unsignet_7) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("100000000000000000", "%hu", &a);
  int st = sscanf("100000000000000000", "%hu", &b);
  ck_assert_uint_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

//------------ %x -----------------

START_TEST(test_hex_1) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("abc7", "%x", &a);
  int st = sscanf("abc7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_2) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("abc7", "%X", &a);
  int st = sscanf("abc7", "%X", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_3) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("3456789876abc7", "%x", &a);
  int st = sscanf("3456789876abc7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_4) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("0xabc7", "%3x", &a);
  int st = sscanf("0xabc7", "%3x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_5) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("00000xabc7", "%x", &a);
  int st = sscanf("00000xabc7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_6) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("0Xabc7", "%x", &a);
  int st = sscanf("0Xabc7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_7) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("0xXabc7", "%x", &a);
  int st = sscanf("0xXabc7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_8) {
  unsigned int a;
  unsigned int b;
  int my = s21_sscanf("0Xabcf7", "%x", &a);
  int st = sscanf("0Xabcf7", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_9) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("abc7", "%lX", &a);
  int st = sscanf("abc7", "%lX", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_10) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("3456789876abc7", "%lx", &a);
  int st = sscanf("3456789876abc7", "%lx", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_11) {
  unsigned long int a;
  unsigned long int b;
  int my = s21_sscanf("0xabc7", "%lx", &a);
  int st = sscanf("0xabc7", "%lx", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_12) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("abc7", "%hX", &a);
  int st = sscanf("abc7", "%hX", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_13) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("3456789876abc7", "%hx", &a);
  int st = sscanf("3456789876abc7", "%hx", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_14) {
  unsigned short int a;
  unsigned short int b;
  int my = s21_sscanf("0xabc7", "%hx", &a);
  int st = sscanf("0xabc7", "%hx", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_17) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf(".", "%x", &a);
  int st = sscanf(".", "%x", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_hex_19) {
  unsigned long int a = 0;
  unsigned long int b = 0;
  int my = s21_sscanf(".", "%lx", &a);
  int st = sscanf(".", "%lx", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

//---------- %i ----------------

START_TEST(test_i_1) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("077", "%i", &a);
  int st = sscanf("077", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_2) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("7f7", "%i", &a);
  int st = sscanf("7f7", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_3) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("077", "%i", &a);
  int st = sscanf("077", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_4) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("0077", "%i", &a);
  int st = sscanf("0077", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_5) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("077", "%hi", &a);
  int st = sscanf("077", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_6) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("7f7", "%hi", &a);
  int st = sscanf("7f7", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_7) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("077", "%hi", &a);
  int st = sscanf("077", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_8) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("0077", "%2hi", &a);
  int st = sscanf("0077", "%2hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_9) {
  unsigned long int a = 0;
  unsigned long int b = 0;
  int my = s21_sscanf("077", "%li", &a);
  int st = sscanf("077", "%li", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_10) {
  unsigned long int a = 0;
  unsigned long int b = 0;
  int my = s21_sscanf("7f7", "%li", &a);
  int st = sscanf("7f7", "%li", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_11) {
  unsigned long int a = 0;
  unsigned long int b = 0;
  int my = s21_sscanf("077", "%li", &a);
  int st = sscanf("077", "%li", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_12) {
  unsigned long int a = 0;
  unsigned long int b = 0;
  int my = s21_sscanf("0077", "%li", &a);
  int st = sscanf("0077", "%li", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_13) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("01234324224377", "%hi", &a);
  int st = sscanf("01234324224377", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_14) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("    0x123456789123456", "%hi", &a);
  int st = sscanf("   0x123456789123456", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_15) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("-7", "%i", &a);
  int st = sscanf("-7", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_16) {
  unsigned int a = 0;
  unsigned int b = 0;
  int my = s21_sscanf("-0x7", "%i", &a);
  int st = sscanf("-0x7", "%i", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_17) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int my = s21_sscanf("-0x123456789123456", "%hi", &a);
  int st = sscanf("-0x123456789123456", "%hi", &b);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_i_18) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  int a1 = 0;
  int b1 = 0;
  int my = s21_sscanf("-0x123456789123456", "%hi%n", &a, &a1);
  int st = sscanf("-0x123456789123456", "%hi%n", &b, &b1);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_i_19) {
  unsigned short int a = 0;
  unsigned short int b = 0;
  char a4[100] = {0};
  char b4[100] = {0};
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int a3 = 0;
  int b3 = 0;
  int my = s21_sscanf("-0x123456789123456 asdf", "%hi%n%s%n%*c%n", &a, &a1, a4,
                      &a2, &a3);
  int st = sscanf("-0x123456789123456 asdf", "%hi%n%s%n%*c%n", &b, &b1, b4, &b2,
                  &b3);
  ck_assert_int_eq(my, st);
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_str_eq(a4, b4);
}
END_TEST

//      САХАЯ

START_TEST(test_sscanf1_c) {
  char format[100] = "%c";
  char str[100] = "s";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf2_c) {
  char format[100] = "%c";
  char str[100] = "";
  char a = 0, b = 0;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf3_c) {
  char format[100] = "%c";
  char str[100] = "hi\thi";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf4_c) {
  char format[100] = "%c %c %c";
  char str[100] = "hi\thi h";
  char o1, o2, o3, s1, s2, s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf5_d) {
  char format[100] = "%d %d %d 45%*d %d";
  char str[100] = "1 2 3 45 6 7";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf7_d) {
  char format[100] = "%hd %4hd %d 45%hd";
  char str[100] = "12 23 34 45 56";
  short o1, o2, o4, s1, s2, s4;
  int o3, s3;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf8_d) {
  char format[100] = "%ld %4ld %d 45%ld";
  char str[100] = "12 -23 34 45 56";
  long int o1, o2, o4, s1, s2, s4;
  int o3, s3;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_pointer) {
  void* a;
  void* b;
  int my = s21_sscanf("0x698a78876a67", "%p", &a);
  int st = sscanf("0x698a78876a67", "%p", &b);
  ck_assert_int_eq(my, st);
  ck_assert_ptr_eq(a, b);
}
END_TEST

Suite* suite_sscanf(void) {
  Suite* suite = suite_create("suite_sscanf");
  TCase* tc_core = tcase_create("tc_core");

  //------------ %d --------------------
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  tcase_add_test(tc_core, test_9);
  tcase_add_test(tc_core, test_10);
  tcase_add_test(tc_core, test_11);
  tcase_add_test(tc_core, test_12);
  tcase_add_test(tc_core, test_13);
  tcase_add_test(tc_core, test_14);
  tcase_add_test(tc_core, test_15);
  tcase_add_test(tc_core, test_16);
  tcase_add_test(tc_core, test_17);
  tcase_add_test(tc_core, test_18);
  tcase_add_test(tc_core, test_19);
  tcase_add_test(tc_core, test_20);
  tcase_add_test(tc_core, test_21);
  tcase_add_test(tc_core, test_22);
  tcase_add_test(tc_core, test_23);
  tcase_add_test(tc_core, test_24);
  tcase_add_test(tc_core, test_26);
  tcase_add_test(tc_core, test_27);  // ld start
  tcase_add_test(tc_core, test_28);
  tcase_add_test(tc_core, test_29);
  tcase_add_test(tc_core, test_30);
  tcase_add_test(tc_core, test_31);
  tcase_add_test(tc_core, test_32);
  tcase_add_test(tc_core, test_33);
  tcase_add_test(tc_core, test_34);
  tcase_add_test(tc_core, test_35);
  tcase_add_test(tc_core, test_36);
  tcase_add_test(tc_core, test_37);
  tcase_add_test(tc_core, test_38);
  tcase_add_test(tc_core, test_39);
  tcase_add_test(tc_core, test_40);
  tcase_add_test(tc_core, test_41);
  tcase_add_test(tc_core, test_42);
  tcase_add_test(tc_core, test_43);
  tcase_add_test(tc_core, test_44);
  tcase_add_test(tc_core, test_45);
  tcase_add_test(tc_core, test_46);
  tcase_add_test(tc_core, test_47);
  tcase_add_test(tc_core, test_48);
  tcase_add_test(tc_core, test_49);
  tcase_add_test(tc_core, test_50);
  tcase_add_test(tc_core, test_51);
  tcase_add_test(tc_core, test_52);
  tcase_add_test(tc_core, test_53);
  tcase_add_test(tc_core, test_54);
  tcase_add_test(tc_core, test_55);
  tcase_add_test(tc_core, test_56);
  tcase_add_test(tc_core, test_57);
  tcase_add_test(tc_core, test_58);
  tcase_add_test(tc_core, test_59);
  tcase_add_test(tc_core, test_60);
  tcase_add_test(tc_core, test_61);
  tcase_add_test(tc_core, test_62);
  tcase_add_test(tc_core, test_63);
  tcase_add_test(tc_core, test_64);
  tcase_add_test(tc_core, test_65);
  tcase_add_test(tc_core, test_66);
  tcase_add_test(tc_core, test_67);
  tcase_add_test(tc_core, test_68);
  tcase_add_test(tc_core, test_69);
  tcase_add_test(tc_core, test_70);
  tcase_add_test(tc_core, test_71);
  tcase_add_test(tc_core, test_72);
  tcase_add_test(tc_core, test_73);
  tcase_add_test(tc_core, test_74);
  tcase_add_test(tc_core, test_75);
  tcase_add_test(tc_core, test_76);
  tcase_add_test(tc_core, test_77);
  // ----------  %c  ----------------
  tcase_add_test(tc_core, test_char_1);
  tcase_add_test(tc_core, test_char_2);
  tcase_add_test(tc_core, test_char_3);
  tcase_add_test(tc_core, test_char_4);
  tcase_add_test(tc_core, test_char_5);
  tcase_add_test(tc_core, test_char_6);
  tcase_add_test(tc_core, test_char_7);
  tcase_add_test(tc_core, test_char_8);
  tcase_add_test(tc_core, test_char_9);
  tcase_add_test(tc_core, test_char_10);
  tcase_add_test(tc_core, test_char_11);
  // -----------  %f  ----------------
  tcase_add_test(tc_core, test_float_1);
  tcase_add_test(tc_core, test_float_2);
  tcase_add_test(tc_core, test_float_5);
  tcase_add_test(tc_core, test_float_3);
  tcase_add_test(tc_core, test_float_4);
  tcase_add_test(tc_core, test_float_6);
  tcase_add_test(tc_core, test_float_7);
  tcase_add_test(tc_core, test_float_8);
  tcase_add_test(tc_core, test_float_9);
  tcase_add_test(tc_core, test_float_10);
  tcase_add_test(tc_core, test_float_11);
  tcase_add_test(tc_core, test_float_12);
  tcase_add_test(tc_core, test_float_13);
  tcase_add_test(tc_core, test_float_14);
  tcase_add_test(tc_core, test_float_16);
  tcase_add_test(tc_core, test_float_17);
  tcase_add_test(tc_core, test_float_18);
  tcase_add_test(tc_core, test_float_19);
  tcase_add_test(tc_core, test_float_20);
  tcase_add_test(tc_core, test_float_21);
  tcase_add_test(tc_core, test_float_22);
  tcase_add_test(tc_core, test_float_23);
  tcase_add_test(tc_core, test_float_24);
  tcase_add_test(tc_core, test_float_25);
  tcase_add_test(tc_core, test_float_26);
  tcase_add_test(tc_core, test_float_27);
  tcase_add_test(tc_core, test_float_28);
  tcase_add_test(tc_core, test_float_29);
  tcase_add_test(tc_core, test_float_30);
  tcase_add_test(tc_core, test_float_31);
  tcase_add_test(tc_core, test_float_32);
  tcase_add_test(tc_core, test_float_33);
  tcase_add_test(tc_core, test_float_34);
  tcase_add_test(tc_core, test_float_36);
  tcase_add_test(tc_core, test_float_37);
  tcase_add_test(tc_core, test_float_38);
  tcase_add_test(tc_core, test_float_39);
  tcase_add_test(tc_core, test_float_40);
  tcase_add_test(tc_core, test_float_41);
  tcase_add_test(tc_core, test_float_42);
  tcase_add_test(tc_core, test_float_43);
  tcase_add_test(tc_core, test_float_44);
  tcase_add_test(tc_core, test_float_45);
  tcase_add_test(tc_core, test_float_46);
  tcase_add_test(tc_core, test_float_47);
  tcase_add_test(tc_core, test_float_48);
  tcase_add_test(tc_core, test_float_49);
  tcase_add_test(tc_core, test_float_50);
  tcase_add_test(tc_core, test_float_51);
  tcase_add_test(tc_core, test_float_52);
  tcase_add_test(tc_core, test_float_53);
  //----------- %s -----------------------
  tcase_add_test(tc_core, test_str_1);
  tcase_add_test(tc_core, test_str_2);
  tcase_add_test(tc_core, test_str_3);
  tcase_add_test(tc_core, test_str_4);
  tcase_add_test(tc_core, test_str_5);
  tcase_add_test(tc_core, test_str_6);
  tcase_add_test(tc_core, test_str_7);
  tcase_add_test(tc_core, test_str_8);
  tcase_add_test(tc_core, test_str_9);
  tcase_add_test(tc_core, test_str_10);
  tcase_add_test(tc_core, test_str_11);
  tcase_add_test(tc_core, test_str_12);
  tcase_add_test(tc_core, test_str_13);
  tcase_add_test(tc_core, test_str_14);

  //----------- %o --------------------
  tcase_add_test(tc_core, test_octal_1);
  tcase_add_test(tc_core, test_octal_2);
  tcase_add_test(tc_core, test_octal_3);
  tcase_add_test(tc_core, test_octal_4);
  tcase_add_test(tc_core, test_octal_5);
  tcase_add_test(tc_core, test_octal_7);
  tcase_add_test(tc_core, test_octal_8);
  tcase_add_test(tc_core, test_octal_9);
  tcase_add_test(tc_core, test_octal_10);

  // ---------- %u -------------------
  tcase_add_test(tc_core, test_unsignet_1);
  tcase_add_test(tc_core, test_unsignet_2);
  tcase_add_test(tc_core, test_unsignet_3);
  tcase_add_test(tc_core, test_unsignet_4);
  tcase_add_test(tc_core, test_unsignet_5);
  tcase_add_test(tc_core, test_unsignet_6);
  tcase_add_test(tc_core, test_unsignet_7);

  // -------------------- %x ----------------
  tcase_add_test(tc_core, test_hex_1);
  tcase_add_test(tc_core, test_hex_2);
  tcase_add_test(tc_core, test_hex_3);
  tcase_add_test(tc_core, test_hex_4);
  tcase_add_test(tc_core, test_hex_5);
  tcase_add_test(tc_core, test_hex_6);
  tcase_add_test(tc_core, test_hex_7);
  tcase_add_test(tc_core, test_hex_8);
  tcase_add_test(tc_core, test_hex_9);
  tcase_add_test(tc_core, test_hex_10);
  tcase_add_test(tc_core, test_hex_11);
  tcase_add_test(tc_core, test_hex_12);
  tcase_add_test(tc_core, test_hex_13);
  tcase_add_test(tc_core, test_hex_14);
  tcase_add_test(tc_core, test_hex_17);
  tcase_add_test(tc_core, test_hex_19);

  // -------- %i ------------
  tcase_add_test(tc_core, test_i_1);
  tcase_add_test(tc_core, test_i_2);
  tcase_add_test(tc_core, test_i_3);
  tcase_add_test(tc_core, test_i_4);
  tcase_add_test(tc_core, test_i_5);
  tcase_add_test(tc_core, test_i_6);
  tcase_add_test(tc_core, test_i_7);
  tcase_add_test(tc_core, test_i_8);
  tcase_add_test(tc_core, test_i_9);
  tcase_add_test(tc_core, test_i_10);
  tcase_add_test(tc_core, test_i_11);
  tcase_add_test(tc_core, test_i_12);
  tcase_add_test(tc_core, test_i_13);
  tcase_add_test(tc_core, test_i_14);
  tcase_add_test(tc_core, test_i_15);
  tcase_add_test(tc_core, test_i_16);
  tcase_add_test(tc_core, test_i_17);
  tcase_add_test(tc_core, test_i_18);
  tcase_add_test(tc_core, test_i_19);

  tcase_add_test(tc_core, test_sscanf1_c);
  tcase_add_test(tc_core, test_sscanf2_c);
  tcase_add_test(tc_core, test_sscanf3_c);
  tcase_add_test(tc_core, test_sscanf4_c);
  tcase_add_test(tc_core, test_sscanf5_d);
  tcase_add_test(tc_core, test_sscanf7_d);
  tcase_add_test(tc_core, test_sscanf8_d);
  // tcase_add_test(tc_core, test_sscanf7_s);

  tcase_add_test(tc_core, test_pointer);

  suite_add_tcase(suite, tc_core);
  return suite;
}
