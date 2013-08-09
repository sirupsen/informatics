#include<iostream>
using namespace std;

int main()
{
  int y,k,n,x,r;
  cin >> y >> k >> n;

  bool printed = false;

  for(r = k; r < y; r += k);
  r - y == 0 ? x = k : x = r - y;

  for(; x + y <= n; x += k) {
    printed = true;
    cout << x << " ";
  }

  if(!printed) cout << -1;
  cout << endl;

  return 0;
}
