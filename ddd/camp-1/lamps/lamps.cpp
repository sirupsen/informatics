#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int n, c;
int on;

string final;
map<string, bool> exists;

vector<int> final_on;
vector<int> final_off;

vector<string> results;

char reverse_state(char &s)
{
  if(s == '1')
    return '0';

  return '1';
}

string apply_operation(int op, string s)
{
  string new_s = s;

  if(op == 1)
  {
    for(int i = 0; i < n; i++)
    {
      new_s[i] = reverse_state(s[i]);
    }
  }
  else if(op == 2)
  {
    for(int i = 1; i < n; i += 2)
    {
      new_s[i] = reverse_state(s[i]);
    }
  }
  else if(op == 3)
  {
    for(int i = 0; i < n; i += 2)
    {
      new_s[i] = reverse_state(s[i]);
    }
  }
  else if(op == 4)
  {
    for(int i = 1; i <= n; i++)
    {
      if(i % 3 == 1) {
        new_s[i - 1] = reverse_state(s[i - 1]);
      }
    }
  }

  return new_s;
}

bool is_good(string &candidate)
{
  for(int i = 0; i < final_off.size(); i++)
  {
    if(candidate[final_off[i]] != '0') {
      return false;
    }
  }

  for(int i = 0; i < final_on.size(); i++)
  {
    if(candidate[final_on[i]] != '1') {
      return false;
    }
  }

  return true;
}

void solve(string candidate, int depth)
{
  if(exists.count(candidate) > 0)
    return;

  exists[candidate] = true;

  if(depth == c && is_good(candidate))
    results.push_back(candidate);

  if(depth == c)
    return;

  for(int i = 1; i <= 4; i++)
  {
    solve(apply_operation(i, candidate), depth + 1);
  }
}

void input()
{
  cin >> n >> c;

  int on_index;
  while(cin >> on_index && on_index != -1)
  {
    final_on.push_back(on_index-1);
  }

  int off_index;
  while(cin >> off_index && off_index != -1)
  {
    final_off.push_back(off_index - 1);
  }
}

int main()
{
  input();

  string starting_point;
  starting_point.assign(n, '1');

  solve(starting_point, 0);

  if(c % 2 == 0)
  {
    string all_1;
    all_1.assign(n, '1');
    results.push_back(all_1);

    string all_0;
    all_0.assign(n, '0');
    results.push_back(all_0);
  }

  sort(results.begin(), results.end());

  for(int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }

  return 0;
}
