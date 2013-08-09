#include<iostream>
#include<algorithm>
#include<climits>
#include<cassert>
#include<string>
#include<vector>
using namespace std;

vector<vector<size_t> > adjl;

#define lsig(i) (i & (-i))

struct FenwickTree {
  vector<int> ft;

  FenwickTree(size_t size)
  {
    ft.assign(size + 1, 0);
  }

  int rmq(size_t j)
  {
    if(j == 0) return 0;

    int sum = 0;

    for(; j; j -= lsig(j))
      sum += ft[j];

    return sum;
  }

  int rmq(size_t i, size_t j)
  {
    return rmq(j) - rmq(i - 1);
  }

  void adjust(size_t i, int k)
  {
    for(; i < ft.size(); i += lsig(i))
    {
      ft[i] += k;
    }
  }
};

string to_binary(int k)
{
  string n;

  while(k > 0)
  {
    n += (char) (k % 2) + '0';
    k /= 2;
  }

  reverse(n.begin(), n.end());

  return n;
}

int it = 0;
int h[50];
int e[50];
int l[50];

void dfs(size_t v, unsigned int depth)
{
  h[v] = it;
  e[it] = v;
  l[it++] = depth;

  for(int i = 0; i < adjl[v].size(); i++)
  {
    cout << v << ":" << adjl[v][i] << endl;

    dfs(adjl[v][i], depth + 1);
    e[it] = v;
    l[it++] = depth;
  }
}

int lca(size_t i, size_t j)
{
  int min_depth = INT_MAX;
  int min_depth_iteration = -1;

  printf("h[%zd]: %d\n", i, h[i]);
  printf("h[%zd]: %d\n", j, h[j]);

  for(int k = h[i]; k <= h[j]; k++)
  {
    cout << k << ": " << l[k] << endl;

    if(l[k] < min_depth)
    {
      min_depth_iteration = k;
      min_depth = l[k];
    }
  }

  printf("Min depth: %d, at i: %d, index: %d\n", min_depth, min_depth_iteration, e[min_depth_iteration]);

  return e[min_depth_iteration];
}

int main()
{
  FenwickTree fenwick(10);

  adjl.resize(11);

  adjl[0].push_back(1);
  adjl[0].push_back(7);

  adjl[1].push_back(2);
  adjl[1].push_back(3);
  adjl[1].push_back(6);

  adjl[3].push_back(4);
  adjl[3].push_back(5);

  adjl[7].push_back(8);
  adjl[7].push_back(9);

  memset(h, -1, sizeof h);
  dfs(0,0);

  cout << lca(5,9) << endl;
  cout << to_binary(24) << endl;

  return 0;
}
