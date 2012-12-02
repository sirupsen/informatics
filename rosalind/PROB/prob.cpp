#include<iostream>
using namespace std;

int main()
{
  double gc_prob;
  while(cin >> gc_prob) {
    double g = gc_prob / 2;
    double t = (1 - gc_prob) / 2;

    cout << g * g * 2 + t * t * 2 << " ";
  }

  cout << endl;

  return 0;
}
