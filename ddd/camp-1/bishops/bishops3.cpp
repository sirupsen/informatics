#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ii;

int n, k, solutions;

inline bool is_attacking(ii &a, ii &b)
{
  return abs(a.first - b.first) == abs(a.second - b.second);
}

bool anybody_attacking(ii &a, vector<ii> &placed)
{
  for(int i = 0; i < placed.size(); i++)
    if(is_attacking(a, placed[i])) return true;

  return false;
}

void print_board(vector<ii> &placed)
{
  bool something[25][25];
  memset(something, 0, sizeof something);

  for(int i = 0; i < placed.size(); i++)
    for(int j = 0; j < placed.size(); j++)
      something[placed[i].second][placed[i].first] = true;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(something[i][j]) printf("%c", 'X');
      else printf("%c", '.');
    }
    printf("\n");
  }

  printf("\n");
}

int color = 0;
void count_color(int p, int goal_b, int b, vector<ii> placed)
{
  if(b == goal_b) {
    color++;
    // print_board(placed);
    return;
  }

  if(p >= n * n)
    return;

  ii here = make_pair(p % n, p / n);
  if(!anybody_attacking(here, placed)) {
    vector<ii> new_placed = placed;
    new_placed.push_back(here);

    if(here.first == n - 1 && n % 2 == 0) {
      count_color(p + 1, goal_b, b + 1, new_placed);
    } else if(here.first == n - 2 && n % 2 == 0) {
      count_color(p + 3, goal_b, b + 1, new_placed);
    } else {
      count_color(p + 2, goal_b, b + 1, new_placed);
    }
  }

  if(here.first == n - 1 && n % 2 == 0) {
    count_color(p + 1, goal_b, b, placed);
  } else if(here.first == n - 2 && n % 2 == 0) {
    count_color(p + 3, goal_b, b, placed);
  } else {
    count_color(p + 2, goal_b, b, placed);
  }
}

#define BLACK 0
#define WHITE 1

int count_color(int p, int goal_b)
{
  color = 0;
  vector<ii> empty;
  count_color(p, goal_b, 0, empty);

  return color;
}

void solve(int p, int lk, vector<ii> placed)
{
  if(lk == k) {
    solutions++;
    return;
  }

  if(p >= n * n)
    return;

  ii here = make_pair(p % n, p / n);

  if(!anybody_attacking(here, placed)) {
    vector<ii> new_placed = placed;
    new_placed.push_back(here);

    solve(p + 1, lk + 1, new_placed);
  }

  solve(p + 1, lk, placed);
}

int main()
{
  solutions = 0;
  cin >> n >> k;

  int sum = 0;

  // cout << count_color(WHITE, 2) << endl;

  // printf("B\tW\tM\t\tR\n");
  for(int blacks = 0; blacks <= k; blacks++) {
    int whites = k - blacks;

    int b_count = count_color(BLACK, blacks);
    int w_count = count_color(WHITE, whites);

    // printf("%d\t%d\t%dx%d\t\t%d\n", blacks, whites, b_count, w_count, b_count * w_count);

    sum += b_count * w_count;
  }

  // printf("\t\t\t\t%d\n", sum);

  // vector<ii> empty;
  // solve(0,0,empty);
  printf("%d\n", sum);
}
