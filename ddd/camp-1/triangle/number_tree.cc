#include <cstdio>
#include <algorithm>
using namespace std;

int n_rows;
int c[1050][1050];
int q[1050][1050];
int current_max;

void input()
{
  scanf("%d", &n_rows);

  for(int i = 0; i < n_rows; i++) {
    for(int k = 0; k <= i; k++) {
      scanf("%d", &c[i][k]);
      q[i][k] = -1;
    }
  }
}

int solve(int row, int column)
{
  // Not set, compute it
  if (q[row][column] == -1)
    if (row == n_rows)
      q[row][column] = c[row][column];
    else
      q[row][column] = (c[row][column] + std::max(solve(row + 1, column), solve(row + 1, column + 1)));

  return q[row][column];
}

int main()
{
  input();
  printf("%d\n", solve(0, 0));
}
