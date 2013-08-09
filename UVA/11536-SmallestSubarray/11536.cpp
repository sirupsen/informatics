#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n_test_cases;
  cin >> n_test_cases;

  vector<int> a(1000002);

  for(int test_case = 1; test_case <= n_test_cases; test_case++)
  {
    int n, m, k;
    cin >> n >> m >> k;

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    deque<int> window;
    vector<int> count(k + 1, 0);

    int uniqs = 0, lmin = INT_MAX;

    for(int i = 0; i < n; i++)
    {
      if(i > 2)
        a[i] = (a[i-3] + a[i-2] + a[i-1]) % m + 1;

      window.push_back(a[i]);

      if(a[i] <= k)
      {
        if(count[a[i]] == 0)
          uniqs++;

        count[a[i]]++;
      }

      while(window.size() > 0 && (window.front() > k || count[window.front()] > 1))
      {
        if(window.front() <= k)
          count[window.front()]--;

        window.pop_front();
      }

      if(uniqs == k)
      {
        lmin = min(lmin, (int) window.size());
      }
    }

    cout << "Case " << test_case << ": ";
    if(lmin == INT_MAX)
    {
      cout << "sequence nai" << endl;
    }
    else
    {
      cout << lmin << endl;
    }
  }

  return 0;
}
