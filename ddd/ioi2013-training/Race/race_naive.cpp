#include<iostream>
#include<climits>
#include<vector>
#include<utility>
#include "race.h"
using namespace std;

vector<vector<pair<int, int> > > adj;
int k, n;
vector<bool> vis;

int dfs(int v, int len, int val)
{
  if(vis[v])
  {
    return INT_MAX;
  }
  else if(val == k)
  {
    return len;
  }
  else
  {
    vis[v] = true;

    int lmin = INT_MAX;

    for(int i = 0; i < adj[v].size(); i++)
      lmin = min(dfs(adj[v][i].first, len + 1, val + adj[v][i].second), lmin);

    return lmin;
  }
}

int best_path(int N, int K, int H[][2], int L[])
{
  k = K, n = N;

  adj.resize(n + 1);

  for(int i = 0; i < n - 1; i++)
  {
    adj[H[i][0]].push_back(make_pair(H[i][1], L[i]));
    adj[H[i][1]].push_back(make_pair(H[i][0], L[i]));
  }

  int lmin = INT_MAX;

  for(int i = 0; i <= n; i++)
  {
    vis.assign(n + 1, false);

    lmin = min(dfs(i, 0, 0), lmin);
  }

  return lmin == INT_MAX ? -1 : lmin;
}
