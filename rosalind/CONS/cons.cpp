#include<iostream>
#include<cassert>
using namespace std;

int base_to_index(char base)
{
  if(base == 'A') return 0;
  if(base == 'C') return 1;
  if(base == 'G') return 2;
  if(base == 'T') return 3;
  assert("BOOM");
  return -1;
}

char index_to_base(int index)
{
  if(index == 0) return 'A';
  if(index == 1) return 'C';
  if(index == 2) return 'G';
  if(index == 3) return 'T';
  assert("BOOM");
  return -1;
}

int main()
{
  int profile[4][1005] = {0};

  string dna_string;
  while(cin >> dna_string)
    for(int i = 0; i < dna_string.size(); i++)
      profile[base_to_index(dna_string[i])][i] += 1;

  for(int i = 0; i < dna_string.size(); i++) {
    int max_val = 0;
    char max_char;

    for(int j = 0; j <= 3; j++)
      if(profile[j][i] > max_val) {
        max_val = profile[j][i];
        max_char = index_to_base(j);
      }

    cout << max_char;
  }

  cout << endl;

  for(int i = 0; i <= 3; i++) {
    cout << index_to_base(i) << ":";

    for(int j = 0; j < dna_string.size(); j++)
      cout << " " << profile[i][j];

    cout << endl;
  }

  return 0;
}
