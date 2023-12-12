#include "util.h"

__attribute_pure__ ulong to_next_symbol(const char **s) {
  for (int i = 1;; i++) {
    char c = (*s)[i];
    if (c != '.' && c >= '!' && c <= '/') {
      *s += i;
      return 0;
    }
    if (c == 0) {
      return 1;
    }
  }
}

__attribute_pure__ static inline ulong make_offsets(ushort *const offsets,
                                                    const char *const in) {
  const char *current = in;
  for (ushort i = 0;; i++) {
    if (to_next_symbol(&current) != 0) {
      return (ulong)i;
    } else {
      ushort v = (ushort)(current - in);
      offsets[i] = v;
    }
  }
}

ulong problem_1(const char *const in) {
  const int line_length = strchr(in, '\n') - in;
  const int data_end = strlen(in);
  char *const buf = calloc(line_length, 1);
  // len fits in a ushort so lets save some space
  ushort *const offsets = calloc(1000, sizeof(ushort)); // todo
  const int offset_len = make_offsets(offsets, in);
  printf("%d\n", offset_len);
}

int main() {
  // char *buf = NULL;
  // read_file("../problems/day_3_input.txt", &buf);
  problem_1(R"(467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..)");
}
