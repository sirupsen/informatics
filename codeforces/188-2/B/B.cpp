#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  string s;
  cin >> s;

  string heavy("heavy");
  string metal("metal");

  int o = 0;
  long long ans = 0;

  for(int i = 0; i < s.size(); i++)
  {
    string sub = s.substr(i, 5);

    if(sub.compare(heavy) == 0)
    {
      o++;
      i += 4;
    }
    else if(sub.compare(metal) == 0)
    {
      ans += o;
      i += 4;
    }
  }

  cout << ans << endl;

  return 0;
}
