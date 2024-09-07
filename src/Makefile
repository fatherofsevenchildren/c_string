CC = gcc
FLAGS = -Wall -Werror -Wextra -pedantic
LIB = s21_string
FILES=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${FILES})
GCO=--coverage
T_FILES= test_me.c
UNAME := $(shell uname)

ifeq ($(UNAME), Linux) #Определяем OS
	OPEN_CMD = xdg-open
	TEST_LIB = -lcheck -lm -pthread -lrt -lsubunit
endif
ifeq ($(UNAME), Darwin)
	OPEN_CMD = open
	TEST_LIB = -lcheck
endif

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: s21_string.a

s21_string.a: $(FILES)
	@gcc -c $(FLAGS) $(TEST_LIB) $(FILES)
	@ar rc s21_string.a $(OBJ)

test: clean $(LIB).a
	$(CC) -o test tests/*.c $(LIB).a $(TEST_LIB)
	./test

gcov_report:
	@$(CC) $(FLAGS) $(GCO) $(FILES) -o test tests/*.c $(TEST_LIB)
	./test
	lcov --capture --directory . --output-file=coverage.info
	genhtml coverage.info --output-directory=res
	open ./res/index.html

clean:
	@-rm -rf *.o string test *.a *res *.info *.gcda *.gcno

style:
	@clang-format --style=Google -n *.c *.h

clang:
	clang-format --style=Google -i *.c *.h

.PHONY:
	all test clean s21_math gcov_report
	