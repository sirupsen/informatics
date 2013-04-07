#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define MAX_N 105

struct BigNum
{
  vector<short> number;

  BigNum()
  {
    number.assign(1, 0);
  }

  BigNum(string initial)
  {
    number.resize(initial.size());

    for(int i = 0; i < initial.size(); i++)
    {
      number[i] = (short) initial[i] - '0';
    }
  }

  BigNum add(BigNum &b)
  {
    BigNum result;

    if(this->number.size() > b.number.size())
    {
      printf("i is larger\n");
      result.number.resize(this->number.size() + 1);
      add(this->number.size() - 1, 0, *this, b, result);
    }
    else
    {
      printf("i is not larger\n");
      result.number.resize(b.number.size() + 1);
      add(b.number.size() - 1, 0, b, *this, result);
    }

    return result;
  }

  string to_string()
  {
    string s;

    for(int i = 0; i < this->number.size(); i++)
    {
      printf("%d", number[i]);
      s += char(number[i] + '0');
    }

    printf("\n");

    return s;
  }

  private:
  void add(int index, short carry, BigNum a, BigNum b, BigNum &result)
  {

    if(index >= b.number.size() && index < a.number.size())
    {
      printf("%d = %d\n", index, a.number[index]);

      short rem = (a.number[index] + carry) / 10;
      result.number[index] = (a.number[index] + carry) % 10;

      add(index - 1, rem, a, b, result);
    }
    else if(index < b.number.size() && a.number.size())
    {
      short rem = (b.number[index] + this->number[index] + carry) / 10;
      result.number[index] = (b.number[index] + this->number[index] + carry) % 10;

      add(index - 1, rem, a, b, result);
    }
  }
};

int n;
long long paths = 0;
long long dp[MAX_N][MAX_N];
int board[MAX_N][MAX_N];

void recurse(int x, int y)
{
  if(dp[y][x] != -1)
  {
    paths += dp[y][x];
  }
  else if(x < 0 && x >= n && y < 0 && y >= n)
  {
  }
  else if(x == n - 1 && y == n - 1)
  {
    paths += 1;
  }
  else if(board[y][x] == 0)
  {
  }
  else
  {
    int steps = board[y][x];

    long long before = paths;

    recurse(x + steps, y);
    recurse(x, y + steps);

    dp[y][x] = paths - before;
  }
}

int main()
{
  BigNum a("123456");
  BigNum b("9876543");

  cout << a.add(b).to_string() << endl;

  // scanf("%d", &n);

  // for(int i = 0; i < n; i++)
  // {
  //   for(int j = 0; j < n; j++)
  //   {
  //     scanf("%d", &board[i][j]);
  //     dp[i][j] = -1;
  //   }
  // }

  // recurse(0, 0);

  // cout << paths << endl;

  return 0;
}
