/*
ID: sirup1
PROG: gift1
LANG: C++
*/
#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int n_names;
struct person {
  char name[20];
  int balance;
};
person persons[100];

map<string, int> name_to_id;

void input()
{

  FILE * c_file;
  c_file = fopen("gift1.in", "r");

  fscanf(c_file, "%d", &n_names);

  for(int i = 0; i < n_names; i++) {
    fscanf(c_file, "%s", persons[i].name);
    name_to_id[persons[i].name] = i; // map name to id
  }

  for(int i = 0; i < n_names; i++) {
    char current_giver[20];
    fscanf(c_file, "%s", current_giver);
    printf("giver: %s\n", current_giver);

    int amount;
    fscanf(c_file, "%d", &amount);
    printf("amount: %d\n", amount);

    int n_gift_receivers;
    fscanf(c_file, "%d", &n_gift_receivers);
    printf("receivers: %d\n", n_gift_receivers);

    // withdraw amount from givers account
    persons[name_to_id[current_giver]].balance -= amount;

    int set = 0;
    int received_each;
    int residue;

    if (amount > 0 && n_gift_receivers > 0) {
      received_each = amount / n_gift_receivers;
      residue = amount % n_gift_receivers;
      printf("\n%d: %s with %d to spare gives %d to:\n", i, current_giver, residue, received_each);

      // add the residue back to the givers account
      persons[name_to_id[current_giver]].balance += residue;
      set = 1;
    }

    // // add the gifts to the receivers
    for(int j = 0; j < n_gift_receivers; j++) {
      char current_receiver[20];
      fscanf(c_file, "%s", current_receiver);
      printf("\t%s\n", current_receiver);

      if (received_each > 0) {
        if (set == 1) persons[name_to_id[current_receiver]].balance += received_each;
      }
    }
  }
}

void output()
{
  FILE * c_file;
  c_file = fopen("gift1.out", "w");

  for(int i = 0; i < n_names; i++)
    fprintf(c_file, "%s %d\n", persons[i].name, persons[i].balance);
}

void solve()
{
}

int main(int argc, char *argv[])
{
  input();
  solve();
  output();
  
  return 0;
}
