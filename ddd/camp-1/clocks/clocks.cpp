/*
ID: sirup1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

const string raw_moves[] = {
  "abde",
  "abc",
  "bcef",
  "adg",
  "bdefh",
  "cfi",
  "degh",
  "ghi",
  "efhi"
};

vector<vector<int> > moves;
vector<int> shortest;

bool all_twelve(const vector<int> &state)
{
  for(int i = 0; i < 9; i++)
    if(state[i] != 0) return false;

  return true;
}

void apply_move(const int &i, vector<int> &state)
{
  vector<int> move = moves[i];

  for(size_t i = 0; i < move.size(); i++)
    state[move[i]] = (state[move[i]] + 1) % 4;
}

bool done = false;

void recurse(vector<int> sequence, vector<int> state, int move)
{
  // Quit early.. lowest found
  // if(done) return;

  if(all_twelve(state)) {
    done = true;
    shortest = sequence;
    return;
  }
  
  if(move == 9) return;

  for(int i = 3; i >= 0; i--) {
    vector<int> sequence_copy = sequence;
    vector<int> state_copy = state;

    for(int j = 0; j < i; j++) {
      apply_move(move, state_copy);
      sequence_copy.push_back(move);
    }

    recurse(sequence_copy, state_copy, move + 1);
  }
}

int main()
{
  moves.resize(9);
  vector<int> sequence;
  vector<int> state(9, 0);

  // freopen("clocks.in", "rt", stdin);
  // freopen("clocks.out", "wt", stdout);

  for(int i = 0; i < 9; i++) {
    string move = raw_moves[i];
    for(size_t j = 0; j < move.size(); j++) {
      int l = (int) (move[j] - 'a');
      moves[i].push_back(l);
    }
  }

  for(int i = 0; i < 9; i++) {
    scanf("%d", &state[i]);
    // state[i] = (state[i] / 3) % 4;
  }

  recurse(sequence, state, 0);

  for(size_t i = 0; i < shortest.size(); i++)
    printf("%d", shortest[i] + 1);

  // printf("%d", shortest[shortest.size() - 1] + 1);

  printf("\n");

  return 0;
}
