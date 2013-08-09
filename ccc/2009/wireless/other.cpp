#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define MAX_ROWS 30005
#define MAX_COLUMNS 1005

int diff[MAX_ROWS][MAX_COLUMNS];

int main()
{
  int rows, cols, k;
  scanf("%d %d %d", &rows, &cols, &k);

  for(int i = 0; i <= rows; i++)
    for(int j = 0; j <= cols; j++)
      diff[i][j] = 0;

  int col, row, r, b;

  while(k--)
  {
    scanf("%d %d %d %d", &col, &row, &r, &b);
    row--; col--;

    for(int j = max(0, col - r); j <= min(cols - 1, col + r); j++)
    {
      int offset = sqrt((r * r) - ((col - j) * (col - j)));

      int left = max(0, row - offset);
      int right = min(rows - 1, row + offset) + 1;

      diff[left][j]  += b;
      diff[right][j] -= b;
    }
  }

  int bmax = 0, count = 0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(i > 0)
        diff[i][j] += diff[i - 1][j];

      if(diff[i][j] == bmax)
        count++;

      if(diff[i][j] > bmax)
      {
        bmax = diff[i][j];
        count = 1;
      }
    }
  }

  printf("%d\n%d\n", bmax, count);

  return 0;
}
