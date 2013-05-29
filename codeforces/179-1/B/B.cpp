#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_N 505
#define INF 1000000000

int main()
{
  int am[MAX_N][MAX_N];
  memset(am, 0, sizeof am);

  int n; scanf("%d", &n);

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &am[i][j]);
    }
  }

  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
      }
    }
  }

  long long sum = 0;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      sum += am[i][j];
    }
  }

  printf("Sum before any queries: %lld\n", sum);

  for(int i = 0; i < n; i++)
  {
    int v; scanf("%d", &v);

    if(i == n - 1)
    {
      printf("%lld\n", sum);
    }
    else
    {
      printf("%lld ", sum);
    }

    for(int j = 0; j < n; j++)
    {
      sum -= am[v][j];
      sum -= am[j][v];

      am[j][v] = 0;
      am[v][j] = 0;
    }
  }

  return 0;
}
