#include<iostream>
#include<string>
using namespace std;

int main()
{
  string dna_string;
  string dna_substring;

  cin >> dna_string >> dna_substring;

  size_t pos;
  size_t i = 0;

  while(pos != string::npos && i <= dna_string.size()) {
    pos = dna_string.substr(i, dna_string.size() - i).find(dna_substring);
    if(pos == string::npos) break;
    cout << pos + i + 1 << " ";
    i = pos + dna_substring.size();
  }

  cout << endl;

  return 0;
}
