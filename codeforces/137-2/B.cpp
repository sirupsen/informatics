#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define MAX 1000
using namespace std;

int main() 
{
  int n, m, k;
  cin >> n >> m >> k;

  int table[MAX][MAX];
  int columns[MAX];
  int rows[MAX];

  for(size_t i = 0; i < n; ++i) rows[i] = i;
  for(size_t i = 0; i < m; ++i) columns[i] = i;

  for(size_t y = 0; y < n; ++y)
    for(size_t x = 0; x < m; ++x)
      cin >> table[y][x];

  for(size_t i = 0; i < k; ++i) {
    char type[2]; int x, y;
    cin >> type >> y >> x; 
    x--; y--;

    if(type[0] == 'g') 
      printf("%d\n", table[rows[y]][columns[x]]);
    else if(type[0] == 'c') 
      swap(columns[x], columns[y]);
    else if(type[0] == 'r') 
      swap(rows[x], rows[y]);
  }

  return 0;
}
