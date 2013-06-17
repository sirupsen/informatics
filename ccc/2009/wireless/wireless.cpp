#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_ROWS 1015
#define MAX_COLUMNS 30015
#define MAX_K 1005

int bandwith[MAX_ROWS][MAX_COLUMNS];

int main()
{
  int rows, cols, k;
  scanf("%d %d %d", &cols, &rows, &k);

  memset(bandwith, 0, sizeof bandwith);

  int col, row, r, b;

  while(k--)
  {
    scanf("%d %d %d %d", &col, &row, &r, &b);
    col--; row--;

    for(int crow = max(row - r, 0); crow <= min(row + r, rows - 1); crow++)
    {
      int offset = fabs((r * r) - ((crow - row) * (crow - row)));

      int min_x = ceil(-sqrt(offset) + col);
      int max_x = floor(sqrt(offset) + col) + 1;

      bandwith[crow][max(min_x, 0)] += b;

      if(max_x < cols)
        bandwith[crow][max_x] -= b;
    }
  }


  int bmax = 0, count = 0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(j > 0)
        bandwith[i][j] += bandwith[i][j - 1];

      if(bandwith[i][j] == bmax)
        count++;

      if(bandwith[i][j] > bmax)
      {
        bmax = bandwith[i][j];
        count = 1;
      }
    }
  }

  // for(int i = rows - 1; i >= 0; i--)
  // {
  //   for(int j = 0; j < cols; j++)
  //   {
  //     printf("%d ", bandwith[i][j]);
  //   }

  //   printf("\n");
  // }

  printf("%d\n%d\n", bmax, count);

  return 0;
}
