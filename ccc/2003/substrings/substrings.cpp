#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;

struct Node {
  map<char, Node*> nodes;
};

struct Trie {
  Node* root;
  char c;

  Trie()
  {
    this->root = new Node();
  }

  bool insert(string suffix)
  {
    Node* cur = root;
    bool uniq = false;

    for(int i = 0; i < suffix.size(); i++)
    {
      if(!cur->nodes.count(suffix[i]))
      {
        uniq = true;
        cur->nodes[suffix[i]] = new Node();
      }

      cur = cur->nodes[suffix[i]];
    }

    return uniq;
  }
};

int main()
{
  int n;
  cin >> n;
  string s;

  while(n--)
  {
    Trie trie;
    cin >> s;

    int c = 1; // blank
    for(int i = 0; i < s.size(); i++)
      for(int j = 0; j + i <= s.size(); j++)
        c += trie.insert(s.substr(i, j));

    cout << c << endl;
  }

  return 0;
}
