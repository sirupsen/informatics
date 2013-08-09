#include<sstream>
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstdio>
using namespace std;

#define MAX_N 5
#define MAX_FLOORS 100

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;

int n_elevators;
int target_floor;
int elevator_weights[MAX_N];

vii AdjList;

int dijkstra(size_t target) {
  vector<int> dist(500, INT_MAX);
  dist[0] = 0;

  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0,0));

  while(!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;

    if (d == dist[u]) {
      for(size_t j = 0; j < (size_t)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first)); // push it
        }
      }
    }
  }

  int local_min = INT_MAX;
  for(size_t i = 0; i < n_elevators; ++i)
    local_min = min(dist[target + 100 * i], local_min);

  return local_min;
}

int main()
{
  string tmp;
  while(getline(cin, tmp)) {
    AdjList.clear();
    AdjList.resize(MAX_FLOORS * MAX_N);

    stringstream(tmp) >> n_elevators >> target_floor;

    getline(cin, tmp);
    stringstream times(tmp);
    for(size_t i = 0; i < n_elevators; ++i) 
      times >> elevator_weights[i];

    for(size_t i = 0; i < n_elevators; ++i) {
      getline(cin, tmp);
      stringstream accessible_floors(tmp);

      int elevator_prefix = i * 100;

      // Build adjadency list for local elevator shaft
      // O((100+5) * N)
      int prev_floor_number, floor_number;
      for(size_t j = 0; accessible_floors >> floor_number; ++j) {
        if(j != 0) {
          int weight = (floor_number - prev_floor_number) * elevator_weights[i];

          ii floor(elevator_prefix + floor_number, weight);
          ii prev_floor(elevator_prefix + prev_floor_number, weight);

          AdjList[elevator_prefix + prev_floor_number].push_back(floor); // The previous floor is adjacent to this floor
          AdjList[elevator_prefix + floor_number].push_back(prev_floor); // The current floor is adjacent to previous floor
        }

        // connect with floors in other shafts
        for(size_t k = 0; k < n_elevators; k++) {
          if(k != j) {
            ii other_shaft_floor(k * 100 + floor_number, 60);
            AdjList[elevator_prefix + floor_number].push_back(other_shaft_floor);
          }
        }

        prev_floor_number = floor_number;
      }
    }

    // connect 0 with 100, 200, 300, 400, 500
    // this walk is free
    for(size_t k = 1; k < n_elevators; k++)
      AdjList[0].push_back(ii(100 * k, 0));

    int res = dijkstra(target_floor);

    if (res == INT_MAX) printf("IMPOSSIBLE\n");
    else printf("%d\n", res);
  }

  // size_t floor = 0;
  // for(vii::const_iterator list = AdjList.begin(); list != AdjList.end(); list++) {
  //   if((*list).size() != 0) 
  //     cout << "Index: " << floor << endl;

  //   for(vi::const_iterator adj = (*list).begin(); adj != (*list).end(); adj++) {
  //     cout << adj->first << ":" << adj->second << endl;
  //   }
  //   floor++;
  // }


  return 0;
}
