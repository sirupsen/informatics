#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int numbers[n];

  for(int i = 0; i < n; i++)
    numbers[i] = i+1;

  int permutations = 0;

  do {
    permutations++;
    for(int i = 0; i < n; i++)
      cout << numbers[i] << " ";

    cout << endl;
  } while ( next_permutation (numbers, numbers + n) );

  cout << permutations << endl;

  return 0;
}
