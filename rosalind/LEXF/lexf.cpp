#include<iostream>
#include<vector>
using namespace std;

int n;
string alphabet;

void recurse(string s)
{
  if(s.size() < n) 
    for(auto a : alphabet) recurse(s + a);
  else cout << s << endl;
}

int main()
{
  cin >> alphabet >> n;
  recurse(string(""));
  return 0;
}
