#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX_N 105

int n;
vector<vector<int> > adj;
string words[MAX_N];
bool visited[30];
bool good = true;

void recurse(int start, int end, int index)
{
  // printf("%d;%d;%d\n\n", start, end, index);

  if(start == end) return;

  vector<char> last;
  last.push_back(words[start][index]);

  int last_switch = start;

  if(end - start == 1 && words[start][index] == words[end][index]) {
    recurse(start, end, index + 1);
    return;
  }

  for(int i = start + 1; i <= end; i++) {
    char current = words[i][index];
    char last_letter = last[last.size() - 1];

    if(current != last_letter) {
      for(int j = 0; j < last.size(); j++) {
        // cout << current << " -> " << last[j] << endl;
        adj[current - 'a'].push_back(last[j] - 'a');
      }

      recurse(last_switch, i - 1, index + 1);

      last_switch = i;
      last.push_back(current);
    }
  }
}

vector<int> top;

void dfs(int i) 
{
  if(!visited[i]) {
    visited[i] = true;

    for(int j = 0; j < adj[i].size(); j++)
      dfs(adj[i][j]);

    top.push_back(i);
  }
}

int main()
{
  cin >> n;
  adj.resize(30);

  bool distinct_letters[30];

  for(int i = 0; i <= 25; i++)
    distinct_letters[i] = false;

  int total_distinct_letters = 0;

  for(int i = 0; i < n; i++) {
    cin >> words[i];

    for(int j = 0; j < words[i].size(); j++) {
      char current = words[i][j];

      if (!distinct_letters[current - 'a']) {
        total_distinct_letters++;
        distinct_letters[current - 'a'] = true;
      }
    }
  }

  recurse(0, n - 1, 0);

  for(int i = 0; i <= 25; i++)
    visited[i] = false;
  for(int i = 0; i <= 25; i++)
    if(adj[i].size() > 0)
      dfs(i);

  if(top.size() == total_distinct_letters || top.size() == total_distinct_letters - 1) {
    for(int i = 0; i < top.size(); i++)
      cout << (char) (top[i] + 'a');
  } else {
    cout << "?";
  }

  cout << endl;

  return 0;
}
