#include<iostream>
using namespace std;

bool board[1001][1001];

bool done(int x, int y) {
  // top left
  if (board[y + 1][x] && board[y + 2][x] 
      && board[y][x + 1] && board[y + 1][x + 1] && board[y + 2][x + 1]
      && board[y][x + 2] && board[y + 1][x + 2] && board[y + 2][x + 2]) return true;

  // top middle
  if (board[y + 1][x] && board[y + 2][x] 
      && board[y][x - 1] && board[y + 1][x - 1] && board[y + 2][x - 1]
      && board[y][x + 1] && board[y + 1][x + 1] && board[y + 2][x + 1]) return true;

  // top right
  if (board[y + 1][x] && board[y + 2][x] 
      && board[y][x - 1] && board[y + 1][x - 1] && board[y + 2][x - 1]
      && board[y][x - 2] && board[y + 1][x - 2] && board[y + 2][x - 2]) return true;

  // middle left
  if (board[y - 1][x] && board[y + 1][x]
      && board[y][x + 1] && board[y - 1][x + 1] && board[y + 1][x + 1]
      && board[y][x + 2] && board[y - 1][x + 2] && board[y + 1][x + 2]) return true;

  // middle middle
  if (board[y - 1][x] && board[y + 1][x]
      && board[y][x + 1] && board[y - 1][x + 1] && board[y + 1][x + 1]
      && board[y][x - 1] && board[y - 1][x - 1] && board[y + 1][x - 1]) return true;

  // middle right
  if (board[y - 1][x] && board[y + 1][x]
      && board[y][x - 1] && board[y - 1][x - 1] && board[y + 1][x - 1]
      && board[y][x - 2] && board[y - 1][x - 2] && board[y + 1][x - 2]) return true;
  
  // bottom left
  if (board[y + 1][x] && board[y + 2][x]
      && board[y][x + 1] && board[y + 1][x + 1] && board[y + 2][x + 1]
      && board[y][x + 2] && board[y + 1][x + 2] && board[y + 2][x + 2]) return true;

  // bottom middle
  if (board[y + 1][x] && board[y + 2][x]
      && board[y][x + 1] && board[y + 1][x + 1] && board[y + 2][x + 1]
      && board[y][x - 1] && board[y + 1][x - 1] && board[y + 2][x - 1]) return true;

  // bottom right
  if (board[y + 1][x] && board[y + 2][x]
      && board[y][x - 1] && board[y + 1][x - 1] && board[y + 2][x - 1]
      && board[y][x - 2] && board[y + 1][x - 2] && board[y + 2][x - 2]) return true;

  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;

  // build empty board
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      board[i][j] = false;

  // place the moves
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    board[y][x] = true; // color it

    if (done(x,y)) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
