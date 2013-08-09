    #include<algorithm>
    #include<string>
    #include<vector>
    #include<iostream>
    using namespace std;

    vector<string> dna;
    size_t n = 0;

    bool all_common_substring(string &substr)
    {
      return all_of(dna.begin(), dna.end(), [&substr](string dna_string) { 
        return dna_string.find(substr) != string::npos; 
      });
    }

    string common_substring(int &length)
    {
      string *first = &dna[0];

      for(size_t i = 0; i <= first->size() - length + 1; i++) {
        string pattern = first->substr(i, length);

        if(all_common_substring(pattern))
          return pattern;
      }

      return string("");
    }

    void input()
    {
      string dna_string;

      while(cin >> dna_string) {
        dna.push_back(dna_string);
        n++;
      }
    }

    string longest_common_substring()
    {
      string *first = &dna[0];

      int hi = first->size(), low = 0;

      while (low + 1 != hi) {
        int mid = (low + hi) / 2;

        if(common_substring(mid).size() > 0) {
          low = mid;
        } else {
          hi = mid;
        }
      }

      return common_substring(low);
    }

    int main()
    {
      input();
      cout << longest_common_substring() << endl;

      return 0;
    }
