#include<iostream>
#include<cstring>
#include<climits>
#define MAX_N 1000005
#define MAX_ALTITUDES 10
using namespace std;

int air[MAX_ALTITUDES][MAX_N];
int dp[MAX_ALTITUDES][MAX_N];
int n;

void output_dp()
{
  for(size_t y = 0; y < MAX_ALTITUDES; y++) {
    for(size_t x = 0; x <= n; x++) {
      cout << dp[y][x] << "   ";
    }
    cout << endl;
  }
}

void output_air()
{
  for(size_t y = 0; y < MAX_ALTITUDES; y++) {
    for(size_t x = 0; x < n; x++) {
      cout << air[y][x] << "   ";
    }
    cout << endl;
  }
}

int main() 
{
  cin >> n;

  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }

  n /= 100;

  for(int y = 9; y >= 0; y--) {
    for(size_t x = 0; x < n; x++) {
      cin >> air[y][x];
      // cout << air[y][x] << "   ";
    }
    // cout << endl;
  }

  memset(dp, -1, sizeof dp);

  // DP base cases
  for(size_t y = 0; y < MAX_ALTITUDES; y++)
    dp[y][0] = 0x3f3f3f3f;
  for(size_t x = 0; x < n; x++)
    dp[0][x] = 0x3f3f3f3f;

  dp[0][0] = 0;

  for(size_t x = 1; x < n; x++) {
    for(size_t y = 1; y < MAX_ALTITUDES; y++) {
      int tmp = INT_MAX;

      //hold
      tmp = min(dp[y][x-1] + 30 - air[y][x-1], tmp);

      // climb
      tmp = min(dp[y-1][x-1] + 60 - air[y-1][x-1], tmp);

      // sink
      if(y < 9) tmp = min(dp[y+1][x-1] + 20 - air[y+1][x-1], tmp);

      dp[y][x] = tmp;
    }
  }

  dp[0][n] = dp[1][n-1] + 20 - air[1][n-1];

  // cout << "DPDP" << endl;
  // output_dp();

  cout << dp[0][n] << endl;

  return 0;
}
