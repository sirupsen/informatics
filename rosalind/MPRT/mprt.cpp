#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

struct RegexPart {
  size_t type;

  set<char> values;
  char value;
};

struct Regex {
  vector<RegexPart> parts;
  
  Regex(string regex) {
    this->parts = this->parse(regex);
  }

  vector<RegexPart> parse(string regex) {
    bool special = false;

    vector<RegexPart> tmp;

    for(size_t i = 0; i < regex.size(); i++) {
      char string_part = regex[i];

      if(string_part == '{') {
        special = true;

        RegexPart new_part;
        new_part.type = 1;

        tmp.push_back(new_part);
      } else if (string_part == '}') {
        special = false;
      } else if (string_part == '[') {
        special = true;

        RegexPart new_part;
        new_part.type = 2;

        tmp.push_back(new_part);
      } else if (string_part == ']') {
        special = false;
      } else {
        if(special) {
          tmp.front().values.insert(string_part);
        } else {
          RegexPart new_part;
          new_part.type = 0;
          new_part.value = string_part;

          tmp.push_back(new_part);
        }
      }
    }

    return tmp;
  }
};

int main()
{
}
