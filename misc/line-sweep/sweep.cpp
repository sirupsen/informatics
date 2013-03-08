#include<iostream>
#include<cmath>
#include<set>
#include<queue>
#include<utility>
using namespace std;

int dist(pair<int, int> p, pair<int, int> q) {
  return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
}

struct Point {
  int x;
  int y;

  Point() {}

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  bool operator<(Point b) const
  {
    return this->y < b.y;
  }

  bool operator==(Point b) const
  {
    return this->y == b.y;
  }
};

int main()
{
  int x, y;
  priority_queue<pair<int, int>> events;

  while(scanf("%d %d", &x, &y) == 2)
    events.push(make_pair(-x, y));

  int d = 1000;
  pair<int, int> p1;
  Point p2;

  set<Point> adjacent;

  while(!events.empty()) {
    pair<int, int> qtop = events.top(); events.pop();
    pair<int, int> top = make_pair(-qtop.first, qtop.second);
    
    // Remove all points where x_top - x > d;

    if(!adjacent.empty()) {
      Point max_down(0, top.second - d);
      Point max_up(0, top.second + d);

      auto point = adjacent.lower_bound(max_down);
      auto end = adjacent.upper_bound(max_up);

      printf("At (%d;%d), lowest point (%d;%d) stopping at (%d;%d) \n", top.first, top.second, 
          point->x, point->y, end->x, end->y);

      for(; point != end; point++) {
        int local_distance = (top.first - point->x) * (top.first - point->x) +
          (top.second - point->y) * (top.second - point->y);

        if(local_distance < d) {
          d = local_distance;
          p1 = top; p2 = *point;
        }
      }
    }

    adjacent.insert(Point(top.first, top.second));
  }

  printf("Closest pair (%d; %d) and (%d; %d): %.2f\n", p1.first, p1.second, p2.x, p2.y, sqrt(d));

  return 0;
}
