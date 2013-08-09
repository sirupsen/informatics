#include<iostream>
using namespace std;

int main()
{
  string nucleotides;
  cin >> nucleotides;

  for(int i = nucleotides.size() - 1; i >= 0; i--) {
    if(nucleotides[i] == 'A') cout << 'T';
    else if(nucleotides[i] == 'T') cout << 'A';
    else if(nucleotides[i] == 'G') cout << 'C';
    else if(nucleotides[i] == 'C') cout << 'G';
  }

  cout << endl;

  return 0;
}
