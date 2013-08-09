#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

typedef long long int;

int main()
{
  int n_test_cases; 
  scanf("%d", &n_test_cases);

  for(int test_case = 1; test_case <= n_test_cases; test_case++) {
    int n, k;
    int a,b,c,r;

    scanf("%d %d", &n, &k);
    scanf("%d %d %d %d", &a, &b, &c, &r);

    map<int,int> count;

    vector<int> m;
    m.resize(k + 5);

    queue<int> q;

    vector<int> repeating;
    repeating.resize(k + 5);

    m[0] = a;

    for(int i = 1; i < k; i++) {
      m[i] = (b * m[i - 1] + c) % r;

      count[m[i]]++;
      q.push(m[i]);

      // cout << m[i] << " ";
    }

    int t = 0;

    for(int i = 0; i < k; i++) {
      for(int j = t;;j++) {
        if(count[j] == 0 || j >= k) {
          int front = q.front(); q.pop();
          count[front]--;

          repeating[i] = j;
          q.push(j);
          count[j]++;

          // cout << j << endl;

          if(count[front] == 0) {
            t = min(front, j);
          } else {
            t = j;
          }
          break;
        }
      }
    }

    // int i = 0;
    // for(auto r : repeating) {
    //   cout << i << " : " << r << endl;
    //   i++;
    // }

    // printf("Case %d: %d\n", test_case, ((n - 1) % k) - 1);
    // printf("Case %d: %d\n", test_case, (n % k) - 2);
    // printf("Case %d: %d\n", test_case, ((n - 1 + k) % k) + 2);
    printf("Case %d: %d\n", test_case, repeating[(n - k) % (k + 1)]);
    // printf("Case %d: %d\n", test_case, (n + k) % (k - 1));
    // printf("Case %d: %d\n", test_case, (n + k) % (k - 1));
    // printf("Case %d: %d\n", test_case, (n + 1) % (k + 1));
  }

  return 0;
}
