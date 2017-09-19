#include <stdio.h>
#include "mini-printf.h"

int main(void)
{
	char buff[30];
	mini_snprintf(buff, sizeof buff, "testing %d %d %07d", 1, 2, 3);
	puts(buff);
	mini_snprintf(buff, sizeof buff, "faster %s %ccheaper%c", "and", 34, 34);
	puts(buff);
	mini_snprintf(buff, sizeof buff, "%x %% %X", 0xdeadf00d, 0xdeadf00d);
	puts(buff);
	mini_snprintf(buff, sizeof buff, "%09d%09d%09d%09d%09d", 1, 2, 3, 4, 5);
	puts(buff);
	mini_snprintf(buff, sizeof buff, "%d %u %d %u", 50, 50, -50, -50);
	puts(buff);
	return 0;
}
