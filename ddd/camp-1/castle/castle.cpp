#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int rows;
int columns;

int castle[100][100];
int visited[100][100];
int room_size[100][100];
int visited_size[100][100];
int identity[100][100];

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

void flood_fill_size(int i, int k, int &size, int &id)
{
  if (visited_size[i][k]) {
    return;
  } else {
    visited_size[i][k] = 1;
    room_size[i][k] = size;
    identity[i][k] = id;

    if (wall_west(i,k) == 0)
      flood_fill_size(i, k - 1, size, id);

    if (wall_east(i,k) == 0)
      flood_fill_size(i, k + 1, size, id);

    if (wall_south(i,k) == 0)
      flood_fill_size(i + 1, k, size, id);

    if (wall_north(i,k) == 0)
      flood_fill_size(i - 1, k, size, id);
  }
}

void solve()
{
  for(int i = 0; i < rows; i++) {
    for(int k = 0; k < columns; k++) {
      int current_room = explore(i, k);

      if(room_size[i][k] == -1)
        flood_fill_size(i, k, current_room, rooms);

      if (current_room > largest_room)
        largest_room = current_room;

      if (current_room > 0)
        rooms++;
    }
  }
}

void break_walls()
{
  int max_room = -1;
  string lolplznig;

  for(int i = 0; i < rows; i++) {
    for(int k = 0; k < columns; k++) {

      if(k + 1 < columns && identity[i][k] != identity[i][k + 1]) {
        int new_room_size = room_size[i][k] + room_size[i][k + 1];

        if(new_room_size > max_room) {
          stringstream buffer;
          buffer << i + 1 << " " << k + 1 << " " << "E";
          lolplznig = buffer.str();
          max_room = new_room_size;
        }
      }

      if(i + 1 < rows && identity[i][k] != identity[i + 1][k]) {
        int new_room_size = room_size[i][k] + room_size[i + 1][k];

        if(new_room_size > max_room) {
          stringstream buffer;
          buffer << i + 1 << " " << k + 1 << " " << "S";
          lolplznig = buffer.str();
          max_room = new_room_size;
        }
      }
    }
  }

  cout << lolplznig << endl;
}

void output()
{
  // for(int i = 0; i < rows; i++) {
  //   for(int k = 0; k < columns; k++) {
  //     printf("%d", room_size[i][k]);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", rooms);
  printf("%d\n", largest_room);
  break_walls();
}

int main()
{
  memset(room_size, -1, sizeof room_size);
  memset(visited_size, 0, sizeof room_size);
  input();
  solve();
  output();
}
