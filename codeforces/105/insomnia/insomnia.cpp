#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}

int main()
{
  int k, l, m, n, d;
  scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);

  int res = d/k + d/l + d/m + d/n
    - d / lcm(k, l) - d/lcm(k, m) - d/lcm(k, n) - d/lcm(l, m) - d/lcm(l, n) - d/lcm(m, n)
    + d / lcm(k, lcm(l, m)) + d / lcm(k, lcm(l, n)) + d / lcm(k, lcm(m, n)) + d / lcm(l, lcm(m, n))
    - d / lcm(lcm(k, l), lcm(m, n));

  printf("%d\n",res);

  return 0;
}
