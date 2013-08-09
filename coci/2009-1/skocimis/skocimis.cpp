#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
  vector<int> k;
  k.resize(3);

  for(int i = 0; i < 3; i++) 
    scanf("%d", &k[i]);

  int res;

  if (k[2] - k[1] > k[1] - k[0]) {
    res = k[2] - k[1] - 1;
  } else {
    res = k[1] - k[0] - 1;
  }

  printf("%d\n", res);

  return 0;
}
