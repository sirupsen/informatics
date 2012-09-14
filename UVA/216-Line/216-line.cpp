#include<iostream>
#include<cmath>
#include<climits>
#include<cstdio>
#include<vector>
using namespace std;

#define MAX_N 10

struct Computer{
  double x;
  double y;
};

Computer computers[MAX_N];
double dist[MAX_N][MAX_N];
double DP[MAX_N][1 << MAX_N];

size_t n; 

double d(Computer a, Computer b) {
  return sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0)) + 16.0;
}

double recurse(int i, int switched, vector<int> prev)
{
  if(switched == (1 << n) - 1) return 0;
  if(DP[i][switched] != 0) return DP[i][switched];

  prev.push_back(i);

  double local_min = INT_MAX;
  for(int j = 0; j < n; j++)
    if(i != j && !(switched & (1 << j)))
      local_min = min(dist[i][j] + recurse(j, switched | (1 << j), prev), local_min);

  return DP[i][switched] = local_min;
}

int main()
{
  for(unsigned int p = 1; cin >> n; p++) {
    if(n == 0) return 0;
    memset(DP, 0, sizeof DP);

    for(size_t i = 0; i < n; ++i) {
      Computer c; cin >> c.x >> c.y;
      computers[i] = c;
    }


    for(size_t i = 0; i < n; ++i) for(size_t j = 0; j < n; ++j)
      dist[i][j] = d(computers[i], computers[j]);

    vector<int> empty;

    printf("%d: %.2f\n", p, recurse(0, 1, empty));
  }
}
