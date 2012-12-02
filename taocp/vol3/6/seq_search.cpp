#include<iostream>
#include<vector>
#include<cstdlib>
#include<sys/time.h>
using namespace std;

int main()
{
  int sought = 4e8;

  vector<int> vec;
  for(size_t i = 0; i < sought + 20; i++)
    vec.push_back(i);

  size_t i = 0;
  size_t size = vec.size() - 1;

  // slowest
  while(true) {
    if(vec[i] == sought) {
      break;
    } else {
      if(i < size)
        i++;
      else
        break;
    }
  }

  // faster
  // for(;i < vec.size(); i++)
  //   if(vec[i] == sought) break;

  // i = 0;
  // vec.push_back(sought);

  // while(true) {
  //   if(vec[i] == sought) {
  //     if (i < vec.size()) break; // success
  //     else if(i == vec.size()) break; // not success
  //   } else {
  //     i++;
  //   }
  // }

  return 0;
}
