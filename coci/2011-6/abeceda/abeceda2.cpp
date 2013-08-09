#include<string>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

size_t n;
vector<string> words;
vector<bool> letters;
vector<int> out;
vector<int> in;
string result;
bool uniq = true;

int am[30][30];

bool is_letter(int l) {
  if(l >= 0 && l <= 25) return true;
  return false;
}

int main()
{
  cin >> n;
  words.resize(n + 5);
  out.assign(30, 0);
  in.assign(30, 0);
  letters.assign(30, false);

  for(size_t i = 0; i < 30; i++)
    for(size_t j = 0; j < 30; j++)
      am[i][j] = -1;

  for(size_t i = 0; i < n; i++)
    cin >> words[i];

  for(size_t i = 0; i < n - 1; i++) {
    size_t j = 0;
    for(;j < words[i].size() && j < words[i + 1].size() 
        && words[i][j] == words[i + 1][j]; j++);

    int a = words[i + 1][j] - 'a';
    int b = words[i][j] - 'a';

    if(is_letter(a) && is_letter(b) && am[b][a] == -1) {
      if(am[b][a] != -1) {
        cout << "!" << endl;
        return 0;
      }

      am[a][b] = 1;

      // cout << char(b + 'a') << "->" << char(a + 'a') << endl;

      letters[a] = true;
      letters[b] = true;

      in[a]++;
    }
  }

  queue<int> q;
  string result;

  for(size_t i = 0; i <= 25; i++)
    if(letters[i] && in[i] == 0) q.push(i);

  // cout << "queue size: " << q.size() << endl;

  while(!q.empty()) {
    if(q.size() != 1) {
      // cout << "queue is oversized" << endl;
      uniq = false;
    }

    int u; u = q.front(); 
    q.pop();

    result += (char) (u + 'a');

    for(size_t i = 0; i < 30; i++) {
      if(am[i][u] != -1) {
        am[i][u] = -1;
        in[i]--;

        // cout << "Ingoing for " << char(i + 'a') << " " << in[i] << endl;

        if(in[i] == 0) q.push(i);
      }
    }
  }

  if(!uniq) {
    cout << "?" << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}
