#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

#define MAX_N 50005

struct Portal {
  size_t target;
  unsigned int in;
  bool state; 
}

struct Island {
  vector<size_t> dest;
  vector<size_t> in;
  vector<bool> state;
  size_t size;

  Island(size_t n, bool initial_state)
  {
    this->size = n;
    this->dest.resize(n + 1);
    this->in.assign(n + 1, 0);
    this->state.assign(n + 1, initial_state);
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

  queue<int> q;

  for(int i = 1; i <= bornholm.size; i++)
    if(!bornholm.in[i]) q.push(i);

  while(!q.empty()) {
    int useless = q.front(); q.pop();
    int dest = bornholm.dest[useless];

    bornholm.state[useless] = 1;
    gotland.state[dest]     = 0;


    if(--bornholm.in[gotland.dest[dest]] == 0)
      q.push(gotland.dest[dest]);
  }

  for(int i = 1; i <= bornholm.size; i++)
    printf("%d ", (int)bornholm.state[i]);

  printf("\n");

  for(int i = 1; i <= gotland.size; i++)
    printf("%d ", (int)gotland.state[i]);

  printf("\n");

  return 0;
}
