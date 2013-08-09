#include<cstdio>
#include<queue>
using namespace std;

int main()
{
  size_t N;
  priority_queue< int, vector<int>, greater<int> > pq;

  while(scanf("%ld", &N) && N) {
    for(size_t i = 0; i < N; ++i) {
      int tmp; scanf("%d", &tmp);
      pq.push(tmp);
    }

    int cost = 0;
    while(pq.size() != 1) {
      int num = pq.top(); pq.pop();
      num += pq.top(); pq.pop();
      cost += num;
      pq.push(num);
    }
    pq.pop();

    printf("%d\n", cost);
  }

  return 0;
}
