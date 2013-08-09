#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;

int main()
{
  int n; scanf("%d", &n);
  vector<int> ing(n);
  vector<int> cum(n);

  for(int i = 0; i < n; i++)
    scanf("%d", &ing[i]);

  cum[0] = ing[0];

  for(int i = 1; i < n; i++)
    cum[i] = ing[i] + cum[i - 1];

  cum[0] = 0;

  float sum = 0;
  int permutations = 0;

  sum += (float) ing[0];

  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      float to_add = (float) (cum[j] - cum[i == 0 ? 0 : i - 1]) / (j - i + 1);
      sum += to_add;
      permutations++;
    }
    
    cum[0] = ing[0];
  }

  assert(permutations != 0);

  printf("%d\n", (int) (sum / permutations));

  return 0;
}
