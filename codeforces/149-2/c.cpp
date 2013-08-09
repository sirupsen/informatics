#include<cstdio>
#include<cassert>
#include<queue>
#include<set>
#include<string>
#include<map>
#include<sstream>
using namespace std;

int main()
{
  pair<int, int> start;
  pair<int, int> final;

  scanf("%d %d %d %d", &start.first, &start.second, &final.first, &final.second);

  int n; scanf("%d", &n);

  set<pair<int, int> > allowed;
  set<pair<int, int> > visited;

  while(n--)
  {
    int row, start, end;
    scanf("%d %d %d", &row, &start, &end);

    for(int i = start; i <= end; i++)
    {
      allowed.insert(pair<int, int> (row, i));
    }
  }

  vector<pair<int, int> > q;
  q.push_back(start);
  visited.insert(start);

  int depth = 0;

  while(!q.empty() && !visited.count(final))
  {
    vector<pair<int, int> > p;

    for(int k = 0; k < q.size(); k++)
    {
      pair<int, int> point = q[k];

      for(int i = -1; i <= 1; i++)
      {
        for(int j = -1; j <= 1; j++)
        {
          if(j == 0 && i == 0) continue;

          pair<int, int> new_point(point.first + i, point.second + j);

          if(allowed.count(new_point) == 1 && visited.count(new_point) == 0)
          {
            visited.insert(new_point);
            p.push_back(new_point);
          }
        }
      }
    }

    depth++;
    q.swap(p);
  }

  if(visited.count(final))
  {
    printf("%d\n", depth);
  }
  else
  {
    printf("-1\n");
  }

  return 0;
}
