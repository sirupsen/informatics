#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> a;
  a.resize(n + 5);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  a[0] = a[n + 1] = INT_MAX;

  vector<int> s;
  s.push_back(a[0]);

  long long res = 0;

  for(int i = 1; i <= n + 1; i++) {
    while(a[i] >= s.back()) {
      int k = min(a[i], s[s.size() - 2]);
      if(k == INT_MAX) break;
      res += k;
      s.pop_back();
    }
    s.push_back(a[i]);
  }

  printf("%lld\n", res);

  return 0;
}
