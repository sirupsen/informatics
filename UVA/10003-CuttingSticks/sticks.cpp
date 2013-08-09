#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

vector<int> cuts;
int DP[55][55];

int cut(int left, int right)
{
  if(left + 1 == right)
    return 0;

  if(DP[left][right] != -1)
    return DP[left][right];

  int local_min = INT_MAX;
  for(int i = left + 1; i < right; i++)
    local_min = min(local_min, cut(left, i) + cut(i, right) + (cuts[right] - cuts[left]));

  return DP[left][right] = local_min;
}

int main()
{
  int l, n;
  cuts.resize(55 + 2);

  scanf("%d", &l);
  scanf("%d", &n);

  cuts[0] = 0;
  cuts[n + 1] = l;

  for(int i = 1; i <= n; i++)
    scanf("%d", &cuts[i]);

  memset(DP, -1, sizeof DP);

  printf("%d\n", cut(0, n + 1));

  return 0;
}
