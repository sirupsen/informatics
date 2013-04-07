#include<iostream>
#include<cassert>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
using namespace std;

struct DisjointSet {
  vector<int> parent;
  vector<int> cost;

  DisjointSet(int n)
  {
    parent.resize(n);
    cost.resize(n);

    for(int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  void merge(int i, int j)
  {
    parent[find_parent(j)] = find_parent(i);
    cost[find_parent(i)] = min(cost[find_parent(i)], cost[find_parent(j)]);
  }

  int find_parent(int i)
  {
    return parent[i] == i ? i : parent[i] = find_parent(parent[i]);
  }

  bool in_same_set(int i, int j)
  {
    return find_parent(i) == find_parent(j);
  }

  int trip_cost(int i)
  {
    return cost[find_parent(i)];
  }
};

typedef pair<int, pair<int, int> > iii;

int main()
{
  int n;
  cin >> n;

  priority_queue<iii, vector<iii>, greater<iii> > edges;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int weight; scanf("%d", &weight);
      edges.push(make_pair(weight, make_pair(i, j)));
    }
  }

  DisjointSet ds(n);

  for(int i = 0; i < n; i++)
  {
    int cost; scanf("%d", &cost);
    ds.cost[i] = cost;
  }

  int min_span = 0;

  while(!edges.empty())
  {
    iii edge = edges.top(); edges.pop();

    int weight = edge.first,
        spy_a = edge.second.first,
        spy_b = edge.second.second;

    if(!ds.in_same_set(spy_a, spy_b) &&
        weight + min(ds.trip_cost(spy_a), ds.trip_cost(spy_b))
          < ds.trip_cost(spy_a) + ds.trip_cost(spy_b))
    {
      ds.merge(spy_a, spy_b);
      min_span += weight;
    }
  }

  vector<bool> visited;
  visited.assign(n, false);

  for(int i = 0; i < n; i++)
  {
    if(!visited[ds.find_parent(i)])
    {
      min_span += ds.trip_cost(i);
    }

    visited[ds.find_parent(i)] = true;
  }

  cout << min_span << endl;

  return 0;
}
