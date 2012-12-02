#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

struct SuffixTrie {
  struct Node {
    Node * parent;
    Node * children[26];

    char character;
    set<string> descendants;

    Node(Node * parent, char character) {
      memset(children, 0, sizeof children);
      this->character = character;
      this->parent = parent;
    }
  };

  Node * root;

  SuffixTrie() {
    this->root = new Node(0, '^');
  }

  void add(string word)
  {
    for(size_t i = 0; i < word.size() - 1; i++)
      add(word.substr(i), this->root, 0, word);

    cout << "Done" << endl;
  }

  void load_dna() 
  {
    string dna;
    while(cin >> dna) add(dna);
  }

  Node * deepest_node;
  size_t max_depth = 0;

  string lcs()
  {
    deepest_node = 0;
    max_depth = 0;
    lcs(this->root, 0);

    return suffix(deepest_node);
  }

  string suffix(Node * node) 
  {
    string s = suffix(node, string(""));
    reverse(s.begin(), s.end());
    return s;
  }

  void lcs(Node * node, size_t depth)
  {
    if(depth > max_depth) {
      deepest_node = node;
      max_depth = depth;
    }

    for(size_t i = 0; i < 26; i++) {
      if(node->children[i] && node->descendants.size() == this->root->descendants.size()) {
        lcs(node->children[i], depth + 1);
      }
    }
  }

  private:
  inline size_t char_to_index(char &c)
  {
    return c - 'A';
  }

  void add(string suffix, Node * parent, size_t pos, string word)
  {
    if(pos == suffix.size()) return;
    
    size_t i = char_to_index(suffix[pos]);

    if (!parent->children[i]) {
      parent->children[i] = new Node(parent, index_to_char(i));
    }

    parent->descendants.insert(word);

    add(suffix, parent->children[i], pos + 1, word);
  }

  inline char index_to_char(size_t &c)
  {
    return c + 'A';
  }

  string suffix(Node * node, string s) 
  {
    if(node->parent) {
      s += node->character;
      return suffix(node->parent, s);
    } else {
      return s;
    }
  }
};


int main()
{
  SuffixTrie trie;
  trie.load_dna();
  cout << "Done adding" << endl;
  // cout << trie.lcs() << endl;

  return 0;
}
