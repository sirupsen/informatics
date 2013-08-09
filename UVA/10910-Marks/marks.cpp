#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;
#define MAX_SUM 70
#define MAX_COURSE 70
#define long long long

unsigned int DP[MAX_SUM + 1][MAX_COURSE + 1];
int c, n, t, p;
int tries;

unsigned int recurse(unsigned int sum, int i)
{
  if(sum == t && i == n)
    return 1;

  if(i >= n)
    return 0;

  if(sum > t)
    return 0;

  if(sum == t)
    return 0;

  if(DP[sum][i] != -1)
    return DP[sum][i];

  unsigned int local_sum = 0;

  for(int j = p; j <= tries; j++)
    local_sum += recurse(sum + j, i + 1);

  return DP[sum][i] = local_sum;
}

int main()
{
  cin >> c;

  while(c-->0) {
    memset(DP, -1, sizeof DP);
    cin >> n >> t >> p;
    tries = t - n * p + p;
    cout << recurse(0, 0) << endl;
  }

  return 0;
}
