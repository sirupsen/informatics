#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> original;
vector<int> lis;
vector<int> m;
int L = 0;

void find_lis()
{
  m.resize(original.size());
  lis.resize(original.size());

  lis.push_back(0);
  m.push_back(0);

  for(size_t i = 1; i < original.size(); ++i) {
    size_t mid = 0, high = L, low = 0;

    //for(j = L; j; j--) if (original[m[j]] < original[i]) break;

    cout << "VALUE: " << original[i] << endl;

    while(high > low) {
      mid = (high + low) / 2;

      if(original[m[mid]] < original[i]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    cout << "J: " << low << endl;

    int j = low;

    lis[i] = m[j];

    if (j == L || original[i] < original[m[j + 1]]) {
      cout << "UPDATED " << original[i] << " INSTEAD OF " << original[m[j+1]] << endl << endl;
      m[j + 1] = i;
      L = max(L, j + 1);
    }
  }
}

int main()
{
  int tmp;
  while(cin >> tmp) original.push_back(tmp);

  find_lis();

  cout << L << endl;

  cout << "-" << endl;

  for(size_t i = 0; i < L; ++i) {
    int val = m[L];
    for(size_t j = 0; j < L - 1 - i; ++j) val = lis[val];
    cout << original[val] << endl;
  }

  return 0;
}
