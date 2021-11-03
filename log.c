#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "log.h"

void log_write(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);
    va_end(arg);
}

unsigned int log_timestamp(void)
{
    return 0;
}