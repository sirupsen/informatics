#include<iostream>
using namespace std;

int main()
{
  int a_s = 0, a_f = 0, b_s = 0, b_f = 0, n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int x,y,z;
    cin >> x >> y >> z;

    if(x == 1) {
      a_s += y;
      a_f += z;
    } else {
      b_s += y;
      b_f += z;
    }
  }

  if(a_s >= a_f) cout << "LIVE" << endl;
  else cout << "DEAD" << endl;

  if(b_s >= b_f) cout << "LIVE" << endl;
  else cout << "DEAD" << endl;

  return 0;
}
