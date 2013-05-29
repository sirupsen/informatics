#include<iostream>
#include<string>
using namespace std;

bool is_capital(char character) {
  if((int) character >= 65 && (int) character <= 90) 
    return true;

  return false;
}

bool is_vowel(char character) {
  if(character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' || character == 'Y' || character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y') return true;
  return false;
}

int main()
{
  string input("Heelo woOorld");

  int vowel_count = 0;
  char last_seen = 'k';
  char other_last_seen = 'k';

  for(int i = 0; i < input.size(); i++) {
    if(is_vowel(input[i])) {
      if(input[i] != last_seen && input[i] != other_last_seen) { 
        vowel_count++;
        last_seen = input[i];

        if(is_capital(last_seen)) {
          other_last_seen = (char) ((int) last_seen + 32);
        } else {
          other_last_seen = (char) ((int) last_seen - 32);
        }
      }
    } else {
      last_seen = 'k';
      other_last_seen = 'K';
    }
  }

  cout << vowel_count << endl;

  return 0;
}
