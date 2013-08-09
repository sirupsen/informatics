#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  int adrian_a[] = {'A', 'B', 'C'};
  int a_counter = 0;
  vector<int> adrian(adrian_a, adrian_a + sizeof(adrian_a));

  int bruno_a[] = {'B', 'A', 'B', 'C'};
  int b_counter = 0;
  vector<int> bruno(bruno_a, bruno_a + sizeof(bruno_a));
  bruno.resize(4);

  int goran_a[] = {'C', 'C', 'A', 'A', 'B', 'B'};
  int g_counter = 0;
  vector<int> goran(goran_a, goran_a + sizeof(goran_a));

  int n; cin >> n;

  string results;
  cin >> results;

  for(size_t i = 0; i < results.size(); i++) {
    if(results[i] == adrian[i % 3]) {
      a_counter++;
    }

    if(results[i] == bruno[i % 4]) {
      b_counter++;
    }

    if(results[i] == goran[i % 6]) {
      g_counter++;
    }
  }

  int very_max = max(max(a_counter, b_counter), g_counter);
  printf("%d\n", very_max);

  if(very_max == a_counter) printf("Adrian\n");
  if(very_max == b_counter) printf("Bruno\n");
  if(very_max == g_counter) printf("Goran\n");
}
