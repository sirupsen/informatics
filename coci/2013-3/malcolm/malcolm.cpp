#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> l(21, 0);
  vector<int> d(n + 5);

  long long m = 0;
  char p[21];

  for(int i = 0; i < n; i++)
  {
    scanf("%s", p);
    d[i] = strlen(p);

    m += l[d[i]];

    if(i >= k)
      l[d[i - k]]--;

    l[d[i]]++;
  }

  printf("%lld", m);

  return 0;
}
