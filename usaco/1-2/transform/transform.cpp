/*
ID: sirup1
PROG: transform
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

#define BOUND 11

char before[BOUND][BOUND];
char after[BOUND][BOUND];

void output_scene(char scene[BOUND][BOUND])
{
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%c", scene[i][j]);

    printf("\n");
  }
}

void input()
{
  FILE *inputFile;
  inputFile = fopen("transform.in", "r");

  fscanf(inputFile, "%d\n", &n);

  for(int i = 0; i < n; i++) {
    for(int k = 0; k <= n; k++) {
      char tmp;
      fscanf(inputFile, "%c", &tmp);
      if (tmp == '\n') 
        continue;
      else
        before[i][k] = tmp;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int k = 0; k <= n; k++) {
      char tmp;
      fscanf(inputFile, "%c", &tmp);
      if (tmp == '\n') continue;

      after[i][k] = tmp;
    }
  }
}

void copy_multi_array(char current_field[BOUND][BOUND], char target_field[BOUND][BOUND])
{
  for(int i = 0; i < n; i++)
    for(int k = 0; k < n; k++)
      target_field[i][k] = current_field[i][k];
}

void rotate_90(char current_field[BOUND][BOUND], char target_field[BOUND][BOUND])
{
  for(int i = 0; i < n; i++)
    for(int k = 0; k < n; k++)
      target_field[i][k] = current_field[n-1-k][i];
}

void rotate_degrees(int degrees, char current_field[BOUND][BOUND], char target_field[BOUND][BOUND])
{
  int times = degrees / 90;

  char tmp_field[BOUND][BOUND];
  copy_multi_array(current_field, tmp_field);

  for(int i = 0; i < times; i++) {
    rotate_90(tmp_field, target_field);
    copy_multi_array(target_field, tmp_field);
  }
}

void reflect(char current_field[BOUND][BOUND], char target_field[BOUND][BOUND])
{
  for(int i = 0; i < n; i++)
    for(int k = 0; k < n; k++)
      target_field[i][k] = current_field[i][n-1-k];
}

void compare_to_after(char current_field[BOUND][BOUND], int method)
{
  FILE *outputFile;
  outputFile = fopen("transform.out", "w");

  bool difference = false;

  for(int i = 0; i < n; i++) {
    for(int k = 0; k < n; k++) {
      if (current_field[i][k] != after[i][k]) {
        difference = true;
        break;
      }
    }
  }

  if (!difference) {
    fprintf(outputFile, "%d\n", method);
    exit(0);
  }

  fclose(outputFile);
}


void solve()
{
  char target[BOUND][BOUND];
  char reflected_target[BOUND][BOUND];

  // Rotation 90
  rotate_degrees(90, before, target);
  compare_to_after(target, 1);
  
  // Rotation 180
  rotate_degrees(180, before, target);
  compare_to_after(target, 2);

  // Rotation 270
  rotate_degrees(270, before, target);
  compare_to_after(target, 3);

  // Reflection
  reflect(before, target);
  compare_to_after(target, 4);
  
  // Rotation 90 + reflection
  reflect(before, reflected_target);
  rotate_degrees(90, reflected_target, target);
  compare_to_after(target, 5);

  // Rotation 180 + reflection
  reflect(before, reflected_target);
  rotate_degrees(180, reflected_target, target);
  compare_to_after(target, 5);

  // Rotation 270 + reflection
  reflect(before, reflected_target);
  rotate_degrees(270, reflected_target, target);
  compare_to_after(target, 5);

  // No change
  compare_to_after(before, 6);

  FILE *outputFile;
  outputFile = fopen("transform.out", "w");
  // All methods tried, go with 7
  fprintf(outputFile, "%d\n", 7);
  exit(0);
}

int main()
{
  input();
  solve();
  // output();

  return 0;
}
