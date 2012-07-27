#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Vertex {
  string name;
  vector<Vertex*> neighbours;
};

struct AdjadencyList {
  vector<Vertex*> verticis;
};

int main()
{
  Vertex t;
  t.name = "t";

  Vertex v;
  v.neighbours.push_back(&t);
  v.name = "v";

  Vertex w;
  w.neighbours.push_back(&t);
  w.name = "w";

  Vertex s;
  s.neighbours.push_back(&w);
  s.neighbours.push_back(&v);
  s.name = "s";

  AdjadencyList alist;
  alist.verticis.push_back(&t);
  alist.verticis.push_back(&v);
  alist.verticis.push_back(&w);
  alist.verticis.push_back(&s);

  for(vector<Vertex*>::iterator it = alist.verticis.begin(); it < alist.verticis.end(); it++) {
    for(vector<Vertex*>::iterator itt = (**it).neighbours.begin(); itt < (**it).neighbours.end(); itt++) {
      cout << (**it).name << " points to " << (**itt).name << endl;
    }
  }

  return 0;
}
