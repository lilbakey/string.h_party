CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LIBFLAGS=-lcheck -lm -lsubunit -lrt -lpthread

CFILES=$(wildcard s21_*.c)
OFILES=$(patsubst %.c, %.o, $(CFILES))

TEST_DIR=tests
TEST_CFILES=$(wildcard $(TEST_DIR)/*_test.c)
TEST_OFILES=$(patsubst %.c, %.o, $(TEST_CFILES))

.PHONY: all s21_string.a test gcov_report check clean

all: s21_string.a

s21_string.a: $(CFILES)
	$(CC) -c $(CFLAGS) $(CFILES)
	ar rcs $@ $(OFILES)
	ranlib $@

test: $(TEST_CFILES) s21_string.a
	# $(CC) $(CFLAGS) -c $(TEST_CFILES) $(LIBFLAGS)
	$(CC) $(CFLAGS) $^ -o test.out $(LIBFLAGS)

gcov_report: CFLAGS += --coverage -O0
gcov_report: clean test
	gcov -f $(CFILES)
	mkdir report
	./test.out
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory ./report

check:
	clang-format -style='{BasedOnStyle: Google}' -i *.c
	clang-format -style='{BasedOnStyle: Google}' -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	valgrind --tool=memcheck --leak-check=yes ./test.out

clean:
	rm -f *.o s21_string.a
	rm -f test.out
	rm -f *.gcno *.gcov *.gcda
	rm -f *.info
	rm -fr ./report
