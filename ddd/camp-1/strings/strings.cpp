#include<iostream>
using namespace std;
#define MAX_N 1005

string a, b;
int dp[MAX_N][MAX_N];

int count(int i, int j)
{
  if(i == 0 && j == 0)
    return 1;

  if(i == 0) return 0;
  if(j == 0) return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(a[i] == b[j])
  {
    return dp[i][j] = count(i - 1, j - 1) + 1;
  }
  else
  {
    return dp[i][j] = max(count(i, j - 1), count(i - 1, j));
  }
}

int main()
{
  for(int i = 0; i < MAX_N; i++)
    for(int j = 0; j < MAX_N; j++)
      dp[i][j] = -1;

  cin >> a >> b;
  cout << count(a.size() - 1, a.size() - 1) << endl;

  return 0;
}
