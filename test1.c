#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mini-printf.h"

int handler(void* data, void* obj, int ch, int len_hint, char **buf)
{
	if(data != NULL) return 0;
	*buf = malloc(32);
	mini_snprintf(*buf, 32, "%cA%03dB%03dC", ch, strlen(obj), len_hint);
	return strlen(*buf);
}

void freeor(void* data, void* buf)
{
	if(data != NULL) return;
	free(buf);
}

int main(void)
{
	mini_printf_set_handler(NULL, handler, freeor);
    int n;
	char buff[30];
	n = mini_snprintf(buff, sizeof buff, "%07d %7d %010d", 1, 2, 3);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "%07lX %7lX %016lX", 0xffffffffffL, 0xffffffffffL, 0xffffffffffL);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "%010O %04R", "object1", "object2");
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "testing %d %d %07d", 1, 2, 3);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "faster %s %ccheaper%c", "and", 34, 34);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "%x %% %X", 0xdeadf00d, 0xdeadf00d);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "%09d%09d%09d%09d%09d", 1, 2, 3, 4, 5);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	n = mini_snprintf(buff, sizeof buff, "%d %u %d %u", 50, 50, -50, -50);
	puts(buff); mini_snprintf(buff, sizeof buff, "%d", n); puts(buff);
	return 0;
}
