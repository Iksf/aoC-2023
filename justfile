run DAY:
  mkdir -p build; cd build; cc -Os -march=native ../src/util.c ../src/aoc_{{DAY}}.c; ./a.out
