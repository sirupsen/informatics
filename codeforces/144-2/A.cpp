#include<cstdio>
using namespace std;

int main()
{
  int n; scanf("%d", &n);

  if(n == 1 || n == 0 || n % 2 == 1) {
    printf("-1\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i) {
    if(i % 2 == 1) {
      printf("%d ", i + 1);
    } else {
      printf("%d ", i - 1);
    }
  }

  printf("\n");

  return 0;
}
