#include<iostream>
#include<vector>
#include<sstream>
#include<climits>
using namespace std;

#define long long long
#define MAX_N 305

int main()
{
  ios::sync_with_stdio(false);

  string line;

  long dp[MAX_N][MAX_N];

  for(int i = 0; i <= 300; i++)
  {
    for(int j = 0; j <= 300; j++)
    {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;

  for(int c = 1; c <= 300; c++)
  {
    for(int i = 1; i <= 300; i++)
    {
      for(int j = c; j <= 300; j++)
      {
        dp[i][j] += dp[i - 1][j - c];
      }
    }
  }

  long sum[MAX_N][MAX_N];

  sum[0][0] = 1;

  for(int i = 1; i <= 300; i++)
  {
    sum[i][0] = 0;
  }

  for(int i = 1; i <= 300; i++)
  {
    for(int j = 1; j <= 300; j++)
    {
      sum[i][j] = sum[i][j - 1] + dp[j][i];
    }
  }

  while(getline(cin, line))
  {
    stringstream ss(line);

    vector<int> input;

    int tmp;
    while(ss >> tmp)
    {
      input.push_back(tmp);
    }

    if(input.size() == 1)
    {
      cout << sum[input[0]][input[0]] << endl;
    }
    else if(input.size() == 2)
    {
      cout << sum[input[0]][min(input[1],input[0])] << endl;
    }
    else
    {
      cout << sum[input[0]][min(input[2],input[0])] - sum[input[0]][input[1]]
        + dp[input[1]][input[0]] << endl;
    }
  }

  return 0;
}
