#include<iostream>
#include<vector>
using namespace std;

struct Vertex {
  string name;
  vector<int> edges;
};

Vertex dgraph[100];

bool explored[100];

int topological_sorted[100];

int label = 0;
int N = 4;

void dfs(int v_i) 
{
  explored[v_i] = true;

  for(int i = 0; i < N; i++) 
  {
    if (!explored[i]) dfs(i);
  }

  topological_sorted[label] = v_i;
  label++;
}

int main() 
{
  Vertex shoes;
  shoes.name = "Shoes";
  dgraph[2] = shoes;

  Vertex undershorts;
  undershorts.name = "Undershorts";
  undershorts.edges.push_back(2);
  undershorts.edges.push_back(0);

  dgraph[1] = undershorts;

  Vertex pants;
  pants.name = "Pants";
  pants.edges.push_back(2);

  dgraph[0] = pants;

  Vertex socks;
  socks.name = "Socks";
  socks.edges.push_back(2);

  dgraph[3] = socks;

  for(int i = 0; i < 4; i++) 
  {
    for(vector<int>::iterator it = dgraph[i].edges.begin(); it != dgraph[i].edges.end(); it++) 
    {
      cout << dgraph[i].name << " points to " << dgraph[*it].name << endl;
    }
  }

  for(int i = 0; i < N; i++) 
  {
    explored[i] = false;
  }

  for(int i = 0; i < N; i++) 
  {
    if (!explored[i])
      dfs(i);
  }

  for(int i = 0; i < N; i++)
  {
    cout << dgraph[topological_sorted[i]].name << endl;
  }

  return 0;
}
