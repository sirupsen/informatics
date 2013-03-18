#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX_N 30
#define long long long

long n;

long dp[200];
long res = 0;

long dp_recurse(long number, long sum)
{
  if(sum == n)
    return 1;

  if(dp[sum] != -1)
    return dp[sum];

  if(sum < n) {
    long local_sum = 0;

    for(int i = 1; i <= 9; ++i)
      local_sum += dp_recurse(number * 10 + i, sum + i);

    return dp[sum] = local_sum;
  }

  return 0;
}

int main()
{
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << dp_recurse(0, 0) << endl;

  return 0;
}
