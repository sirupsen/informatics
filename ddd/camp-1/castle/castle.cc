#include <cstdio>

int n;
int m;

int table[500][500];
int visited[500][500];

int largest_room;
int rooms;

void input() 
{
  scanf("%d", &n); // rows
  scanf("%d", &m); // columns

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &table[i][j]);
    }
  }
}

int wall_west(int i, int j) 
{
  int walls = table[i][j];

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
  int walls = table[i][j];

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
  int walls = table[i][j];

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
  int walls = table[i][j];
  if (walls >= 8) return 1;

  return 0;
}

int explore(int i, int j)
{
  if (visited[i][j]) {
    return 0;
  } else {
    visited[i][j] = 1;

    int sum = 1; // one for current
    if (wall_west(i,j) == 0)  sum += explore(i, j - 1);
    if (wall_east(i,j) == 0)  sum += explore(i, j + 1);
    if (wall_south(i,j) == 0) sum += explore(i + 1, j);
    if (wall_north(i,j) == 0) sum += explore(i - 1, j);

    return sum;
  }

  return 0;
}

void solve()
{
  for(int i = 0; i < 1; i++) {
    for(int j = 0; j < 1; j++) {
      printf("%d", i);
      int current_room = explore(i, j);
      // if (current_room > largest_room) largest_room = current_room;
      // if (current_room > 0) rooms += 1;
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
  printf("boom: %d for %d\n", wall_west(0,0), table[0][0]);
  printf("boom: %d for %d\n", wall_west(0,1), table[0][1]);
  solve();
  // output();
  //
  // int i, j;
  // scanf("%d %d", &i, &j);
  // printf("\n%d\n", wall_west(i,j));

  return 0;
}
