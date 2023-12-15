#include "util.h"
#include <time.h>
#define INNER_IF                                                               \
  if ((*s > '9' || *s < '0') && *s != '.' && *s != '\n' && *s != '\0') {       \
    total += i;                                                                \
    goto end_outer_while;                                                      \
  }

ulong part_1(const char *const in, const char *const end) {
  const char *ptr = in;
  ulong line_length = strchr(in, '\n') - in;
  char *ptr2 = NULL;
  ulong total = 0;
  while (LIKELY(ptr < end)) {
    while (*ptr < '0' || *ptr > '9') {
      if (UNLIKELY(ptr >= end)) {
        goto end;
      }
      ptr++;
    }
    long i = strtol(ptr, &ptr2, 10);
    // above
    for (const char *s = ptr - line_length - 1 // newline
                         - 1                   // diagonal
         ;
         s != ptr2 - line_length - 1 // newline
                  + 1                // other diagonal
         && s > in;
         s++)
      INNER_IF;

    // below
    for (const char *s = ptr + line_length + 1 // newline
                         - 1                   // diagonal
         ;
         s != ptr2 + line_length + 1 // newline
                  + 1                // other diagonal
         && LIKELY(s < end);
         s++)
      INNER_IF;

    // left
    for (const char *const s = ptr - 1; LIKELY(ptr >= in);) {
      INNER_IF;
      break;
    }
    // right
    for (const char *const s = ptr2; LIKELY(s < end);) {
      INNER_IF;
      break;
    }
  end_outer_while:
    ptr = ptr2;
  }
end:

  return total;
}

int main() {
  char *buf = NULL;
  read_file("../problems/day_3_input.txt", &buf);
  const char *const end_pos = buf + strlen(buf) + 1;
  for (int i = 0; i < 10; i++)
    part_1(buf, end_pos);

  // ...

  struct timespec start, end;
  long seconds, nanoseconds;
  double elapsed;

  clock_gettime(CLOCK_MONOTONIC, &start);

  long total = part_1(buf, end_pos);

  clock_gettime(CLOCK_MONOTONIC, &end);

  seconds = end.tv_sec - start.tv_sec;
  nanoseconds = end.tv_nsec - start.tv_nsec;
  elapsed = (seconds * 1e6) + nanoseconds / 1e3;

  printf("Part 1: %ld (%.1fµs)\n", total, elapsed);

  //   problem_1(
  //       R"(*467.114..
  // ..........
  // ..35*.633*
  // ..........
  // 617*......
  // .....+.58.
  // ..592.....
  // ......755.
  // ...$.*....
  // .664.598..
  // )");
}
