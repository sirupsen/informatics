/*
ID: sirup1
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstring>

char comet_name[10];
char group_name[10];

void input()
{
  FILE * pFile;

  pFile = fopen("ride.in", "r");
  fscanf(pFile, "%s", comet_name);
  fscanf(pFile, "%s", group_name);
  fclose(pFile);
}

bool solve()
{
  long unsigned int comet_name_sum = ((int) comet_name[0]) - 64;

  // printf("initial comet name sum: %lu\n", comet_name_sum);

  for(int i = 1; i < strlen(comet_name); i++) {
    // printf("letter %c with val %d\n", comet_name[i], ((int) comet_name[i]) - 64);
    comet_name_sum *= ((int) comet_name[i]) - 64;
    // printf("new sum %lu\n", comet_name_sum);
  }

  unsigned long group_name_sum = ((int) group_name[0]) - 64;

  for(int i = 1; i < strlen(group_name); i++)
    group_name_sum *= ((int) group_name[i]) - 64;

  // printf("%lu and %lu\n", comet_name_sum % 47, group_name_sum % 47);

  return (comet_name_sum % 47) == (group_name_sum % 47);
}

void output(bool go)
{
  FILE * pFile;
  pFile = fopen("ride.out", "w");

  if (go)
    fprintf(pFile, "GO\n");
  else
    fprintf(pFile, "STAY\n");

  fclose(pFile);
}

int main(int argc, char *argv[])
{
  input();
  output(solve());

  return 0;
}
