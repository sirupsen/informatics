#include <iostream>
using namespace std;

int n_parties, half, p;
int parties[21];
int visited[21];

void power_index(int party, int sum, int depth)
{
  for(int i = depth; i < n_parties; i++) {
    if(i == party) {
      continue;
    }
    
    // otherwise it counts somewhere else
    if(sum + parties[i] < half) {
      if (sum + parties[i] + parties[party] >= half) {
        p++;
        // cout << "power_index(" << party << ", " << sum << ", " << depth << ") +1: " << i << endl;
      }

      // cout << "power_index(" << party << ", " << sum << ", " << depth << ") -1: " << i << endl;
      power_index(party, sum + parties[i], i + 1);
    }
  }
}

int main()
{
  int n_cases;
  cin >> n_cases;

  for(int i = 0; i < n_cases; i++) {
    cin >> n_parties;

    int sum = 0;
    // load parties into memory
    for(int j = 0; j < n_parties; j++) {
      int votes;
      cin >> votes;

      sum += votes;
      parties[j] = votes;
    }

    half = (sum / 2)+1;

    for(int j = 0; j < n_parties; j++) {
      p = 0;
      power_index(j, 0, 0);
      cout << "party " << j + 1 << " has power index " << p << endl;
    }
    cout << endl;
  }

  return 0;
}
