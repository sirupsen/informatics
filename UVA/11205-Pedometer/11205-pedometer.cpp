#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

size_t n_leds, n_symbols;

bool any_duplicates(const vector<string> &leds)
{
  for(size_t i = 0; i < leds.size(); ++i)
    for(size_t j = i + 1; j < leds.size(); ++j)
      if(leds[i] == leds[j]) return true;

  return false;
}

int possible_led_removals(size_t erase_index, vector<string> leds, size_t depth)
{
  for(vector<string>::iterator it = leds.begin(); it != leds.end(); ++it) {
    string::iterator string_it;
    string_it = it->begin() + erase_index;
    it->erase(string_it);
  }

  int max_depth = 0;

  if (any_duplicates(leds)) {
    return depth;
  } else {
    for(size_t i = 0; i < leds[0].length(); ++i)
      max_depth = max(possible_led_removals(i, leds, depth + 1), max_depth);
  }

  return max_depth;
}

int main()
{
  size_t problems;
  cin >> problems;

  for(size_t i = 0; i < problems; ++i) {
    cin >> n_leds >> n_symbols;
    vector<string> symbols;


    for(size_t j = 0; j < n_symbols; j++) {
      ostringstream led;

      for(size_t k = 0; k < n_leds; k++) {
        bool on;
        cin >> on;
        led << on;
      }

      symbols.push_back(led.str());
    }

    if (n_symbols == 1) {
      cout << 0 << endl;
    } else {
      int max_removals = 0;
      for(size_t i = 0; i < n_leds; ++i)
        max_removals = max(max_removals, possible_led_removals(i, symbols, 0));

      cout << n_leds - max_removals << endl;
    }
  }

  return 0;
}
