#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char, bool> m;

int main() 
{
  m['C'] = true;
  m['A'] = true;
  m['M'] = true;
  m['B'] = true;
  m['R'] = true;
  m['I'] = true;
  m['D'] = true;
  m['G'] = true;
  m['E'] = true;

  string word; cin >> word;

  string fixed_word;

  for(size_t i = 0; i < word.length(); i++)
    if(m.count(word[i]) == 0)
      fixed_word += word[i];

  cout << fixed_word << endl;

  return 0;
}
