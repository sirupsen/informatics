#include <cstdio>
#include <cstdlib>

int n_board; // upper bound is 8
int n_bishops; // upper bound is 8^2 = 64
int n_solutions;

char board[20][20];

void input()
{
  scanf("%d", &n_board);
  scanf("%d", &n_bishops);

  for(int i = 0; i < n_board; i++) 
    for(int j = 0; j < n_board; j++) 
      board[i][j] = '.';
}

// int promising(int parent_i, int parent_j, int child_i, int child_j) {
//   if (abs(parent_i - child_i) == abs(parent_j - child_j)) return 1;
//   return 0;
// }
// 
// int out_of_board(int i, int j) {
//   return (i > n_board || i < 0 || j < 0 || j > n_board);
// }

void print_board()
{
  for(int i = 0; i < n_board; i++) {
    for(int j = 0; j < n_board; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
  char junk;
  scanf("%c", &junk);
}

int expand(int i, int j, int placed) {
}


void solve(int p, int k)
{
  if(k == 0) {
    print_board();
    return;
  }
  if(p == n_board*n_board) return;
  
  int x = p%n_board;
  int y = p/n_board;

  board[y][x] = 'x';
  solve(p+1,k-1);
  board[y][x] = '.';
  solve(p+1,k);
}

void output()
{
  printf("%d\n", n_solutions);
}

int main(int argc, char *argv[]) 
{
  input();
  solve(0,n_bishops);
  output();
}
