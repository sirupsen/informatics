#include<cstdio>
#include<vector>
using namespace std;

int main()
{
  int n; scanf("%d", &n);

  int last = n;

  vector<int> a(n);

  for(int i = n - 1; i >= 0; i--)
  {
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < n; i++)
  {
    if(last == a[i])
    {
      last--;
    }
  }

  printf("%d\n", last);

  return 0;
}
