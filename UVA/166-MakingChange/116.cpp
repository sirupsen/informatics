#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

#define MAX_N 5050
#define MAX_C 6

const int vals[] = {
  5, 10, 20, 50, 100, 200
};

int n;

int amount[MAX_C];
int shop[MAX_N];

void build_shop_array()
{
  for(int i = 0; i < MAX_N; i++)
  {
    shop[i] = INT_MAX - 1;
  }

  shop[0] = 0;

  for(int i = 0; i < MAX_C; i++)
  {
    for(int j = vals[i]; j < MAX_N; j++)
    {
      shop[j] = min(shop[j - vals[i]] + 1, shop[j]);
    }
  }
}

int solve(int sum, int used_of_i, int i, int total)
{
  if(i > 5)
  {
    return INT_MAX;
  }
  else if(amount[i] == 0)
  {
    return solve(sum, 0, i + 1, total);
  }
  else if(used_of_i > amount[i])
  {
    return INT_MAX;
  }
  if(sum <= 0)
  {
    return shop[-sum] + total;
  }
  else
  {
    return min(
        solve(sum - vals[i], used_of_i + 1, i, total + 1),
        solve(sum, 0, i + 1, total)
      );
  }
}

int main()
{
  build_shop_array();

  while(true)
  {
    bool all_zero = true;

    for(int i = 0; i < MAX_C; i++)
    {
      cin >> amount[i];
      if(amount[i] != 0) all_zero = false;
    }

    if(all_zero) break;

    double s;
    cin >> s;

    n = (int) ((s * 100) + 0.5);

    printf("%3d\n", solve(n, 0,0,0));
  }

  return 0;
}
