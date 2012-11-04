#include<iostream>
#include<set>
#include<map>
using namespace std;

map<int, int> freq;

int main()
{
  set<int> points;
  int n; cin >> n;

  for(int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    freq.count(tmp) > 0 ? freq[tmp] += 1 : freq[tmp] = 1;
    points.insert(tmp);
  }


  int winners = 0;

  for(set<int>::iterator it = points.begin(); it != points.end(); it++) {
    set<int>::iterator next = points.upper_bound(*it);
    if(*it + n >= *next + n - 1) winners += freq[*it];
  }

  cout << winners << endl;

  return 0;
}
