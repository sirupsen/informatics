#include<iostream>
using namespace std;

int main()
{
  int count[256] = {0};
  char nucleotide;
  
  while(cin >> nucleotide)
    count[(int)nucleotide]++;

  cout << count[(int)'A'] << " " << count[(int)'C'] << " " << count[(int)'G'] << " " << count[(int)'T'] << endl;;
}
