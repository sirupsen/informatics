#include <string>
// #include <iostream>
#include <climits>
#include <set>
#include <vector>
using namespace std;

class UniversalAntiVenom
{
  set<char> all_venoms;

  public:
    int recurse(vector<string> &venomType, vector<bool> taken, set<char> venoms, int index, int snakes)
    {
      if(venoms.size() == all_venoms.size())
      {
        return snakes;
      }

      if(index >= 5)
      {
        return INT_MAX;
      }

      int first = recurse(venomType, taken, venoms, index + 1, snakes + 0);

      taken[index] = true;

      for(int j = 0; j < venomType[index].size(); j++)
      {
        venoms.insert(venomType[index][j]);
      }

      int second = recurse(venomType, taken, venoms, index + 1, snakes + 1);

      return min(second, first);
    }

    int getLeast(vector<string> venomType)
    {
      vector<bool> taken(10, 0);
      set<char> venoms;

      for(int i = 0; i < venomType.size(); i++)
      {
        for(int j = 0; j < venomType[i].size(); j++)
        {
          all_venoms.insert(venomType[i][j]);
        }
      }

      return recurse(venomType, taken, venoms, 0, 0);
    }
};

// int main()
// {
//   UniversalAntiVenom uav;
// 
//   vector<string> venomTypes;
//   venomTypes.push_back(string("afb"));
//   venomTypes.push_back(string("ed"));
//   venomTypes.push_back(string("bdaf"));
//   venomTypes.push_back(string("ebdf"));
//   venomTypes.push_back(string("ebafd"));
// 
//   cout << uav.getLeast(venomTypes) << endl;
// 
//   return 0;
// }
