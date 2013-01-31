#include<iostream>
#include<vector>
using namespace std;

struct SegmentTree {
  vector<int> tree;

  SegmentTree(size_t n) {
    tree.assign(n * 2, 0);
  }

  void add(size_t pos, int start, int end, int key, int val) {
    if(key >= start && key <= end) {
      tree[pos] += val;

      if(start != end) {
        add(pos * 2, start, (start + end)/2, key, val);
        add(pos * 2 + 1, (start + end)/2 + 1, end, key, val);
      }
    }
  }

  int sum(size_t pos, int start, int end, int query_start, int query_end) {
    if(start >= query_start && end <= query_end) {
      return tree[pos];
    } else if (query_start > end || query_end < start) {
      return 0;
    } else {
      return sum(pos * 2, start, (start + end)/2, query_start, query_end) +
        sum(pos * 2 + 1, (start + end)/2 + 1, end, query_start, query_end);
    }
  }

  int prefix_sum(size_t pos, int start, int end, int search) {
    if (end == start) return start;

    if(tree[pos * 2] >= search) {
      return prefix_sum(pos * 2, start, (start+end)/2, search);
    } else {
      return prefix_sum(pos * 2+1, (start + end)/2 + 1, end, search - tree[pos * 2]);
    }
  }
};

struct Match {
  int a;
  int b;
  int a_i;
  int b_i;
};

int main()
{
  priority_queue<pair<int, Match>> pq;
  vector<int> numbers;

  int n; scanf("%d", &n);
  numbers.resize(n);

  for(int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);

  for(int i = 0; i < n; i++) {
    int a = numbers[i], b = numbers[i + 1];

    Match m = {};

    pq.push(max(a,b), m);
  }

  for(size_t i = 0; i < 

  return 0;
}
