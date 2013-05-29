#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

#define long long long
#define MAX_M 10e9
#define MAX_TIME LLONG_MAX
#define MAX_N 10e5

long n, m;
vector<long> desks;

bool can_serve_all_in_time(long &time)
{
  long lm = m;

  for(auto desk = desks.begin(); lm > 0 && desk != desks.end(); desk++)
  {
    lm -= time / *desk;
  }

  return lm <= 0;
}

int main()
{
  scanf("%lld %lld", &n, &m);

  desks.resize(n);
  for(auto &desk : desks)
  {
    scanf("%lld", &desk);
  }

  sort(desks.begin(), desks.end());

  long upper = MAX_TIME, lower = 0, middle;

  while(upper > lower)
  {
    middle = lower + ((upper - lower) / 2);

    if(can_serve_all_in_time(middle))
    {
      upper = middle;
    }
    else
    {
      lower = middle + 1;
    }
  }

  printf("%lld\n", (lower + upper) / 2);

  return 0;
}
