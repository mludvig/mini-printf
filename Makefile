CFLAGS = --std=c99 -O2 -pedantic -Wall -Wextra -Wshadow -DMINI_PRINTF_ENABLE_OBJECTS

%_check: %.out %.gold
	cmp $^
	@echo PASS

size_check:
	echo WITHOUT_PRINTF_ENABLE_OBJECTS
	$(CC) -std=c99 -Os -pedantic -Wall -Wextra -Wshadow mini-printf.c -c -o tmp-mini-printf.o
	ls -l tmp-mini-printf.o
	echo WITHOUT_PRINTF_ENABLE_OBJECTS
	$(CC) -std=c99 -Os -pedantic -Wall -Wextra -Wshadow -DMINI_PRINTF_ENABLE_OBJECTS mini-printf.c -c -o tmp-mini-printf.o
	ls -l tmp-mini-printf.o
all test: test1_check

test1: mini-printf.o

test1.out: test1
	./test1 > $@

clean:
	rm -f *.o test1 test1.out
