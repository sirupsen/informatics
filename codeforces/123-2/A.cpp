#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
  int a, b, c;
  cin >> a >> b >> c;

  double total_size = a * c;
  // cout << "total time " << total_size << "\n";
  double downloaded_while_watching = b * c;
  // cout << "watch downloaded time " << downloaded_while_watching << "\n";

  int buffer_time = ceil((total_size - downloaded_while_watching) / (double)b);

  cout << buffer_time << "\n";

  return 0;
}
