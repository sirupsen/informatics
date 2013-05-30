#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main()
{
  string s; cin >> s;

  vector<int> pairs(s.size() + 1, 0);

  for(int i = 0; i < s.size() - 1; i++)
  {
    if(s[i] == s[i + 1])
    {
      pairs[i + 1] = pairs[i] + 1;
    }
    else
    {
      pairs[i + 1] = pairs[i];
    }
  }

  int m;
  cin >> m;

  while(m--)
  {
    int a, b;
    cin >> a >> b;

    cout << (pairs[b - 1] - pairs[a - 1]) << endl;
  }

  return 0;
}
