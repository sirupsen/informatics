#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int max_sum;

vector<int> global_best;

int global_max_sum;

int max_tape(int sum, size_t index, vector<int> remaining, vector<int> tracks)
{
  int new_sum = sum;

  if (index != -1) {
    new_sum = sum + remaining[index];
    if (new_sum > max_sum) return sum;

    tracks.push_back(index);

    if (new_sum > global_max_sum) {
      global_best = tracks;
      global_max_sum = new_sum;
    }

    if (remaining.size() == 1) return new_sum;

    remaining.erase(remaining.begin() + index);
  }

  int local_max = 0;
  for(size_t i = 0; i < (size_t) remaining.size(); ++i) {
    local_max = max(local_max, max_tape(new_sum, i, remaining, tracks));
  }

  return local_max;
}

int main()
{
  int n_tracks;
  while(scanf("%d %d", &max_sum, &n_tracks) == 2) {
    vector<int> remaining;
    vector<int> empty;

    for(size_t i = 0; i < n_tracks; ++i) {
      int tmp;
      cin >> tmp;
      remaining.push_back(tmp);
    }

    max_tape(0, -1, remaining, empty);

    for(vector<int>::const_iterator it = global_best.begin(); it != global_best.end(); ++it) {
      cout << *it << " ";
    }

    cout << "sum:" << global_max_sum << endl;
  }

  return 0;
}
