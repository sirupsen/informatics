#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;

  for(int i = 0; i < test_cases; i++) {
    int n, speed;
    cin >> n;

    int m = 0;

    for(int k = 0; k < n; k++) {
      cin >> speed;
      if (speed > m) m = speed;
    }

    cout << "Case " << i + 1 << ": " << m << endl;
  }
}
