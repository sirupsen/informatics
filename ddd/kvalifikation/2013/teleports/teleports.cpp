#include<cstdio>
#include<cassert>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
using namespace std;

#define MAX_N 50005

struct Island {
  vector<size_t> dest;
  vector<int> in;
  vector<bool> state;
  size_t size;

  Island(size_t n, bool initial_state)
  {
    this->size = n;
    this->dest.resize(n + 5);
    this->in.assign(n + 5, 0);
    this->state.assign(n + 5, initial_state);
  }
};

int main()
{
  int m,n;
  scanf("%d %d", &m, &n);

  Island bornholm(m, 0);
  Island gotland(n, 1);

  for(int i = 1; i <= bornholm.size; i++) {
    scanf("%ld", &bornholm.dest[i]);
    gotland.in[bornholm.dest[i]]++;
  }

  for(int i = 1; i <= n; i++) {
    scanf("%ld", &gotland.dest[i]);
    bornholm.in[gotland.dest[i]]++;
  }

  stack<int> s;

  for(int i = 1; i <= bornholm.size; i++)
    if(bornholm.in[i] == 0) s.push(i);

  while(!s.empty()) {
    size_t useless = s.top(); s.pop();
    size_t dest = bornholm.dest[useless];

    bornholm.state[useless] = 1;
    gotland.state[dest]     = 0;

    size_t third = gotland.dest[dest];

    bornholm.in[third]--;

    if(bornholm.in[third] <= 0 && bornholm.state[third] == 0)
      s.push(third);
  }

  for(int i = 0; i < gotland.size; i++) {
    size_t dest = gotland.dest[i];

    if(gotland.state[i] == 1 && bornholm.state[dest] == 1) {
      printf("fuck @ %d which sends to %d\n", i, (int)dest);
    }
  }

  for(int i = 1; i <= bornholm.size; i++)
    printf("%d", (int)bornholm.state[i]);

  printf("\n");

  for(int i = 1; i <= gotland.size; i++)
    printf("%d", (int)gotland.state[i]);

  printf("\n");

  return 0;
}
