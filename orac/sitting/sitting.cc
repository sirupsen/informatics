#include <cstdio>

int seated;
int standing;

int rows;
int seats_per_row;

int tickets;

void input() 
{
  FILE * pFile;
  pFile = fopen("sitin.txt", "r");
  fscanf(pFile, "%d", &rows);
  fscanf(pFile, "%d", &seats_per_row);
  fscanf(pFile, "%d", &tickets);
  fclose(pFile);
}

void solve()
{
  int seats_available = rows * seats_per_row;

  if (tickets > seats_available) {
    seated = seats_available;
    standing = tickets - seated;
  } else {
    seated = tickets;
    standing = 0;
  }
}

int output()
{
  FILE * pFile;
  pFile = fopen("sitout.txt", "w+");
  fprintf(pFile, "%d ", seated);
  fprintf(pFile, "%d", standing);
  fclose(pFile);
}

int main(int argc, char *argv[])
{
  input();
  solve();
  output();

  return 0;
}
