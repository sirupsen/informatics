#include <cstdio>

int teller;
int nevner;

int result_integer;
int result_teller;
int result_nevner;

void input() 
{
  FILE * pFile;
  pFile = fopen("mixin.txt", "r");
  fscanf(pFile, "%d", &teller);
  fscanf(pFile, "%d", &nevner);
  fclose(pFile);
}

void solve()
{
  result_integer = teller / nevner;

  result_teller = teller % nevner;
  result_nevner = nevner;
}

void output()
{
  FILE * pFile;
  pFile = fopen("mixout.txt", "w+");
  fprintf(pFile, "%d ", result_integer);

  if (result_teller > 0)
    fprintf(pFile, "%d/%d", result_teller, result_nevner);

  fclose(pFile);
}

int main(int argc, char *argv[])
{
  input();
  solve();
  output();

  return 0;
}
