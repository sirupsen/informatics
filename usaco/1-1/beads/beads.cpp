/*
ID: sirup1
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

int n_beads;
char beads[500];
int visited[500];

int collect_white_backwards_from_position(int pos) 
{
  int current_n_beads = 0;

  for(int current_pos = pos - 1; beads[current_pos] == 'w'; current_pos--)
    current_n_beads++;

  return current_n_beads;
}

int collect_beads_from_position(int pos)
{
  if (visited[pos] == 1) return -1; // this messes up previous_n_beads

  char color = beads[pos];
  int current_n_beads = 0;

  int last_pos = -1;

  // forward within necklace
  for(int current_pos = pos; beads[current_pos] == color || beads[current_pos] == 'w'; current_pos++) {
    visited[current_pos] = 1;
    current_n_beads++;
    last_pos = current_pos;
  }

  // backwards, circular
  if (pos == 0)
    for(int current_pos = n_beads - 1; beads[current_pos] == color || beads[current_pos] == 'w'; current_pos--)
      current_n_beads++;

  // last, circular
  if (last_pos == n_beads - 1)
    for(int current_pos = 0; beads[current_pos] == color || beads[current_pos] == 'w'; current_pos++)
      current_n_beads++;

  return current_n_beads;
}

int solve()
{
  FILE *file;
  file = fopen("beads.in", "r");
  fscanf(file, "%d\n%s", &n_beads, beads);

  int max = 0;
  int previous_n_beads = 0;

  for(int pos = 0; pos < n_beads; pos++) {
    int current_n_beads = collect_beads_from_position(pos);
    if (current_n_beads == -1) continue;

    if (previous_n_beads + current_n_beads > max) max = previous_n_beads + current_n_beads;

    previous_n_beads = current_n_beads + collect_white_backwards_from_position(pos);
  }

  if (max > n_beads) max = n_beads;

  return max;
}

int main() 
{
  FILE * file;
  file = fopen("beads.out", "w");
  fprintf(file, "%d\n", solve());
  return 0;
}
