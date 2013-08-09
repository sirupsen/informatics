#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main()
{
  ll cache[100000] = {0};
  ll k;

  cin >> k;

  ll current_k = 1;

  for(int i = 1; i <= 100; i++) {
    ll numbers = 1 << i;
    ll multiplier = pow((double)10, i - 1);

    for(ll j = 0; j < numbers / 2; j++) {
      if(current_k == 1) cache[current_k] = 4 * multiplier;
      else cache[current_k] = 4 * multiplier + cache[current_k - numbers / 2];

      if(current_k == k) {
        cout << cache[current_k] << endl;
        return 0;
      }
      current_k++;
    }

    for(ll j = 0; j < numbers / 2; j++) {
      if(current_k == 2) cache[current_k] = 7 * multiplier;
      else cache[current_k] = 7 * multiplier + cache[current_k - numbers];

      if(current_k == k) {
        cout << cache[current_k] << endl;
        return 0;
      }

      current_k++;
    }
  }

  return 0;
}
