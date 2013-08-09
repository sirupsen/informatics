#include<iostream>
#include<string>
using namespace std;

struct DNA {
  string name;
  string dna;
};

int main()
{
  DNA corpus[1000];

  char character;

  int i = -1;
  while(cin >> character) {
    if(character == '>') {
      i++;
      cin >> corpus[i].name;
      continue;
    }

    corpus[i].dna += character;
  }

  for(int j = 0; j <= i; j++) {
    for(int k = 0; k <= i; k++) {
      if(corpus[k].dna.compare(corpus[j].dna) == 0) continue;
      if(k == j) continue;

      if (corpus[k].dna.substr(0,3).compare(corpus[j].dna.substr(corpus[j].dna.size() - 3, 3)) == 0) 
        cout << corpus[j].name << " " << corpus[k].name << endl;
    }
  }

  return 0;
}
