/*
ID: sirup1
PROG: crypt1
LANG: C++
*/
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int allowed[15];
int allowed_lookup[15];
int allowed_length = 5;

bool integers_in_allowed(int val)
{
  while(val) {
    if (!allowed_lookup[val % 10])
      return false;

    val /= 10;
  }

  return true;
}

int main()
{
  int possibilities = 0;

  ifstream input("crypt1.in");
  input >> allowed_length;
  
  for(int i = 0; i < allowed_length; i++) {
    input >> allowed[i];
    allowed_lookup[allowed[i]] = 1;
  }

  for(int i = 0; i < allowed_length; i++) {
    for(int j = 0; j < allowed_length; j++) {
      int second = (allowed[i] * 10) + allowed[j];

      for(int p = 0; p < allowed_length; p++) {
        for(int k = 0; k < allowed_length; k++) {
          for(int t = 0; t < allowed_length; t++) {
            int first = (allowed[p] * 100) + (allowed[k] * 10) + allowed[t];

            int first_partial = allowed[j] * first;
            int second_partial = allowed[i] * first; // don't multiply with 10, just gives dumb 0 suffix edge-case in find

            int result = first * second;

            // cout << first << "\n";
            // cout << second << "\n";
            // cout << first_partial << "\n";
            // cout << second_partial << "\n";
            // cout << result << "\n\n";

            // it'll never be under 100 or 1000 anyway
            if(first_partial <= 999 && second_partial <= 999 && result <= 9999)
              if (integers_in_allowed(first_partial) && integers_in_allowed(second_partial) && integers_in_allowed(result))
                possibilities++;
          }
        }
      }
    }
  }

  ofstream output("crypt1.out");
  output << possibilities << "\n";

  return 0;
}
