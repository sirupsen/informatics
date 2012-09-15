#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<string, int> people;
vector<int> parent_set;
vector<int> set_size;

int n_people = 0;

void initSet(int friendships)
{
  int max = friendships * 2;

  parent_set.clear();
  parent_set.resize(max);

  set_size.assign(max, 1);

  while(max--) parent_set[max] = max;
}

int findSet(int friend1)
{
  return (friend1 == parent_set[friend1]) ? friend1 : (parent_set[friend1] = findSet(parent_set[friend1]));
}

bool inSameSet(int friend1, int friend2)
{
  return findSet(friend1) == findSet(friend2);
}

void mergeSet(int friend1, int friend2)
{
  if(!inSameSet(friend1, friend2)) {
    set_size[findSet(friend2)] += set_size[findSet(friend1)];
    parent_set[findSet(friend1)] = findSet(friend2);
  }
}

int setSize(int friend1)
{
  return set_size[findSet(friend1)];
}

void initializeSet(string &friend1) {
  if(people.find(friend1) == people.end()) {
    people[friend1] = n_people;
    n_people++;
  }
}

int main()
{
  int n_test_cases;
  scanf("%d", &n_test_cases);

  while(n_test_cases--) {
    int n_friendships_formed, n_people = 0;
    scanf("%d", &n_friendships_formed);

    initSet(n_friendships_formed);

    while(n_friendships_formed--) {
      char friend1c[21], friend2c[21];
      scanf("%s %s", friend1c, friend2c);
      string friend1(friend1c), friend2(friend2c);

      initializeSet(friend1);
      initializeSet(friend2);

      int f1 = people[friend1];
      mergeSet(f1, people[friend2]);

      cout << setSize(findSet(f1)) << endl;
    }
  }

  return 0;
}
