#include<iostream>
using namespace std;
#define MAX_N 1005

int main()
{
  int n; cin >> n;
  int h[MAX_N];
  int dp[MAX_N];

  for(int i = 0; i < n; i++) {
    cin >> h[i];
    dp[i] = 0;
  }

  int local_max = 0;

  for(int i = 0; i < n; i++) {
    if(i != 0 && h[i] > h[i - 1])
      dp[i] = h[i] - h[i - 1] + dp[i - 1];

    local_max = max(dp[i], local_max);
  }

  cout << local_max << endl;

  return 0;
}
