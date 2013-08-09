#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  vector<int> numbers;

  for(int i = 0; i < 3; i++) {
    int tmp; cin >> tmp;
    numbers.push_back(tmp);
  }

  sort(numbers.begin(), numbers.end());

  int c1 = numbers[1] - numbers[0];
  int c2 = numbers[2] - numbers[1];

  if(c1 * 2 + numbers[1] == numbers[2]) {
    cout << numbers[1] + c1 << endl;
  } else if(numbers[1] - c2 * 2 == numbers[0]) {
    cout << numbers[1] - c2 << endl;
  } else if(c1 == c2) {
    cout << numbers.back() + c1 << endl;
  }

  return 0;
}
