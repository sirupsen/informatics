#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
  int n, m, p;
  cin >> n >> m >> p;

  vector<int> dist(n);

  for(int i = 2; i <= n; i++)
  {
    cin >> dist[i];
  }

  vector<vector<int> > hills(n + 1);

  for(int i = 0; i < m; i++)
  {
    int h, t;
    cin >> h >> t;

    hills[h].push_back(t);
  }

  int d = 0;

  vector<int> leave;

  for(int i = 1; i <= n; i++)
  {
    if(i > 1) d += dist[i];

    for(int j = 0; j < hills[i].size(); j++)
    {
      leave.push_back(hills[i][j] - d);
    }
  }

  sort(leave.begin(), leave.end());

  // SIZE, START INDEX
  priority_queue<pair<int, int> > pq;

  for(int i = 1; i < leave.size(); i++)
  {
    pq.push(pair<int, int> (-(leave[i] - leave[i - 1]), i + 1));
  }

  // START INDEX, SIZE
  priority_queue<int> q;

  q.push(-leave.size());

  // p - 1 times
  for(int i = 1; i <= p - 1; i++)
  {
    q.push(-pq.top().second);
    pq.pop();
  }

  int prev = 0;
  int sum = 0;

  while(!q.empty())
  {
    int v = -q.top();

    for(int i = prev; i < v; i++)
    {
      sum += leave[v - 1] - leave[i];
    }

    prev = v;
    q.pop();
  }

  cout << sum << endl;

  return 0;
}
