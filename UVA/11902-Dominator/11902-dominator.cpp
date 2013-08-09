#include<cstdio>
#include<cstring>

bool adjmat[105][105];
bool domMat[105][105];
int n; 

bool reached_goal = false;

void dfs(int y, int g)
{
  if (y == g) {
    printf("Reached goal\n");
    reached_goal = true;
    return;
  }

  for(size_t k = 0; k < n; ++k)
    if(adjmat[y][k]) dfs(k, g);
}

int main()
{
  int n_test_cases;
  scanf("%d", &n_test_cases);

  while(n_test_cases--) {
    scanf("%d", &n);

    for(size_t i = 0; i < n; ++i) {
      for(size_t j = 0; j < n; ++j) {
        int tmp; scanf("%d", &tmp);
        adjmat[i][j] = tmp;
      }
    }

    dfs(0, 3);
    printf("%d\n", reached_goal);

    reached_goal = false;
    adjmat[3][4] = 0;
    dfs(0, 3);
    printf("%d\n", reached_goal);

    // for(size_t i = 0; i < n; ++i) {
    //   for(size_t j = 0; j < n; ++j) {
    //     if(adjmat[i][j]) {
    //       int before = dfs_count(0);
    //       adjmat[i][j] = 0;
    //       int after = dfs_count(0);
    //       adjmat[i][j] = 1;

    //       printf("Before: %d, After: %d\n", before, after);

    //       // readability changed, this one is dominating
    //       if(after != before) 
    //         domMat[i][j] = 1;
    //     }
    //   }
    // }

    for(size_t i = 0; i < n; ++i) {
      for(size_t j = 0; j < n; ++j)
        printf("%d ", adjmat[i][j]);

      printf("\n");
    }
  }

  return 0;
}
