#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define BOARD 5

struct Field {
  int x;
  int y;
};

Field previous[BOARD][BOARD];
Field starting_field;

int board[BOARD][BOARD];
int dist[BOARD][BOARD];

void fill_board()
{
  for(int i = 0; i < BOARD; i++)
    for(int j = 0; j < BOARD; j++)
      board[i][j] = (rand() % 9) + 1; // avoid zero
}

void set_beginner_position()
{
  starting_field.x = rand() % BOARD;
  starting_field.y = rand() % BOARD;

  board[starting_field.y][starting_field.x] = 0;
}

void print_board()
{
  for(int i = 0; i < BOARD; i++) {
    for(int j = 0; j < BOARD; j++)
      cout << board[i][j] << " ";
    
    cout << "\n";
  }
}

void seed_dist()
{
  for(int i = 0; i < BOARD; i++) {
    for(int j = 0; j < BOARD; j++) {
      dist[i][j] = INT_MAX;
      Field null_field;
      null_field.x = -1;
      null_field.y = -1;

      previous[i][j] = null_field;
    }
  }

  dist[starting_field.y][starting_field.x] = 0;
}

void dijkstra()
{
  queue<Field> q;
}

int main()
{
  srand(time(NULL)); // seed
  fill_board();
  set_beginner_position();
  print_board();
  seed_dist();
  dijkstra();
}
