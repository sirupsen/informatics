#include<iostream>
using namespace std;

#define MAX_N 10005

int main()
{
  int sum = 0, ans = 0;

  int numbers[MAX_N], n;

  while(cin >> n)
  {
    if(n == 0) break;

    for(int i = 0; i < n; i++)
    {
      cin >> numbers[i];
    }

    int ans = 0, sum = 0;

    for(int i = 0; i < n; i++)
    {
      sum += numbers[i];
      ans = max(ans, sum);

      if(sum < 0)
      {
        sum = 0;
      }
    }

    if(ans <= 0)
    {
      cout << "Losing streak." << endl;
    }
    else
    {
      cout << "The maximum winning streak is " << ans << "." << endl;
    }
  }

  return 0;
}
