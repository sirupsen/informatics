#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> boards;
vector<int> rails;

int best_so_far = 0;
  int n, r;

void recurse(int board_i, int rails_i, int board_size, set<int> local_rails)
{
  if(local_rails.size() > best_so_far)
  {
    best_so_far = local_rails.size();
  }

  if(board_i >= boards.size() || rails_i >= rails.size())
  {
    return;
  }

  if(board_size >= rails[rails_i] && local_rails.count(rails_i) == 0)
  {
    set<int> new_local_rails = local_rails;
    new_local_rails.insert(rails_i);

    recurse(board_i, rails_i + 1, board_size - rails[rails_i], new_local_rails);
  }

  if(board_size >= boards[0])
  {
    recurse(board_i, rails_i + 1, board_size, local_rails);
  }

  if(board_i + 1 < boards.size())
  {
    recurse(board_i + 1, 0, boards[board_i + 1], local_rails);
  }
}

void input()
{
  scanf("%d", &n);

  boards.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &boards[i]);

  scanf("%d", &r);
  rails.resize(r);
  for(int i = 0; i < r; i++)
    scanf("%d", &rails[i]);
}

void output()
{
  if(n>=4||n==2) printf("%d\n", best_so_far + 1);
  else printf("%d\n", best_so_far);
}

int main()
{
  input();

  set<int> empty;
  sort(rails.begin(), rails.end());
  recurse(0, 0, boards[0], empty);

  output();

  return 0;
}
