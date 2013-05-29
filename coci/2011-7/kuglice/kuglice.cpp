#include<iostream>
#include<sstream>
#include<cassert>
#include<vector>
using namespace std;

#define MARBLE_QUERY  1
#define EDGE_DELETION 2
#define CYCLE -1

struct DisjointSet {
  vector<int> parent;
  vector<bool> cycle;

  DisjointSet(int n)
  {
    parent.resize(n);
    cycle.assign(n, false);

    for(int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int find_parent(int i)
  {
    return i == parent[i] ? i : parent[i] = find_parent(parent[i]);
  }

  int same_set(int i, int j)
  {
    return find_parent(i) == find_parent(j);
  }

  int has_cycle(int i)
  {
    return cycle[find_parent(i)];
  }

  void merge(int origin, int target)
  {
    if(same_set(origin, target))
    {
      cycle[find_parent(origin)] = true;
    }
    else
    {
      parent[find_parent(target)] = find_parent(origin);
    }
  }
};

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> targets(n + 1);

  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &targets[i]);
  }

  int q;
  cin >> q;

  vector<pair<int, int> > queries(q);

  vector<bool> deleted_by_end(n + 1, false);

  for(int i = 0; i < q; i++)
  {
    scanf("%d %d", &queries[i].first, &queries[i].second);

    if(queries[i].first == EDGE_DELETION)
    {
      deleted_by_end[queries[i].second] = true;
    }
  }

  DisjointSet graph(n + 1);

  for(int i = 1; i <= n; i++)
  {
    if(!deleted_by_end[i])
    {
      int origin = i;
      int target = targets[origin];

      if(target)
      {
        graph.merge(target, origin);
      }
    }
  }

  vector<int> output;

  for(int i = q - 1; i >= 0; i--)
  {
    if(queries[i].first == EDGE_DELETION)
    {
      int origin = queries[i].second;
      int target = targets[origin];

      graph.merge(target, origin);
    }
    else if(queries[i].first == MARBLE_QUERY)
    {
      if(graph.has_cycle(queries[i].second))
      {
        output.push_back(CYCLE);
      }
      else
      {
        output.push_back(graph.find_parent(queries[i].second));
      }
    }
  }


  reverse(output.begin(), output.end());

  for(auto line : output)
  {
    if(line == CYCLE)
    {
      printf("CIKLUS\n");
    }
    else
    {
      printf("%d\n", line);
    }
  }

  return 0;
}
