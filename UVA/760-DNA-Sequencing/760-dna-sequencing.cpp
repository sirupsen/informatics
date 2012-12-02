#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Suffix {
  string suffix;
  int origin;
};

vector<Suffix> suffixes;

void add_suffixes(string s, int origin)
{
  for(size_t i = 0; i < s.size(); i++) {
    Suffix suf = {s.substr(i), origin};
    suffixes.push_back(suf);
  }
}

bool compare(Suffix a, Suffix b) 
{
  return a.suffix > b.suffix;
}

bool cmp_strings(string a, string b)
{
  return a.compare(b) == 0;
}

int main() {
  string a, b;
  int n_test_case = 0;

  while(getline(cin, a) && getline(cin, b)) {
    if(n_test_case != 0) {
      a = b;
      getline(cin, b);
    }

    if(n_test_case != 0) 
      cout << endl;

    suffixes.clear();

    add_suffixes(a, 1);
    add_suffixes(b, 2);

    sort(suffixes.begin(), suffixes.end(), compare);

    int max_len = 0;
    vector<string> max_strings;
    max_strings.push_back("");

    for(size_t i = 0; i < suffixes.size(); i++) {
      Suffix sa = suffixes[i];

      size_t j = 1;
      for(;i + j < suffixes.size() && suffixes[i + j].origin == sa.origin; j++);
      if(i + j >= suffixes.size()) continue;

      Suffix sb = suffixes[i + j];

      string::iterator ap = sa.suffix.begin(), bp = sb.suffix.begin();
      for(;ap != sa.suffix.end() && bp != sb.suffix.end(); ap++, bp++)
        if(*ap != *bp) break;

      string candidate = string(sa.suffix.begin(), ap);

      if(candidate.size() > max_strings.front().size()) {
        max_strings.clear();
        max_strings.push_back(candidate);
      } else if(candidate.size() == max_strings.front().size()) {
        max_strings.push_back(candidate);
      }
    }

    if(max_strings.front().size() > 0) {
      sort(max_strings.begin(), max_strings.end());
      vector<string>::iterator non_duplicate_end = unique(max_strings.begin(), max_strings.end(), cmp_strings);

      for(vector<string>::iterator max_string = max_strings.begin(); max_string != non_duplicate_end; max_string++)
        cout << *max_string << endl;
    } else {
      cout << "No common sequence." << endl;
    }
    
    n_test_case++;
  }

  return 0;
}
