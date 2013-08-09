#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define long long long
#define MAX_S 7490
#define MAX_COINS 5

int main()
{
  const int coins[] = {50,25,10,5,1};
  long dp[MAX_S];

  dp[0] = 1;

  for(int i = 0; i < MAX_COINS; ++i)
  {
    for(int j = coins[i]; j <= MAX_S; ++j)
    {
      dp[j] += dp[j - coins[i]];
    }
  }

  int n;
  while(scanf("%d", &n))
  {
    printf("%lld\n", dp[n]);
  }

  return 0;
}
