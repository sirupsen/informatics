#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  long long moves = 0;

  int n; cin >> n;

  vector<int> a(n);

  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  for(int i = 1; i <= n; i++)
  {
    moves += abs(a[i - 1] - i);
  }

  cout << moves << endl;

  return 0;
}
