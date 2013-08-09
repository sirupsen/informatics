#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  for(int i = k; k; k--) {
    if (m % 2 == 1) {
      m--;
    } else if (n * 2 > m) {
      n--;
    } else {
      m--;
    }
  }

  int teams = 0;

  if(n * 2 > m) teams = floor((double) m / 2);
  else teams = n;

  cout << teams << endl;

  return 0;
}
