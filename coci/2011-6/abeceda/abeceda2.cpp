#include<string>
#include<vector>
#include<iostream>
using namespace std;

size_t n;
vector<string> words;
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> distinct;
vector<bool> stack;
vector<char> letters;
string result;
bool loop = false;

void dfs(int i)
{
  if(stack[i]) {
    loop = true;
    return;
  }

  if(!visited[i]) {
    stack[i] = true;

    for(size_t j = 0; j < adj[i].size(); j++)
      dfs(adj[i][j]);

    stack[i] = false;
    visited[i] = true;
    result += (char) (i + 'a');
  }
}

int main()
{
  cin >> n;
  words.resize(n + 5);
  adj.resize(30);
  visited.assign(30, false);
  stack.assign(30, false);
  distinct.assign(30, false);
  letters.assign(30, false);

  for(size_t i = 0; i < n; i++) {
    cin >> words[i];
    
    for(size_t j = 0; j < words[i].size(); j++) {
      int letter = (int) (words[i][j] - 'a');

      if (!distinct[letter]) {
        distinct[letter] = true;
        letters.push_back(letter);
      }
    }
  }

  for(size_t i = 0; i < n - 1; i++) {
    size_t j = 0;
    for(;j < words[i].size() && j < words[i + 1].size() 
        && words[i][j] == words[i + 1][j]; j++);

    char first = words[i + 1][j];
    char second = words[i][j];

    // cout << first << "->" << second << endl;

    if(first != 0 && second != 0 && first != ' ' && second != ' ')
      adj[(int) (first - 'a')].push_back((int) (second - 'a'));
  }

  vector<vector<int> > adj2;
  adj2 = adj;

  for(size_t i = 0; i < letters.size(); i++) {
    int current = 0;

    for(size_t j = 0; j < letters.size(); j++) {
      if(adj2[j].size() == 0) current++;
    }
  }

  visited.assign(30, false);
  for(size_t i = 0; i <= 25; i++)
    if(adj[i].size() > 0)
      dfs(i);

  // reverse(result.begin(), result.end());

  if(loop) {
    cout << "!" << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}
