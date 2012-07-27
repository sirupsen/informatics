#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
  map<string,int> countries;

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    string country;
    cin >> country;
    countries[country] += 1;

    string woman;
    getline(cin, woman);
  }

  map<string,int>::iterator it;

  for(it = countries.begin(); it != countries.end(); it++)
    cout << (*it).first << " " << (*it).second << endl;

  return 0;
}
