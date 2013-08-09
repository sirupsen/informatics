#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;

#define MAX_N 100000

vector<int> a;
int dp[MAX_N];

int lds(int i)
{
  int &c = dp[i];

  if(c != -1) return c;

  int lmax = 0;

  for(int j = i + 1; j < a.size(); j++)
    if(a[i] >= a[j])
      lmax = max(lds(j), lmax);

  lmax++;
  return c = lmax;
}

int main()
{
  int test_case = 1;

  while(true)
  {

    bool all_done = false;
    a.clear();

    memset(dp, -1, sizeof dp);

    for(int i = 0; ;i++)
    {
      int tmp; cin >> tmp;

      if(tmp == -1)
      {
        if(i == 0) all_done = true;
        break;
      }

      a.push_back(tmp);
    }

    if(all_done) break;

    if(test_case != 1)
      cout << endl;

    int lmax = 0;
    for(int i = 0; i < a.size(); i++)
      lmax = max(lds(i), lmax);

    cout << "Test #" << test_case << ":" << endl;
    cout << "  maximum possible interceptions: " << lmax << endl;

    test_case++;
  }

  return 0;
}
