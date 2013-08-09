#include<iostream>
#include<vector>
using namespace std;

int n, s, t;

vector<int> p;
vector<bool> v;

int recurse(int pos, int depth)
{
  if(pos == t)
  {
    return depth;
  }

  if(v[pos] == true)
  {
    return -1;
  }

  v[pos] = true;

  return recurse(p[pos], depth + 1);
}

int main()
{
  cin >> n >> s >> t;

  p.resize(n + 1);
  v.assign(n + 1, false);

  for(int i = 1; i <= n; i++)
  {
    cin >> p[i];
  }

  cout << recurse(s, 0) << endl;

  return 0;
}
