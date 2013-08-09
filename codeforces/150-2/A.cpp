#include<iostream>
using namespace std;

int main()
{
  int n,k;
  int wishes[1000];
  bool taken[1000] = {false};

  cin >> n >> k;

  for(int i = 0; i < k; i++) {
    cin >> wishes[i];
    taken[wishes[i]] = true;
  }

  for(int i = 0; i < k; i++) {
    for(int j = 1, segments = 0; j <= n * k && segments < n - 1; j++) {
      if(!taken[j]) {
        taken[j] = true;
        cout << j << " ";
        segments++;
      }
    }

    cout << wishes[i] << endl;
  }

  return 0;
}
