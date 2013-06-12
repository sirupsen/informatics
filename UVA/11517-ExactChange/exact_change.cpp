#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_N 10000
#define SUPER_MAX_N 4*MAX_N

int main()
{
  ios::sync_with_stdio(false);

  int n_test_cases;
  cin >> n_test_cases;

  while(n_test_cases--)
  {
    int n, m; cin >> n >> m;

    vector<int> coins(m);

    for(int i = 0; i < m; i++)
    {
      cin >> coins[i];
    }

    vector<int> dp(SUPER_MAX_N, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < m; i++)
    {
      for(int j = SUPER_MAX_N - 1 - coins[i]; j >= 0; j--)
      {
        if(dp[j] < INT_MAX)
        {
          dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
        }
      }
    }

    for(int i = n; i <= 2*MAX_N; i++)
    {
      if(dp[i] != INT_MAX)
      {
        cout << i << " " << dp[i] << endl;
        break;
      }
    }
  }

  return 0;
}
