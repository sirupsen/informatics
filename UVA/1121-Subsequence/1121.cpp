#include<iostream>
#include<climits>
#include<queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n, s;
  while(cin >> n >> s)
  {
    deque<int> d;

    int lmin = INT_MAX;

    for(int i = 0, tmp, sum = 0; i < n; i++)
    {
      cin >> tmp;
      d.push_back(tmp);
      sum += tmp;

      while(sum - d.front() >= s && d.size() > 0)
      {
        sum -= d.front();
        d.pop_front();
      }

      if(sum >= s)
      {
        lmin = min(lmin, (int)d.size());
      }
    }

    if(lmin == INT_MAX) lmin = 0;

    cout << lmin << endl;
  }

  return 0;
}
