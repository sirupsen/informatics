#include<iostream>
#include<vector>
using namespace std;

int best_try = 101;
vector<vector<bool> > lights(11, 0);

void output_lights()
{
  for(size_t y = 0; y < 10; ++y) {
    for(size_t x = 0; x < 10; ++x)
      cout << lights[y][x];
    cout << endl;
  }
}

int main()
{
  string name;

  while(true) {
    cin >> name;
    if(name == "end") return 0;

    char light;
    for(size_t y = 0; y < 10; ++y) {
      for(size_t x = 0; x < 10; ++x) {
        cin >> light;
        lights[y][x] = (light == 'O' ? 1 : 0);
      }
    }

    output_lights();
  }

  return 0;
}
