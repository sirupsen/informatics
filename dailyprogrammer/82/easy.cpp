    #include<iostream>
    using namespace std;

    void substrings(string main_string, int substring_length) 
    {
      for(int i = 0; i < substring_length; i++) {
        for(int j = i; j < substring_length; j++) {
          for(int k = i; k <= j; k++)
            cout << main_string[k];

          cout << endl;
        }
      }
    }

    string remove_duplicates(string subject)
    {
      string no_duplicates("");

      for(int i = 0; i < subject.length(); i++) {
        bool found = false;

        for(int j = 0; j < no_duplicates.length(); j++) {
          if (no_duplicates[j] == subject[i]) {
            found = true;
            break;
          }
        }

        if (!found) no_duplicates += subject[i];
      }

      return no_duplicates;
    }

    int n_substrings(int substring_length) 
    {
      return (substring_length * (substring_length + 1)) / 2;
    }

    int main()
    {
      string alphabet("abcdefghijklmnopqrstuvwxyz");
      string hello("hello there");

      substrings(alphabet, 5);
      cout << n_substrings(5) << endl;
      substrings(remove_duplicates(hello), 5);

      return 0;
    }
