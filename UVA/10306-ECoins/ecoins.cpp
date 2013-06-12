#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

#define long long long
#define MAX_S 305
#define MAX_M 45

int main()
{
  ios::sync_with_stdio(false);
  int n_test_cases;
  cin >> n_test_cases;

  vector<pair<int, int> > coins(MAX_M);

  int dp[MAX_S][MAX_S];

  for(int test_case = 1; test_case <= n_test_cases; test_case++)
  {
    int m, s;
    cin >> m >> s;

    for(int i = 0; i < m; i++)
    {
      long a, b;
      cin >> a >> b;

      coins[i].first  = a;
      coins[i].second = b;
    }

    for(int i = 0; i <= s; i++)
    {
      for(int j = 0; j <= s; j++)
      {
        dp[i][j] = INT_MAX-1;
      }
    }

    dp[0][0] = 0;

    for(int i = 0; i < m; i++)
    {
      for(int j = coins[i].first; j <= s; j++)
      {
        for(int k = coins[i].second; k <= s; k++)
        {
          dp[j][k] = min(dp[j][k], dp[j - coins[i].first][k - coins[i].second] + 1);
        }
      }
    }

    int ss = s * s;
    int min_coins = INT_MAX;

    for(int i = 0; i <= s; i++)
    {
      for(int j = 0; j <= s; j++)
      {
        if(i * i + j * j == ss)
        {
          min_coins = min(dp[i][j], min_coins);
        }
      }
    }

    if(min_coins == INT_MAX - 1)
    {
      cout << "not possible" << endl;
    }
    else
    {
      cout << min_coins << endl;
    }
  }

  return 0;
}
