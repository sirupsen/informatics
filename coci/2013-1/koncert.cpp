#include<iostream>
#include<vector>
using namespace std;
vector<bool> guy_ticket;

int main() {

  int n_guys, n_ticket_guys;
  cin >> n_guys >> n_ticket_guys;

  guy_ticket.assign(n_ticket_guys + 5, false);

  for(int i = 0; i < n_ticket_guys; i++) {
    int ticket_guy; cin >> ticket_guy;
    guy_ticket[ticket_guy - 1] = true;
  }

  int n_girls, n_ticket_girls;
  cin >> n_girls >> n_ticket_girls;

  int current_guy = 0;
  for(int i = 0; i < n_ticket_girls && current_guy < n_guys; i++) {
    int ticket_girl; cin >> ticket_girl;

    // find next guy who needs a ticket
    while(guy_ticket[current_guy]) current_guy++;
    if(current_guy >= n_guys) break;

    cout << "GIVE GIRL " << ticket_girl << " GUY " << current_guy + 1 << endl;
    guy_ticket[current_guy] = true;
  }

  for(int i = 0; i < n_guys; i++)
    cout << "ENTER GUY " << i + 1 << endl;
}
