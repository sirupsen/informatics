#include<iostream>
#include<utility>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;

map<string, int> mapper;
vector<string> from_id;
int uniqs;

int to_id(string &key)
{
  if(mapper.count(key))
  {
    return mapper[key];
  }
  else
  {
    mapper[key] = uniqs;
    from_id[uniqs] = key;
    return uniqs++;
  }
}

int main()
{
  int n, m;
  int case_no = 0;
  bool d[205][205];

  while(cin >> n)
  {
    if(n == 0) return 0;

    case_no++;

    memset(d, false, sizeof d);
    mapper.clear();
    from_id.clear();
    from_id.resize(205);
    uniqs = 0;

    while(n--)
    {
      int k; cin >> k;

      string prev; cin >> prev;
      to_id(prev);

      for(int i = 1; i < k; i++)
      {
        string tmp; cin >> tmp;

        d[to_id(prev)][to_id(tmp)] = true;

        prev = tmp;
      }
    }

    cin >> m;

    while(m--)
    {
      string a, b;
      cin >> a >> b;

      d[to_id(a)][to_id(b)] = true;
    }

    for(int k = 0; k < uniqs; k++)
    {
      for(int i = 0; i < uniqs; i++)
      {
        for(int j = 0; j < uniqs; j++)
        {
          d[i][j] |= d[i][k] & d[k][j];
        }
      }
    }

    vector<pair<string, string> > pairs;

    for(int i = 0; i < uniqs; i++)
    {
      for(int j = i + 1; j < uniqs; j++)
      {
        if(!d[i][j] && !d[j][i])
        {
          pairs.push_back(make_pair(from_id[i], from_id[j]));
        }
      }
    }

    if(!pairs.size())
    {
      printf("Case %d, no concurrent events.\n", case_no);
    }
    else
    {
      printf("Case %d, %ld concurrent events:\n", case_no, pairs.size());

      for(int i = 0; i < pairs.size() && i < 2; i++)
      {
        cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
      }

      cout << endl;
    }
  }

  return 0;
}
