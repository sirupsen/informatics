#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
  int n, i; cin >> n;

  while(n--)
  {
    string dna; cin >> dna;
    set<string> suffixes;

    for(i = 0; i < dna.size(); i++)
    {
      suffixes.insert(dna.substr(i));
    }

    string longest;
    int count = -1;

    for(set<string>::iterator suffix = suffixes.begin(); suffix != --suffixes.end(); )
    {
      string current = *suffix;
      suffix++;
      string next = *suffix;

      for(i = 0; i < min(next.size(), current.size()) && next[i] == current[i]; i++) {}

      string local = next.substr(0, i);

      if(local.size() == 0) continue;

      if(local.size() > longest.size())
      {
        longest = local;
        count = 2;
      }
      else if(local.size() == longest.size())
      {
        int compare = longest.compare(local);

        if(compare > 0)
        {
          longest = local;
          count = 2;
        }
        else if(compare == 0)
        {
          count++;
        }
      }
    }

    if(count != -1)
    {
      cout << longest << " " << count << endl;
    }
    else
    {
      cout << "No repetitions found!" << endl;
    }
  }

  return 0;
}
