#include<iostream>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;
#define MAX_N 105
#define MOD 1000007

char board[MAX_N][MAX_N];
int n; 
long long dp[MAX_N][MAX_N];

bool out_of_board(int x, int y)
{
  return x >= n || y >= n || y < 0 || x < 0;
}

long long dfs(int x, int y)
{
  if(board[y][x] == 'B' || y < 0 || x < 0 || x == n || y == n)
    assert(false);

  if(dp[y][x] != -1)
    return dp[y][x];

  if(out_of_board(x, y)) 
    return 0;

  if(y == 0 && board[y][x] != 'B')
    return 1; // base case

  long long sum = 0;
  // black piece to the right
  if(!out_of_board(x + 2, y - 2) 
      && !out_of_board(x + 1, y - 1) 
      && board[y - 1][x + 1] == 'B' 
      && board[y - 2][x + 2] != 'B') 
  {
    sum += dfs(x + 2, y - 2) % MOD;
  } 
    else if (!out_of_board(x + 1, y - 1) 
              && board[y - 1][x + 1] != 'B')
  {
    sum += dfs(x + 1, y - 1) % MOD;
  }

  // black piece to the left
  if(!out_of_board(x - 2, y - 2) 
      && !out_of_board(x - 1, y - 1) 
      && board[y - 1][x - 1] == 'B' 
      && board[y - 2][x - 2] != 'B') 
  {
    sum += dfs(x - 2, y - 2) % MOD;
  } else if(!out_of_board(x - 1, y - 1) 
      && board[y - 1][x - 1] != 'B') 
  {
    sum += dfs(x - 1, y - 1) % MOD;
  }

  return dp[y][x] = sum % MOD;
}

int main()
{
  int n_test_cases;
  cin >> n_test_cases;

  for(size_t i = 0; i < n_test_cases; ++i) {
    cin >> n;

    int start_x, start_y;
    memset(dp, -1, sizeof dp);

    // 0: Black piece
    // 1: No pieces
    for(size_t y = 0; y < n; ++y) {
      for(size_t x = 0; x < n; ++x) { // last one is the newline
        cin >> board[y][x];

        if(board[y][x] == 'W') {
          start_x = x;
          start_y = y;
        }

        // printf("%c", board[y][x]);
      }
      // printf("\n");
    }

    // printf("\nStaritng at (%d;%d)\n", start_x, start_y);
    printf("Case %ld: %lld\n", i + 1, dfs(start_x, start_y) % MOD);
  }

  return 0;
}
