#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifdef ONLINE_JUDGE
#define debug(M, ...)
#else 
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__) 
#endif

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; } 

int main()
{
  int n; cin >> n;

  // int numbers[5] = {2, 2, 2, 1};

  // int m = 4;

  // for(int i = 0; i < m; i++)
  //   for(int j = i; j < m - 1; j++)
  //     if(numbers[j] > numbers[j + 1]) swap(numbers[j], numbers[j + 1]);

  // for(int i = 0; i < m; i++)
  //   cout << numbers[i] << " ";

  // cout << endl;

  if(n <= 2) {
    cout << -1;
  } else {
    cout << 2 << " ";

    for(int i = 0; i < n - 2; i++)
      cout << 2 << " ";

    cout << 1;
  }

  cout << endl;

  return 0;
}
