#include<iostream>
#include<cmath>
using namespace std;

struct ring {
  int x;
  int y;
  int r;
  int R;
};

int d;

int absqr(int n)
{
  abs(n * n);
}

int inside(int r1, int r2) 
{
  if (r1 > r2 && d + r1 <= r2) return 1;
  if (r1 < r2 && d + r2 <= r1) return 1;

  return 0;
}

int outside(int r1, int r2)
{
  if (d - r1 >= r2) return 1;

  return 0;
}

int main()
{
  ring first;
  ring second;

  cin >> first.x >> first.y >> first.r >> first.R;
  cin >> second.x >> second.y >> second.r >> second.R;

  d = sqrt(abs((first.x - second.x) * (first.x - second.x)) + abs((first.y - second.y) * (first.y - second.y)));

  int count = 0;

  count += inside(first.R, second.r);
  count += inside(first.r, second.R);
  count += inside(first.R, second.R);
  count += inside(first.r, second.r);

  count += outside(first.R, second.r);
  count += outside(first.r, second.R);
  count += outside(first.R, second.R);
  count += outside(first.r, second.r);

  cout << count << endl;

  return 0;
}
