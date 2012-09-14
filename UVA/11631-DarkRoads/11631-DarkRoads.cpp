#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

vector<vector<pair<int, int> > > adjlist;
priority_queue<pair<int, int> > pq;
vector<bool> taken;

void proccess(int i)
{
  taken[i] = 1;

  for(int j = 0; j < adjlist[i].size(); ++j) {
    pair<int, int> v = adjlist[i][j];

    if(!taken[v.first])
      pq.push(pair<int, int>(-v.second, -v.first)); // negate to handle negatives
  }
}

int main()
{
  int n, m;

  while(cin >> m >> n) {
    if(n == 0 && m == 0) return 0;
    adjlist.clear(); adjlist.resize(n);

    int current = 0;
    for(size_t i = 0; i < n; ++i) {
      int x,y,z; cin >> x >> y >> z;
      current += z;

      adjlist[x].push_back(pair<int, int> (y, z));
      adjlist[y].push_back(pair<int, int> (x, z));
    }

    taken.clear();
    taken.resize(n, 0);
    proccess(0);
    int min_cost = 0;

    while(!pq.empty()) {
      pair<int, int> front = pq.top(); pq.pop();
      int u = -front.second; // vertex
      int w = -front.first; // weight

      if(!taken[u]) {
        min_cost += w;
        proccess(u);
      }
    }

    cout << current - min_cost << endl;
  }

  return 0;
}
