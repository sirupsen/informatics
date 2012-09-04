#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Elephant {
  int weight;
  int iq;
  int index;
};

vector<Elephant> elephants;
vector<vector<Elephant> > DP;

vector<Elephant> sequence;

vector<Elephant> lds(size_t i) {
  if(DP[i].size() != 0) return DP[i];

  vector<Elephant> local_max;
  int best_j = 0;

  for(size_t j = 0; j < i; ++j) {
    if (elephants[j].weight < elephants[i].weight) // iq should be higher
    {
      vector<Elephant> s = lds(j);

      if (s.size() > local_max.size()) {
        local_max = s;
      }
    }
  }

  local_max.push_back(elephants[i]);

  return DP[i] = local_max;
}

bool by_iq(Elephant a, Elephant b) {
  return a.iq > b.iq;
}

int main() {
  int tmp;

  int tmp_weight, tmp_iq, i = 1;
  while(cin >> tmp_weight && cin >> tmp_iq) {
    Elephant new_elephant = {tmp_weight, tmp_iq, i};
    elephants.push_back(new_elephant);
    i++;
  }

  DP.resize(i);

  // for(vector<Elephant>::const_iterator it = elephants.begin(); it != elephants.end(); ++it) {
  //   cout << it->weight << ": " << it->iq << endl;
  // }

  sort(elephants.begin(), elephants.end(), by_iq);

  // cout << "sorted" << endl;

  // for(vector<Elephant>::const_iterator it = elephants.begin(); it != elephants.end(); ++it) {
  //   cout << it->weight << ": " << it->iq << endl;
  // }

  vector<Elephant> local_max;
  for(size_t i = 0; i < elephants.size(); ++i) {
    vector<Elephant> s = lds(i);

    if (s.size() > local_max.size()) {
      local_max = s;
    }
  }

  // sequence.clear();
  // cout << sequence.size() << endl;
  // subsequence(best_i); // regen
  // cout << sequence.size() << endl;
  //
  cout << local_max.size() << endl;

  for(vector<Elephant>::const_iterator it = local_max.begin(); it != local_max.end(); ++it) {
    cout << it->index << endl;
  }

  // cout << best_i << endl;
  // cout << local_max << endl;

  return 0;
}
