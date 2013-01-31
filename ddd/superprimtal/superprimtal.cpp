#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<int> super_primes;

int is_prime(int number)
{
  for(int n = 2; n <= sqrt(number); n++)
    if(number % n == 0) return false;

  return true;
}

void recurse(int number, int depth)
{
  if(depth == n) return;

  for(int i = 1; i <= 9; i++) {
    int new_number = number * 10 + i;

    if(is_prime(new_number)) {
      super_primes.push_back(new_number);
      recurse(new_number, depth + 1);
    }
  }
}

int main()
{
  cin >> n;
  recurse(0, 0);

  sort(super_primes.begin(), super_primes.end());

  for(auto p : super_primes)
    printf("%d\n", p);

  return 0;
}
