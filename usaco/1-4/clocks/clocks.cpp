/*
ID: sirup1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define CLOCKS 3

size_t clocks[CLOCKS][CLOCKS];

void input()
{
  for(int y = 0; y < CLOCKS; y++)
    for (int x = 0; x < CLOCKS; x++)
      cin >> clocks[y][x];
}

void turn_clock(int x, int y, vector<int>& moves) {
  clks[y][x] = (clks[y][x] + 3) % 12;
}

void perform_move(int move, int clks[CLOCKS][CLOCKS], vector<int> moves)
{
  if (move == 1) {
    turn_clock(0,0, clks);
    turn_clock(0,1, clks);
    turn_clock(1,0, clks);
    turn_clock(1,1, clks);
  } else if (move == 2) {
    turn_clock(0,0, clks);
    turn_clock(0,1, clks);
    turn_clock(0,2, clks);
  } else if (move == 3) {
    turn_clock(0,1, clks);
    turn_clock(0,2, clks);
    turn_clock(1,1, clks);
    turn_clock(1,2, clks);
  } else if (move == 4) {
    turn_clock(0,0, clks);
    turn_clock(1,0, clks);
    turn_clock(2,0, clks);
  } else if (move == 5) {
    turn_clock(0,1, clks);
    turn_clock(1,0, clks);
    turn_clock(1,1, clks);
    turn_clock(1,2, clks);
    turn_clock(2,1, clks);
  } else if (move == 6) {
    turn_clock(0,2, clks);
    turn_clock(1,2, clks);
    turn_clock(2,2, clks);
  } else if (move == 7) {
    turn_clock(1,0, clks);
    turn_clock(1,1, clks);
    turn_clock(2,0, clks);
    turn_clock(2,1, clks);
  } else if (move == 8) {
    turn_clock(2,0, clks);
    turn_clock(2,1, clks);
    turn_clock(2,2, clks);
  } else if (move == 9) {
    turn_clock(1,1, clks);
    turn_clock(1,2, clks);
    turn_clock(2,1, clks);
    turn_clock(2,2, clks);
  }
}

bool all_clocks_twelve(int clks[CLOCKS][CLOCKS]) {
  for(int y = 0; y < CLOCKS; y++)
    for(int x = 0; x < CLOCKS; x++)
      if (clks[y][x] != 12) return false;

  return true;
}

void bfs() {
  queue<int> q;

  // queue all first time moves possible
  for(int move = 1; move <= 9; move++) {
    int clks[CLOCKS][CLOCKS];

    int moves[10];
    moves[move] = 1;

    memcpy(clks, clocks, sizeof(clks));
    perform_move(move, clks, moves);
  }

  // traverse the tree with DFS
  while (!q.empty) {
    if (all_clocks_twelve) return moves;
  }
}

int main()
{
  input();

  return 0;
}
