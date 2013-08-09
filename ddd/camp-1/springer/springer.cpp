#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<utility>
using namespace std;

int board[30][30];
int visited[30][30];

struct Coordinate {
  int x;
  int y;
  int d;

  Coordinate(int x, int y, int d)
  {
    this->x = x;
    this->y = y;
    this->d = d;
  }
};

int main()
{
  int n; cin >> n;

  memset(board, -1, sizeof board);
  memset(visited, -1, sizeof board);

  int column, row; char c;
  cin >> c >> row;
  column = c - 'A';
  row -= 1;

  queue<Coordinate> q;

  Coordinate start(column, row, 0);
  q.push(start);

  while(!q.empty()) {
    Coordinate field = q.front(); q.pop();

    // printf("%d;%d\n", field.x, field.y);

    if(field.y < 0 || field.y >= n || field.x < 0 || field.x >= n)
      continue;

    if(visited[field.y][field.x] != -1)
      continue;

    board[field.y][field.x] = field.d;

    int column = field.x;
    int row = field.y;
    int new_d = field.d + 1;

    Coordinate q1(column + 1, row - 2, new_d);
    q.push(q1);

    Coordinate q2(column + 2, row - 1, new_d);
    q.push(q2);

    Coordinate q3(column + 2, row + 1, new_d);
    q.push(q3);

    Coordinate q4(column + 1, row + 2, new_d);
    q.push(q4);

    Coordinate q5(column - 1, row + 2, new_d);
    q.push(q5);

    Coordinate q6(column - 2, row + 1, new_d);
    q.push(q6);

    Coordinate q7(column - 2, row - 1, new_d);
    q.push(q7);

    Coordinate q8(column - 1, row - 2, new_d);
    q.push(q8);

    visited[field.y][field.x] = 1;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
