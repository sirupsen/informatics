#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

struct SegmentTree {
  vector<size_t> tree;

  SegmentTree(size_t size)
  {
    tree.assign(size * 3, 0);
  }

  void add(int key, int value)
  {
    add(1, 1, tree.size(), key, value);
  }

  int sum(int query_start, int query_end)
  {
    return sum(1, 1, tree.size(), query_start, query_end);
  }

  private:
  void add(int pos, int range_start, int range_end, int key, int value)
  {
    if(key >= range_start && key <= range_end)
    {
      tree[pos] += value;

      if(range_start < range_end)
      {
        add(pos * 2, range_start, (range_start + range_end) / 2, key, value);
        add(pos * 2 + 1, (range_start + range_end) / 2 + 1, range_end, key, value);
      }
    }
  }

  int sum(int pos, int range_start, int range_end, int query_start, int query_end)
  {
    if(range_start >= query_start && range_end <= query_end)
    {
      return tree[pos];
    }
    else if(range_end < query_start || range_start > query_end)
    {
      return 0;
    }
    else
    {
      return sum(pos * 2, range_start, (range_start + range_end) / 2, query_start, query_end) +
             sum(pos * 2 + 1, (range_start + range_end) / 2 + 1, range_end, query_start, query_end);
    }
  }
};

#define MOVE_REQUEST 1
#define CONTINUQUES_REQUEST 2

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> dwarves(n + 1);
  vector<int> height_to_index(n + 1);
  SegmentTree st(n);

  for(int i = 1; i <= n; i++)
  {
    cin >> dwarves[i];
    height_to_index[dwarves[i]] = i;

    st.add(i, dwarves[i]);
  }

  for(int i = 1; i <= m; i++)
  {
    int request, a, b; cin >> request >> a >> b;

    if(request == MOVE_REQUEST)
    {
      st.add(a, dwarves[b]);
      st.add(a, -dwarves[a]);

      st.add(b, dwarves[a]);
      st.add(b, -dwarves[b]);

      height_to_index[dwarves[a]] = b;
      height_to_index[dwarves[b]] = a;

      swap(dwarves[a], dwarves[b]);
    }
    else if(request == CONTINUQUES_REQUEST)
    {
      int range_sum    = st.sum(height_to_index[a], height_to_index[b]);
      int expected_sum = ((b * (b + 1)) / 2) - (((a - 1) * a) / 2);

      printf("Range sum (%d;%d) = (%d;%d): %d, expected: %d\n", a, b, height_to_index[a], height_to_index[b], range_sum, expected_sum);

      if(range_sum == expected_sum)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
    else
    {
      assert("UNKNOWN REQUEST");
    }
  }

  return 0;
}
