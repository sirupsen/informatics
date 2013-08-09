#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<int> parent_set;

void initSet(size_t size) 
{
  parent_set.clear();
  parent_set.resize(size);

  for(size_t i = 0; i < size; i++)
    parent_set[i] = i;
}

int findSet(size_t i)
{
  return (parent_set[i] == i) ? i : (parent_set[i] = findSet(parent_set[i]));
}

void mergeSet(size_t i, size_t j)
{
  parent_set[findSet(i)] = findSet(j);
}

bool inSameSet(size_t i, size_t j)
{
  return findSet(i) == findSet(j);
}

int main()
{
  int n_test_cases, computers, next_computers, success, error;
  cin >> n_test_cases;

  for(bool newline = false; n_test_cases--; newline = true) {
    if(newline) cout  << endl;
    success = 0, error = 0;
    cin >> computers;
    initSet(computers + 10);

    cin.ignore();

    for(string line; getline(cin, line) && !line.empty();) {
      stringstream input(line);

      char type;
      int i, j;
      input >> type >> i >> j;

      if(type == 'c')
        mergeSet(i, j);
      else if(type == 'q')
        inSameSet(i, j) ? success++ : error++;
    }

    printf("%d,%d\n", success, error);
  }

  return 0;
}
