CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LIBFLAGS=-lcheck -lm -lsubunit -lrt -lpthread

CFILES=$(wildcard s21_*.c)
OFILES=$(patsubst %.c, %.o, $(CFILES))

TEST_DIR=tests
TEST_CFILES=$(wildcard $(TEST_DIR)/*_test.c)
TEST_OFILES=$(patsubst %.c, %.o, $(TEST_CFILES))


all: s21_string.a

s21_string.a: $(CFILES)
	$(CC) -c $(CFLAGS) $(CFILES)
	ar rcs $@ $(OFILES)
	ranlib $@

tests: $(TEST_CFILES) s21_string.a
	# $(CC) $(CFLAGS) -c $(TEST_CFILES) $(LIBFLAGS)
	$(CC) $(CFLAGS) $^ -o test.out $(LIBFLAGS)

check:
	clang-format -style='{BasedOnStyle: Google}' -i *.c
	# clang-format -style='{BasedOnStyle: Google}' -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

clean:
	rm -f *.o s21_string.a test.out