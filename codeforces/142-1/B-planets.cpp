#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<queue>
using namespace std;
#define MAX_N 100005

vector<pair<int, int> > al[MAX_N];
vector<int> passengers[MAX_N];
vector<int> dist;

int main()
{
  int n_planets, n_stargates;
  cin >> n_planets >> n_stargates;

  dist.assign(n_planets + 5, INT_MAX);

  for(int i = 0; i < n_stargates; ++i) {
    int a, b, c; 
    cin >> a >> b >> c;

    al[a].push_back(make_pair(c, b));
    al[b].push_back(make_pair(c, a));
  }

  for(int i = 1; i <= n_planets; ++i) {
    int n; cin >> n;

    for(int j = 0; j < n; ++j) {
      int a; cin >> a;
      passengers[i].push_back(a);
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  dist[1] = 0;
  pq.push(make_pair(0, 1));

  while(!pq.empty()) {
    pair<int, int> top = pq.top(); pq.pop();
    int d = top.first;
    int u = top.second;

    if(dist[u] == d) {

      if(u == n_planets || u == INT_MAX) 
        break;

      vector<int>::const_iterator it(lower_bound(passengers[u].begin(), passengers[u].end(), dist[u]));

      while(it != passengers[u].end() && dist[u] == *it) {
        dist[u]++;
        it++;
      }
      
      for(int i = 0; i < al[u].size(); ++i) {
        pair<int, int> child = al[u][i];
        int v = child.second;
        int w = child.first;

        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
  }

  cout << ((dist[n_planets] < INT_MAX) ? dist[n_planets] : -1) << endl;

  return 0;
}
