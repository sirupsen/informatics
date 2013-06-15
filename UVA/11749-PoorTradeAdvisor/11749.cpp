#include<cstdio>
#include<set>
#include<utility>
#include<vector>
using namespace std;

typedef pair<int, int> ii;

vector<set<ii> > adj;
vector<bool> visited;

int max_ppa;

int recurse(int i)
{
  visited[i] = true;

  int sum = 1;
  for(set<ii>::iterator j = adj[i].begin();
      j != adj[i].end() && -j->first == max_ppa;
      j++)
  {
    if(!visited[j->second])
      sum += recurse(j->second);
  }

  return sum;
}

int main()
{
  int n, m, a, b, c;

  while(scanf("%d %d", &n, &m))
  {
    if(n == 0 && m == 0)
      break;

    adj.clear();
    adj.resize(n + 1);
    max_ppa = 0;

    while(m--)
    {
      scanf("%d %d %d", &a, &b, &c);

      adj[a].insert(ii (-c, b));
      adj[b].insert(ii (-c, a));

      max_ppa = max(max_ppa, c);
    }

    int max_city_size = 0;

    for(int i = 1; i <= n; i++)
    {
      visited.assign(n + 1, false);
      max_city_size = max(recurse(i), max_city_size);
    }

    printf("%d\n", max_city_size);
  }

  return 0;
}
