#include<cstdio>
#include<set>
#include<vector>
using namespace std;

struct DisjointSet {
  vector<size_t> parent;
  size_t n;
  int distinct_sets;

  DisjointSet(size_t n) 
  {
    this->n = n;
    this->distinct_sets = n - 1;
    parent.resize(this->n + 1);

    for(size_t i = 1; i < this->n; i++)
      parent[i] = i;
  }

  size_t find_parent(size_t i)
  {
    return parent[i] == i ? i : parent[i] = find_parent(parent[i]);
  }

  void merge(size_t i, size_t j)
  {
    if(find_parent(i) != find_parent(j)) 
      this->distinct_sets--;

    parent[find_parent(i)] = find_parent(j);
  }
};

int main()
{
  int n; 
  for(int i = 0; scanf("%d", &n) == 1; i++) {
    if(i > 0) printf(" ");

    vector<int> boxes(n + 1);

    DisjointSet ds(n + 1);

    for(int i = 1; i <= n; i++)
      scanf("%d", &boxes[i]);

    for(size_t i = 1; i <= n; i++)
      ds.merge(boxes[i], i);

    printf("%zd", ds.distinct_sets);
  }

  printf("\n");

  return 0;
}
