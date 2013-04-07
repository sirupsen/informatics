#include<iostream>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int i = n;
  for(; i >= 0 && k > 0; i--, k--)
  {
    cout << i << " ";
  }

  for(int j = 1; j <= i; j++)
  {
    cout << j << " ";
  }

  cout << endl;

  return 0;
}
