#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n;
vector<int> tree;

void initTree(int position, int interval_start, int interval_end)
{
  tree[position] = interval_end - interval_start + 1; // number of balls

  if(interval_end > interval_start) {
    initTree(position * 2, interval_start, (interval_start + interval_end)/2); // lowest left
    initTree(position * 2 + 1, (interval_start + interval_end)/2 + 1, interval_end);
  }
}

void addToTree(int position, int interval_start, int interval_end, int key, int value)
{
  if(key >= interval_start && key <= interval_end) {
    tree[position] += value;

    if(interval_start != interval_end) {
      addToTree(position * 2, interval_start, (interval_start + interval_end)/2, key, value);
      addToTree(position * 2 + 1, (interval_start + interval_end)/2+1, interval_end, key, value);
    }
  }
}

int getSum(int position, int interval_start, int interval_end, int query_start, int query_end) {
	if(query_start <= interval_start && query_end >= interval_end) { 
		return tree[position];
	} else if(query_start > interval_end || query_end < interval_start) { 
		return 0;
	} else {
		return getSum(2*position, interval_start, (interval_start+interval_end)/2, query_start, query_end) +
			     getSum(2*position+1, (interval_start+interval_end)/2+1, interval_end, query_start, query_end);
	}
}

void addToRange(int position, int interval_start, int interval_end, int selected_start, int selected_end, int val) {
  // in range
	if(selected_start <= interval_end && selected_end >= interval_start) { 
    tree[position] += (min(interval_end, selected_end) - max(selected_start, interval_start) + 1) * val;

    if(interval_end > interval_start) {
      addToRange(position * 2, interval_start, (interval_start + interval_end)/2, 
          selected_start, selected_end, val);
      addToRange(position * 2 + 1, (interval_start + interval_end)/2+1, interval_end, 
          selected_start, selected_end, val);
    }
  }
}

int searchMinEnd(int position, int start, int end, int search)
{
  if(end == start) return start;

  if(tree[position * 2] >= search) {
    return searchMinEnd(position * 2, start, (start + end)/2, search);
  } else {
    return searchMinEnd(position * 2+1, (start + end)/2+1, end, search - tree[position * 2]);
  }
}

void addToTree(int key, int val)
{
  addToTree(1,1,n,key,val);
}

void addToRange(int range_start, int range_end, int val)
{
  addToRange(1,1,n,range_start,range_end,val);
}

int searchMinEnd(int search)
{
  return searchMinEnd(1,1,n,search);
}

int main()
{
  int k;
  cin >> n;
  tree.resize(n * 4);
  initTree(1, 1, n);

  for(size_t i = 0; i < n - 1; ++i) 
  {
    cin >> k;
    int pos = searchMinEnd(k);
    // cout << pos << endl;
    addToTree(pos, -1);
  }

  cout << searchMinEnd(1) << endl;

  return 0;
}
