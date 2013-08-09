#include<iostream>
#include<locale>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  string s; cin >> s;

  int als = 0;
  vector<bool> used(30, false);

  long long sum = 1;

  for(int i = 0; i < s.size(); i++)
  {
    int multiplier = 1;

    if(s[i] == '?')
    {
      if(i > 0)
      {
        multiplier = 10;
      }
      else
      {
        multiplier = 9;
      }
    }
    else if(isalpha(s[i]))
    {
      if(used[s[i] - 'A'])
      {
        multiplier = 1;
      }
      else if(i > 0)
      {
        multiplier = 10 - als;
      }
      else
      {
        multiplier = 9;
      }
    }

    sum *= multiplier;

    if(isalpha(s[i]) && !used[s[i] - 'A'])
    {
      als++;
      used[s[i] - 'A'] = true;
    }
  }

  cout << sum << endl;

  return 0;
}
