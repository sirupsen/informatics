#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 1000000
#define MAX_N 105

int n, k;

int DP[MAX_N][MAX_N];

long long ans(int sum, int n_numbers)
{
  if(sum > n || n_numbers > k)
    return 0;

  if(sum == n && n_numbers == k)
    return 1;

  if(DP[sum][n_numbers] != -1)
    return DP[sum][n_numbers];

  long long local_sum = 0;
  for(int i = 0; i <= n; i++)
    local_sum += ans(sum + i, n_numbers + 1);

  return DP[sum][n_numbers] = local_sum;
}

int main()
{
  while(scanf("%d %d", &n, &k) && n && k && memset(DP, -1, sizeof(DP)))
    printf("%lld\n", ans(0, 0));

  return 0;
}
