#include<cstdio>
#include<cstring>

const int types[] = {1, 5, 10, 25, 50};
unsigned long long int DP[30005] = {0};

int main()
{
  int V;
  DP[0] = 1;
  for(size_t i = 0; i < 5; i++)
    for(size_t j = types[i]; j < 30005; ++j)
      DP[j] += DP[j - types[i]];

  while(scanf("%d", &V) == 1) {
    if(DP[V] > 1) printf("There are %lld ways to produce %d cents change.\n", DP[V], V);
    else printf("There is only 1 way to produce %d cents change.\n", V);
  }

  return 0;
}
