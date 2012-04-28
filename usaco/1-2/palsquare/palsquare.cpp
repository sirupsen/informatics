/*
ID: sirup1
PROG: palsquare
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

char base_digits[21] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'
};

string convert_to_base(int n, int base) {
  int converted_number[500];
  int number = n;

  stringstream remainders;

  while(number != 0) {
    remainders << base_digits[number % base];
    number = number / base;
  }

  // reverse stream
  string final(remainders.str());
  reverse(final.begin(), final.end());

  return(final);
}

int main()
{
  int base;

  FILE *input;
  input = fopen("palsquare.in", "r");
  fscanf(input, "%d", &base);

  ofstream output;
  output.open("palsquare.out");

  for(int i = 1; i <= 300; i++) {
    int isquared = i * i;

    string number(convert_to_base(isquared, base));

    string reversed(number);
    reverse(reversed.begin(), reversed.end());

    string ibase(convert_to_base(i, base));

    if (reversed == number) output << ibase << " " << number << "\n";
  }

  return 0;
}
