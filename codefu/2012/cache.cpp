#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <cassert>
using namespace std;

class Cache
{
  public:
    string callCache(int m, string sequence)
    {
      map<char, int> last_used;

      string result("");
      string cache("");

      for(int i = 0; i < sequence.size(); i++) {
        // cout << sequence[i] << endl;

        if (sequence[i] == '?') {
          if(result.size() > 0) {
            result += ",";
          }

          if(cache.size() == 0) {
            result += "*";
          } else {
            result += cache;
          }
        } else if (sequence[i] == '!') {
          // last_used.clear();
          cache.clear();
        } else {
          if(cache.size() < m) {
            if(last_used.count(sequence[i]) > 0) {
              last_used[sequence[i]] = i;
            } else {
              cache += sequence[i];
              last_used[sequence[i]] = i;
            }
          } else {
            // cout << "ALT" << endl;

            int lowest = INT_MAX;
            int lowest_index;

            for(int j = 0; j < m; j++) {

              if(last_used[cache[j]] < lowest) {
                lowest = last_used[cache[j]];
                lowest_index = j;
              }

              cout << lowest << endl;
              cout << cache[j] << " : " << last_used[cache[j]] << endl;
            }

            cout << "lowest id " << lowest_index << endl;

            cache[lowest_index] = sequence[i];
            last_used[sequence[i]] = i;
          }
        }
      }

      return result;
    }
};

int main()
{

  Cache cache;

  string lol("LH?HGIVBXQUXVEFFL!TRIZMYMEBUUYQNZJANKPVLJT?RDR?");
  cout << cache.callCache(3, lol) << endl;

  return 0;
}
