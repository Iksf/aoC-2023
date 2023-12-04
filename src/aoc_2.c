#include "util.h"
#define SWITCH_CASE_HANDLE_RGB(l, n, str)                                      \
  case l: {                                                                    \
    if (num > vals[n])                                                         \
      vals[n] = num;                                                           \
    term = space_after_num + strlen(str) + 1;                                  \
    break;                                                                     \
  }

long part_1(const char *input) {
  long total = 0;
  const char *row_cursor = input;
  const char *group_cursor;
  char val[3];
  int vals[3]; // rgb
  char *num_start, *row_first_num_start;
b:
  row_first_num_start = num_start = strchr(row_cursor, ':') + 2;
  memset(vals, 0, 3 * sizeof(int));
a:
  memset(val, '\0', 3);
  char *space_after_num = strchr(num_start, ' ');
  memcpy(val, num_start, space_after_num - num_start);
  int num = atoi(val);
  char *term;
  switch (*(space_after_num + 1)) {
    SWITCH_CASE_HANDLE_RGB('r', 0, "red")
    SWITCH_CASE_HANDLE_RGB('g', 1, "green")
    SWITCH_CASE_HANDLE_RGB('b', 2, "blue")
  }
  switch (*term) {
  case '\0':
  case '\n': {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
      if (vals[i] > (12 + i)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      const char *row_num_start = row_cursor + 5;
      const char *row_num_end = row_first_num_start + 1;
      char row_num[5];
      memset(row_num, '\0', 5);
      memcpy(row_num, row_num_start, row_num_end - row_num_start - 1);
      total += (long)atoi(row_num);
    }
    if (UNLIKELY(*term == '\0') || UNLIKELY(*(term + 1) == '\0')) {
      return total;
    }
    row_cursor = term + 1;
    goto b;
  }
  case ';':
  case ',': {
    num_start = term + 2;
    goto a;
  }
  }
  __builtin_unreachable();
}

int main() {
  char *buf = NULL;
  read_file("../problems/day_2_input.txt", &buf);
  long total = part_1(buf);
  printf("%ld\n", total);
}
