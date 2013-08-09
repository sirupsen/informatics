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

    bool cmp(size_t a, size_t b) {
      return b > a;
    }

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
              tmp.back().values.insert(string_part);
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

      string matcher;
      int visited[20000][30];
      vector<size_t> matches;

      void match(string name, string matcher) {
        this->matcher = matcher;

        memset(visited, -1, sizeof visited);
        this->matches.clear();

        recursive_match(0, 0);

        if(matches.size() > 0) {
          sort(matches.begin(), matches.end(), cmp);

          cout << name << endl;

          for(auto match : matches)
            cout << match << " ";

          cout << endl;
        }

        this->matcher = "";
      }

      void recursive_match(size_t i, size_t j) {
        if(visited[i][j] != -1) return; 
        visited[i][j] = 1;

        if(i == this->matcher.size())
          return;

        if(j == this->parts.size()) {
          matches.push_back(i - j + 1);
          return;
        }

        recursive_match(i + 1, 0);

        if(this->parts[j].type == 0 && this->matcher[i] == this->parts[j].value) {
          recursive_match(i + 1, j + 1);
        } else if (this->parts[j].type == 1 || this->parts[j].type == 2) {
          bool in_set = false;

          if(this->parts[j].values.find(this->matcher[i]) != this->parts[j].values.end())
            in_set = true;

          if(this->parts[j].type == 1) { // not
            if(in_set) return;
            recursive_match(i + 1, j + 1);
          } else if (this->parts[j].type == 2) { // must be in
            if(!in_set) return;
            recursive_match(i + 1, j + 1);
          }
        }
      }
    };

    int main()
    {
      Regex protein(string("N{P}[ST]{P}"));

      string name, data;
      while(cin >> name >> data)
        protein.match(name, data);

      return 0;
    }
