#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<climits>
using namespace std;

#define long long long
#define MAX_N 105

int main()
{
  int n, m;

  long board[MAX_N][MAX_N];
  long dp[MAX_N][MAX_N];
  int parent[MAX_N][MAX_N];

  while(cin >> n >> m)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        cin >> board[i][j];
      }
    }

    for(int i = 0; i < m; i++)
    {
      dp[0][i] = board[i][0];
      parent[0][i] = -1;
    }

    for(int i = 1; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        int up_index = j - 1 == -1 ? n - 1 : j - 1;
        int down_index = j + 1 == n ? 0 : j + 1;

        cout << down_index << endl;
        cout << up_index << endl;

        dp[i][j] = dp[i - 1][up_index] + board[j][i];
        parent[i][j] = up_index;

        int a = dp[i - 1][j] + board[j][i];
        if(a < dp[i][j] || (a == dp[i][j] && j < parent[i][j]))
        {
          dp[i][j] = a;
          parent[i][j] = j;
        }

        int b = dp[i - 1][down_index] + board[j][i];
        if(b < dp[i][j] || (b == dp[i][j] && down_index < parent[i][j]))
        {
          dp[i][j] = b;
          parent[i][j] = down_index;
        }
      }
    }

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        cout << dp[j][i] << " ";
      }
      cout << endl;
    }

    int shortest = dp[m-1][0];
    int shortest_row = 0;

    for(int i = 1; i < n; i++)
    {
      if(dp[m-1][i] < shortest)
      {
        shortest_row = i;
        shortest = dp[m-1][i];
      }
    }

    int c = m-1;
    int p = parent[c][shortest_row];

    cout << "parent: " << p << endl;
    cout << shortest_row << endl;

    stringstream ss;

    cout << (shortest_row + 1) << " ";

    while(p != -1)
    {
      cout << (p + 1) << " ";
      p = parent[--c][p];
    }
    cout << endl;

    // string output(ss.str());

    // reverse(output.begin(), output.end());
    // cout << output.substr(2) << endl;
    cout << shortest << endl;
  }

  return 0;
}
