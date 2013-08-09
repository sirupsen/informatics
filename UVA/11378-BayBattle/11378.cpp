#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<complex>
using namespace std;

#define x imag()
#define y real()
#define MAX_COORDINATE 1000005

typedef complex<double> Point;

struct CompareX{
  bool operator()(const Point &a, const Point &b) const {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }
};

struct CompareY {
  bool operator()(const Point &a, const Point &b) const {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

int main()
{
  set<Point, CompareY> py;
  vector<Point> px;

  int n;
  while(scanf("%d", &n) == 1)
  {
    px.resize(n);

    for(int i = 0; i < n; i++)
    {
      int a, b;
      scanf("%d %d", &a, &b);

      px[i] = Point(a, b);
    }

    sort(px.begin(), px.end(), CompareX());

    double h = MAX_COORDINATE;

    for(int i = 0, tail = 0; i < px.size(); i++)
    {
      while(abs(px[i] - px[tail]) > h) {
        py.erase(px[tail]);
        tail++;
      }

      set<Point, CompareY>::iterator lower, upper;
      lower = py.lower_bound(Point(0, px[i].y - h));
      upper = py.upper_bound(Point(0, px[i].y + h));

      for(;lower != upper; lower++)
        h = min(h, max(abs((*lower).y - px[i].y), abs((*lower).x - px[i].x)));

      py.insert(px[i]);
    }

    printf("%d\n", (int) h);
  }

  return 0;
}
