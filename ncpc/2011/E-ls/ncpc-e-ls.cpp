#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

string file_name, pattern; 

short dp[105][105];

bool match(size_t index, size_t pattern_index)
{
  if(index >= file_name.size() || pattern_index >= pattern.size()) 
    return false;

  if(pattern[pattern_index] != '*' && pattern[pattern_index] != file_name[index])
    return false;

  if(index == file_name.size() - 1 && pattern_index == pattern.size() - 1)
    return true;

  if(dp[index][pattern_index] != -1)
    return dp[index][pattern_index];

  bool possible = false;
  if (pattern[pattern_index] == '*') {
    if(match(index + 1, pattern_index)) possible = true;
    if(match(index, pattern_index + 1)) possible = true;
  }

  if(match(index + 1, pattern_index + 1)) possible = true;

  return dp[index][pattern_index] = possible;
}

int main()
{
  cin >> pattern;
  int n; cin >> n;

  for(size_t i = 0; i < n; ++i) {
    cin >> file_name;
    memset(dp, -1, sizeof dp);
    if(match(0, 0)) cout << file_name << endl;
  }

  return 0;
}
