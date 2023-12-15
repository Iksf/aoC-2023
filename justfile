run DAY:
  mkdir -p build; touch outs/{{DAY}}.txt; cd build; cc -Os -march=native ../src/util.c ../src/aoc_{{DAY}}.c; ./a.out | tee ../outs/{{DAY}}.txt
