#include<iostream>
#include<cstdio>

#include <queue>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class CrushingSnake
{
  vector<string> m;

  bool point_ok(pair<int, int> &point, int depth)
  {
    return point.first > depth / 4 && // North
        point.first < m.size() - depth / 4 && // South
        point.second > depth / 4 && // West
        point.second < m[0].size() - depth / 4 && this->m[point.first][point.second] != '#';
  }

  public:
    int getSurvivalTime(vector<string> maze)
    {
      this->m = maze;
      queue<pair<int, pair<int, int> > > q;

      pair<int, int> start;
      pair<int, int> teleport;

      for(int i = 0; i < maze.size(); i++)
      {
        for(int j = 0; j < maze[0].size(); j++)
        {
          if(maze[i][j] == 'X')
          {
            start = pair<int, int> (i, j);
          }

          if(maze[i][j] == 'T')
          {
            teleport = pair<int, int> (i, j);
          }

          // cout << maze[i][j];
        }
        // cout << endl;
      }

      // cout << teleport.first << ";" << teleport.second << endl;

      q.push(pair<int, pair<int, int> > (0, start));

      bool visited[100][100];
      memset(visited, 0, sizeof visited);

      while(!q.empty())
      {
        pair<int, pair<int, int> > front = q.front(); q.pop();
        int depth = front.first;
        pair<int, int> point = front.second;

        if(point.first == teleport.first && point.second == teleport.second)
        {
          return depth;
        }

        // printf("Point (%d;%d), depth: %d\n", point.first, point.second, depth);

        if(!visited[point.first + 1][point.second])
        {
          pair<int, int> new_point(point.first + 1, point.second);

          if(point_ok(new_point, depth)) {
            visited[point.first + 1][point.second] = true;

            q.push(pair<int, pair<int, int> > (depth + 1, new_point));
          }
        }

        if(!visited[point.first - 1][point.second])
        {
          pair<int, int> new_point(point.first - 1, point.second);
          if(point_ok(new_point, depth)) {
            visited[point.first - 1][point.second] = true;

            q.push(pair<int, pair<int, int> > (depth + 1, new_point));
          }
        }

        if(!visited[point.first][point.second + 1])
        {
          pair<int, int> new_point(point.first, point.second + 1);

          if(point_ok(new_point, depth)) {
            visited[point.first][point.second + 1] = true;

            q.push(pair<int, pair<int, int> > (depth + 1, new_point));
          }
        }

        if(!visited[point.first][point.second - 1])
        {
          pair<int, int> new_point(point.first, point.second - 1);
          if(point_ok(new_point, depth)) {
            visited[point.first][point.second - 1] = true;

            q.push(pair<int, pair<int, int> > (depth + 1, new_point));
          }
        }
      }

      return -1;
    }
};

// int main()
// {
//   CrushingSnake cs;
// 
//   vector<string> m;
// 
//   m.push_back(string("...##...."));
//   m.push_back(string(".#.....#."));
//   m.push_back(string(".##T..#.."));
//   m.push_back(string("....#...#"));
//   m.push_back(string(".##..##.."));
//   m.push_back(string(".#..#...."));
//   m.push_back(string(".#.###..."));
//   m.push_back(string("##..#..#."));
//   m.push_back(string(".X.#..#.."));
// 
//   cout << cs.getSurvivalTime(m) << endl;
// 
//   return 0;
// }
