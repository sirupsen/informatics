#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Time {
  public:
    string whatTime(int offset) 
    {
      int h, m, s;

      h = offset / 3600;
      offset = offset % 3600;
      m = offset / 60;
      s = offset % 60;

      stringstream time;
      time << h << ":" << m << ":" << s;

      return time.str();
    }
};

int main()
{
  Time lol;

  cout << lol.whatTime(2343);
  return 0;
}
