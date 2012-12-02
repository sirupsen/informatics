#include<iostream>
using namespace std;

int main()
{
  int n_people, area;
  cin >> n_people >> area;

  int actual_people = n_people * area;

  for(int i = 1; i <= 5; i++) {
    int newspaper; cin >> newspaper;
    cout << newspaper - actual_people << " ";
  }

  cout << endl;

  return 0;
}
