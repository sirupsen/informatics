#include<cstdio>
#define MAX_N 10000

size_t n_rows, n_columns, start_column;
char grid[MAX_N][MAX_N];
short visited[MAX_N][MAX_N];

void dfs(int x, int y, int length, int cycle_length)
{
  visited[y][x] += 1;

  // printf("At (%x;%d), walking %c, visited %d\n", x, y, grid[y][x], visited[y][x]);

  if(x <= 0 || y < 0 || y == n_rows || x > n_columns) {
    printf("%d step(s) to exit\n", length);
    return;
  }

  if(visited[y][x] == 3) { // we've finished rewalking the cycle
    int steps = length - cycle_length - cycle_length;
    steps = steps < 0 ? 0 : steps;
    printf("%d step(s) before a loop of %d step(s)\n", steps, cycle_length);
    return;
  }

  if(visited[y][x] == 2) { // we're entering a cycle/in a cycle
    cycle_length++;
  }

  if(grid[y][x] == 'N') {
    dfs(x, y - 1, length + 1, cycle_length);
  } else if(grid[y][x] == 'S') {
    dfs(x, y + 1, length + 1, cycle_length);
  } else if(grid[y][x] == 'W') {
    dfs(x - 1, y, length + 1, cycle_length);
  } else if(grid[y][x] == 'E') {
    dfs(x + 1, y, length + 1, cycle_length);
  }
}

int main()
{
  while(scanf("%ld %ld %ld", &n_rows, &n_columns, &start_column) == 3) {
    if(n_rows == 0 && n_columns == 0 && start_column == 0)
      return 0;

    for(size_t y = 0; y <= n_rows; ++y)
      for(size_t x = 0; x <= n_columns; ++x)
        visited[y][x] = 0;

    for(size_t y = 0; y < n_rows; ++y)
      for(size_t x = 0; x <= n_columns; ++x)
        scanf("%c", &grid[y][x]);

    dfs(start_column, 0, 0, 0);
  }

  return 0;
}
