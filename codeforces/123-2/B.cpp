#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;


int main() 
{
  int baskets[100001];

  int balls, n_baskets;
  cin>>balls>>n_baskets;

  // reset basket array
  for(int i = 0; i < n_baskets; i++)
    baskets[i] = 0;

  int middle_basket = (n_baskets + 1) / 2;

  // O(n*m)
  for(int i = 0; i < balls; i++) {
    int min_value = 2147483647;
    int min_index = 2147483647;

    // start in middle, then increase to each side
    for(int p = 0; p <= middle_basket; p++) {
      int left_index = middle_basket - p;
      int right_index = middle_basket + p;

      int left = baskets[left_index];
      int right = baskets[right_index];

      if (left < min_value && left_index > 0) {
        min_value = left;
        min_index = left_index;
      } else if (right < min_value && right_index <= n_baskets) {
        min_value = right;
        min_index = right_index;
      }
    }

    baskets[min_index] += 1;
    cout << min_index << "\n";
  }

  return 0;
}
