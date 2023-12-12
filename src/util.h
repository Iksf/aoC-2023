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

// atoi without needing null term string
__attribute__((const)) inline long to_num_signed(const char *s, long n) {
  long result = 0;
  long sign = 1;
  long i = 0;
  if (s[0] == '-') {
    sign = -1;
    i = 1;
  }
  for (; i < n && isdigit(s[i]); ++i)
    result = result * 10 + (s[i] - '0');

  return result * sign;
}

__attribute__((const)) inline ulong to_num_unsigned(const char *s, long n) {
  ulong result = 0;
  long i = 0;
  for (; i < n && isdigit(s[i]); ++i)
    result = result * 10 + (s[i] - '0');

  return result;
}

#endif
