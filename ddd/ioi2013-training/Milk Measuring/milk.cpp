#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define INFTY 200000
#define IS_SET(v) (v != INFTY)

int main()
{
  cin.sync_with_stdio(false);

  int q, p;
  cin >> q >> p;

  vector<int> pails(p);

  for(int i = 0; i < p; i++)
    cin >> pails[i];

  vector<int> uniq(q + 1, INFTY);
  vector<int> prev(q + 1, -1);
  vector<int> last(q + 1, -1);

  sort(pails.begin(), pails.end());

  uniq[0] = 0;

  for(int i = 0; i < p; i++)
  {
    int v = pails[i];

    for(int j = v; j <= q; j++)
    {
      int p = j - v;

      if(uniq[p] != -1)
      {
        int new_uniqs = (last[p] == v ? 0 : 1) + uniq[p];

        if(j == q)
        {
          printf("At q with %d new uniqs.\n", new_uniqs);
        }

        if(new_uniqs < uniq[j])
        {
          uniq[j] = new_uniqs;
          prev[j] = p;
          last[j] = v;
        }
      }
    }
  }

  for(int i = 0; i <= q; i++)
    cout << uniq[i] << " ";

  cout << endl;


  cout << uniq[q] << endl;

  set<int> cups;

  int previous = q;
  for(int v = prev[q]; v != -1; v = prev[v])
  {
    cout << previous - v << endl;
    cups.insert(previous - v);
    previous = v;
  }

  for(set<int>::iterator cup = cups.begin(); cup != cups.end(); cup++)
  {
    cout << " " << *cup;
  }

  cout << endl;

  cout << "yolo: " << uniq[33] << endl;

  return 0;
}
