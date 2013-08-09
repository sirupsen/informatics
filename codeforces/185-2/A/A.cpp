#include<iostream>
#include<string>
using namespace std;

int main()
{

  string line;
  getline(cin, line);

  while(getline(cin, line))
  {
    int freda = !line.substr(line.size() - 5).compare(string("lala."));
    int rainbow = !line.substr(0, 5).compare(string("miao."));

    if(rainbow && !freda)
    {
      cout << "Rainbow's" << endl;
    }
    else if(freda && !rainbow)
    {
      cout << "Freda's" << endl;
    }
    else
    {
      cout << "OMG>.< I don't know!" << endl;
    }
  }

  return 0;
}
