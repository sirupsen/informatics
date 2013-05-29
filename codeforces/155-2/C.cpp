#include<iostream>
#include<stack>
#include<queue>
#include<cassert>
#include<vector>
#include<string>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;

  vector<int> g(30, 0);
  vector<int> c(30, 0);

  assert(a.size() == b.size());

  for(int i = 0; i < a.size(); i++)
  {
    c[(int) a[i] - 'A']++;
    g[(int) b[i] - 'A']++;
  }

  deque<char> dq;

  for(int i = 0; i < 26; i++)
  {
    if(c[i] < g[i])
    {
      dq.push_back((char) i + 'A');
    }
  }

  stack<int> pos;

  int moves = 0;

  for(int i = 0; i < a.size() && dq.size() > 0; i++)
  {
    int chr = (int) a[i] - 'A';

    if(c[chr] > g[chr])
    {
      if(dq.front() < a[i])
      {
        moves++;
        a[i] = dq.front();
        dq.pop_front();

        c[chr]--;
        g[dq.front() - 'A']--;
      }
      else
      {
        pos.push(i);
      }
    }
  }

  while(!dq.empty())
  {
    int index_back = pos.top();
    pos.pop();

    int lexi_greatest = dq.back();
    dq.pop_back();

    a[index_back] = lexi_greatest;
    moves++;
  }

  cout << moves << endl;
  cout << a << endl;

  return 0;
}
