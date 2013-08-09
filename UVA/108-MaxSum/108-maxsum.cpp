#include<iostream>
#include<climits>
using namespace std;
#define MAX_N 105

size_t N;
int board[MAX_N][MAX_N];

int main() 
{
  cin >> N;

  for(size_t i = 0; i < N * N; ++i) {
    const int y = i / N;
    const int x = i % N;

    int tmp; cin >> tmp;

    if(y > 0) tmp += board[y - 1][x];
    if(x > 0) tmp += board[y][x - 1];
    if(x > 0 && y > 0) tmp -= board[y - 1][x - 1];

    board[y][x] = tmp;
  }

  int maximum_square = INT_MIN;

  for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j)
    for(size_t k = i; k < N; ++k) for(size_t l = j; l < N; ++l) {
      int tmp = board[k][l];
      if (i > 0) tmp -= board[i - 1][l];
      if (j > 0) tmp -= board[k][j - 1];
      if (i > 0 && j > 0) tmp += board[i - 1][j - 1];

      maximum_square = max(tmp, maximum_square);
    }

  cout << maximum_square << endl;

  return 0;
}
