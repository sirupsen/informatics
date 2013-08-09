#include <cstdio>

int first;
int second;

void input() 
{
  FILE * pFile;
  pFile = fopen("addin.txt", "r");
  fscanf(pFile, "%d", &first);
  fscanf(pFile, "%d", &second);
  fclose(pFile);
}

int solve()
{
  return first + second;
}

int output(int result)
{
  FILE * pFile;
  pFile = fopen("addout.txt", "w+");
  fprintf(pFile, "%d", result);
  fclose(pFile);
}

int main(int argc, char *argv[])
{
  input();
  output(solve());

  return 0;
}
