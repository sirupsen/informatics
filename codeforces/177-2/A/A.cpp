#include<iostream>
#include<set>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  long long count = 0;

  for(int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    count += b - a + 1;
  }

  long long moves = 0;

  for(int i = count; i % k != 0; i++)
  {
    moves++;
  }

  cout << moves << endl;

  return 0;
}
