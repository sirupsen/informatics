#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_X 3
#define MAX_Y 3

char board[5][5];

int recurse(int x, int y, char type, int mod_x, int mod_y)
{
  if(x < 0 || x > MAX_X || y < 0 || y > MAX_Y)
  {
    return 0;
  }
  else if(board[y][x] == type || board[y][x] == 'T')
  {
    return recurse(x + mod_x, y + mod_y, type, mod_x, mod_y) + 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n; cin >> n;

  for(register test_case = 1; test_case <= n; test_case++)
  {

    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        cin >> board[i][j];
      }
    }


    bool any_blanks = false;
    char winner = 'N';

    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        if(board[i][j] == '.')
        {
          any_blanks = true;
        }
        else
        {
          int lmax = 0;

          lmax = max(lmax, recurse(i, j, board[i][j], -1, 0));
          lmax = max(lmax, recurse(i, j, board[i][j], +1, 0));

          lmax = max(lmax, recurse(i, j, board[i][j], 0, -1));
          lmax = max(lmax, recurse(i, j, board[i][j], 0, +1));

          lmax = max(lmax, recurse(i, j, board[i][j], -1, +1));
          lmax = max(lmax, recurse(i, j, board[i][j], -1, -1));

          lmax = max(lmax, recurse(i, j, board[i][j], +1, +1));
          lmax = max(lmax, recurse(i, j, board[i][j], +1, -1));

          if(lmax > 3)
          {
            winner = board[i][j];
            break;
          }
        }
      }
    }


    cout << "Case #" << test_case << ": ";

    if(winner != 'N')
    {
      cout << winner << " won";
    }
    else if(any_blanks)
    {
      cout << "Game has not completed";
    }
    else
    {
      cout << "Draw";
    }

    cout << endl;
  }

  return 0;
}
