#include<iostream>
#include<queue>
#include<cstdio>
#include<climits>
#include<vector>
#include<utility>
#include "race.h"
using namespace std;

int root = 0;

vector<vector<pair<int, int> > > adj;
vector<int> depths;
vector<bool> vis;

bool 

#define IS_OK -2

void set_depth(int v, int depth)
{
  if(vis[v]) return;

  vis[v] = true;

  for(int i = 0; i < adj[v].size(); i++)
  {
    int edge = adj[v][i].first, target = adj[v][i].second;

    depths[edge] = depth;

    set_depth(target, depth + 1);
  }
}

int best_path(int N, int K, int H[][2], int L[])
{
  int k = K, n = N;

  adj.resize(n);
  depths.assign(n, -1);
  vis.assign(n, false);

  for(int i = 0; i < n - 1; i++)
  {
    adj[H[i][0]].push_back(make_pair(i, H[i][1]));
    adj[H[i][1]].push_back(make_pair(i, H[i][0]));
  }

  set_depth(0, 0);

  priority_queue<pair<int, int> > pq;

  for(int i = 0; i < n - 1; i++)
    pq.push(make_pair(depths[i], i));

  vector<pair<int, pair<int, int> > > dp(K + 5);

  dp[0] = make_pair(0, make_pair(IS_OK, IS_OK));

  for(int i = 1; i <= k; i++)
    dp[i] = make_pair(INT_MAX, make_pair(INT_MAX, INT_MAX));

  while(!pq.empty())
  {
    pair<int, int> top = pq.top();
    pq.pop();

    int index = top.second, depth = top.first;
    int weight = L[index];
    int dest = H[index][0], orig = H[index][1];

    for(int i = K - weight; i >= 0; i--)
    {
      if(dp[i].first < INT_MAX &&
          (dp[i].second.first == dest || dp[i].second.first == orig || dp[i].second.first == IS_OK) ||
          (dp[i].second.second == dest || dp[i].second.second == orig)
        )
      {
        // printf("w: %d, i: %d, dp[i + weight]: %d\n", weight, i, dp[i + weight].first);

        if(dp[i].first + 1 <= dp[i + weight].first)
        {
          dp[i + weight].first  = dp[i].first + 1;

          dp[i + weight].second.first = orig;
          dp[i + weight].second.second = dest;
        }
      }
    }
  }

  for(int i = 0; i <= K; i++)
  {
    printf("%d ", dp[i].first);
  }
  printf("\n");

  return dp[k].first == INT_MAX ? -1 : dp[k].first;
}
