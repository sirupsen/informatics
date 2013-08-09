#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int c, r;
  cin >> r >> c;

  vector<string> columns(c);

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
    {
      char tmp; cin >> tmp;
      columns[j].push_back(tmp);
    }

  for(auto &column : columns)
    reverse(column.begin(), column.end());

  int top = r;
  int bottom = 0;
  int mid = 0;
  int ans = -1;

  while(top - bottom != 1)
  {
    mid = (top + bottom) / 2;

    vector<string> subset(c);

    for(int i = 0; i < c; i++)
    {
      subset[i] = columns[i].substr(0, mid + 1);
      cout << subset[i] << endl;
    }

    sort(subset.begin(), subset.end());

    bool ok = true;

    for(int i = 0; i < c; i++)
    {
      if (subset[i].compare(subset[i + 1]) == 0)
      {
        ok = false;
      }
    }

    printf("Top: %d, Mid: %d, Bot: %d, Ok: %d\n", top, mid, bottom, (int) ok);

    if(ok)
    {
      ans = mid;
      top = mid;
    }
    else
    {
      bottom = mid;
    }
  }

  cout << "ans is: " << ans << endl;

  if(ans != -1)
    cout << (r - 1) - ans << endl;
  else
    cout << 0 << endl;

  return 0;
}
