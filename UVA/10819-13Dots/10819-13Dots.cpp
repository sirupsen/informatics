#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

#define MAX_N 105
#define MAX_M 10205
#define MAX_F 505

struct Product {
  unsigned short price;
  unsigned short priority;
};

size_t n_products;
Product products[MAX_N];

int money;

int DP[MAX_M][MAX_N];

int recurse(size_t i, int total) {
  if(i == n_products) {
    int d = money + 200 - total;
    if (d > money && d <= 2000) return INT_MIN;
    return 0;
  }

  if(DP[total][i] != -1) return DP[total][i];

  if (total - products[i].price >= 0) {
    return DP[total][i] = max(
          recurse(i + 1, total - products[i].price) + products[i].priority,
          recurse(i + 1, total)
        );
  } else {
    return DP[total][i] = recurse(i + 1, total);
  }
}

int main()
{
  while(scanf("%d %ld", &money, &n_products) == 2) {
    for(size_t i = 0; i < n_products; ++i) {
      Product tmp;
      scanf("%hd %hd", &tmp.price, &tmp.priority);
      products[i] = tmp;
    }

    memset(DP, -1, sizeof DP);
    printf("%d\n", recurse(0, money + 200));
  }

  return 0;
}
