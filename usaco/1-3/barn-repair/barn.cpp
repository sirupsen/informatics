/*
ID: sirup1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int n_boards;
int n_stalls;
int n_cow_stalls;

struct Range {
  int start_index;
  int end_index;
};

bool cmp(Range a, Range b) {
  return (a.end_index - a.start_index) > (b.end_index - b.start_index);
}

int main()
{
  ifstream input;
  input.open("barn1.in");

  input >> n_boards;
  input >> n_stalls;
  input >> n_cow_stalls;

  // because they're fucking mean probably giving unsorted results
  // O(n)
  vector<int> stalls;
  for(int i = 0; i < n_cow_stalls; i++) {
    int current_stall;
    input >> current_stall;
    stalls.push_back(current_stall);
  }

  // O(n * log(n))
  sort(stalls.begin(), stalls.end());

  vector<Range> ranges;
  int last = -1;

  // O(n)
  for(vector<int>::iterator it = stalls.begin(); it != stalls.end(); it++) {
    if (last != -1) { // don't create for the first stall
      Range new_range = {last, *it};
      ranges.push_back(new_range);
    }

    last = *it;
  }

  // O(n * log(n))
  sort(ranges.begin(), ranges.end(), cmp);

  // for(vector<Range>::iterator it = ranges.begin(); it != ranges.end(); it++)
  //   cout << "[" << it->start_index << ";" << it->end_index << "]: " << it->end_index - it->start_index - 1 << "\n";

  int blocked = 0;
  // we don't have to use all the boards
  if (n_boards - 1 < ranges.size())
    for(vector<Range>::iterator it = ranges.begin() + (n_boards - 1); // boards aren't placed on biggest gaps
        (it->end_index - it->start_index - 1) != 0 && // these count towards "n_cow_stalls", and aren't "useless blocks"
         it != ranges.end(); it++)
      blocked += it->end_index - it->start_index - 1; // add the amount of "non cow stalls" blocked with boards

  ofstream output;
  output.open("barn1.out");

  output << blocked + n_cow_stalls << "\n";

  return 0;
}
