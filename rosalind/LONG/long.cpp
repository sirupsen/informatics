#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  string dna_string;
  vector<string> dna;
  int n = 0;

  while(cin >> dna_string) {
    dna.push_back(dna_string);
    n++;
  }

  for(auto a : dna) {
  }

  return 0;
}
