#include<iostream>
#include<cstring>
#include<climits>
#include<cassert>
#include<map>
#include<queue>
#include<vector>
using namespace std;

#define x first
#define y second
#define MAX_N 2005
#define N_MOVES 4

typedef pair<int, int> ii;

struct Mall {
  size_t n_points;
  vector<ii> points;

  bool read()
  {
    cin >> n_points;

    if(n_points == 0)
      return false;

    points.resize(n_points + 5);

    for(int i = 0; i < n_points; i++)
      cin >> points[i].x >> points[i].y;

    return true;
  }

  bool within_bounds(ii &a)
  {
    return a.x >= 0 && a.x < 2000 && a.y >= 0 && a.y < 2000;
  }
};

int main()
{
  ios::sync_with_stdio(false);

  while(true)
  {
    Mall m1;
    if(!m1.read()) break;

    Mall m2;
    m2.read();

    static int dist[MAX_N][MAX_N];
    static bool other_mall[MAX_N][MAX_N];

    for(int i = 0; i < MAX_N; i++)
    {
      for(int j = 0; j < MAX_N; j++)
      {
        dist[i][j] = -1;
        other_mall[i][j] = false;
      }
    }

    queue<ii> q;

    for(int i = 0; i < m1.n_points; i++)
    {
      ii &point = m1.points[i];
      dist[point.x][point.y] = 0;
      q.push(point);
    }

    for(int i = 0; i < m2.n_points; i++)
    {
      ii &point = m2.points[i];
      other_mall[point.x][point.y] = true;
    }

    const ii moves[] = {
      ii(1,0),
      ii(-1,0),
      ii(0,1),
      ii(0,-1)
    };

    int depth = -1;

    while(!q.empty())
    {
      int current_depth_stack_size = q.size();

      while(current_depth_stack_size--)
      {
        ii front = q.front(); q.pop();

        if(other_mall[front.x][front.y])
        {
          depth = dist[front.x][front.y];
          goto tobias_er_en_lort;
        }

        for(int i = 0; i < N_MOVES; i++)
        {
          ii p = ii(front.x + moves[i].x, front.y + moves[i].y);

          if(p.x >= 0 && p.x < 2000 && p.y >= 0 && p.y < 2000 && dist[p.x][p.y] == -1)
          {
            dist[p.x][p.y] = dist[front.x][front.y] + 1;
            q.push(p);
          }
        }
      }
    }

tobias_er_en_lort:
    cout << depth << endl;
  }

  return 0;
}
