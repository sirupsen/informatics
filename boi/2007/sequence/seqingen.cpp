/* Task Sequence
 * Author: Jakub Radoszewski
 * Date: 15.04.2007
 * Description: input files generating program
 * Generates 20 files: seq1.in .. seq20.in */

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
#define MAX_A 1000000000
#define INFTY 1000000001

/* A random number between 0 and m-1. */
inline int rnd(int m)
{
  return (int)((double)m * (rand() / (RAND_MAX + 1.0)));
}

/* Generates a sequence of length n: a,a+d,a+2d,... */
void monotone(int n, int a, int d)
{
  printf("%d\n", n);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", a);
    a += d;
  }
}

/* Generates a sequence of length n with random elements
 * between 0 and a. */
void random(int n, int a)
{
  printf("%d\n", n);
  for (int i = 0; i < n; i++)
    printf("%d\n", rnd(a + 1));
}

void down_and_up(int n)
{
  printf("%d\n", n);
  for (int i = n / 2; i >= 1; i--)
    printf("%d\n", 2 * i);
  for (int i = 1; i <= (n + 1) / 2; i++)
    printf("%d\n", 2 * i - 1);
}

/* Generates a sequence of length n, divided into
 * p pieces, each of which is increasing, decreasing
 * or completely random */
void special(int n, int p)
{
  printf("%d\n", n);
  int len = n / p, n0 = n;
  while (p--)
  {
    int l = len;
    if (!p)
      l = n;
    int a, b;
    int x = rnd(3);
    /* a hard beginning/ending */
    if (n == n0)
      x = 1;
    else if (n == l)
      x = 0;
    /* a piece of length l */
    switch (x)
    {
      case 0: /* increasing */
        a = rnd(MAX_A - MAX_N);
        b = rnd((MAX_A - a) / l) + 1;
        for (int i = 0; i < l; i++)
          printf("%d\n", a + i * b);
        break;
      case 1: /* decreasing */
        a = rnd(MAX_A - MAX_N) + MAX_N;
        b = rnd(a / l) + 1;
        for (int i = 0; i < l; i++)
          printf("%d\n", a - i * b);
        break;
      default: /* random */
        for (int i = 0; i < l; i++)
          printf("%d\n", rnd(MAX_A + 1));
    }
    n -= l;
  }
}

int main()
{
  srand(214565);
  /* 30% test cases with n<=500 */
  freopen("seq1.in", "w", stdout);  printf("1\n1234\n");
  freopen("seq2.in", "w", stdout);  printf("2\n2\n1\n");
  freopen("seq3.in", "w", stdout);  random(10, 10);
  freopen("seq4.in", "w", stdout);  random(50, 2);
  freopen("seq5.in", "w", stdout);  random(200, 10000000);
  freopen("seq6.in", "w", stdout);  random(500, MAX_A);
  
  /* additional 20% test cases with n<=20.000 */
  freopen("seq7.in", "w", stdout);  random(2000, 1000000);
  freopen("seq8.in", "w", stdout);  random(7000, MAX_A);
  freopen("seq9.in", "w", stdout);  down_and_up(18000);
  freopen("seq10.in", "w", stdout); random(20000, MAX_A);

  /* additional 25% test cases that are passed by seqs3.cpp and/or seqs4.cpp */
  freopen("seq11.in", "w", stdout); monotone(MAX_N, MAX_A, 0);
  freopen("seq12.in", "w", stdout); monotone(MAX_N, 0, 87); /* passed by s3 */
  freopen("seq13.in", "w", stdout); monotone(MAX_N, MAX_A, -78); /* passed by s4 */
  freopen("seq14.in", "w", stdout); random(900000, MAX_A);
  freopen("seq15.in", "w", stdout); random(MAX_N - 3, 2000);

  /* 30% - big test cases, passed only by efficient solutions */
  freopen("seq16.in", "w", stdout); down_and_up(MAX_N);
  freopen("seq17.in", "w", stdout); special(200000, 6);
  freopen("seq18.in", "w", stdout); special(589723, 17);
  freopen("seq19.in", "w", stdout); special(MAX_N - 1, 34);
  freopen("seq20.in", "w", stdout); special(MAX_N, 10);
  return 0;
}
