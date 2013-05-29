#include<iostream>
#include<climits>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

struct Time {
  unsigned int time;

  Time(unsigned int hour, unsigned int minute)
  {
    this->hour = hour;
    this->minute = minute;
    this->time = from_hour_and_minute(hour, minute);
  }

  Time()
  {
  }

  unsigned int travel_time(Time &departure)
  {
    return this->time - departure.time;
  }

  void from_input()
  {
    int h, m; cin >> h >> m;
    this->hour = h;
    this->minute = m;
    this->time = from_hour_and_minute(h, m);
  }

  private:
  void from_hour_and_minute(unsigned int hour, unsigned int minute)
  {
    return hour * 60 + minute;
  }
};

struct Connection {
  Location *origin, *destination;
  Time departure, arrival;

  unsigned int travel_time()
  {
    return this->arrival.difference(this->departure);
  }
};

struct Location {
  unsigned int id;
  vector<Connection> connections;
  vector<Connection> reverse_connections;

  Location(unsigned int _id)
  {
    this->id = _id;
  }

  Location()
  {
  }

  unsigned int shortest_travel_time_to(Location &destination)
  {
    priority_queue<pair<int, Connection> > pq;
    vector<unsigned int> dist(50, INT_MAX);

    pq.push(make_pair(0, this));

    while(!pq.empty())
    {
      pair<int, Connection> v = pq.top(); pq.pop();
      int weight = v.first;

      if(weight <= dist[v.second.id])
      {
        for(auto &connection : v.second.connections)
        {
          if(v.second.time.time >= connection->departure.time)
          {
            unsigned int new_weight = weight + connection.travel_time();
            pq.push(make_pair(v.first + new_weight, *(connection->destination)));
          }
        }
      }
    }

    return dist[destination.id];
  }
};

struct Solver {
  size_t n_locations, n_connections;
  Time start, end;

  vector<Location> locations;

  void solve()
  {
    cin >> n_locations >> n_connections;
    construct_locations();
    read_connections();
    read_restrictions();
  }

  private:
  void read_restrictions()
  {
    start.from_input();
    end.from_input();
  }

  void construct_locations()
  {
    locations.resize(this->n_locations);

    for(int i = 0; i < this->n_locations)
    {
      locations[i].id = i;
    }
  }

  void read_connections()
  {

    for(size_t i = 0; i < n_connections; i++)
    {
      build_connection();
    }
  }

  void build_connection()
  {
    int a, b, h_dep, m_dep, h_arr, m_arr;
    cin >> a >> b;

    Connection connection;
    connection.origin      = &locations[a];
    connection.destination = &locations[b];

    connection.departure.from_input();
    connection.arrival.from_input();

    locations[a].connections.push_back(connection);
    locations[b].reverse_connections.push_back(connection);
  }
};

int main()
{
  return 0;
}
