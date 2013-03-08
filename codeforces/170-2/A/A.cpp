#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector<int> v(n + 5);

  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int s, t;
  scanf("%d %d", &s, &t);

  int c = s;
  int l_d = 0, r_d = 0;

  while(c != t) {
    // cout << c << endl;
    l_d += v[c];
    c = (c + 1) % n;
  }

  c = s - 1;

  while(true) {
    r_d += v[c];
    if(c == t) break;

    if(c - 1 < 1) c = n;
    else c -= 1;
  }

  printf("%d\n", min(l_d, r_d));

  return 0;
}
