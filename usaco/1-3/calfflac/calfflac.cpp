/*
ID: sirup1
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

int main()
{
  FILE *input;
  input = fopen("calfflac.in", "r");

  char start;
  int end_offset;

  for(end_offset = 0; (start = fgetc(input)) != EOF; end_offset--) {
    printf("%c", start);
  }

  printf("\n");

  return 0;
}
