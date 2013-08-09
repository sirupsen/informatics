#include<iostream>
#include<cstring>
using namespace std;

string s1, s2;

int n;

int lcs()
{
  int dp[5][1000];

  memset(dp, 0, sizeof dp);

  int now, prev;

  for(int i = 1; i <= n; i++)
  {
    now = i % 2;
    prev = (i + 1) % 2;

    for(int j = 1; j <= n; j++)
    {
      if(s1[i - 1] == s2[j - 1])
      {
        dp[now][j] = dp[prev][j - 1] + 1;
      }
      else
      {
        dp[now][j] = max(
            dp[now][j - 1],
            dp[prev][j]
        );
      }
    }
  }

  return dp[now][n];
}

void input()
{
  cin >> n >> s1;

  s2 = s1;
  reverse(s2.begin(), s2.end());
}

int main()
{
  input();

  cout << n - lcs() << endl;

  return 0;
}
