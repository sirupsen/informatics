#include<iostream>
using namespace std;

int main()
{
  int n = 10;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if((j & i) > 0) {
        cout << ".";
      } else {
        cout << "X";
      }
    }

    cout << endl;
  }

  return 0;
}
