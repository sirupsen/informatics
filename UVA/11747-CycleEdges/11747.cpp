#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct UnionDisjointSet {
  vector<int> parent;

  UnionDisjointSet(size_t n) {
    parent.resize(n + 1);

    for(size_t i = 0; i <= n; i++)
      parent[i] = i;
  }

  void merge(size_t i, size_t j) {
    parent[find_parent(i)] = find_parent(j);
  }

  size_t find_parent(size_t i) {
    return parent[i] == i ? i : parent[i] = find_parent(parent[i]);
  }

  bool in_same_set(size_t i, size_t j) {
    return find_parent(i) == find_parent(j);
  }
};

int main()
{
  while(true) {
    int n, m;
    scanf("%d %d", &n, &m);

    if(n == 0 && m == 0) break;

    vector<iii> edges;

    vector<size_t> all_weights, used_weights, diff_weights;

    UnionDisjointSet uds(n);

    for(size_t i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edges.push_back(make_pair(w, make_pair(u, v)));
      all_weights.push_back(w);
    }

    sort(edges.begin(), edges.end());

    for(vector<iii>::iterator e = edges.begin(); e != edges.end(); e++) {
      if(!uds.in_same_set(e->second.first, e->second.second)) {
        used_weights.push_back(e->first);
        uds.merge(e->second.first, e->second.second);
      }
    }

    sort(all_weights.begin(), all_weights.end());
    sort(used_weights.begin(), used_weights.end());

    set_difference(all_weights.begin(), all_weights.end(),
        used_weights.begin(), used_weights.end(),
        inserter(diff_weights, diff_weights.begin()));

    if(all_weights.size() == used_weights.size()) {
      printf("forest\n");
    } else {
      for(vector<size_t>::iterator e = diff_weights.begin(); e != diff_weights.end(); e++) {
        if(e == diff_weights.end() - 1) {
          printf("%ld", *e);
        } else {
          printf("%ld ", *e);
        }
      }

      printf("\n");
    }
  }

  return 0;
}
