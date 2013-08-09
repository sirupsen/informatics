#include<cstdio>
#include<cstring>
using namespace std;

int n, m;
int board[205][205];
int visited[205][205];
int current_color;

int flood_fill(int x, int y)
{
  if(x < 0 || y < 0 || y >= n || x >= n || board[y][x] != current_color)
    return 0;

  if(visited[y][x] != -1)
    return 0;

  visited[y][x] = 1;

  return 1 + flood_fill(x + 1, y) + flood_fill(x - 1, y)
    + flood_fill(x, y + 1) + flood_fill(x, y - 1);
}

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);

  scanf("%d %d", &n, &m);
  for(int y = 0; y < m; y++)
    for(int x = 0; x < n; x++)
      scanf("%d", &board[y][x]);

  memset(visited, -1, sizeof visited);

  current_color = board[y][x];

  printf("%d\n", flood_fill(x, y));

  return 0;
}
