#include<iostream>
#include<limits>
#include<set>
#include<algorithm>
#include<complex>
#include<vector>
#include<climits>
#include<cstdio>
using namespace std;
// closest pair problem

#define x real()
#define y imag()
#define MAX_N 10005
#define DOUBLE_MAX numeric_limits<double>::max()

typedef complex<double> Point;

struct CompareX {
  bool operator()(const Point &a, const Point &b) const
  {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }
};

struct CompareY {
  bool operator()(const Point &a, const Point &b)
  {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

int main()
{
  set<Point, CompareY> py;
  int n;
  double max_dist = 10000;

  while(scanf("%d", &n))
  {
    if(!n) break;

    vector<Point> px(n);
    py.clear();

    double a, b;
    for(int i = 0; i < n; i++)
    {
      scanf("%lf %lf", &a, &b);

      px[i] = Point(a, b);
    }

    double h = 1000005;

    sort(px.begin(), px.end(), CompareX());

    for(int i = 0, tail = 0; i < n; i++)
    {
      while(abs(px[i].x - px[tail].x) > h)
      {
        py.erase(px[tail]);
        tail++;
      }

      set<Point, CompareY>::const_iterator lower, upper;

      lower = py.lower_bound(Point(0, px[i].y - h));
      upper = py.upper_bound(Point(0, px[i].y + h));

      for(; lower != upper; lower++)
        h = min(h, abs(*lower - px[i]));

      py.insert(px[i]);
    }

    if(h >= max_dist || n == 1)
    {
      printf("INFINITY\n");
    }
    else
    {
      printf("%.4f\n", h);
    }
  }

  return 0;
}
