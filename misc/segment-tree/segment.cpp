#include<iostream>
#include<vector>
using namespace std;

vector<int> array;

struct RangeMinimumTree {
  vector<size_t> tree;

  RangeMinimumTree(size_t n) 
  {
    tree.assign(n * 4, 0);
    build(1, 0, n);
  }

  void build(size_t pos, int start, int end) 
  {
    if(start == end) {
      tree[pos] = start;
    } else {
      build(2 * pos, start, (start+end)/2);
      build(2 * pos + 1, (start+end)/2+1, end);

      int left = tree[2 * pos];
      int left_value = array[left];

      int right = tree[2 * pos + 1];
      int right_value = array[right];

      (left_value <= right_value) ? tree[pos] = left : tree[pos] = right;
    }
  }

  int rmq(int pos, int start, int end, int query_start, int query_end)
  {
    if(start > query_end || end < query_start) 
      return -1;

    if(start >= query_start && end <= query_end)
      return tree[pos];

    int left = rmq(2 * pos, start, (start+end)/2, query_start, query_end);
    int right = rmq(2 * pos + 1, (start+end)/2+1, end, query_start, query_end);

    if(left == -1)
      return right;
    if(right == -1)
      return left;

    return array[left] <= array[right] ? left : right;
  }
};

int main()
{
  array.push_back(7); // 0
  array.push_back(2); // 1
  array.push_back(8); // 2

  array.push_back(3); // 3
  array.push_back(6); // 4
  array.push_back(7); // 5

  array.push_back(4); // 6
  array.push_back(5); // 7
  array.push_back(8); // 8

  array.push_back(1); // 9

  RangeMinimumTree rmq(array.size() - 1);

  cout << rmq.rmq(1, 0, array.size() - 1, 0, 3) << endl;

  return 0;
}
