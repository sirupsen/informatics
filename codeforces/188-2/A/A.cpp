#include<iostream>
using namespace std;

#define long long long

int main()
{
  long k, n;
  cin >> n >> k;

  long odd_numbers = (n % 2 == 0 ? n / 2 : (n / 2) + 1);

  if (k <= odd_numbers)
  {
    cout << (2 * k - 1) << endl;
  }
  else
  {
    cout << (2 * (k - odd_numbers)) << endl;
  }

  return 0;
}
