#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

struct Tree {
  vector<ll> tree;
  ll n;

  Tree() {}

  Tree(ll n) 
  {
    init(n);
  }

  void init(ll n)
  {
    tree.assign(n * 4, 0);
    this->n = n;
  }

  inline ll left_memory(ll position)
  {
    return position * 2;
  }

  inline ll right_memory(ll position)
  {
    return left_memory(position) + 1;
  }

  ll sum(ll position, ll start, ll end, 
      ll query_start, ll query_end)
  {
    if(start >= query_start && end <= query_end) {
      return tree[position];
    } else if(start > query_end || end < query_start) {
      return 0;
    } else {
      return sum(left_memory(position), start, (start+end)/2, query_start, query_end) + 
        sum(right_memory(position), (start+end)/2+1, end, query_start, query_end);
    }
  }
  
  void add(ll position, ll start, ll end, ll key, ll val)
  {
    if(key <= end && key >= start) {
      tree[position] += val;

      if(start != end) {
        add(left_memory(position), start, (start+end)/2, key, val);
        add(right_memory(position), (start+end)/2+1, end, key, val);
      }
    }
  }

  void add(ll key, ll val)
  {
    add(1, 1, n, key, val);
  }

  ll sum(ll query_start, ll query_end)
  {
    return sum(1, 1, n, query_start, query_end);
  }
};

struct SuperRangeTree {
  Tree b, c;

  SuperRangeTree(ll size)
  {
    this->b.init(size);
    this->c.init(size);
  }

  void add(ll start, ll end, ll val)
  {
    b.add(start, val);
    b.add(end + 1, -val);

    c.add(start, start * val);
    c.add(end + 1, -((end + 1) * val));
  }

  ll sum(ll start, ll end)
  {
    // (k - 1) * (b1 + b1 + .. + b_end) - (c1 + c2 + .. + c_end)
    ll first = (end + 1) * b.sum(1, end) - c.sum(1, end);
    ll second = start * b.sum(1, start - 1) - c.sum(1, start - 1);

    return first - second;
  }
};

int main()
{
  size_t n, m;
  scanf("%ld %ld", &n, &m);
  SuperRangeTree srt(n);

  while(m--) {
    size_t cmd, x, y, z; 
    scanf("%ld", &cmd);

    if(cmd == 0) {
      scanf("%ld %ld", &x, &y);
      printf("%lld\n", srt.sum(x, y));
    } else {
      scanf("%ld %ld %ld", &x, &y, &z);
      srt.add(x, y, z);
    }
  }

  return 0;
}
