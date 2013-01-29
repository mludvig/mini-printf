/*
 * The Minimal snprintf() implementation
 * Copyright (c) 2013 Michal Ludvig <michal@logix.cz>
 */


#ifndef __MINI_PRINTF__
#define __MINI_PRINTF__

#include <stdarg.h>

int mini_vsnprintf(char* buffer, unsigned int buffer_len, char *fmt, va_list va);
int mini_snprintf(char* buffer, unsigned int buffer_len, char *fmt, ...);

#define vsnprintf mini_vsnprintf
#define snprintf mini_snprintf

#endif
