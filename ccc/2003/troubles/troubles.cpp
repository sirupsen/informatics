#include<cstdio>
#include<climits>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct DisjointSet {
  vector<int> parent;
  vector<int> val;

  DisjointSet(int size)
  {
    parent.resize(size + 5);
    val.assign(size + 5, 0);

    for(int i = 0; i <= size; i++)
      parent[i] = i;
  }

  int find_parent(int i)
  {
    return i == parent[i] ? i : parent[i] = find_parent(parent[i]);
  }

  bool in_same_set(int i, int j)
  {
    return find_parent(i) == find_parent(j);
  }

  void merge(int i, int j, int v)
  {
    int pi = find_parent(i);
    int pj = find_parent(j);

    int new_val = val[pi] + v;

    val[pi] = 0;
    parent[pi] = pj;
    val[pj] += new_val;
  }
};

int main()
{
  int c, r, d;

  scanf("%d %d %d", &c, &r, &d);

  priority_queue<iii> pq;

  for(int i = 0; i < r; i++)
  {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    pq.push(iii(w, ii(a, b)));
  }

  vector<bool> must_vis(c + 5, false);

  for(int i = 0; i < d; i++)
  {
    int a;
    scanf("%d", &a);
    must_vis[a] = true;
  }

  DisjointSet ds(c);

  int max_load = 0, val = 0;

  while(!pq.empty() && ds.val[ds.find_parent(1)] != d)
  {
    iii front = pq.top(); pq.pop();
    ii &cities = front.second;

    max_load = front.first;

    val = must_vis[cities.first] + must_vis[cities.second];

    must_vis[cities.first] = false;
    must_vis[cities.second] = false;

    ds.merge(cities.first, cities.second, val);
  }

  printf("%d\n", max_load);

  return 0;
}
