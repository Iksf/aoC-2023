#include "util.h"

long part_1(const char *const input) {
  long start = 0, end = 0, res = 0, acc = 0;
  do {
    for (long i = start;; i++) {
      char c = input[i];
      if (c == '\n' || c == '\0') {
        end = i;
        break;
      }
    }
    for (long i = end; i >= start; --i) {
      char c = input[i];
      if (c >= '0' && c <= '9') {
        res = (long)(c - '0');
        break;
      }
    }
    for (long i = start; i < end; i++) {
      char c = input[i];
      if (c >= '0' && c <= '9') {
        res += ((long)(c - '0')) * 10;
        break;
      }
    }
    acc += res;
    res = 0;
    start = end + 1;
  } while (LIKELY(input[end] != '\0'));
  return acc;
}

#define NUMBERS 9
#define LEN_CHARS_WITH_TERM 6

struct p2dict {
  char dict[NUMBERS][LEN_CHARS_WITH_TERM];
  int lens[NUMBERS];
};

__attribute__((const)) static inline const struct p2dict build_p2dict() {
  struct p2dict dict = {.dict = {"one", "two", "three", "four", "five", "six",
                                 "seven", "eight", "nine"}};
  for (int i = 0; i < NUMBERS; i++)
    dict.lens[i] = strlen(dict.dict[i]);
  return dict;
}

long part_2(char *const input) {
  const struct p2dict dict = build_p2dict();
  const char *const pat = "(one|two|three|four|five|six|seven|eight|nine)";
  regex_t regex;
  regmatch_t match[2];
  char *cursor = input;
  int r = regcomp(&regex, pat, REG_EXTENDED);
  if (UNLIKELY(r))
    exit(1);
  do {
    r = regexec(&regex, cursor, 2, match, 0);
    regmatch_t m = match[1];
    if (LIKELY(m.rm_eo != 0)) {
      int s = m.rm_eo - m.rm_so;
      for (int i = 0; i < NUMBERS; i++) {
        if (s > dict.lens[i])
          continue;
        if (memcmp(dict.dict[i], cursor + m.rm_so, s) == 0) {
          cursor[m.rm_so] = '0' + i + 1;
          cursor = input + m.rm_so;
          break;
        }
      }
    }
  } while (LIKELY(r != REG_NOMATCH));
  return part_1(input);
}

int main(int argc, char **argv) {
  char *buf = NULL;
  read_file("../problems/day_1_input.txt", &buf);
  long res1 = part_1(buf);
  printf("PART1 IS %ld\n", res1);
  long res2 = part_2(buf);
  printf("PART2 IS %ld\n", res2);
  return 0;
}
