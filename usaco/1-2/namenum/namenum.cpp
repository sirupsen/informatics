/*
ID: sirup1
PROG: namenum
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>

int character_to_group(char character)
{
  if ((int) character > 81) character-= 1; // handle q
  return (int) (character - 'A') / 3 + 2;
}

int main()
{
  FILE *input;
  input = fopen("namenum.in", "r");

  char number[20];
  fscanf(input, "%s", number);

  int n_digits = strlen(number);
  int n_valids = 0;

  FILE *dictionary;
  dictionary = fopen("dict.txt", "r");

  FILE *output;
  output = fopen("namenum.out", "w");

  while(!feof(dictionary)) {
    char name[80];
    fscanf(dictionary, "%s\n", name);

    if (strlen(name) != strlen(number)) continue;

    bool fits = true;
    for(int i = 0; i < strlen(name); i++)
      if ((int) (number[i] - '0') != character_to_group(name[i])) fits = false;

    if (fits) fprintf(output, "%s\n", name) && n_valids++;
  }

  if (n_valids == 0) fprintf(output, "NONE\n");

  return 0;
}
