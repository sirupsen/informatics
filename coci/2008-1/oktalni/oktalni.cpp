#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  vector<int> bools;

  // fuck input
  char b;
  while(cin >> b)
    bools.push_back(int(b - '0'));

  // fucked linked lists
  reverse(bools.begin(), bools.end());
  while(bools.size() % 3 != 0)
    bools.push_back(0);
  reverse(bools.begin(), bools.end());

  for(int i = 0; i < bools.size(); i += 3) {
    int dec = 0, pow = 1;
    for(int j = i + 2; j >= i; j--, pow <<= 1)
      dec += bools[j] * pow;

    cout << dec;
  }

  cout << endl;

  return 0;
}
