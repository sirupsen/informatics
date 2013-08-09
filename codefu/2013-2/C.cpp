#include <string>
// #include <cstdio>
// #include <iostream>
#include <vector>
using namespace std;

class SnakeEggs
{
  public:
    string getLargest(string eggs, int K)
    {
      int previous_egg = -1;
      string final;

      while(previous_egg < (int) eggs.size() - 1)
      {
        int best_offset = 1;

        for(int offset = 1; offset <= K + 1 && offset + previous_egg < eggs.size(); offset++)
        {
          if(eggs[previous_egg + offset] > eggs[previous_egg + best_offset])
          {
            best_offset = offset;
          }
        }

        K -= best_offset - 1;

        // cout << "Adding " << eggs[previous_egg + best_offset] << " to final, best offset at " << previous_egg << " was " << best_offset << endl;
        // cout << "K is now " << K << endl;

        previous_egg += best_offset;

        final += eggs[previous_egg];
      }

      string ultra_final;

      for(int i = 0; i < final.size() - K; i++)
      {
        ultra_final.push_back(final[i]);
      }

      return ultra_final;
    }
};

// int main()
// {
//   SnakeEggs se;
// 
//   cout << se.getLargest(string("836696295"), 3) << endl;
//   cout << se.getLargest(string("150530555"), 7) << endl;
//   cout << se.getLargest(string("282427614"), 6) << endl;
//   cout << se.getLargest(string("7139807"), 6) << endl;
//   cout << se.getLargest(string("44467298699295426217363792650705184457169194582852394856915067823"), 27) << endl;
//   return 0;
// }
