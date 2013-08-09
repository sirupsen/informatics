#include<iostream>
using namespace std;

char original_program[105];
int n;

void run(int i, int j)
{
  // cout << i << ".." << j << endl;
  // if(i == j) return;

  int k,p;

  int len = j - i + 1;

  char copy[105];

  for(k = i - 1, p = 0; k < j; k++, p++)
    copy[p] = original_program[k];

  int cp = 0;
  int dp = 1;

  int table[10];
  for(int k = 0; k < 10; k++)
    table[k] = 0;

  // for(int k = 0; k < j; k++)
  //   cout << copy[k];
  // cout << endl;

  int d = -1;

  while(cp < len && cp >= 0) {
    if(cp > 100) break;

    if(copy[cp] == 'I') {
      cp += dp;
    } else if (copy[cp] != '<' && copy[cp] != '>' && copy[cp] != 'I') { // digit
      d = -1;

      table[copy[cp] - '0'] += 1;
      copy[cp] == '0' ? copy[cp] = 'I' : copy[cp] -= 1;

      cp += dp;
    } else if (copy[cp] == '<' || copy[cp] == '>') {
      if(d != -1) copy[d] = 'I';

      copy[cp] == '<' ? dp = -1 : dp = 1;
      d = cp;

      cp += dp;
    }
  }

  for(int i = 0; i < 10; i++)
    cout << table[i] << " ";

  cout << endl;
}

int main() 
{
  int q;
  cin >> n >> q;

  for(int i = 0; i < n; i++)
    cin >> original_program[i];

  for(int i = 0; i < q; i++) {
    int start,stop;
    cin >> start >> stop;

    run(start, stop);
  }

  return 0;
}
