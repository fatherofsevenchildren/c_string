#include "test_me.h"

START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!";
  char s2[] = "hELLO, WORLD!";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s21_to_lower(s1), s21_to_lower(s2));
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s2[30] = "\nH\t\\G123123";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s21_to_lower(s1), s21_to_lower(s2));
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "already lower";
  char s2[30] = "already lower";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s2[30] = "";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s2[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s21_to_lower(s1), s21_to_lower(s2));
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s2[30] = "_?};!234";
  s21_to_lower(s2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  s21_to_lower(s2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_LOWER=-\033[0m");
  TCase *tc = tcase_create("to_lower_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  suite_add_tcase(s, tc);
  return s;
}
