#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Detector {
  int pos;
  int calls;

  Detector() {}

  Detector(int pos, int calls)
  {
    this->pos = pos;
    this->calls = calls;
  }

  bool operator()(const Detector &a, const Detector &b) const
  {
    return a.pos < b.pos;
  }
};

int main()
{
  int n, m;

  scanf("%d %d", &n, &m);

  vector<Detector> detectors(n + 1);

  for(int i = 0; i < n; i++)
    scanf("%d %d", &detectors[i].pos, &detectors[i].calls);

  detectors[n] = Detector(m, 0);

  sort(detectors.begin(), detectors.end(), Detector());

  long long res = 0;

  for(int i = 1; i <= n; i++)
    if(detectors[i - 1].calls > detectors[i].calls)
      res += detectors[i - 1].calls - detectors[i].calls;

  printf("%lld\n", res);

  return 0;
}
