#include<string>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

typedef long long ll;

ll digsum(ll x) {
  ll sum = 0;

  while(x) {
    sum += x%10;
    x /= 10;
  }

  return sum;
}

int main()
{
  ll n; cin >> n;

  ll root = INT_MAX;
  for(ll s = 0; s <= 90; ++s) {
    ll d = s * s + 4 * n;
    ll x1 = (-s + sqrt(d))/2;

    if(x1 * x1 + s * x1 == n && s == digsum(x1)) 
      root = min(root, x1);
  }

  if(root == INT_MAX) 
    cout << -1 << endl;
  else 
    cout << root << endl;

  return 0;
}
