#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
  int n, m, d;
  cin >> n >> m >> d;

  int b[105][105];

  vector<int> v;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cin >> b[i][j];
      v.push_back(b[i][j]);
    }
  }

  long long min_moves = -1;

  for(int k = 0; k < v.size(); k++)
  {
    long long local_moves = 0;

    bool done_done = false;

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        int diff = abs(b[i][j] - v[k]);

        if(diff % d == 0)
        {
          local_moves += abs(b[i][j] - v[k]) / d;
        }
        else
        {
          done_done = true;
          break;
        }
      }

      if(done_done)
        break;
    }

    if(!done_done)
    {
      if(min_moves == -1)
        min_moves = local_moves;

      min_moves = min(local_moves, min_moves);
    }
  }

  cout << min_moves << endl;

  return 0;
}
