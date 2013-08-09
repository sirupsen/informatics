#include<iostream>
#include<vector>
using namespace std;

int lcs(vector<int> numbers) 
{
  return 1;
}

int main()
{
  int n_test_cases;
  cin >> n_test_cases;

  for(int i = 0; i < n_test_cases; i++) {
    int n; cin >> n;

    vector<int> numbers;
    numbers.resize(n + 5);

    for(int j = 0; j < n; j++)
      cin >> numbers[j];

    int lcs_length = lcs(numbers);

    cout << n - lcs_length << endl;
  }

  return 0;
}
