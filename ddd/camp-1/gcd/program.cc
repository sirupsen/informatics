#include <cstdio>
#include <cstdlib>

int gcd(int n, int m)
{
  if (m > n) {
    return gcd(n, m - n);
  } else if (m < n) {
    return gcd(n - m, m);
  }

  return n;
}

int main(int argc, char *argv[])
{
  int first;
  int second;

  scanf("%d %d", &first, &second);

  printf("%d\n", gcd(first, second));

  return 0;
}
