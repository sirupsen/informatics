#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
  vector<int> c;
  
  int ai, bi, i;
  ai = bi = i = 0;

  for(;i < a.size() + b.size(); i++) {
    if (ai + 1 > a.size()) {
      ai--;
      a[ai] = INT_MAX;
    }

    if (bi + 1 > b.size()) {
      bi--;
      b[bi] = INT_MAX;
    } 
    
    if (a[ai] < b[bi]) {
      c.push_back(a[ai]);
      ai++;
    } else {
      c.push_back(b[bi]);
      bi++;
    }
  }

  return c;
}

void output_vector(vector<int> v) {
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    cout << *it << " ";

  cout << "\n";
}

vector<int> merge_sort(vector<int> vec)
{
  if (vec.size() > 1) {
    int mid = (vec.size() + 1) / 2;

    vector<int> a;
    vector<int> b;

    vector<int>::iterator it;

    // a is left half
    for(it=vec.begin(); it != vec.begin() + mid; it++)
      a.push_back(*it);

    // b is second half
    for(it=vec.begin() + mid; it != vec.end(); it++)
      b.push_back(*it);

    vector<int>sorted_a = merge_sort(a);
    vector<int>sorted_b = merge_sort(b);

    return merge(sorted_a, sorted_b);
  } else { // n=1
    return vec;
  }
}

int main() {
  vector<int> numbers;

  int c;
  while((cin.peek() != '\n') && (cin >> c)) numbers.push_back(c);

  output_vector(merge_sort(numbers));

  return 0;
}
