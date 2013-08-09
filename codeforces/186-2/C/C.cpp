#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define long long long

int main()
{
  long four_n;
  cin >> four_n;

  long n = 0;

  while(pow(4, n) != four_n)
  {
    n++;
  }

  vector<long> v(four_n + 5);

  for(int i = 0; i < four_n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<long> sum(four_n + 5, 0);

  for(int i = 1; i <= four_n; i++)
  {
    sum[i] = sum[i - 1] + v[v.size() - i];
  }

  long f = 0;

  for(long i = 0; i <= n; i++)
  {
    f += sum[(1 << (2 * i))];
  }

  cout << f << endl;

  return 0;
}
