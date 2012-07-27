#include <cstdio>

typedef int dice[6];
dice dices[10000];
int N;
int max_sum;

int opposite_index(int index)
{
  if (index == 0) return 5;
  if (index == 1) return 3;
  if (index == 2) return 4;
  if (index == 3) return 1;
  if (index == 4) return 2;
  return 0; // index = 5, avoid warning
}

void input()
{
  scanf("%d", &N);

  int i;
  for(i = 0; i < N; i++)
    scanf("%d %d %d %d %d %d", &dices[i][0], &dices[i][1], &dices[i][2], &dices[i][3], &dices[i][4], &dices[i][5]);
}

void solve()
{
  int i, j, t;
  int prev_up;
  int sum;
  int largest_side;
  int down_index, up_index;
  int *current_dice;

  // i determines how the dice should be turned
  for (i = 0; i < 6; i++) {
    // turn the first psuedu dice based on i..
    prev_up = dices[0][opposite_index(i)];
    sum = 0;

    // loop through each dice and stack them on top of it
    for (j = 0; j < N; j++) {
      current_dice = dices[j]; // point to current dice

      // find down index, which is where prev_up is
      for (t = 0; t < 6; t++)
        if (current_dice[t] == prev_up) down_index = t;

      up_index = opposite_index(down_index);

      // find maximum of the not up/down sides
      largest_side = 0;
      for (t = 0; t < 6; t++) { // reuse t
        if (t != down_index && t != up_index)
          if (current_dice[t] > largest_side)
            largest_side = current_dice[t];
      }

      // and add this to the sum of the current stack
      sum += largest_side;

      prev_up = current_dice[up_index];
    }

    if (sum > max_sum) max_sum = sum;
  }
}

void output()
{
  printf("%d\n", max_sum);
}

int main(int argc, char * argv[])
{
  input();
  solve();
  output();

  return 0;
}
