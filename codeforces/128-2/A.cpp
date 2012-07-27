#include<iostream>
using namespace std;

int main()
{
  int x, t, a, b, da, db;

  cin >> x;
  cin >> t;
  cin >> a;
  cin >> b;
  cin >> da;
  cin >> db;

  // try combining the problems
  // problem 1 at i second
  for(int i = 0; i < t; i++) {
    // try every possible score from problem 2, with
    // the score from problem 1

    // problem 2
    for(int j = 0; j < t; j++) {
      int problem_1 = a - (i * da);
      int problem_2 = b - (j * db);

      // combined, or each one of them (problem_2 will be seen many times)
      // 0 if nothing is submitted
      if (problem_1 + problem_2 == x || problem_1 == x || problem_2 == x || 0 == x) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  
  cout << "NO" << endl;
  return 0;
}
