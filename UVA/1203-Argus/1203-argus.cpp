#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

struct Event {
  int period, t, output;

  Event() {}

  Event(int period, int t, int output) 
  {
    this->period = period;
    this->t = t;
    this->output = output;
  }

  bool operator<(Event const &b) const
  {
    if(this->t == b.t) return this->output > b.output;
    return this->t > b.t;
  }

  Event next() 
  {
    return Event(period, t + period, output);
  }
};

int main()
{
  priority_queue<Event> pq;

  string r;
  int k, output, period;

  while(cin >> r) {
    if(r == "#") break;

    cin >> output >> period;
    pq.push(Event(period, period, output));
  }

  cin >> k;

  while(k--) {
    Event top = pq.top(); pq.pop();
    pq.push(top.next());

    cout << top.output << endl;
  }

  return 0;
}
