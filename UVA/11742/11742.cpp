#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

struct Constraint {
  int first_person;
  int second_person;
  int constraint;
};

int n_persons, n_constraints;

bool satisfies_condition(int arrangement[], Constraint condition)
{
  int first_person_index;
  for(int i = 0; i < n_persons; i++)
    if(arrangement[i] == condition.first_person) first_person_index = i;

  int second_person_index;
  for(int i = 0; i < n_persons; i++)
    if(arrangement[i] == condition.second_person) second_person_index = i;

  int difference = abs(first_person_index - second_person_index);
  // cout << difference << endl;

  if (condition.constraint < 0) {
    return abs(condition.constraint) <= difference;
  } else {
    return abs(condition.constraint) >= difference;
  }
}

int main()
{
  while(scanf("%d %d", &n_persons, &n_constraints) == 2) {
    Constraint conditions[22];

    if(n_persons == 0 && n_constraints == 0) return 0;

    for(int i = 0; i < n_constraints; i++) {
      int person_1, person_2, constraint;
      scanf("%d %d %d", &person_1, &person_2, &constraint);

      Constraint condition = {person_1, person_2, constraint};
      conditions[i] = condition;
    }

    int permute_me[21];
    int count = 0; 

    for(int i = 0; i < n_persons; i++)
      permute_me[i] = i;

    do {
      // for(int i = 0; i < n_persons; i++)
      //   cout << permute_me[i];
      // cout << endl;

      bool all = true;
      for(int i = 0; i < n_constraints; i++)
        if (!satisfies_condition(permute_me, conditions[i])) all = false;

      if(all) count++;
    } while (next_permutation(permute_me, permute_me + n_persons));

    cout << count << endl;
  }

  return 0;
}
