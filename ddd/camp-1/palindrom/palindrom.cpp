#include<iostream>
#include<string>
using namespace std;

list<char> original;

void input()
{
  int n;
  string s;
  cin >> n >> s;

  for(int i = 0; i < s.size(); i++)
  {
    original.push_back(s[i]);
  }
}

// Either insert, or don't insert..
void recurse(list<char>::iterator left, list<char>::iterator right,
    list<char>::iterator original)
{
  if(*left == *right)
  {
    recurse(left - 1, right + 1, original);
  }

  if(*left != *right)
  {
    list<char>>:iterator right_insert = original.insert(left - 1, *right);
    recurse(left, right_insert, original)
    original.erase(right_insert);

    list<char>>:iterator left_insert = original.insert(right - 1, *left);
    recurse(left_insert, right, original)
    original.erase(left_insert);

    list<char>>:iterator left_insert = original.insert(right - 1, *left);
    list<char>>:iterator right_insert = original.insert(left - 1, *right);
    recurse(left_insert, right_insert, original)
  }
}

int solve()
{
  int mid = original.size() / 2;
  int shifts = 0;

  int left, right;

  if(original.size() % 2 == 1)
  {
    left = mid - 1;
    right = mid + 1;
  }
  else
  {
    left = mid - 1;
    right = mid;
  }

  while(left >= 0 || right < original.size())
  {
    if(left < 0 && right < original.size())
    {
      shifts++;
      right++;
    }
    else if(right >= original.size() && left >= 0)
    {
      shifts++;
      left--;
    }
    else if(original[left] != original[right])
    {
      // cout << original[left] << " != " << original[right] << endl;
      shifts += 2;
      right++;
      left--;
    }
    else if(original[left] == original[right])
    {
      right++;
      left--;
    }
  }

  return shifts;
}

int main()
{
  input();
  int res = solve();
  cout << res << endl;

  return 0;
}
