#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int length = 4;
  int numbers[] = {0,1,2,3};

  do {
    for(int i = 0; i < length; i++)
      cout << numbers[i];
    
    cout << endl;
  } while (next_permutation(numbers, numbers + length));

  return 0;
}
