#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100010

int main()
{
  long long initial[MAX_N], l[MAX_N], r[MAX_N], d[MAX_N], operations[MAX_N], sum[MAX_N];

  memset(sum, 0, sizeof sum);
  memset(operations, 0, sizeof operations);

  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);

  for(int i = 1; i <= n; i++)
  {
    scanf("%lld", &initial[i]);
  }

  for(int i = 1; i <= m; i++)
  {
    scanf("%lld %lld %lld", &l[i], &r[i], &d[i]);
  }

  for(int i = 1; i <= k; i++)
  {
    long long low, high;
    scanf("%lld %lld", &low, &high);

    operations[low]++;
    operations[high + 1]--;
  }

  for(int i = 1; i <= m; i++)
  {
    operations[i]  += operations[i - 1];

    sum[l[i]]      += operations[i] * d[i];
    sum[r[i] + 1]  -= operations[i] * d[i];
  }

  for(int i = 1; i <= n; i++)
  {
    sum[i] += sum[i - 1];
    printf("%lld ", initial[i] + sum[i]);
  }
  printf("\n");

  return 0;
}
