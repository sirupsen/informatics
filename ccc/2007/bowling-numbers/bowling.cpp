#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 30005
#define MAX_K 505

int n_tests, n, k, w;
int pins[MAX_N];
int sum[MAX_N];
int dp[MAX_N][MAX_K];

int rec(int pos, int k)
{
  if(k == 0)
    return 0;

  int &memo = dp[pos][k];
  if(memo != -1) return memo;

  if(pos + w >= n)
    return memo = (sum[n] - sum[pos]);

  return memo = max(
      rec(pos + w, k - 1) + (sum[pos + w - 1] - sum[pos - 1]),
      rec(pos + 1, k)
  );
}

int main()
{
  scanf("%d", &n_tests);

  while(n_tests--)
  {
    scanf("%d %d %d", &n, &k, &w);

    for(int i = 1; i <= n; i++)
      scanf("%d", &pins[i]);

    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= k; j++)
        dp[i][j] = -1;

    sum[0] = 0;
    for(int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + pins[i];

    printf("%d\n", rec(1, k));
  }

  return 0;
}
