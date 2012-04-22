/*
ID: sirup1
PROG: milk2
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct range {
  int start;
  int end;
};

bool range_cmp(const range &a, const range &b)
{
  return a.start < b.start;
}

int main()
{
  FILE * inputFile;
  inputFile = fopen("milk2.in", "r");

  int n_sessions;
  fscanf(inputFile, "%d", &n_sessions);

  vector<range> sessions;
  vector<range> ranges;

  for(int i = 0; i < n_sessions; i++) {
    range new_range;
    fscanf(inputFile, "%d %d", &new_range.start, &new_range.end);

    sessions.push_back(new_range);
  }

  std::sort(sessions.begin(), sessions.end(), range_cmp);

  for(int i = 0; i < n_sessions; i++) {
    range current_session = sessions[i];
    
    bool in_range = false;

    // merge with range
    for(int i = 0; i < ranges.size(); i++) {
      if (current_session.start >= ranges[i].start && current_session.start <= ranges[i].end) {
        in_range = true;
        if (current_session.end > ranges[i].end) ranges[i].end = current_session.end; // extend range
        break;
      }
    }

    // create new range
    if (!in_range) {
      range new_range;
      new_range.start = current_session.start;
      new_range.end = current_session.end;

      ranges.push_back(new_range);
    }
  }

  std::sort(ranges.begin(), ranges.end(), range_cmp);

  int max_milking_time = 0;
  int max_idle_time = 0;

  // analyze ranges
  for(int i = 0; i < ranges.size(); i++) {
    range current_range = ranges[i];

    int milking_time = current_range.end - current_range.start;
    if (milking_time > max_milking_time) max_milking_time = milking_time;

    // only makes sense if we have > 1 session
    if (ranges.size() > 1) {
      int idle_time = ranges[i+1].start - current_range.end;
      if (idle_time > max_idle_time) max_idle_time = idle_time;
    }

    // printf("[%d;%d]\n", current_range.start, current_range.end);
  }

  FILE * outputFile;
  outputFile = fopen("milk2.out", "w");

  fprintf(outputFile, "%d %d\n", max_milking_time, max_idle_time);

  return 0;
}
