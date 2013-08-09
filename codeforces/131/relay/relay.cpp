#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX_N 305

int dp[MAX_N][MAX_N][MAX_N];
int board[MAX_N][MAX_N];

const int dx1[] = {1,1,0,0};
const int dx2[] = {0,1,0,1};

#define MAX_MOVES 4

int n;

int y_from_x_d(int x, int d)
{
  int y = (d - x) + 1;

  if (y >= 1 && y <= n)
  {
    return y;
  }
  else
  {
    return -1;
  }
}

#define NEGINF INT_MIN

int recurse(int x1, int x2, int d)
{
  int y1 = y_from_x_d(x1, d), y2 = y_from_x_d(x2, d);
  int &dpr = dp[x1][x2][d % 2];

  if(x1 > n || x1 <= 0 || x2 > n || x2 <= 0 || y1 > n || y1 <= 0 || y2 > n || y2 <= 0)
    return NEGINF;

  if(dpr != -1)
    return dpr;

  if(y1 == n && y2 == n && x1 == n && x2 == n)
    return board[n][n];

  int diff = board[y1][x1] + board[y2][x2];
  if(x1 == x2) diff -= board[y2][x1];

  int lmax = NEGINF;
  for(int i = 0; i < MAX_MOVES; i++)
    lmax = max(lmax, recurse(x1 + dx1[i], x2 + dx2[i], d + 1));

  return dpr = lmax + diff;
}

int main()
{
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      scanf("%d", &board[i][j]);

  memset(dp, -1, sizeof dp);

  cout << recurse(1,1,1) << endl;

  return 0;
}
