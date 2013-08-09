#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
using namespace std;

vector<pair<int, pair<int, int> > > edgelist;

vector<int> parent_set;
vector<int> solution;
int n_schools, n_connections;

void initSet(size_t size)
{
  parent_set.clear();
  parent_set.resize(size);

  while(size--) parent_set[size] = size;
}

int findSet(size_t i)
{
  return (parent_set[i] == i) ? i : (parent_set[i] = findSet(parent_set[i]));
}

bool sameSet(size_t i, size_t j)
{
  return findSet(i) == findSet(j);
}

void mergeSet(size_t i, size_t j)
{
  if(!sameSet(i, j)) parent_set[findSet(i)] = findSet(j);
}

int kruskals(size_t skip_index) {
  initSet(n_schools + 1);
  int best_mst = 0;

  for(size_t i = 0; i < (size_t) edgelist.size(); ++i) {
    if(i == skip_index) continue;
    pair<int, pair<int, int> > front = edgelist[i];

    if(!sameSet(front.second.first, front.second.second)) {
      best_mst += front.first;
      mergeSet(front.second.first, front.second.second);

      if(skip_index == -1) 
        solution.push_back(i);
    }
  }

  for(size_t i = 2; i <= n_schools; ++i)
    if(!sameSet(i, 1)) return INT_MAX;

  return best_mst;
}

int main()
{
  int n_test_cases;
  scanf("%d", &n_test_cases);

  while(n_test_cases--) {
    scanf("%d %d", &n_schools, &n_connections);
    solution.clear();
    edgelist.clear();

    for(size_t i = 0; i < n_connections; ++i) {
      pair<int, pair<int, int> > u;
      scanf("%d %d %d", &u.second.first, &u.second.second, &u.first);
      edgelist.push_back(u);
    }

    sort(edgelist.begin(), edgelist.end());

    int best_mst = kruskals(-1);

    int second_best_mst = INT_MAX;
    for(vector<int>::iterator it = solution.begin(); it != solution.end(); ++it)
      second_best_mst = min(kruskals(*it), second_best_mst);

    printf("%d %d\n", best_mst, second_best_mst);
  }

  return 0;
}
