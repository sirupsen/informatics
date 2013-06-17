#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main()
{
  int n, a, b;
  scanf("%d", &n);

  vector<vector<int> > adj(n + 1);
  vector<int> in(n + 1, 0);
  vector<int> dp(n + 1, 0);
  dp[1] = 1;

  while(scanf("%d %d", &a, &b) == 2)
  {
    adj[a].push_back(b);
    in[b]++;
  }

  queue<int> q;
  q.push(1);

  while(!q.empty())
  {
    int v = q.front();
    q.pop();

    for(auto &u : adj[v])
    {
      if(!--in[u]) q.push(u);
      dp[u] += dp[v];
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}
