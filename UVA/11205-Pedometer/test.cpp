#include<iostream>
using namespace std;

int count_bits(int n) 
{
  return n == 0 ? 0 : count_bits(n & (n - 1)) + 1;
}

int main()
{
  cout << count_bits(5) << endl;
  cout << (4 & 3) << endl;

  return 0;
}
