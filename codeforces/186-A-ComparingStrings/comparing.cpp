#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
  string first;
  string second;

  cin >> first;
  cin >> second;

  if (first.size() != second.size()) {
    cout << "NO" << "\n";
    return 0;
  }

  vector<int> differences;

  // loop through both
  for(int i = 0; i < first.size(); i++)
    if (first[i] != second[i])
      differences.push_back(i);

  if (differences.size() != 2) {
    cout << "NO" << "\n";
    return 0;
  }

  if (first[differences[0]] == second[differences[1]] && first[differences[1]] == second[differences[0]])
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";

  return 0;
}
