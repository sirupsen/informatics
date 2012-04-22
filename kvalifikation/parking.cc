#include <cstdio>
#include <algorithm>

using namespace std;

int total_workers;
int workers;

int N;
int types;

int order[20001];
int target[20001];

int start_of_target_range_cache[51];
int end_of_target_range_cache[51];

int n_rounds = 0;
typedef int round[102]; // one round, maximum entries is 2 x 50 which is the maximum amount of workers
round rounds[1000]; // all rounds, theoretical maximum is 408, but we're safe, rather score little than none

void input()
{
  int i;

  scanf("%d", &N);
  scanf("%d", &types);
  scanf("%d", &total_workers);

  for(i = 0; i < N; i++)
    scanf("%d", &order[i]);
}

void add_four_to_round(int first, int second, int third, int fourth)
{
  int offset;

  if (!(workers > 1)) {
    workers = total_workers;
    n_rounds += 1;
  }

  offset = rounds[n_rounds][0];
  rounds[n_rounds][offset + 1] = first;
  rounds[n_rounds][offset + 2] = second;
  rounds[n_rounds][offset + 3] = third;
  rounds[n_rounds][offset + 4] = fourth;

  rounds[n_rounds][0] += 4; // offset, / 2 in output
}

// Find first entry of integer in Array
int index_of_type(int type)
{
  int i;

  // Iterate through array of unknown size
  for (i = 0; i < N; i++)
    if (target[i] == type)
      return i;

  return -1;
}

void target_range(int type, int *start_of_target_range, int *end_of_target_range)
{
  int s;
  int e;

  // Is the range in the cache?
  if ((s = start_of_target_range_cache[type]) != 0) {
    *start_of_target_range = s;
    *end_of_target_range = end_of_target_range_cache[type];
  // Then search the array..
  } else {
    s = index_of_type(type);
    *start_of_target_range = s; 

    e = index_of_type(type + 1) - 1; // -1 since it's the first of the next one
    if (e == -2) e = N - 1; // end of types, end must be last array entry N - 1
    *end_of_target_range = e;

    start_of_target_range_cache[type] = s;
    end_of_target_range_cache[type] = e;
  }
}


int two_two_switches()
{
  int i;
  int start_of_target_range, end_of_target_range;
  int j;

  for (i = 0; i < N; i++) {
    // It's not in the right place
    if (order[i] != 0) {
      // Get the target range
      target_range(order[i], &start_of_target_range, &end_of_target_range);

      // Iterate through the target range
      for (j = start_of_target_range; j <= end_of_target_range; j++) {
        // Does anything in the target range want to be where the current type is?
        if (order[j] == target[i]) {
          order[i] = 0;
          order[j] = 0;

          workers -= 2;
          add_four_to_round(i + 1, j + 1, j + 1, i + 1);

          return 1; // succees! lets try again.
        }
      }
    }
  }
  return 0;
}

int two_one_switches()
{
  int i;
  int target_index;
  int start_of_target_range, end_of_target_range;

  for (i = 0; i < N; i++) {
    // Not in right place
    if (order[i] != 0) {
      target_range(order[i], &start_of_target_range, &end_of_target_range);

      // Iterate through the target range
      for (target_index = start_of_target_range; target_index <= end_of_target_range; target_index++) {
        // If it's not in the right place, lets switch with it
        if (order[target_index] != 0) {
          order[i] = order[target_index];
          order[target_index] = 0;

          workers -= 2;
          add_four_to_round(i + 1, target_index + 1, target_index + 1, i + 1);

          break;
        }
      }
    }
  }
}

void zero_out_ones_in_place()
{
  int i;
  for (i = 0; i < N; i++)
    if (order[i] == target[i]) 
      order[i] = 0;
}

void iterate_solutions()
{
  if (two_two_switches() == 1) return;
  two_one_switches();
}

int check_if_done()
{
  int i;

  for(i = 0; i < N; i++)
    if (order[i] != 0) 
      return 0;

  return 1;
}

void solve()
{
  int i;
  int j;

  // Create a copy of the default parking lot order
  // and sort it. Copy has to be made, since sort modifies
  // the Array.
  memcpy(target, order, sizeof(order));
  sort(target, target + N);

  zero_out_ones_in_place();
  while (check_if_done() == 0)
    iterate_solutions();

  for(i = 0; i < N; i++)
    printf("%d ", target[i]);

  printf("\n%d\n", n_rounds);

  for(i = 1; i <= n_rounds; i++) {
    for(j = 0; j <= rounds[i][0]; j++) {
      if (j == 0) {
        printf("%d ", rounds[i][j] / 2);
      } else {
        printf("%d ", rounds[i][j]);
      }
    }

    printf("\n");
  }
}

int main(int argc, char * argv[])
{
  input();
  solve();

  return 0;
}
