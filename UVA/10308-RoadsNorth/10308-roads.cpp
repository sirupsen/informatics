#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<sstream>
#define MAX_N 10005
using namespace std;

struct Edge {
  int target;
  int weight;
};

vector<vector<Edge> > al;
bool visited[MAX_N];

int global_max_u;
int global_max_cost;
int global_max_depth;

void dfs(size_t u, int depth, int cost)
{
  if(visited[u]) return;

  if(depth > global_max_depth) {
    global_max_u = u;
    global_max_cost = cost;
    global_max_depth = depth;
  }

  visited[u] = true;

  int local_max = 0;
  for(size_t i = 0; i < al[u].size(); ++i)
    dfs(al[u][i].target, depth + 1, cost + al[u][i].weight);
}

void solve()
{
  global_max_u = -1;
  global_max_cost = -1;
  global_max_depth = INT_MIN;

  for(size_t i = 0; i < MAX_N; ++i)
    visited[i] = false;

  dfs(1, 0, 0);

  for(size_t i = 0; i < MAX_N; ++i)
    visited[i] = false;

  dfs(global_max_u, 0, 0);

  cout << global_max_cost << endl;
}

int main()
{
  string line;
  al.resize(MAX_N);

  // handle horrible input
  while(getline(cin, line)) {
    if(line == "") {
      solve();
      al.clear();
      al.resize(MAX_N);
      continue;
    }

    int a, b, w;
    stringstream ss(line);

    ss >> a >> b >> w;
    Edge c = {a, w};
    Edge d = {b, w};
    al[a].push_back(d);
    al[b].push_back(c);
  }
  solve();

  return 0;
}
