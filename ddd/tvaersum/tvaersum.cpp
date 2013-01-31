#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX_N 30
#define long long long

long n;
long lower, upper;

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

vector<string> solutions;

void recurse2(string s, short sum)
{
  if(sum < n) {
    for(int i = 1; i < 10; ++i)
      recurse2(s + char(i+'0'), sum + i);
  } else if (sum == n) {
    solutions.push_back(s);
    // for(auto l : s) printf("%c", l);
    // printf("\n");
  }
}

long dp[200]; // depth, sum
long res = 0;
long smallest = INT_MAX;

long dp_recurse(long number, long sum)
{
  if(dp[sum] != -1) 
    return dp[sum];

  // cout << sum << ":" << number << endl;

  if(sum < n && number <= upper) {
    long local_sum = 0;

    for(long i = 1; i < 10; ++i)
      local_sum += dp_recurse(number * 10 + i, sum + i);

    return local_sum;
  } else if (sum == n && number <= upper && number >= lower) {
    smallest = min(smallest, number);
    return 1;
  }

  return 0;
}

int main()
{
  lower = 11111;
  upper = 99999;
  n = 24;

  memset(dp, -1, sizeof dp);
  cout << dp_recurse(0, 0) << endl;
  cout << smallest << endl;


  return 0;
}
