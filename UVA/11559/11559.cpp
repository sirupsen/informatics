#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;

int main()
{
  int n, b, h, w; 

  while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
    int best_price = -1;

    for(int i = 0; i < h; i++) {
      int p, beds; 
      cin >> p;

      for(int j = 0; j < w; j++) {
        cin >> beds;
        int total_price = n * p;
        if (beds >= n && total_price <= b && (total_price < best_price || best_price == -1))
          best_price = total_price;
      }
    }

    if (best_price == -1) 
      cout << "stay home" << endl;
    else 
      cout << best_price << endl;
  }

  return 0;
}
