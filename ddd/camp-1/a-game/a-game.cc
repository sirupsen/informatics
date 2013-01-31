#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int opposite_player(int player)
{
  if (player == -1) return +1;
  return -1;
}

int negamax(deque<int> board, size_t depth, int alpha, int beta, size_t player, vector<int> scores)
{
  // Handle end of depth/end of game
  if (depth == 0 || board.empty()) {
    return player * 23;
  } else {
    int best = INT_MIN, val;

    deque<int> shifted_board;
    scores.push_back(board.front());
    shifted_board.pop_front();

    val = -negamax(shifted_board, depth--, -beta, -alpha, -player, scores);

    deque<int> popped_board;
    scores.push_back(board.back());
    shifted_board.pop_back();

    val = -negamax(popped_board, depth--, -beta, -alpha, -player, scores);

    if (val >= beta)
      return val;

    if (val >= alpha)
      alpha = val;

    return alpha;
  }
}

int main()
{
  deque<int> numbers;
  numbers.push_back(4);
  numbers.push_back(7);
  numbers.push_back(2);
  numbers.push_back(9);
  numbers.push_back(5);
  numbers.push_back(2);

  vector<int> scores;

  int val;
  val = negamax(numbers, 2, -32000, 32000, 1, scores);

  return 0;
}
