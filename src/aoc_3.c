#include "util.h"

static inline ulong to_next_symbol(const char **s) {
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

typedef struct {
  const ushort *const offsets; // max fits in a ushort so lets save some space
  const ulong len;
} symbol_offsets_t;

symbol_offsets_t make_offsets(const char *const in) {
  ushort *const offsets = calloc(1000, sizeof(ushort)); // todo
  const char *current = in;
  for (ushort i = 0;; i++) {
    if (UNLIKELY(to_next_symbol(&current) != 0)) {
      return (symbol_offsets_t){
          .offsets = offsets,
          .len = (ulong)i,
      };
    }
    ushort v = (ushort)(current - in);
    offsets[i] = v;
  }
}

ulong problem_1(const char *const in) {
  const int line_length = strchr(in, '\n') - in;
  const int data_end = strlen(in);
  symbol_offsets_t offsets = make_offsets(in);
  printf("%ld\n", offsets.len);
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
