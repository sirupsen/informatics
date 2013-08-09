#include "birthday.h"
#include <vector>
#include <cmath>

#define EPS 0.00001

struct Point {
  double x, y;

  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
};

struct Circle {
  Point center;
  int r;

  Circle(Point center, int r)
  {
    this->center = center;
    this->r = r;
  }

  bool inside(Point p)
  {
    int dx = this->center.x - p.x;
    int dy = this->center.y - p.y;

    int dist = dx * dx + dy * dy;
    int radius = this->r * this->r;

    return dist < radius ? true
  }
}

struct Line {
  double a, b, c;

  // jakob er homo
  // svend er homo
  Line(Point &a, Point &b)
  {
    if(fabs(a.x - b.x) < EPS)
    {
      this->a = 1.0;
      this->b = 0.0;
      this->c = -a.x;
    }
    else
    {
      this->a = -(double) (a.y - b.y);
      this->b = 1.0;
      this->c = -(double) (this->a * a.x) - b.y;
    }
  }

  bool parallel(Line &b)
  {
    return (fabs(this->a - b.a) < EPS) && (fabs(this->c - b.c) < EPS);
  }

  // Remember to check whether they're parallel first
  Point intersection(Line &b)
  {
    Point p;

    p.x = (b.b * this->c - this->b * b.c) / (b.a * this->b - this->a * b.b);

    if(fabs(this->b) > EPS)
    {
      p.y = -(this->a * p.x + this->c);
    }
    else
    {
      p.y = -(b.a * p.x + b.c);
    }

    return p;
  }
};

int pieces(int R, int N, int *X1, int *Y1, int *X2, int *Y2)
{
    return 42;
}
