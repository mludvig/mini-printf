CFLAGS = --std=c99 -O2 -pedantic -Wall -Wextra -Wshadow
CFLAGS += -Wstrict-prototypes -Wmissing-prototypes -Wundef
CFLAGS += -Wpointer-arith -Wcast-align -Wcast-qual -Wredundant-decls

%_check: %.out %.gold
	cmp $^
	@echo PASS

all test: test1_check

test1: mini-printf.o

test1.out: test1
	./test1 > $@

clean:
	rm -f *.o test1 test1.out
