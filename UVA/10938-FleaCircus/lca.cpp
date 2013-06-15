#include <vector>
#include <climits>
using namespace std;

int iteration = 0;
vector<size_t> h, l, e;
vector<vector<size_t> > adj;

void lca_dfs(size_t v, size_t depth)
{
  if(h[v] == -1)
    h[v] = iteration;

  e[iteration] = v;
  l[iteration++] = depth;

  for(vector<size_t>::iterator u = adj[v].begin();
      u != adj[v].end(); u++)
  {
    // Just because our graph is bidirectional,
    // we check if we've visited it before, so we don't
    // go infinite.
    if(h[*u] == -1)
    {
      lca_dfs(*u, depth + 1);

      // Back at parent
      e[iteration] = v;
      l[iteration++] = depth;
    }
  }
}

size_t lca(size_t v, size_t w)
{
  int min_depth_iteration = -1;
  int min_depth = INT_MAX;

  // Naive RMQ, #yolo
  for(int i = h[v]; i <= h[w]; i++) {
    if(l[i] < min_depth) {
      min_depth = l[i];
      min_depth_iteration = i;
    }
  }

  // Now min_depth_iteration is the iteration
  // at which we have the minimum depth
  // return whatever node was present at that iteration
  return e[min_depth_iteration];
}

int main()
{
  return 0;
}
