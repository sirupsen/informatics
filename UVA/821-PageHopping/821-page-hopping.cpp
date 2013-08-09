#include<cstdio>
#include<vector>
using namespace std;

int AdjMat[105][105];
bool exists[105];

int main()
{
  int test_case = 1;
  while(1) {
    int n_edges = 1;

    for(size_t i = 0; i <= 101; ++i) {
      exists[i] = false;

      for(size_t j = 0; j <= 101; ++j)
        AdjMat[i][j] = 1000000000;
    }

    while(1) {
      int a, b;
      scanf("%d %d", &a, &b);

      if(a == 0 && b == 0) {
        if(n_edges == 1) return 0;
        else break;
      }

      exists[a] = true;
      exists[b] = true;

      AdjMat[a][b] = 1;
      AdjMat[a][a] = 0;
      AdjMat[b][b] = 0;
      n_edges++;
    }
    n_edges--;

    int V = 0;
    for(size_t i = 0; i < 101; i++)
      if(exists[i]) V++;

    for(size_t k = 1; k <= 100; ++k)
      for(size_t i = 1; i <= 100; ++i)
        for(size_t j = 1; j <= 100; ++j)
          AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

    double sum = 0;
    double connections = V * (V - 1);

    for(size_t i = 1; i <= 100; ++i)
      for(size_t j = 1; j <= 100; ++j)
        if(AdjMat[i][j] != 1000000000) sum += AdjMat[i][j];

    printf("Case %d: average length between pages = %.3f clicks\n", test_case, sum/connections);

    test_case++;
  }

  return 0;
}
