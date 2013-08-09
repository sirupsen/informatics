#include<cstdio>
#include<set>
#include<cassert>
#include<vector>
#include<cmath>
using namespace std;

struct City
{
  int x, y;
  double s;
  int index;
  bool demo;

  City()
  {
    this->demo = false;
  }
};

struct DisjointSet
{
  vector<int> parent;

  DisjointSet(int n)
  {
    parent.resize(n + 5);

    for(int i = 1; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int find_parent(int i)
  {
    return i == parent[i] ? i : parent[i] = find_parent(parent[i]);
  }

  void merge(int i, int j)
  {
    parent[find_parent(i)] = find_parent(j);
  }
};

double influence(City &a, City &b)
{
  double eucl_dist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

  return b.s / eucl_dist;
}

int main()
{
  int n;
  scanf("%d", &n);

  vector<City> cities(n + 1);
  vector<bool> demo;
  demo.assign(n + 1, false);

  for(int i = 1; i <= n; i++)
  {
    scanf("%d %d %lf", &cities[i].x, &cities[i].y, &cities[i].s);
    cities[i].index = i;
  }

  DisjointSet dset(n);

  for(auto city : cities)
  {
    bool double_dominated = false;
    double dominated = 0;
    City dominator = city;

    for(auto other : cities)
    {
      if(city.index == other.index) continue;

      double infl = influence(city, other);

      // printf("%d -> %d: %.2f ~ %2.f\n", j, i, infl, a->s);

      if(infl > city.s)
      {
        if(dominator.index != city.index && fabs(dominated - infl) < numeric_limits<double>::epsilon())
        {
          double_dominated = true;
        }
        else if (infl > dominated)
        {
          dominated = infl;
          dominator = other;
          double_dominated = false;
        }
      }
    }

    if(double_dominated)
    {
      demo[city.index] = true;
    }
    else if(dominator.index != city.index)
    {
      dset.merge(city.index, dominator.index);
    }
  }

  for(auto city : cities)
  {
    if(city.index == 0)
      continue;

    if(demo[city.index])
    {
      printf("D\n");
    }
    else if(dset.find_parent(city.index) == city.index)
    {
      printf("K\n");
    }
    else
    {
      printf("%d\n", dset.find_parent(city.index));
    }
  }

  return 0;
}
