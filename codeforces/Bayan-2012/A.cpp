#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

vector<int> roads;
vector<int> cities;

int best_so_far = INT_MAX;
int m, k;

int DP[1005][1005];

int solve(int t, int city, int fuel, map<int, int> visited) {
  if(t > best_so_far)
    return INT_MAX;

  if(fuel < 0)
    return INT_MAX;

  if(city == m) {
    best_so_far = t;
    return t;
  }

  if(DP[city][fuel] != -1)
    return DP[city][fuel];

  if(visited.count(city) == 0 || t - visited[city] >= k) {
    visited[city] = t;
    fuel += cities[city];
  }

  return DP[city][fuel] = t - min( // just store delta
      solve(t + roads[city], city + 1, fuel - roads[city], visited),
      solve(t + k, city, fuel, visited)
  );
}

int main() 
{
  cin >> m >> k;

  for(int i = 0; i < 1005; i++)
    for(int j = 0; j < 1005; j++)
      DP[i][j] = -1;

  roads.resize(m + 5);
  cities.resize(m + 5);

  for(int i = 0; i < m; i++) {
    int tmp; cin >> tmp;
    roads[i] = tmp;
  }

  for(int i = 0; i < m; i++) {
    int tmp; cin >> tmp;
    cities[i] = tmp;
  }

  map<int, int> almost_empty;
  almost_empty[0] = 0;

  solve(0, 0, cities[0], almost_empty);

  cout << best_so_far << endl;

  return 0;
}
