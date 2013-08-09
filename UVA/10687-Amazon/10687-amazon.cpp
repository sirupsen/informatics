#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<climits>
using namespace std;

struct Coordinate {
  int x;
  int y;
};

struct UnionSet {
  vector<int> parent_set;
  vector<int> size_set;
  vector<int> connections;

  UnionSet(size_t size) {
    parent_set.resize(size + 5);
    size_set.assign(size + 5, 1);
    connections.assign(size + 5, 0);

    for(size_t i = 0; i < size + 5; i++)
      parent_set[i] = i;
  }

  size_t parent(size_t i)
  {
    return (parent_set[i] == i) ? i : (parent_set[i] = parent(parent_set[i]));
  }

  void merge(size_t i, size_t j)
  {
    if(parent(i) != parent(j)) {
      size_set[parent(j)] += size_set[parent(i)];
      parent_set[parent(i)] = parent(j);
    }
  }
};

struct Candidate {
  double distance;
  double x;
  double y;
  size_t index;
};

double euclidian_distance(Coordinate first, Coordinate second)
{
  double dx = first.x - second.x;
  double dy = first.y - second.y;
  return dx * dx + dy * dy;
}

int main()
{
  size_t n_stations;
  while(scanf("%ld", &n_stations) == 1) {
    if(n_stations == 0) return 0;

    vector<Coordinate> stations;
    UnionSet us(n_stations);

    for(size_t i = 0; i < n_stations; ++i) {
      Coordinate station;
      scanf("%d %d", &station.x, &station.y);
      stations.push_back(station);
    }

    short connections[n_stations + 5];
    for(size_t i = 0; i < n_stations + 5; i++)
      connections[i] = 0;

    // For each station
    // O(N^2)
    for(size_t i = 0; i < n_stations; ++i) {
      Candidate best = {INT_MAX, 0, 0, 0};
      Candidate second_best = {INT_MAX, 0, 0, 0};

      // Find the two nearest
      for(size_t j = 0; j < n_stations; ++j) {
        if(j == i) continue;
        Candidate new_candidate = {
          euclidian_distance(stations[j], stations[i]),
          stations[j].x,
          stations[j].y,
          j
        };

        // printf("Distance from %d to %d: %.3f\n", i, j, euclidian_distance(stations[i], stations[j]));

        if(new_candidate.distance < best.distance) {
          second_best = best;
          best = new_candidate;
        } else if(new_candidate.distance < second_best.distance) {
          second_best = new_candidate;
        } else if(new_candidate.distance == best.distance) { // tie, compare by x/y
          if(new_candidate.x < best.x || new_candidate.y < best.y) { // more westly/southly
            second_best = best;
            best = new_candidate;
          }
        } else if(new_candidate.distance == second_best.distance) {
          if(new_candidate.x < second_best.x || new_candidate.y < second_best.y) { // more westly/southly
            second_best = new_candidate;
          }
        }
      }

      // printf("Merge %d and %d into %d\n", best.index, second_best.index, i);

      // Merge these into set with first one
      // ~O(1)
      
      if (connections[best.index] < 2) {
        us.merge(i, best.index);
        connections[best.index]++;
      }

      if(connections[second_best.index] < 2) {
        us.merge(i, second_best.index);
        connections[second_best.index]++;
      }

      connections[i] = 2;
    }

    if(us.size_set[us.parent(0)] == n_stations) printf("All stations are reachable.\n");
    else printf("There are stations that are unreachable.\n");
  }

  return 0;
}
