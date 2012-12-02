#include<iostream>
using namespace std;

int main()
{
  string name;

  string highest_name;
  double highest_gc = 0;

  while(cin >> name) {
    char nucleotide;
    double gc_count = 0;
    double size = 0;

    while(cin >> nucleotide) {
      if(nucleotide == '>') break;
      if(nucleotide == 'G' || nucleotide == 'C') gc_count++;
      size++;
    }

    double gc = gc_count / size;

    if(gc > highest_gc) {
      highest_name = name;
      highest_gc = gc;
    }
  }

  cout << highest_name << endl;
  cout << highest_gc * 100 << "%" << endl;

  return 0;
}
