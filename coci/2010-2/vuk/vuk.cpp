#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> Point;

#define MAX_N 505
#define MAX_DIST MAX_N * MAX_N
#define x first
#define y second

int n, m;
int dist[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

queue<Point> q;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

#define N_MOVES 4
#define WITHIN_BOUNDS(p) p.x >= 0 && p.x < n && p.y >= 0 && p.y < m
#define DIST(p) dist[p.x][p.y]
#define DPOINT(p,i) Point(p.x + dx[i], p.y + dy[i])
#define VISITED(p) vis[p.x][p.y]

Point t, s;

bool flood_fill(Point cur, int &min_depth)
{
  if(dist[cur.x][cur.y] < min_depth)
    return false;

  if(cur.x == t.x && cur.y == t.y)
    return true;

  if(!(WITHIN_BOUNDS(cur)))
    return false;

  if(VISITED(cur))
    return false;

  VISITED(cur) = true;

  bool any = false;

  for(int i = 0; i < N_MOVES; i++)
    any = max(flood_fill(DPOINT(cur, i), min_depth), any);

  return any;
}

int max_possible(int upper_bound)
{
  int lower = 0, upper = upper_bound, middle;

  while(upper - lower > 10)
  {
    middle = (lower + upper) / 2;

    memset(vis, false, sizeof vis);

    if(flood_fill(s, middle))
    {
      lower = middle;
    }
    else
    {
      upper = middle - 1;
    }
  }

  for(;upper >= lower; upper--)
  {
    memset(vis, false, sizeof vis);

    if(flood_fill(s, upper))
    {
      return upper;
    }
  }
}

void tree_dist()
{
  memset(dist, -1, sizeof dist);

  for(int depth = 0; !q.empty(); depth++)
  {
    int c = q.size();

    while(c--)
    {
      Point f = q.front(); q.pop();
      if(DIST(f) != -1) continue;

      DIST(f) = depth;

      for(int i = 0; i < N_MOVES; i++)
      {
        Point new_point = DPOINT(f, i);

        if(DIST(new_point) == -1 && (WITHIN_BOUNDS(new_point)))
          q.push(new_point);
      }
    }
  }
}

int main()
{
  cin >> n >> m;

  char tmp;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cin >> tmp;

      if(tmp == '+')
      {
        q.push(Point(i, j));
      }
      else if(tmp == 'J')
      {
        t = Point(i, j);
      }
      else if(tmp == 'V')
      {
        s = Point(i, j);
      }
    }
  }

  tree_dist();

  // for(int i = 0; i < n; i++)
  // {
  //   for(int j = 0; j < m; j++)
  //   {
  //     printf("%d", dist[i][j]);
  //   }
  //   printf("\n");
  // }

  cout << max_possible(MAX_DIST) << endl;

  return 0;
}
