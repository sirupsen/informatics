#include<iostream>
#include<string>
using namespace std;

int main()
{
  string dna; cin >> dna;

  int l, r, i, len;

  for(int i = 1; i < dna.size(); i++) {
    for(l = i - 1, r = i; l >= 0 && r < dna.size() &&
        ((dna[l] == 'A' && dna[r] == 'T')  ||
         (dna[l] == 'T'  && dna[r] == 'A')  ||
         (dna[l] == 'G'  && dna[r] == 'C')  ||
         (dna[l] == 'C'  && dna[r] == 'G')); l--, r++) {
      int len = r - l + 1;
      if(len >= 4 && len <= 12)
        cout << l + 1 << " " << len << endl;
    }
  }

  return 0;
}
