#include<iostream>
using namespace std;

#define long long long

int main()
{
  long x, y, m;
  cin >> x >> y >> m;

  long xx = max(x, y), yy = min(x, y);
  long a = max(xx, xx + yy), b = min(xx, xx + yy);

  long lower = -100, upper = 100;

  while(upper - lower > 10)
  {
    long mid = (lower + upper) / 2;
    long v = mid * a + (mid - 1) * b;

    if(v < m)
    {
      lower = mid + 1;
    }
    else
    {
      upper = mid;
    }
  }

  cout << lower << endl;

  return 0;
}
