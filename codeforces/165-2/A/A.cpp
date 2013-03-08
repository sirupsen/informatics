#include<iostream>
using namespace std;

int main() 
{
  int n, p; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p;
    360 % (180 - p) == 0 ? cout << "YES" : cout << "NO";
    cout << endl;
  }
  return 0;
}
