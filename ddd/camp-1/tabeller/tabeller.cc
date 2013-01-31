#include <cstdio>

int n;
int m;
int table[300][300];

int n_areas;
int n_fields_largest;
int area_color;

void input() {
  scanf("%d", &n);
  scanf("%d", &m);

  for(int i = 0; i < n; i++)
    for(int k = 0; k < m; k++)
      scanf("%d", &table[i][k]);
}

int out_of_board(int i, int k) {
  return (i >= n || i < 0 || k < 0 || k >= m);
}

int explore(int i, int k, int color) {
  if (table[i][k] == -1) { // already visited
    return 0;
  } else if (out_of_board(i,k)) {
    return 0;
  } else if (table[i][k] == color) {
    table[i][k] = -1;

    return 1 + explore(i + 1, k, color)
             + explore(i - 1, k, color)
             + explore(i, k + 1, color)
             + explore(i, k - 1, color);
// ..
    // explore(i + 1, k + 1, table[i][k])
  }

  // visits one with other color
  return 0;
}

void solve() {
  // Go through each field, and call the recursive function:
  // Explores areas with the same color (if it hasn't been there)
  for(int i = 0; i < n; i++) {
    for(int k = 0; k < m; k++) {
      int curr_size = explore(i, k, table[i][k]);
      if (curr_size > n_fields_largest) n_fields_largest = curr_size;
      if (curr_size > 0) n_areas += 1;
    }
  }
}

void output() {
  printf("%d ", n_areas);
  printf("%d\n", n_fields_largest);
}

int main() {
  input();
  solve();
  output();

  return 0;
}
