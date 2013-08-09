#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
  string n;
  cin >> n;

  stringstream ss;

  if(n[0] == '-')
  {
    int s = n.size();

    if(n[s - 1] > n[s - 2])
    {
      ss << n.substr(0, s - 1);
    }
    else
    {
      ss << n.substr(0, s - 2) << n[s - 1];
    }
  }
  else
  {
    ss << n;
  }

  if(ss.str().size() == 2 && ss.str()[0] == '-' && ss.str()[1] == '0')
  {
    cout << 0 << endl;
  }
  else
  {
    cout << ss.str() << endl;
  }

  return 0;
}
