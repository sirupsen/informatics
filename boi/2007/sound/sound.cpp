#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

int main()
{
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);

  vector<int> samples;
  samples.resize(n + 5);

  for(int i = 0; i < n; i++)
    scanf("%d", &samples[i]);

  deque<pair<int, int> > min;
  deque<pair<int, int> > max;

  for(int i = 0; i < n; i++) {
    // MINIMUM WINDOW
    while(!min.empty() && min.back().first >= samples[i])
      min.pop_back();

    min.push_back(make_pair(samples[i], i));

    while(min.front().second <= i - m)
      min.pop_front();

    // MAXIMUM WINDOW
    while(!max.empty() && max.back().first <= samples[i])
      max.pop_back();

    max.push_back(make_pair(samples[i], i));

    while(max.front().second <= i - m)
      max.pop_front();

    if(max.front().first - min.front().first <= c && i + 1 >= m)
      printf("%zd\n", i - m + 2);
  }

  return 0;
}
