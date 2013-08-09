/*
ID: sirup1
PROG: milk2
LANG: C++
*/
#include <cstdlib>
#include <cstdio>

int main()
{
  FILE * i_file;
  i_file = fopen("milk2.in", "r");

  int n;
  fscanf(i_file, "%d", &n);

  int max_idle = 0;
  int max_milking_time = 0;

  int range_start = 0;
  int range_end = 0;

  for(int i = 0; i < n; i++) {
    int time_start;
    int time_end;

    fscanf(i_file, "%d %d", &time_start, &time_end);

    if (range_end == 0) range_end = time_end;
    if (range_start == 0) range_start = time_start;

    // is this time within the current range?
    if (time_start > (range_end + 1))
    {
      // calculate continues milking time
      int continues_milking_time = range_end - range_start;
      if (continues_milking_time > max_milking_time) max_milking_time = continues_milking_time;

      // printf("Continues milking time [%d;%d]: %d\n", range_start, range_end, continues_milking_time);

      // yep
      int idle_time = time_start - range_end;
      // printf("Idle time [%d;%d].. %d\n", time_start, range_end, idle_time);
      if (idle_time > max_idle) max_idle = idle_time;

      // set range start again, to not fuck up continues milking times
      range_start = time_start;
      range_end = time_end;
    }

    // only set end range, if the milking end time is actually larger
    if (time_end > range_end) range_end = time_end;

    if (n == 1) max_milking_time = time_end - time_start;
    if (n == 1) max_idle = 0;
  }

  FILE * o_file;
  o_file = fopen("milk2.out", "w");

  fprintf(o_file, "%d %d\n", max_milking_time, max_idle);

  return 0;
}
