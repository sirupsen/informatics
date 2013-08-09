#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

struct Leaf ;
vector<Leaf> leaves;
vector<vector<size_t> > adj;
vector<bool> visited;
int n_branches;

struct RMQTree
{
  vector<size_t> index, val;
  size_t n;

  RMQTree() {}

  RMQTree(size_t n)
  {
    resize(n);
  }

  size_t rmq(size_t query_left, size_t query_right)
  {
    return pair_rmq(1, 0, n - 1, query_left, query_right).second;
  }

  void insert(size_t key, size_t value)
  {
    insert(1, 0, n - 1, key, value);
  }

  void resize(size_t n)
  {
    this->n = n;
    this->index.assign(n * 4, INT_MAX);
    this->val.assign(n * 4, INT_MAX);
  }

  private:
  size_t left_memory(size_t &pos)
  {
    return pos * 2;
  }

  size_t right_memory(size_t &pos)
  {
    return left_memory(pos) + 1;
  }

  void insert(size_t pos, size_t left, size_t right, size_t key, size_t value)
  {
    if(key >= left && key <= right)
    {
      if(value < val[pos])
      {
        val[pos] = value;
        index[pos] = key;
      }

      if(left < right)
      {
        insert(left_memory(pos), left, (left + right) / 2, key, value);
        insert(right_memory(pos), (left + right) / 2 + 1, right, key, value);
      }
    }
  }

  pair<int, int> pair_rmq(size_t pos, size_t left, size_t right, size_t query_left, size_t query_right)
  {
    if(query_left <= left && query_right >= right)
    {
      return pair<int, int> (val[pos], index[pos]);
    }
    else if(query_left > right || query_right < left)
    {
      return pair<int, int> (INT_MAX, INT_MAX);
    }

    pair<int, int> l  = pair_rmq(left_memory(pos), left, (left + right)/2, query_left, query_right);
    pair<int, int> r = pair_rmq(right_memory(pos), (left + right)/2 + 1, right, query_left, query_right);

    if(l.first <= r.first)
    {
      return l;
    }
    else
    {
      return r;
    }
  }
};

struct Leaf
{
  size_t label, depth;

  Leaf *parent;

  vector<Leaf*> descendants, ancestors;

  Leaf() { }

  Leaf(size_t label, Leaf *parent)
  {
    this->label  = label;
    this->parent = parent;
  }

  void precompute_ancestors()
  {
    this->ancestors.clear();

    this->ancestors.push_back(this);

    if(parent != NULL)
      precompute_ancestors(parent);
  }

  void declare_root()
  {
    visited.assign(n_branches + 1, false);
    set_relative_depths(0);

    visited.assign(n_branches + 1, false);
    set_parents(NULL);
  }

  private:
  void precompute_ancestors(Leaf* kth_ancestor)
  {
    if(kth_ancestor != NULL)
    {
      this->ancestors.push_back(kth_ancestor);
      precompute_ancestors(kth_ancestor->parent);
    }
  }

  void set_relative_depths(size_t depth)
  {
    this->depth = depth;
    visited[this->label] = true;

    for(vector<size_t>::iterator child = adj[this->label].begin();
        child != adj[this->label].end(); child++)
    {
      if(!visited[*child])
        leaves[*child].set_relative_depths(depth + 1);
    }
  }

  void set_parents(Leaf *parent)
  {
    this->parent = parent;
    visited[this->label] = true;

    for(vector<size_t>::iterator child = adj[this->label].begin();
        child != adj[this->label].end(); child++)
    {
      if(!visited[*child])
        leaves[*child].set_parents(this);
    }
  }
};

struct LCA {
  RMQTree rmq;
  vector<size_t> h, l;
  vector<Leaf*> e;

  size_t iteration;

  LCA()
  {
    h.assign(n_branches + 1, -1);
    l.assign(2 * n_branches, -1);
    e.assign(2 * n_branches, NULL);

    this->iteration = 0;

    rmq.resize(2 * n_branches);
  }

  void build(Leaf *root)
  {
    lca_dfs(root);
    build_rmq();
  }

  void build_rmq()
  {
    for(size_t i = 0; i < this->iteration; i++)
      rmq.insert(i, l[i]);
  }

  Leaf* lca(Leaf* a, Leaf *b)
  {
    size_t min_label = min(h[a->label], h[b->label]),
           max_label = max(h[a->label], h[b->label]);

    size_t lca_iteration = this->rmq.rmq(min_label, max_label);

    return e[lca_iteration];
  }

  private:
  void lca_dfs(Leaf* leaf)
  {
    if(h[leaf->label] == -1)
      h[leaf->label] = this->iteration;

    e[this->iteration] = leaf;
    l[this->iteration++] = leaf->depth;

    for(vector<size_t>::iterator child = adj[leaf->label].begin();
        child != adj[leaf->label].end(); child++)
    {
      if(h[*child] == -1)
      {
        lca_dfs(&leaves[*child]);

        e[this->iteration] = leaf;
        l[this->iteration++] = leaf->depth;
      }
    }
  }
};

int main()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  size_t a, b;

  while(cin >> n_branches)
  {
    if(!n_branches) break;

    leaves.clear();
    leaves.resize(n_branches + 1);

    adj.clear();
    adj.resize(n_branches + 1);

    for(int i = 1; i < n_branches; i++)
    {
      cin >> a >> b;

      leaves[i].label = i;

      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    leaves[n_branches].label = n_branches;

    Leaf &root = leaves[1];
    root.declare_root();

    for(int i = 1; i <= n_branches; i++)
      leaves[i].precompute_ancestors();

    LCA lca;
    lca.build(&root);

    int n_queries;
    cin >> n_queries;

    while(n_queries--)
    {
      cin >> a >> b;

      Leaf* l = lca.lca(&leaves[a], &leaves[b]);
      size_t distance = leaves[a].depth + leaves[b].depth - 2 * l->depth;

      Leaf* v;
      Leaf* w;

      if(leaves[a].depth >= leaves[b].depth)
      {
        v = &leaves[a];
        w = &leaves[b];
      }
      else
      {
        w = &leaves[a];
        v = &leaves[b];
      }

      if(distance % 2 == 1)
      {
        size_t one = v->ancestors[(distance/2) + 1]->label;
        size_t two = v->ancestors[(distance/2)]->label;

        printf("The fleas jump forever between %zd and %zd.\n", min(one, two), max(one, two));
      }
      else
      {
        printf("The fleas meet at %zd.\n", v->ancestors[distance/2]->label);
      }

      // printf("\n");
    }
  }

  return 0;
}
