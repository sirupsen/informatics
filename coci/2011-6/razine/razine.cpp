#include<iostream>
using namespace std;
#define MAX_N 105

int main()
{
  int n; cin >> n;
  int numbers[MAX_N];

  for(int i = 0; i < n; i++)
    cin >> numbers[i];

  int last = numbers[n - 1];
  int cost = 0;

  for(int i = n - 2; i >= 0; i--) {
    if(numbers[i] < last) {
      last = numbers[i];
    } else {
      cost += -last + 1 + numbers[i];
      last--;
    }
  }

  cout << cost << endl;

  return 0;
}
