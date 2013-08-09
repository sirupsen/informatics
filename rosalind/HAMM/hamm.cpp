#include<iostream>
using namespace std;

int main()
{
  string first;
  string second;

  cin >> first >> second;

  int distance = 0;
  for(int i = 0; i < first.size(); i++)
    if(first[i] != second[i]) distance++;

  cout << distance << endl;

  return 0;
}
