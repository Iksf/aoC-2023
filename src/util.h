#ifndef util_h
#define util_h
#include <assert.h>
#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/stat.h>

#define LIKELY(x) __builtin_expect(!!(x), 1L)
#define UNLIKELY(x) __builtin_expect(!!(x), 0L)

void read_file(const char *file_name, char **const buf);

#endif
