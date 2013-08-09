#include<cstdio>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 1005

struct Bead {
  unsigned int first;
  unsigned int second;
};

struct Adjadency {
  size_t index;
  unsigned int color;
  bool visited;
};

struct BeadGraph {
  vector<vector<Adjadency> > AdjList;
  list<size_t> cyc;
  Bead beads[MAX_N];

  void 
  read_input(int &n) 
  {
    for(size_t i = 0; i < n; ++i)
      scanf("%d %d", &beads[i].first, &beads[i].second);

    build_adjadency_list(n);
  }

  bool
  beads_match(Bead &first, Bead &second)
  {
    return first.first == second.first || 
           first.first == second.second ||
           first.second == second.second ||
           first.second == second.first;
  }

  void
  build_adjadency_list(int &n)
  {
    AdjList.resize(n + 5);

    for(size_t i = 0; i < n; ++i)
      for(size_t j = i + 1; j < n; ++j)
        if(beads_match(beads[i], beads[j])) {
          Adjadency p = {j, false};
          AdjList[i].push_back(p);

          Adjadency q = {i, false};
          AdjList[j].push_back(q);
        }
  }

  void 
  euler_tour(list<size_t>::iterator i, size_t u)
  {
    printf("At %ld\n", u);

    for(size_t j = 0; j < (size_t) AdjList[u].size(); ++j) {
      Adjadency v = AdjList[u][j];

      if(!v.visited) {
        AdjList[u][j].visited = true;

        // Remove bi-directional edge
        for(size_t k = 0; k < (size_t)AdjList[v.index].size(); ++k) {
          Adjadency uu = AdjList[v.index][k];

          if(uu.index == u) {
            AdjList[v.index][k].visited = true;
          }
        }

        euler_tour(cyc.insert(i, u), v.index);
      }
    }
  }

  void 
  print_euler_tour()
  {
    cyc.clear();

    size_t i = 0;
    for(vector<vector<Adjadency> >::iterator list = AdjList.begin(); list != AdjList.end(); list++) {
      printf("Vertex: %ld\n", i);

      for(vector<Adjadency>::iterator adjadent = (*list).begin(); adjadent != (*list).end(); adjadent++) {
        printf("Adjacent to: %ld\n", adjadent->index);
      }

      printf("\n");
      i++;
    }

    euler_tour(cyc.begin(), 0);

    // for(size_t i = 0; i < 0; )

    for(list<size_t>::iterator it = cyc.begin(); it != cyc.end(); ++it)
      printf("%ld\n", *it);
  }
};

int main()
{
  BeadGraph bead_graph;
  int n; scanf("%d", &n);
  bead_graph.read_input(n);
  bead_graph.print_euler_tour();

  return 0;
}
