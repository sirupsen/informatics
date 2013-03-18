#include<cstdio>
#include<cmath>

int main()
{
  int n; scanf("%d", &n);

  int pl, pr, l, r;

  int res = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d %d", &l, &r);

    if(i == 0) {
      res += l;
    } else {
      if(res < 0) {
        res += fabs(pl - l);
      } else {
        res -= fabs(pl - l);
      }
    }

    pl = l;
    pr = r;
  }

  if(fabs(res) <= 500) {
    printf("YES\n");
  } else {
    printf("%d", res);
  }

  return 0;
}
