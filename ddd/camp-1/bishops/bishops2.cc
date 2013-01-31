#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

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


bool is_attacking(int x_1, int y_1, int x_2, int y_2)
{
  if (abs(x_1 - x_2) == abs(y_1 - y_2)) return true;
  return false;
}

bool promise(int x_1, y_2, int previous_positions)
{
}

int solve(int p, int k, vector<coordinates> previous_positions)
{
  int x = p % n_board; 
  int y = p / n_board;

  if (k == 0) {
    print_board();
    n_solutions += 1;
    return 0;
  } else if (false) {
    return 0;
  } else if (p == n_board * n_board) {
    return 0;
  } else {
    previous_positions.push_back(p);
    // printf("(%d;%d)\n", x, y);

    board[y][x] = 'x';
    solve(p + 1, k - 1, previous_positions);

    board[y][x] = '.';
    solve(p + 1, k, previous_positions);
  }
}

int main()
{
  int x_1;
  int y_1;

  int x_2;
  int y_2;

  scanf("%d", &n_board);

  scanf("%d", &x_1);
  scanf("%d", &y_1);

  scanf("%d", &x_2);
  scanf("%d", &y_2);

  printf("Does (%d;%d) attack (%d;%d) on a %dx%d board? %d\n", x_1, y_1, x_2, y_2,
      n_board, n_board, is_attacking(x_1, y_1, x_2, y_2));

  // input();
  // vector<int> initial_positions;
  // solve(0, n_bishops, initial_positions);
  // printf("%d\n", n_solutions);
  // return 0;
}
