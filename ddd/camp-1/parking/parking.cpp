#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
#include<utility>
using namespace std;

int N, M, W;
vector<int> state;
vector<int> final;

vector<int> counting_sort(vector<int> &a, int &types) 
{
  vector<int> b(a.size());
  vector<int> count(types + 1, 0);

  for(size_t i = 0; i < a.size(); i++)
    count[a[i]]++;

  int total = 0;
  for(size_t i = 0; i < count.size(); i++) {
    int previous = count[i];
    count[i] = total;
    total += previous;
  }

  for(size_t i = 0; i < a.size(); i++) {
    int n = a[i];
    b[count[n]] = n;
    count[n]++;
  }

  return b;
}

int first_dif()
{
  for(int i = 0; i < state.size(); i++)
    if(state[i] != final[i]) return i;

  return -1;
}

int find_slot(const int type)
{
  int upper = N, lower = 0;

  while(upper != lower) {
    int mid = (upper + lower) / 2;
    int local = final[mid];
    
    if(type == local) return mid;
    else if(type > local) lower = mid;
    else upper = mid;
  }

  return -1;
}

int find_empty_slot(const int type, const vector<int> &occupied)
{
  int mid = find_slot(type);
  assert(mid != -1);

  // Go right
  for(int i = mid; final[i] == type && i < final.size(); i++)
    if(state[i] != type && occupied[i] == -1)
      return i;

  // Go left
  for(int i = mid; final[i] == type && i >= 0; i--)
    if(state[i] != type && occupied[i] == -1)
      return i;

  return -1;
}

int swaps;

void inner()
{
  int dif = first_dif();

  vector<vector<pair<int, int> > > global_switches;

  while(dif != -1) {
    int left = W;

    // printf("Going in with dif: %d\n", dif);

    vector<pair<int, int> > round_switches;

    while(left >= 2 && dif != -1) {
      vector<int> occupied(N, -1);
      vector<int> workers(W + 5, -1);

      int worker = 1;
      workers[worker] = dif;
      occupied[dif] = worker;

      vector<pair<int, int> > switches;

      bool early = false;

      for(; left > 1; left--) {
        int target = state[workers[worker]];
        int next = find_empty_slot(target, occupied);

        // We're done here.. nothing to switch with.
        if(next == -1) {
          early = true;
          break;
        }

        worker++;
        workers[worker] = next;
        occupied[next] = worker;

        switches.push_back(make_pair(workers[worker - 1], workers[worker]));
      }

      int next = state[workers[worker]];

      for(int i = switches.size() - 1; i >= 0; i--) {
        pair<int, int> s = switches[i];
        swap(state[s.first], state[s.second]);
      }
      
      state[workers[1]] = next;
      switches.push_back(make_pair(workers[worker], workers[1]));
      left--;

      for(int i = 0; i < switches.size(); i++)
        round_switches.push_back(switches[i]);

      dif = first_dif();
    }

    global_switches.push_back(round_switches);
  }

  printf("%ld\n", global_switches.size());
  for(int i = 0; i < global_switches.size(); i++) {
    printf("%ld ", global_switches[i].size());

    for(int j = 0; j < global_switches[i].size(); j++) {
      pair<int, int> s = global_switches[i][j];
      printf("%d %d ", s.first + 1, s.second + 1);
    }

    printf("\n");
  }
}

int main() 
{
  scanf("%d %d %d", &N, &M, &W);

  state.resize(N);

  for(int i = 0; i < N; i++)
    scanf("%d", &state[i]);

  final = state;
  sort(final.begin(), final.end());

  for(size_t i = 0; i < final.size(); i++)
    printf("%d ", final[i]);
  printf("\n");

  inner();

  return 0;
}

