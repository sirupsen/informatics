#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int k, n;
  cin >> n >> k;

  vector<int> sequence;

  if(n == 0 || n == 1) {
    cout << 0 << endl;
    return 0;
  }

  for(size_t i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    sequence.push_back(tmp);
  }

  bool possible = true;
  for(size_t j = k - 1; j < n; ++j) {
    if(sequence[j] != sequence[k - 1]) {
      possible = false;
      break;
    }
  }

  if(possible) {
    for(int j = k - 1; j != -1; --j) {
      if(sequence[j] != sequence[k - 1]) {
        cout << j + 1 << endl;
        return 0;
      }
    }

    cout << 0 << endl;
    return 0;
  } else {
    cout << -1 << endl;
    return 0;
  }
}
