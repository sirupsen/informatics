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
  // #ifdef ONLINE_JUDGE
  //   freopen ("A.in" , "r", stdin);
  //   freopen ("A.out", "w", stdout);
  // #endif

  int numbers[100005];

  int frequency[20008] = {0};
  int max_val = 10004;

  int n; cin >> n;

  int local_max = 0;

  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
    local_max = max(local_max, numbers[i]);

    frequency[max_val + numbers[i]]++;
  }

  int total = 0;

  for(int i = -10004; i < local_max; i++)
    total += (frequency[i + max_val] / 2) * 2;

  total += frequency[local_max + max_val];

  cout << total << endl;

  return 0;
}
