#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstdio>
#include<cstring>
using namespace std;

int count_bits(int n)
{
  return n == 0 ? 0 : count_bits(n & (n - 1)) + 1;
}

int main()
{
  size_t problems;
  cin >> problems;

  int n_leds, n_symbols;

  for(size_t i = 0; i < problems; ++i) {
    cin >> n_leds >> n_symbols;
    int symbols[101];

    for(size_t j = 0; j < n_symbols; ++j) {
      int led = 0;
      for(size_t k = n_leds; k--;) {
        int is_on;
        cin >> is_on;
        led += is_on << k;
      }
      symbols[j] = led;
    }

    int best = INT_MAX;
    bool masked[1 << 15];

    for(size_t mask = 0; mask < (1 << n_leds); ++mask) {
      memset(masked, false, sizeof(masked));
      bool unique = true;

      for(int k = 0; k < n_symbols; ++k) {
        if (masked[mask & symbols[k]]) {
          unique = false;
          break;
        }

        masked[mask & symbols[k]] = true;
      }

      if (unique) best = min(best, count_bits(mask));
    }

    cout << best << endl;
  }

  return 0;
}
