#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX_N 30

short n;

void recurse(int numbers[], short sum, int j)
{
  if(sum < n) {
    for(int i = 1; i < 10; ++i) {
      int copy[MAX_N];
      memcpy(copy, numbers, sizeof copy);
      copy[j] = i;

      recurse(copy, sum + i, j + 1);
    }
  } else if(sum == n) {
    for(size_t i = 0; i < j; i++)
      printf("%d", numbers[i]);

    printf("\n");
  }
}

void recurse2(string s, short sum)
{
  if(sum < n) {
    for(int i = 1; i < 10; ++i)
      recurse2(s + char(i+'0'), sum + i);
  } else {
    for(auto l : s) printf("%c", l);
    printf("\n");
  }
}

int main()
{
  n = 22;

  // int numbers[MAX_N];
  // recurse(numbers, 0, 0);

  recurse2("", 0);

  return 0;
}
