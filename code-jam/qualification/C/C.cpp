#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#define long long long

long reverse_number(long n, long partial)
{
  if(n == 0) return partial;
  return reverse_number(n / 10, partial * 10 + n % 10);
}

bool is_palindrome(long n)
{
  return reverse_number(n, 0) == n;
}

int main()
{
  vector<bool> fair_number(10e7 + 1, false);

  int n_test_cases;
  cin >> n_test_cases;

  for(long i = 1; i <= 10e7; i++)
  {
    if(is_palindrome(i) && is_palindrome(i * i))
    {
      fair_number[i] = true;
    }
  }

  for(int test_case = 1; test_case <= n_test_cases; test_case++)
  {
    long a, b, count;
    cin >> a >> b;

    cout << "Case #" << test_case << ": ";

    for(long i = (long) ceil(sqrt(a)), count = 0; i <= (long) floor(sqrt(b)); i++)
    {
      if(fair_number[i])
      {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
