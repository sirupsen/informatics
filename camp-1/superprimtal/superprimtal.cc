#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <math.h>

int N;
int superprimes;
// int prime_cache[50000];

int prime(int number) 
{
  // Check whether it is divisable by a number below it..
  for (int i = 2; i * i <= number; i++)
    if (number % i == 0) return 0;

  return 1;
}

int superprime(int n) {
  int is_prime = prime(n); // cache

  // printf("number: %d ", n);
  // printf("length: %lu ", strlen(length));
  // printf("prime: %d ", is_prime);
  // printf("\n");

  if (is_prime && ceil(log10(n))) {
    return 1; // base case
  } else if (is_prime) {
    return superprime((int)(n * 0.1)); // remove one number from the right
  }

  return 0;
}

int main(int argc, char *argv[])
{
  scanf("%d", &N);

  // printf("is %d superprime? %d\n", N, superprime(N));

  int count = 0;
  for(int i = 2; i <= N; i++)
    superprime(i) && count++;

  printf("%d\n", count);

  return 0;
}
