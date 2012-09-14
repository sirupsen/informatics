#include<cstdio>
#include<cstring>
#include<climits>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;

#define MAX_M 15
#define MAX_N 205

typedef long long ll;

int numbers[MAX_N];
size_t N_numbers, N_queries, i, m, j;
unsigned int set = 1, d, divisile = 0;

int DP[MAX_M][1000][MAX_N];

int myMod(int a, int b) {
  return abs(a) % abs(b);
}

int subset_sum(size_t i, int to_grab, int sum)
{
  if(i == N_numbers) return 0;

  if(DP[i][sum][to_grab] != -1) {
    return DP[i][sum][to_grab];
  }

  if(to_grab == 0) {
    if(sum % d == 0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return DP[i][sum][to_grab] = subset_sum(i + 1, to_grab - 1, sum + numbers[i]) + subset_sum(i + 1, to_grab, sum);
  }
}

int main() 
{
  while(scanf("%ld %ld", &N_numbers, &N_queries) == 2) {
    divisile = 0;
    memset(DP, -1, sizeof DP);

    if (N_numbers == 0 && N_queries == 0) return 0;

    for(i = 0; i < N_numbers; ++i) scanf("%d", &numbers[i]);
    printf("SET %d:\n", set);

    for(i = 0; i < N_queries; ++i) {
      scanf("%d %ld", &d, &m);

      ll total = 0;
      for(j = 0; j < N_numbers; ++j) {
        total += subset_sum(j, m, 0);
      }

      printf("QUERY %ld: %lld\n", i + 1, total);
    }

    set++;
  }

  return 0;
}
