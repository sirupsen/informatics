#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main()
{
  long long n, m;
  cin >> n >> m;

  long long nominator; cin >> nominator;
  for(size_t i = 1; i < n; i++) {
    long long tmp; cin >> tmp;
    nominator *= tmp;
  }

  long long denominator; cin >> denominator;
  for(size_t i = 1; i < m; i++) {
    long long tmp; cin >> tmp;
    denominator *= tmp;
  }

  long long d = gcd(nominator, denominator);

  cout << "1 1" << endl;
  cout << nominator / d << endl;
  cout << denominator / d << endl;

  return 0;
}
