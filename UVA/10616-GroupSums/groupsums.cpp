#include<cmath>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
using namespace std;
#define MAX_N 205

size_t N_numbers, N_queries;
unsigned int d, grab_limit;
int numbers[MAX_N];

long long DP[MAX_N][MAX_N][MAX_N];

// map<string, long long> DP;

int negMod(int a, int b) {
  return (a % b + b) % b;
}

long long recurse(size_t index, int sum, int to_grab) 
{
  int sum_mod = negMod(sum, d);

  // if(DP[index][sum][to_grab] > 0) return DP[index][sum][to_grab];

  // printf("I: %ld, Number: %d\n", index, numbers[index]);

  if(to_grab == 0) {
    if(sum_mod == 0) {
      printf("%d counts\n", sum_mod);
      return 1;
    } else {
      return 0;
    }
  }

  if(index == N_numbers) {
    return 0;
  }

  int local = recurse(index + 1, sum, to_grab);
  if(to_grab - 1 >= 0) local += recurse(index + 1, sum + numbers[index], to_grab - 1);

  return local;
}

int main()
{
  unsigned int set = 0;
  while(scanf("%ld %ld", &N_numbers, &N_queries) == 2) {
    if(N_numbers == 0 && N_queries == 0) return 0;
    memset(DP, -1, sizeof DP);

    for(size_t i = 0; i < N_numbers; ++i)
      scanf("%d", &numbers[i]);

    for(size_t i = 0; i < N_queries; ++i) {
      scanf("%d %d", &d, &grab_limit);

      printf("Got: %lld\n", recurse(0, 0, grab_limit));
    }

    set++;
  }

  return 0;
}
