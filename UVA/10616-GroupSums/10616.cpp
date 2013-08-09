#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

#define MAX_N 201
#define MAX_M 11
#define MAX_D 21

int n, q, m, d;
vector<int> a(MAX_N);

int dp[MAX_N][MAX_M][MAX_D];

int mod(int &a)
{
  int ret = a % d;
  if (ret < 0) ret += d;
  return ret;
}

int recurse(int l, int i, int sum)
{
  int &m = dp[i][l][mod(sum)];

  if(i == n && l > 0)
  {
    return 0;
  }
  if(!l)
  {
    return m = (sum == 0);
  }
  if(m != -1)
  {
    return m;
  }
  else
  {
    int diff = sum - a[i];
    return m = recurse(l, i + 1, mod(sum))
      + recurse(l - 1, i + 1, mod(diff));
  }
}

int main()
{
  for(int set = 1; scanf("%d %d", &n, &q) == 2; set++)
  {
    if(!(n ^ q)) break;

    printf("SET %d:\n", set);

    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    for(int i = 1; i <= q; i++)
    {
      scanf("%d %d", &d, &m);

      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
          for(int k = 0; k <= d; k++)
            dp[i][j][k] = -1;

      printf("QUERY %d: %d\n", i, recurse(m, 0, 0));
    }
  }

  return 0;
}
