#include<iostream>
#include<vector>
using namespace std;

int total = 0, n;

inline bool out_of_bounds(int &x, int &y)
{
  if(x < 0 || x >= n || y >= n || y < 0) return true;
  return false;
}

struct Coord {
  int x;
  int y;
};

void recurse(vector<vector<bool>> visited, int x, int y, int count)
{
  if (x == n - 1 && y == n - 1) {
    if(count == n * n) total++;
    return;
  } else if (out_of_bounds(x,y) || visited[x][y]) {
    return;
  } else {
    visited[x][y] = true;

    recurse(visited, x + 1, y, count + 1);
    recurse(visited, x - 1, y, count + 1);
    recurse(visited, x, y + 1, count + 1);
    recurse(visited, x, y - 1, count + 1);
  }
}

int main()
{
  cin >> n;

  vector<vector<bool> > visited;
  visited.resize(n + 1);

  for(size_t i = 0; i < visited.size(); i++)
    visited[i].assign(n + 1, false);

  recurse(visited, n - 1, 0, 1);

  printf("%d\n", total);

  return 0;
}
