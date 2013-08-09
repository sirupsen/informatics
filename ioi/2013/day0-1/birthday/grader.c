#include <stdio.h>
#include <stdlib.h>
#include "birthday.h"

#define fail(s, x...) do { \
  fprintf(stderr, s "\n", ## x); \
  exit(1); \
} while(0)

#define MAX_R 500
#define MAX_N 1000

int X1[MAX_N];
int Y1[MAX_N];
int X2[MAX_N];
int Y2[MAX_N];

int main() {
  int R, N, i;
  int res;

  FILE *f = fopen("birthday.in", "r");
  if (!f)
    fail("Failed to open input file.");

  res = fscanf(f, "%d", &R);
  if (res != 1)
    fail("Failed to read R from input file.");

  res = fscanf(f, "%d", &N);
  if (res != 1)
    fail("Failed to read N from input file.");

  if (N < 1 || N > MAX_N)
    fail("N is out of bounds.");

  for (i = 0; i < N; i++) {
    res = fscanf(f, "%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
    if (res != 4)
      fail("Failed to read data from input file.");
  }
  fclose(f);

  int answer = pieces(R, N, X1, Y1, X2, Y2);

  printf("%d\n", answer);

  return 0;
}
