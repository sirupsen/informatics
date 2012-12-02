#include<iostream>
#include<cstdio>
#include<utility>
#define MAX_N 100005
using namespace std;

int main()
{
  int grades[6], n;
  pair<int, int> tables[MAX_N];

  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    scanf("%d %d", &tables[i].first, &tables[i].second);

  int local_max = 0, local_max_grade = 0;

  for(int i = 0; i < n; i++) {
    for(int grade = 1; grade <= 5; grade++) {
      if (tables[i].first == grade || tables[i].second == grade) {
        grades[grade]++;

        if(grades[grade] > local_max || (grades[grade] == local_max && grade < local_max_grade)) {
          local_max = grades[grade];
          local_max_grade = grade;
        }
      } else {
        grades[grade] = 0;
      }
    }
  }

  printf("%d %d\n", local_max, local_max_grade);

  return 0;
}
