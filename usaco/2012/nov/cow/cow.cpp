#include<iostream>
#include<string>
using namespace std;

int main()
{
  // freopen("cowfind.in" , "r" , stdin);
  // freopen("cowfind.out" , "w" , stdout);

  string grass;
  cin >> grass;

  int left_legs = 0;
  int positions = 0;

  for(int i = 1; i < grass.size(); i++) {
    if(grass[i - 1] == '(' && grass[i] == '(') 
      left_legs++;

    if(grass[i - 1] == ')' && grass[i] == ')') 
      positions += left_legs;
  }

  cout << positions << endl;

  return 0;
}
