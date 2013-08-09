#include<iostream>
using namespace std;

int main()
{
  double numbers[] = {2,2,2,1.5,1,0}, sum = 0;
  int n;

  for(size_t i = 0; i < 6; i++) {
    cin >> n; 
    sum += n * numbers[i];
  }

  cout << sum << endl;

  return 0;
}
