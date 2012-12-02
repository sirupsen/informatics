#include<iostream>
#include<string>
using namespace std;

int main()
{
  string guests;
  cin >> guests;

  int now = 0;
  int distinct = 0;
  int local_max = 0;
  int local_min = 0;

  for(int i = 0; i < guests.size(); i++) {
    if(guests[i] == '+') {
      now++;

      if(now > local_max) {
        local_max = now;
        distinct++;
      }
    } else {
      now--;

      if(now < local_min) {
        local_min = now;
        distinct++;
      }
    }
  }

  sleep(2);

  cout << distinct << endl;

  return 0;
}
