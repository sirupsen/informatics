#include<iostream>
#include<climits>
using namespace std;
#define long long long

// int n;

// int recurse(int last, int pictures, int pages)
// {
//   if(pictures >= n) {
//     return pages;
//   } else {
//     return min(
//         recurse(last * 2, pictures + last * 2, pages + 1),
//         recurse(last, pictures + last, pages + 1)
//     );
//   }
// }

int main()
{
  int n; scanf("%d", &n);

  int pages = 0;

  int i;
  for(i = 0; (1 << i) <= n; i++, pages++) {
    // cout << (1 << i) << endl;
    n -= (1 << i);
  }

  for(int j = i; n != 0; j--) {
    if(1 << j <= n) {
      // cout << (1 << j) << endl;
      pages++;
      n -= (1 << j);
    }
  }

  printf("%d", pages);

  return 0;
}
