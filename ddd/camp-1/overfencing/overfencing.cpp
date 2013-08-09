#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define MAX_N 500

struct Coordinate
{
  int i;
  int j;
  int weight;
  bool exit;

  Coordinate(int i, int j, int weight)
  {
    this->i = i;
    this->j = j;
    this->weight = weight;
    this->exit = false;
  }

  Coordinate(int i, int j, int weight, bool exit)
  {
    this->i = i;
    this->j = j;
    this->weight = weight;
    this->exit = true;
  }
};

void solve()
{
  string line;

  int w, h;
  scanf("%d %d", &w, &h);

  char field[MAX_N][MAX_N];
  int dist[MAX_N][MAX_N];

  queue<Coordinate> q;

  getchar();

  for(int i = 1; i <= h * 2 + 1; i++, getchar()) {
    for(int j = 1; j <= w * 2 + 1; j++) {
      field[i][j] = getchar();
      // printf("%c", field[i][j]);

      // If we're at an exit
      if(field[i][j] == ' ' && (j == 1 || j == 2 * w + 1 || i == 1 || i == 2 * h + 1))
      {
        if(j == 1)
        {
          q.push(Coordinate(i, j - 1, 0, true));
        }
        else if(j == 2 * w + 1)
        {
          q.push(Coordinate(i, 2 * w + 2, 0, true));
        }
        else if(i == 1)
        {
          q.push(Coordinate(i - 1, j, 0, true));
        }
        else if(i == 2 * h + 1)
        {
          q.push(Coordinate(2 * h + 2, j, 0, true));
        }
      }
    }

    // printf("\n");
  }

  // char testing = field[6][11];
  // printf("\n\nboom:%d => %c\n", testing, testing);

  // For the sake of testing
  // q.push(q.front());
  // q.pop();
  // q.pop();

  memset(dist, -1, sizeof dist);

  while(!q.empty())
  {
    Coordinate front = q.front(); q.pop();

    // printf("(%d;%d): %d\n", front.j, front.i, front.weight);

    if(!front.exit) {
      if(dist[front.i][front.j] != -1)
      {
        continue;
      }

      dist[front.i][front.j] = front.weight;
    }

    if(front.i < 2 * h)
    {
      if(field[front.i + 1][front.j] != '-')
      {
        q.push(Coordinate(front.i + 2, front.j, front.weight + 1));
      }
    }

    if(front.i > 2)
    {
      if(field[front.i - 1][front.j] != '-')
      {
        q.push(Coordinate(front.i - 2, front.j, front.weight + 1));
      }
    }

    if(front.j < 2 * w)
    {
      if(field[front.i][front.j + 1] != '|')
      {
        q.push(Coordinate(front.i, front.j + 2, front.weight + 1));
      }
    }

    if(front.j > 2)
    {
      if(field[front.i][front.j - 1] != '|')
      {
        q.push(Coordinate(front.i, front.j - 2, front.weight + 1));
      }
    }
  }

  int maximum = 0;

  for(int i = 0; i < MAX_N; i++)
    for(int j = 0; j < MAX_N; j++)
      maximum = max(maximum, dist[i][j]);

  printf("%d\n", maximum);
}

int main()
{
  solve();
  return 0;
}
