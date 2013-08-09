#include<cstdio>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int main()
{

  int n, k;
  scanf("%d %d", &n, &k);

  int tot = ((n - 1) * n) / 2;

  if(tot > k)
  {
    for(int y = 0; y < n; y++)
    {
      printf("%d %d\n", 0, y);
    }
  }
  else
  {
    printf("no solution\n");
  }

  return 0;
}
