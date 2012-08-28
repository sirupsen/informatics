#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define EPS 1e-9

double p, q, r, s, t, u;

double f(double x)
{
  return p / exp(x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
  while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
    double high = 1.0, low = 0.0, x = 0.0;

    while(high - low > EPS) {
      x = (low + high) / 2.0;

      if (f(x) * f(low) <= 0) high = x;
      else low = x;
    }

    if (f(0) * f(1) > 0) cout << "No solution" << endl;
    else printf("%.4f\n", x);
  }

  return 0;
}
