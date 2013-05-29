#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  double first = a/b;
  double second = c/d;

  double p = first;

  for(int i = 3; i < 1000000; i += 2)
  {
    p += pow(1 - first, (int) (i / 2)) * pow(1 - second, (int) (i / 2)) * first;
  }

  printf("%.12f\n", p);

  return 0;
}
