#include <stdio.h>
#include <math.h>

int N;
int tastes[200000];
int acc_tastes[200000];

void input()
{
  scanf("%d", &N);

  for(int i = 0; i < N; i++)
    scanf("%d", &tastes[i]);
}

void solve()
{
  int sum = 0;

  // build acc array
  for(int i = 0; i < N; i++)
    sum = acc_tastes[i] = sum + tastes[i];

  float averages = 0;
  int combinations = 0;

  for(int i = 0; i < N; i++) {
    for(int k = i; k < N; k++) {
      int low;
      if (i - 1 == -1) {
        low = 0;
      } else {
        low = acc_tastes[i - 1];
      }

      int high = acc_tastes[k];
      int elements = (k + 1) - i;
      float average = (float) (high - low) / elements;

      averages += average;
      combinations += 1;
    }
  }

  printf("%d\n", (int) averages / combinations);
}

int main(int argc, char *argv[])
{
  input();
  solve();
}
