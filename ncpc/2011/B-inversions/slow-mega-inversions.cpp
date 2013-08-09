#include<iostream>

typedef long long ll;
ll numbers[100000], n;

int main()
{
  scanf("%lld", &n);

  for(ll i = 0; i < n; ++i)
    scanf("%lld", &numbers[i]);

  ll sum = 0;

  for(ll i = 0; i < n; i++)
    for(ll j = i + 1; j < n; j++)
      for(ll k = j + 1; k < n; k++)
        if(numbers[i] > numbers[j] && numbers[j] > numbers[k])
          sum++;

  printf("%lld\n", sum);
}
