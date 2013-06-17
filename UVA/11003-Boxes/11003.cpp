#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 1005
#define MAX_W 3005

int n;

struct Box {
  int weight;
  int capacity;
};

Box boxes[MAX_N];
int dp[MAX_N][MAX_W];

int recurse(int capacity, int i)
{
  if(i == n || !capacity)
    return 0;

  int &memo = dp[i][capacity];

  if(memo != -1) return memo;

  if(boxes[i].weight <= capacity)
  {
    return memo = max(
        recurse(min(capacity - boxes[i].weight, boxes[i].capacity), i + 1) + 1,
        recurse(capacity, i + 1)
      );
  }
  else
  {
    return memo = recurse(capacity, i + 1);
  }
}

int main()
{

  while(scanf("%d", &n))
  {
    if(!n) break;

    for(int i = 0; i < n; i++)
      scanf("%d %d", &boxes[i].weight, &boxes[i].capacity);

    memset(dp, -1, sizeof dp);

    int lmax = 1;
    for(int i = 0; i < n; i++)
      lmax = max(recurse(boxes[i].capacity, i + 1) + 1, lmax);

    printf("%d\n", lmax);
  }

  return 0;
}
