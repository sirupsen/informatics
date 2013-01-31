#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  int n; cin >> n;

  vector<int> v;

  for(size_t i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  int count = 0;

  vector<int>::iterator i = v.begin();
  vector<int>::iterator j = v.end() - 1;

  for(; i != j; i++) {
    if(*i * 2 >= *j) {
      break;
    } else {
      count++;
    } 
  }

  cout << count << endl;

  return 0;
}
