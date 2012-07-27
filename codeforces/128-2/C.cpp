#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Client {
  int low;
  int high;
  int original_index;
};

int n, d;
int a, b;

bool size_sort(Client fir, Client sec) {
  return ((fir.low * a) + (fir.high * b)) < ((sec.low * a) + (sec.high * b));
}

int main()
{

  cin >> n >> d;
  cin >> a >> b;

  vector<Client> clients;
  vector<Client> served_clients;

  for(int i = 0; i < n; i++) {
    Client new_client;
    cin >> new_client.low;
    cin >> new_client.high;
    new_client.original_index = i + 1;

    clients.push_back(new_client);
  }

  sort(clients.begin(), clients.end(), size_sort);

  vector<Client>::iterator it;
  for (it = clients.begin(); it != clients.end(); ++it) {
    int client_cost = it->low * a + it->high * b;

    if (d - client_cost >= 0) {
      served_clients.push_back(*it);
      d -= client_cost;
    } else {
      break;
    }
  }

  cout << served_clients.size() << endl;
  for(it = served_clients.begin(); it != served_clients.end(); it++) {
    cout << it->original_index << " ";
  }

  cout << endl;

  return 0;
}
