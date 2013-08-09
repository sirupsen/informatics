#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007
#define N 10005

long long DP[N + 5];

long long binomial(int n, int k)
{
  if(k > n) {
    return 0;
  } else {
    return (DP[n] / (DP[k] * DP[n-k]));
  }
}

int main()
{
  int n_cases; 
  scanf("%d", &n_cases);

  DP[0] = 1;

  for(int i = 1; i < N + 5; i++)
    DP[i] = (DP[i - 1] * i) % MOD;

  for(int t = 1; t <= n_cases; t++) {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<long long> a;
    a.resize(n);

    for(int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long res = 0;

    for(int i = 0; i < n; i++) {
      int c = binomial(n - i - 1, k - 1);
      res = (res + a[i] * c) % MOD;
    }

    printf("Case #%d: %lld\n", t, res);
  }

  return 0;
}
