#include <stdio.h>
#ifndef _LIBC_REVERT
#include "mini-printf.h"
#define snprintf mini_snprintf
#endif

int main(void)
{
	char buff[30];
	snprintf(buff, sizeof buff, "testing %d %d %07d", 1, 2, 3);
	puts(buff);
	snprintf(buff, sizeof buff, "faster %s %ccheaper%c", "and", 34, 34);
	puts(buff);
	snprintf(buff, sizeof buff, "%x %% %X", 0xdeadf00d, 0xdeadf00d);
	puts(buff);
	snprintf(buff, sizeof buff, "%09d%09d%09d%09d%09d", 1, 2, 3, 4, 5);
	puts(buff);
	snprintf(buff, sizeof buff, "%d %u %d %u", 50, 50, -50, -50);
	puts(buff);
	snprintf(buff, sizeof buff, "%0");
	puts(buff);
	snprintf(buff, sizeof buff, "a%0");
	puts(buff);
	snprintf(buff, sizeof buff, "%");
	puts(buff);
	snprintf(buff, sizeof buff, "b%");
	puts(buff);
	snprintf(buff, 0, "%s", "hello");
	puts(buff);
	snprintf(buff, sizeof buff, "");
	puts(buff);
	snprintf(buff, sizeof buff, "(%6d) (%12d)", 78, 78);
	puts(buff);
	snprintf(buff, sizeof buff, "(%s) (%12s) (%s)", "a", "b", "xcccccccccccccccx");
	puts(buff);
	snprintf(buff, sizeof buff, "(%s)", "xcccccccccccccccx");
	puts(buff);
	return 0;
}
