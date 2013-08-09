#include<iostream>
#include<vector>
using namespace std;

int n;

vector<bool> visited;
vector<bool> used;

long long answer = 0;

void dfs(int depth)
{
  if(depth == 0)
  {
    answer++;
  }
  else
  {
    for(int i = 1; i <= n; i++)
    {
      int mod = (i + depth - 2) % n + 1;

      if(!used[i] && !visited[mod])
      {
        visited[mod] = true;
        used[i] = true;

        dfs(depth - 1);

        visited[mod] = false;
        used[i] = false;
      }
    }
  }
}

void precompute()
{
  for(int i = 1; i <= 16; i++)
  {
    visited.assign(17, false);
    used.assign(17, false);
    answer = 0;
    n = i;

    dfs(i);

    cout << answer << endl;
  }
}

#define MOD 1000000007

long long precomputation[] = { 1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925 };

int main()
{
  int n;
  cin >> n;

  long long ans = 0;

  ans = precomputation[n - 1];

  for(int i = 1; i <= n; i++)
  {
    ans = (ans * i) % MOD;
  }

  cout << ans << endl;

  return 0;
}
