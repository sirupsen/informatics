#include<iostream>
#include<cassert>
#include<set>
#include<vector>
using namespace std;

vector<int> adj;
vector<int> revadj;
vector<int> sizes;
set<int> endings;

int size_dfs(int pos, int size)
{
  if(adj[pos] == -1)
  {
    sizes[pos] = max(size, sizes[pos]);
    endings.insert(pos);
    return pos;
  }
  else
  {
    return size_dfs(adj[pos], size + 1);
  }
}

int main()
{
  int n, x;
  cin >> n >> x;

  adj.assign(n + 5, -1);
  revadj.assign(n + 5, -1);
  sizes.assign(n + 5, -1);

  for(int source = 1; source <= n; source++)
  {
    int target; cin >> target;

    if(target != 0)
    {
      adj[source] = target;
      revadj[target] = source;
    }
  }

  int x_ending = size_dfs(x, 1);

  for(int i = 1; i <= n; i++)
    size_dfs(i, 1);

  vector<bool> seq(n + 1, false);

  seq[0] = true;

  for(auto ending : endings)
  {
    if(ending != x_ending)
    {
      int s = sizes[ending];

      for(int i = n - s; i >= 0; i--)
      {
        seq[i + s] = max(seq[i], seq[i + s]);
      }
    }
  }

  int depth = 1;

  for(int e = x_ending; e != x; e = revadj[e], depth++) {}

  for(int i = 0; i <= n; i++)
  {
    if(seq[i])
    {
      cout << i + depth << endl;
    }
  }

  return 0;
}
