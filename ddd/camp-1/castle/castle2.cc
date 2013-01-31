#include <cstdio>

int rows;
int columns;

int castle[100][100];
int visited[100][100];

int largest_room;
int rooms;

int wall_west(int i, int j) 
{
  int walls = castle[i][j];

  if (walls == 1) return 1;
  if (walls == 3) return 1;
  if (walls == 5) return 1;
  if (walls == 7) return 1;
  if (walls == 9) return 1;
  if (walls == 11) return 1;
  if (walls == 13) return 1;
  if (walls == 15) return 1;

  return 0;
}

int wall_north(int i, int j)
{
  int walls = castle[i][j];

  if (walls == 2) return 1;
  if (walls == 3) return 1;
  if (walls == 6) return 1;
  if (walls == 7) return 1; // 3
  if (walls == 10) return 1;
  if (walls == 11) return 1; // 3
  if (walls == 14) return 1;
  if (walls == 15) return 1;

  return 0;
}

int wall_east(int i, int j)
{
  int walls = castle[i][j];

  if (walls == 4) return 1;
  if (walls == 5) return 1;
  if (walls == 6) return 1;
  if (walls == 7) return 1;
  if (walls == 12) return 1;
  if (walls == 13) return 1;
  if (walls == 14) return 1;
  if (walls == 15) return 1;

  return 0;
}

int wall_south(int i, int j)
{
  int walls = castle[i][j];
  if (walls >= 8) return 1;

  return 0;
}

void input() 
{
  scanf("%d", &rows);
  scanf("%d", &columns);

  int i, k;
  for(i = 0; i < rows; i++)
    for(k = 0; k < columns; k++)
      scanf("%d", &castle[i][k]);
}

int explore(int i, int k)
{
  if (visited[i][k] == 1) {
    return 0;
  } else {
    visited[i][k] = 1;
    int sum = 1;

    if (wall_west(i,k) == 0) sum += explore(i, k - 1);
    if (wall_east(i,k) == 0) sum += explore(i, k + 1);
    if (wall_south(i,k) == 0) sum += explore(i + 1, k);
    if (wall_north(i,k) == 0) sum += explore(i - 1, k);

    return sum;
  }

  return 0;
}

void solve() 
{
  for(int i = 0; i < rows; i++) {
    for(int k = 0; k < columns; k++) {
      int current_room = explore(i, k);
      if (current_room > largest_room) largest_room = current_room;
      if (current_room > 0) rooms += 1;
    }
  }
}

void output() 
{
  printf("%d\n", rooms);
  printf("%d\n", largest_room);
}

int main() 
{
  input();
  solve();
  output();
}
