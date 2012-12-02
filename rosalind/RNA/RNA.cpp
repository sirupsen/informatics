#include<iostream>
using namespace std;

int main()
{
  char nucleotide;
  while(cin >> nucleotide) {
    if(nucleotide == 'T') cout << 'U';
    else cout << nucleotide;
  }
  cout << endl;

  return 0;
}
