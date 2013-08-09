#include<iostream>
#include<map>
using namespace std;

int main()
{
  cin.sync_with_stdio(false);

  map<int, int> m;
  int n, x;
  cin >> n;

  long long res = 0;

  while(n--)
  {
    cin >> x;
    auto r = m.lower_bound(x);

    int d = 0;

    if(r != m.end())
      d = max(d, r->second + 1);

    if(r != m.begin())
      d = max(d, (--r)->second + 1);

    m[x] = d;
    res += d;
    cout << res << endl;
  }

  return 0;
}
