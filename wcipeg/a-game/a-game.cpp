#include<iostream>
using namespace std;

int main()
{
  long long n, tmp, sum[2];
  scanf("%lld", &n);

  for(int i = 1; i <= n; i++)
  {
    scanf("%lld", &tmp);
    sum[i % 2] += tmp;
  }

  printf("%lld\n", max(sum[0], sum[1]));

  return 0;
}
