CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
LDLIBS=-lcheck -lm -lsubunit -lrt -lpthread

SOURCES=./tests/string_suite.c ./tests/string_strlen_test.c s21_strlen.c 

all: tests

tests:
	$(CC) $(CFLAGS) $(SOURCES) $(LDLIBS)

check:
	clang-format -style='{BasedOnStyle: Google}' -i *.c
	# clang-format -style='{BasedOnStyle: Google}' -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

