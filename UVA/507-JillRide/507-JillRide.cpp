#include<climits>
#include<cstdio>
using namespace std;
#define MAX_N 10000005

int ride[MAX_N];
int N_bus_stops;
int N_test_cases;

int main() 
{
  scanf("%d", &N_test_cases);

  for(size_t i = 0; i < N_test_cases; ++i) {
    scanf("%d", &N_bus_stops); size_t lim = N_bus_stops - 1;

    for(size_t j = 0; j < lim; ++j) scanf("%d", &ride[j]);

    int max_sum = INT_MIN, current_max_sum = 0;
    size_t max_start_index = 0, max_end_index = 0, current_start_index = 0,
           current_end_index = 0, max_length = 0;

    for(;current_end_index < lim; ++current_end_index) {
      current_max_sum += ride[current_end_index];

      if (current_max_sum > max_sum ||
            (current_max_sum == max_sum 
             && current_end_index - current_start_index > max_length)
          )
      {
        max_sum = current_max_sum;
        max_start_index = current_start_index;
        max_end_index = current_end_index;
        max_length = current_end_index - current_start_index;
      } 
      
      if (current_max_sum < 0) {
        current_max_sum = 0;
        current_start_index = current_end_index + 1;
      }
    }

    if (max_sum < 1)
      printf("Route %ld has no nice parts\n", i + 1);
    else
      printf("The nicest part of route %ld is between stops %ld and %ld\n", i + 1, max_start_index + 1, max_end_index + 2);
  }

  return 0;
}
