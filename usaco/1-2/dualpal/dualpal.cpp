/*
ID: sirup1
PROG: dualpal
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

bool palindrome(string number) {
  string reversed(number);
  reverse(reversed.begin(), reversed.end());

  if(reversed == number) return true;

  return false;
}

int main() 
{
  FILE *input;
  input = fopen("dualpal.in", "r");

  int n = 0, s = 0;
  fscanf(input, "%d", &n);
  fscanf(input, "%d", &s);

  FILE *output;
  output = fopen("dualpal.out", "w");

  int numbers = 0;
  for(int number = (s + 1); numbers < n; number++) {
    int n_palindromes = 0;

    for(int base = 2; base <= 10 && n_palindromes != 2; base++)
      if(palindrome(convert_to_base(number, base))) n_palindromes++;

    if (n_palindromes == 2) {
      numbers++;
      fprintf(output, "%d\n", number);
    }
  }

  return 0;
}
