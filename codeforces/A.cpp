#include<cstdio>
using namespace std;
#define MAX_N 10e9 + 5

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  int freq[10e9 + 5];
  int sum[10e5 + 5];
  sum[0] = 0;
  for(size_t i = 1; i < n; ++i) {
    int p;
    scanf("%d", p);

    freq[p] += 1;
    if (freq[n] == p) 
      sum[i] = sum[i-1] += 1;
    else 
      sum[i] = sum[i-1];
  }

  return 0;
}
