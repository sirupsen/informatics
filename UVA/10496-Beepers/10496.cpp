#include<iostream>
#include<cstring>
#include<cmath>
#include<climits>
#include<utility>
#include<vector>
using namespace std;

#define x first
#define y second
#define MAX_N 15

vector<pair<int, int> > points;
pair<int, int> start;

int dist(pair<int, int> &a, pair<int, int> &b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int dp[MAX_N][1 << MAX_N];

int solve(int point, int mask)
{
  if(mask == (1 << points.size()) - 1)
    return dist(points[point], start);

  int lmin = INT_MAX;

  for(int i = 0; i < points.size(); i++)
  {
    if(!(mask & (1 << i)))
    {
      lmin = min(solve(i, mask | (1 << i)) + dist(points[point], points[i]), lmin);
    }
  }

  return dp[point][mask] = lmin;
}

int main()
{
  int n_test_cases;
  cin >> n_test_cases;

  for(int test_case = 0; test_case < n_test_cases; test_case++)
  {
    int n, m;
    cin >> n >> m;

    cin >> start.x >> start.y;

    int n_points;
    cin >> n_points;

    points.clear();
    points.resize(n_points + 1);

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n_points; i++)
    {
      cin >> points[i].x >> points[i].y;
    }

    points[n_points] = start;

    cout << "The shortest path has length " << solve(n_points, 1 << n_points) << endl;
  }

  return 0;
}
