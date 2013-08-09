#include<iostream>
#include<vector>
#include<utility>
using namespace std;

#define MAX_N 10005
#define x first
#define y second

typedef pair<int, int> Point;

vector<int> R, C;
int n, k;

Point initial_point(int x)
{
  return Point(x % n == 0 ? n : x % n,
               x % n == 0 ? x / n : (x / n) + 1);
}

int rotate(int source, int dest, int &T)
{
  int rotations = dest - source;

  if (source > dest)
    rotations = (n - source) + dest;

  T += rotations;

  return rotations;
}

Point find(int v)
{
  Point p = initial_point(v);
  int new_x = (p.x + R[p.y]) % n;
  new_x = (new_x == 0 ? n : new_x);

  int new_y = (p.y + C[new_x]) % n;
  new_y = (new_y == 0 ? n : new_y);

  // printf("orig: %d at (%d;%d)\n", v, p.x, p.y);
  // printf("new: %d at (%d;%d)\n", v, new_x, new_y);

  return Point(new_x, new_y);
}

int main()
{
  scanf("%d %d", &n, &k);

  R.assign(n, 0);
  C.assign(n, 0);

  int x, r, c;

  while(k--)
  {
    scanf("%d %d %d", &x, &r, &c);

    int rots = 0;

    Point source = find(x);

    // printf("%d at (%d;%d)\n", x, source.x, source.y);

    rots += rotate(source.x, c, R[source.y]);
    // printf("Rotating row %d times.\n", R[source.y]);

    rots += rotate(source.y, r, C[c]);
    // printf("Rotating col %d times.\n", C[c]);

    printf("%d\n", rots);
  }

  return 0;
}
