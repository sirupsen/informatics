#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct player {
  int original_position;
  int matches;
};
vector<player> players;

vector<int> games[1002];

int n_players;

void input() {
  scanf("%d", &n_players);

  for(int i = 0; i < n_players; i++) {
    int matches;
    scanf("%d", &matches);

    player new_player;

    new_player.matches = matches;
    new_player.original_position = i + 1;

    players.push_back(new_player);
  }
}

bool players_happy(vector<player> current_players)
{
  for(int i = 0; i < n_players; i++) 
    if (current_players[i].matches != 0)
      return false;

  return true;
}

bool solve(vector<player> current_players, int index) {
  int i;

  for(i = 0; i < n_players; i++)
    printf("%d ", current_players[i].matches);

  printf("\n");

  if (players_happy(current_players)) return true;

  int current_index = n_players + index - 1;

  for(i = 0; i < (current_index + 1); i++) {
    if (current_players[current_index].matches == 0) return solve(current_players, index - 1);

    if (current_players[i].matches > 0) {
      current_players[i].matches -= 1;
      current_players[current_index].matches -= 1;

      games[current_players[i].original_position - 1].push_back(current_players[current_index].original_position);
      games[current_players[current_index].original_position - 1].push_back(current_players[i].original_position);

  return false;
}

bool player_sorter(const player& left, const player& right) {
  return left.matches > right.matches;
}

bool game_sorter(const int left, const int right)
{
  return left < right;
}

int main(int argc, char *argv[]) {
  input();

  sort(players.begin(), players.end(), &player_sorter);

  if (solve(players, 0)) {
    printf("SOLUTION\n");
    for(int i = 0; i < (n_players); i++) {
      std::sort(games[i].begin(), games[i].end(), &game_sorter);
      for(int k = 0; k < games[i].size(); k++) {
        printf("%d ", games[i].at(k));
      }
      printf("\n");
    }
  } else {
    printf("NO SOLUTION");
  }

  return 0;
}
