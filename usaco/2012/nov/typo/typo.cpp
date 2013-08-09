#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
  string parantheses;
  cin >> parantheses;

  int lefties = 0;
  int righties = 0;
  int total = 0;

  for(int i = 0; i < parantheses.size(); i++) {
    if(parantheses[i] == ')') lefties++;
    else righties++;

    if(righties - lefties > 0 && i != 0 && i != parantheses.size() - 1) total++; 
  }

  cout << total << endl;

  return 0;
}
