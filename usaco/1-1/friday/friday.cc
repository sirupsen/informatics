/*
TASK: friday
USERNAME: sirup1
LANG: C++
*/
#include <cstdio>
#include <cassert>

int n_years;

int months[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int fridays[7];

int daysInFeb(int year) 
{
  if (year % 4 == 0)
    if (year % 100 == 0)
      if (year % 400 == 0) 
        return 29;
      else
        return 28;
    else
      return 29;

  return 28;
}

int toWeekday(int number)
{
  return number % 7;
}

void solve()
{
  int prev = toWeekday(12);

  // First friday 13th
  fridays[prev] += 1;

  int first = true;

  // Loop through each year following 1900
  for(int current_year = 0; current_year < n_years; current_year++) {
    // Loop through each month of that year
    int current_month = 0;
    if (first) current_month = 1;

    for(; current_month < 12; current_month++) {
      int days_in_month = months[current_month - 1];

      if ((current_month - 1) == -1) days_in_month = months[11];
      if (days_in_month == -1) days_in_month = daysInFeb(1900 + current_year);

      int weekday = (prev + days_in_month) % 7;

      assert(weekday > -1 && weekday < 7);
      assert(days_in_month != 0 && days_in_month < 32);

      prev = weekday;
      fridays[weekday] += 1;
    }

    first = false;
  }
}

void input()
{
  FILE * file;

  file = fopen("friday.in", "r");
  fscanf(file, "%d", &n_years);
}

int main()
{
  input();
  solve();

  FILE * file;

  file = fopen("friday.out", "w");
  fprintf(file, "%d ", fridays[5]);
  fprintf(file, "%d ", fridays[6]);
  fprintf(file, "%d ", fridays[0]);
  fprintf(file, "%d ", fridays[1]);
  fprintf(file, "%d ", fridays[2]);
  fprintf(file, "%d ", fridays[3]);
  fprintf(file, "%d\n", fridays[4]);

  return 0;
}
