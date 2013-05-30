#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define long long long
#define MOD 1000000007
#define MAX_N 3005

vector<string> names;
long f[MAX_N];

long recurse(int p, int a, int b)
{
  long blocks = 0, nested = 1, i, j;

  for(i = a; i <= b; i = j, blocks++)
  {
    for(j = i; j <= b && names[i][p] == names[j][p]; j++) {}

    nested = (nested * (i == j - 1 ? 1 : recurse(p + 1, i, j - 1))) % MOD;
  }

  return (f[blocks] * nested) % MOD;
}

int main()
{
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  names.resize(n);

  f[0] = 1;

  for(int i = 1; i < MAX_N; i++)
    f[i] = (f[i - 1] * i) % MOD;

  for(int i = 0; i < n; i++)
    cin >> names[i];

  sort(names.begin(), names.end());

  cout << recurse(0, 0, n - 1) % MOD << endl;

  return 0;
}
