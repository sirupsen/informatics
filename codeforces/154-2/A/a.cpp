#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  
  int n, m;
  cin >> n >> m;

  if(n > m) {
    for(size_t i = 0; i < m; i++)
      cout << "BG";

    for(size_t i = 0; i < n - m; i++)
      cout << "B";
  } else {
    for(size_t i = 0; i < n; i++)
      cout << "GB";

    for(size_t i = 0; i < m - n; i++)
      cout << "G";
  }

  cout << endl;

  return 0;
}
