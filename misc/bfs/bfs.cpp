#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

#define MAX_N 200

struct Field{
  int x;
  int y;
  int moves;
};

int board[MAX_N][MAX_N];
int n;
queue<Field> q;

void print_board()
{
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }

    cout << "\n";
  }
}

void dfs(int x, int y, int moves)
{
  if (x < 0 || x >= n || y < 0 || y >= n) {
    return; // out of board
  } else if (board[y][x] == -1 || moves < board[y][x]) {
    cin.ignore();
    print_board();

    // first time visiting
    board[y][x] = moves;

    dfs(x + 1, y, moves + 1);
    dfs(x, y + 1, moves + 1);
    dfs(x, y - 1, moves + 1);
    dfs(x - 1, y, moves + 1);
  } else {
    return;
  }
}

int moves = 0;

void add_to_board_and_queue(int x, int y, int moves) {
  if (x < 0 || x >= n || y < 0 || y >= n) return;

  Field new_field = {x, y, moves};

  q.push(new_field);
}

Field bfs(int x, int y)
{
  Field first_field = {x, y, 0};

  q.push(first_field);

  while(!q.empty()) {
    Field field; 
    field = q.front();
    q.pop();

    if (board[field.y][field.x] == -2) return field;
    if (board[field.y][field.x] != -1) continue;

    board[field.y][field.x] = field.moves;
    field.moves++;

    cin.ignore();
    cout << "(" << field.x << ";" << field.y << ")\n";
    print_board();

    add_to_board_and_queue(field.x + 1, field.y, field.moves);
    add_to_board_and_queue(field.x, field.y + 1, field.moves);
    add_to_board_and_queue(field.x - 1, field.y, field.moves);
    add_to_board_and_queue(field.x, field.y - 1, field.moves);
  }
}

void reset_board() 
{
  for(int y = 0; y < n; y++)
    for(int x = 0; x < n; x++)
      board[y][x] = -1;
}

int main()
{
  cout << "Board dimensions NxN? ";
  cin >> n;

  int x;
  cout << "Start x-coordinate: ";
  cin >> x;

  int y;
  cout << "Start y-coordinate: ";
  cin >> y;

  reset_board();

  board[rand() % (n - 1)][rand() % (n - 1)] = -2;

  Field target;

  dfs(x,y,0);

  printf("Target found at (%d;%d) and you can get there in %d moves\n", target.x, target.y, target.moves);

  print_board();

  return 0;
}
