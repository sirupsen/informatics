/*
ID: sirup1
PROG: calfflac
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Palindrome {
  int start_index;
  int end_index;
  int length;
};

bool alphabetic(char character)
{
  // A-Z check, then a-z check
  return (((int)character >= 65 && (int)character <= 90) || ((int)character >= 97 && (int)character <= 122));
}

bool special_character(char character)
{
  // If it's not alphabetic, then it's special
  return !alphabetic(character);
}

int main()
{
  ifstream input("calfflac.in");

  input.seekg(0, ios::end);
  int file_length = input.tellg();
  input.seekg(0, ios::beg);

  char contents[file_length];
  input.read(contents, file_length);

  Palindrome largest_palindrome = {0,0,0};

  for(int i = 0; i < file_length; i++) {
    int backward = i, forward = i;
    int palindrome_length = -1; // since we +2 even at middle char of palindrome

    while(backward >= 0 && forward < file_length) {
      // If we're dealing with special characters, just ignore them and go on,
      // this doesn't add to the palindrome length!
      if (special_character(contents[forward])) {
        forward++;
      } else if (special_character(contents[backward])) {
        backward--;
      // If the characters are the same, our Palindrome has increased with two
      // characters
      } else if (tolower(contents[forward]) == tolower(contents[backward])) {
        palindrome_length += 2;
        forward++;
        backward--;
      // The characters weren't special (skip) nor the same, so stop
      } else {
        break;
      }
    }

    if (palindrome_length > largest_palindrome.length) {
      largest_palindrome.start_index = backward + 1; // since it looped one extra time
      largest_palindrome.end_index = forward - 1;
      largest_palindrome.length = palindrome_length;
    }
  }

  int first_char_index = -1;
  for(int i = largest_palindrome.start_index; first_char_index == -1 && i <= largest_palindrome.end_index; i++)
    if (alphabetic(contents[i])) first_char_index = i;

  int last_char_index = -1;
  for(int i = largest_palindrome.end_index; last_char_index == -1 && i >= largest_palindrome.start_index; i--)
    if (alphabetic(contents[i])) last_char_index = i;

  ofstream output("calfflac.out");

  // don't understand why the other method doesn't work :s
  int real_length = 0;
  for(int i = first_char_index; i <= last_char_index; i++)
    if(alphabetic(contents[i])) real_length++;

  output << real_length << "\n";

  for(int i = first_char_index; i <= last_char_index; i++)
    output << contents[i];

  output << "\n";

  return 0;
}
