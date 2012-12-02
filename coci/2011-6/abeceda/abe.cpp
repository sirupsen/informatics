#include<iostream>
#include<vector>
#include<string>
using namespace std;

size_t n; 
vector<string> words;
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> stack;
bool fucked = false;

string result("");

// * Handle out of bound indices
void recurse(size_t start, size_t end, size_t index)
{
  if(start == end) return;

  printf("%ld;%ld;%ld\n", start, end, index);

  bool last_set = false;
  char last;

  if(index >= words[start].size()) 
    last = *(words[start].end() - 1);
  else 
    last = words[start][index];

  size_t last_switch = start;

  for(size_t i = start + 1; i <= end; i++) {
    if(index >= words[i].size()) continue;

    char current = words[i][index];

    if(current != last) {
      adj[current - 'a'].push_back(last - 'a');
      cout << current << " -> " << last << endl;

      recurse(last_switch, i - 1, index + 1);

      last_switch = i;
      last = words[i][index];
    } else if(current == last && i == end) { // recurse deeper on segment
      recurse(last_switch, i, index + 1);
    }
  }
}

void dfs(size_t i) {
  if(stack[i]) {
    fucked = true;
    return;
  }

  if(!visited[i]) {
    stack[i] = true;
    visited[i] = true;

    for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
      dfs(*it);

    stack[i] = false;
    result += (char) (i + 'a');
  }
}

int count_distinct_letters() {
  vector<bool> distinct;
  distinct.assign(256, false);
  int d = 0;

  for(int i = 0; i < words.size(); i++) {
    for(int j = 0; j < words[i].size(); j++) {
      char c = words[i][j];
      if(!distinct[c]) {
        distinct[c] = true;
        d++;
      }
    }
  }

  return d;
}

int main()
{
  cin >> n;
  words.resize(n + 5);
  adj.resize(100);

  for(size_t i = 0; i < n; i++)
    cin >> words[i];

  recurse(0, n - 1, 0);

  // for(size_t i = 0; i <= 25; i++)
  //   for(size_t j = 0; j < adj[i].size(); j++)
  //     cout << (char) ('a' + i) << " -> " << (char) ('a' + adj[i][j]) << endl;

  // cout << "sup" << endl;

  visited.assign(30, false);
  stack.assign(30, false);

  for(size_t i = 0; i <= 25; i++)
    if(adj[i].size() > 0)
      dfs(i);

  // cout << "sup2" << endl;

  if(fucked)
    cout << "!" << endl;
  else if(count_distinct_letters() != result.size())
    cout << "?" << endl;
  else
    cout << result << endl;

  return 0;
}
