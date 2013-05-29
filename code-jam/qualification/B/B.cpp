#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 105

int board[MAX_N][MAX_N];
int h, w;

bool possible(int x, int y, int mod_x, int mod_y, int initial_height)
{
  if(x < 0 || x >= w || y < 0 || y >= h)
  {
    return true;
  }
  else if(board[y][x] <= initial_height)
  {
    return possible(x + mod_x, y + mod_y, mod_x, mod_y, initial_height);
  }
  else
  {
    return false;
  }
}

int go(int x, int y)
{
  bool ok = false;

  bool left = possible(x, y, -1, 0, board[y][x]);
  bool right = possible(x, y, +1, 0, board[y][x]);

  if(left && right)
  {
    return true;
  }

  bool up = possible(x, y, 0, -1, board[y][x]);
  bool down =  possible(x, y, 0, +1, board[y][x]);

  if(up && down)
  {
    return true;
  }

  return false;
}

bool all_points_ok()
{
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      if(!go(j, i))
      {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  int n_test_cases;
  cin >> n_test_cases;

  for(int test_case = 1; test_case <= n_test_cases; test_case++)
  {
    cin >> h >> w;

    for(int i = 0; i < h; i++)
    {
      for(int j = 0; j < w; j++)
      {
        cin >> board[i][j];
      }
    }

    cout << "Case #" << test_case << ": ";

    if(all_points_ok())
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}
