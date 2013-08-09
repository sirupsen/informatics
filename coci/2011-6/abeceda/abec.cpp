#include<iostream>
#include<vector>
#include<cctype>
#include<cassert>
#include<set>
#include<cctype>
#include<string>
#include<queue>
using namespace std;

int cti(char c)
{
  int i = c - 'a';
  if(i <= 0 && i >= 25) assert("Bad situation");
  return i;
}

int itc(int i)
{
  if(i <= 0 && i >= 25) assert("Bad situation");
  return i + 'a';
}

int main()
{
  size_t n;
  cin >> n;

  vector<string> words;
  vector<vector<int> > graph;
  int in[26] = {0};
  graph.resize(26);
  set<size_t> play;

  bool unique = true;

  for(size_t i = 0; i < n; i++) {
    string tmp; cin >> tmp;
    words.push_back(tmp);

    // Play contains all characters in play
    for(auto c : tmp) play.insert(cti(c));
  }

  // For each consecutive pair
  for(size_t i = 0; i < n - 1; i++) {
    string a = words[i];
    string b = words[i + 1];

    // Find first character where they differ
    auto ap = a.begin(), bp = b.begin();
    for(;ap != a.end() && bp != b.end(); ap++, bp++)
      if(*ap != *bp) break;

    // We can't say anything if they end at the same point
    if(ap != a.end() && bp != b.end()) {
      // Add to graph
      graph[cti(*ap)].push_back(cti(*bp));
      // Save ingoing edge count
      in[cti(*bp)]++;

      // Detect conflicts
      // TODO: Can be sped up by being done afterwards.
      for(auto node : graph[cti(*bp)]) {
        if(node == cti(*ap)) {
          cout << "!" << endl;
          return 0;
        }
      }
    }
  }

  queue<size_t> q;

  // Add whatever has 0 ingoing edges to the queue
  for(auto l : play)
    if(in[l] == 0) q.push(l);

  string result;

  // Toposort
  while(!q.empty()) {
    // Multiple options in the toposort, it's not unique.
    if(q.size() != 1) {
      unique = false;
      break;
    }

    int ch = q.front(); q.pop();
    result += itc(ch);

    // For each edge
    for(auto node = graph[ch].begin(); node != graph[ch].end(); node++) {
      // If the edge still exists
      if(*node > -1) {
        // If the node no longer has any ingoing edges, we're good.
        in[*node]--;
        if(in[*node] == 0) q.push(*node);
        *node = -1;
      }
    }
  }

  if(!unique) {
    cout << "?" << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}
