#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 100005

struct Mast {
  unsigned int height;
  unsigned int sails;

  bool operator() (Mast a, Mast b) 
  { 
    return a.height < b.height;
  }
};

struct Masts {
  vector<Mast> masts;
  vector<int> flags;

  unsigned int n, max_mast_height;

  Masts() 
  {
    masts.resize(MAX_N);
    flags.resize(MAX_N, 0);
  }

  void read_input() 
  {
    scanf("%d", &n);

    for(size_t i = 0; i < n; ++i) {
      Mast new_mast;
      scanf("%d %d", &new_mast.height, &new_mast.sails);
      masts.push_back(new_mast);
    }
  }

  void sort_input() 
  {
    Mast sorter_mast;
    sort(masts.begin(), masts.end(), sorter_mast);
    max_mast_height = masts[0].height;
  }

  void output_flags()
  {
    for(vector<int>::const_iterator flag = flags.begin(); flag != flags.begin() + n; flag++)
      printf("%d ", *flag);

    printf("\n");
  }

  void minimum_efficiency()
  {
    size_t last_iterator = 0;
    for(vector<Mast>::const_iterator mast = masts.begin(); mast != masts.end(); ++mast) {
      if(mast->height == 0) break;

      size_t start_index = last_iterator % mast->height;
      size_t end_index = (start_index + mast->sails) % mast->height;

      printf("Mast height: %d, flags: %d, start: %ld, end: %ld\n", mast->height, mast->sails, start_index, end_index);

      flags[start_index] += 1;
      flags[end_index] -= 1;

      output_flags();

      last_iterator = end_index;
    }
  }
};

int main()
{
  Masts masts;

  masts.read_input();
  masts.sort_input();
  masts.minimum_efficiency();

  // printf("Highest mast: %d\n", masts.max_mast_height);

  return 0;
}
