#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n; cin >> n;
  int x = 0;

  string line;

  for(int i = 0; i < n; i++) {
    cin >> line;

    for(int j = 0; j < line.size(); j++) {
      if(line[j] == '+') {
        x++;
        break;
      } else if(line[j] == '-') {
        x--;
        break;
      }
    }
  }

  cout << x << endl;

  return 0;
}
