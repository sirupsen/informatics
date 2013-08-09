#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Building{
  int height;
  int width;
};

vector<Building> buildings;

int LIS[10000];
int LDS[10000];

int lds(int i) {
  if(LDS[i] != -1) return LDS[i];

  int local_max = 0;

  for(size_t j = 0; j < i; ++j) {
    if (buildings[j].height > buildings[i].height)
      local_max = max(local_max, lds(j));
  }

  return LDS[i] = buildings[i].width + local_max;
}

int lis(int i) {
  if(LIS[i] != -1) return LIS[i];

  int local_max = 0;

  for(size_t j = 0; j < i; ++j) {
    if (buildings[j].height < buildings[i].height)
      local_max = max(local_max, lis(j));
  }

  return LIS[i] = buildings[i].width + local_max;
}

int main()
{
  int n_tests; cin >> n_tests;

  for(size_t i = 0; i < n_tests; ++i) {
    int n_buildings; cin >> n_buildings;

    // reset for new test case
    memset(LIS, -1, sizeof LIS);
    memset(LDS, -1, sizeof LDS);
    buildings.clear();

    // read heights
    for(size_t j = 0; j < n_buildings; ++j) {
      Building new_building;
      cin >> new_building.height;
      buildings.push_back(new_building);
    }

    // read widths
    for(size_t j = 0; j < n_buildings; ++j)
      cin >> buildings[j].width;

    int best_lis = 0;
    for(size_t j = 0; j < n_buildings; ++j)
      best_lis = max(best_lis, lis(j));

    int best_lds = 0;
    for(size_t j = 0; j < n_buildings; ++j)
      best_lds = max(best_lds, lds(j));

    if (best_lds > best_lis) {
      cout << "Case " << i + 1 << ". Decreasing (" << best_lds << "). Increasing (" << best_lis << ")." << endl;
    } else {
      cout << "Case " << i + 1 << ". Increasing (" << best_lis << "). Decreasing (" << best_lds << ")." << endl;
    }
  }

  return 0;
}
