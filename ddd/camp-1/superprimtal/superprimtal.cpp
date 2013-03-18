#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

int n;
int super_primes = 0;

int is_prime(int number)
{
  if(number <= 1) return false;

  for(int n = 2; n <= (int)std::sqrt((double)number); n++)
    if(number % n == 0) return false;

  return true;
}

void recurse(int number, int depth)
{
  if(depth == n) return;

  for(int i = 1; i <= 9; i++) {
    int new_number = number * 10 + i;

    if(is_prime(new_number)) {
      super_primes++;
      recurse(new_number, depth + 1);
    }
  }
}

int main()
{
  scanf("%d", &n);
  recurse(0, 0);

  printf("%d\n", super_primes);

  return 0;
}
