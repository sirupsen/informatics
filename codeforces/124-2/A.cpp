#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, b, r;

  cin >> a >> b >> r;

  int plates_horizontal = a / (2 * r);
  int plates_vertical   = b / (2 * r);

  int plates = plates_horizontal * plates_vertical;

  if (plates == 0)
    cout << "Second" << endl;
  else
    cout << "First" << endl;

  return 0;
}
