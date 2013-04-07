#include<iostream>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  if(k > n)
  {
    cout << -1 << endl;
    return 0;
  }

  if(k == n && k == 1)
  {
    cout << 'a' << endl;
    return 0;
  }

  int stop = n - (k - 2);

  for(int i = 0; i < stop; i++)
  {
    if(i % 2 == 0)
    {
      cout << 'a';
    }
    else
    {
      cout << 'b';
    }
  }

  char last = 'b';

  for(int i = stop; i < n; i++)
  {
    last = last + 1;
    cout << last;
  }

  cout << endl;

  return 0;
}
