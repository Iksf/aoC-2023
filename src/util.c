#include "util.h"
#include <ctype.h>

void read_file(const char *const file_name, char **const buf) {
  FILE *fp = NULL;
  long file_size;
  bool success = false;

  fp = fopen(file_name, "r");
  if (UNLIKELY(!fp)) {
    fputs("Error opening file\n", stderr);
    exit(1);
  }

  if (UNLIKELY(fseek(fp, 0, SEEK_END) != 0) ||
      UNLIKELY((file_size = ftell(fp)) == -1)) {
    fputs("Error determining file size\n", stderr);
    goto cleanup;
  }
  rewind(fp);
  *buf = malloc(file_size + 1);
  if (fread(*buf, 1, file_size, fp) < file_size) {
    fputs("Error reading file\n", stderr);
    goto cleanup;
  }

  (*buf)[file_size] = '\0';
  success = true;

cleanup:
  if (LIKELY(fp)) {
    fclose(fp);
  }
  if (!success || *buf == NULL) {
    exit(1);
  }
}

// atoi without needing null term string
long to_num_signed(const char *s, long n) {
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

ulong to_num_unsigned(const char *s, long n) {
  long result = 0;
  long i = 0;
  for (; i < n && isdigit(s[i]); ++i)
    result = result * 10 + (s[i] - '0');

  return result;
}
