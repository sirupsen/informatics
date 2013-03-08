#include<cstdio>
#include<iostream>
using namespace std;
#define MAX_DIMENSIONS 230

int w,h;
bool visited[MAX_DIMENSIONS][MAX_DIMENSIONS];
bool grid[MAX_DIMENSIONS][MAX_DIMENSIONS];

int flood_fill(int x, int y)
{
  if(x >= w * 3 || x < 0 || y < 0 || y >= h * 3) {
    return -50000;
  } else if(visited[y][x] || grid[y][x]) {
    return 0;
  } else {
    visited[y][x] = true;

    return flood_fill(x + 1, y)
            + flood_fill(x, y + 1)
            + flood_fill(x - 1, y)
            + flood_fill(x, y - 1) + 1;
  }
}

int main()
{
  int maze_no = 1;

  while(cin >> w >> h) {
    if(w == 0 && h == 0) break;
    // if(maze_no != 1) printf("\n");

    for(int i = 0; i < MAX_DIMENSIONS; i++) {
      for(int j = 0; j < MAX_DIMENSIONS; j++) {
        grid[i][j] = 0;
        visited[i][j] = 0;
      }
    }

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        char tile; cin >> tile;

        if(tile == '\\') {
          grid[i * 3 + 0][j * 3 + 0] = true;
          grid[i * 3 + 1][j * 3 + 1] = true;
          grid[i * 3 + 2][j * 3 + 2] = true;
        } else {
          grid[i * 3 + 0][j * 3 + 2] = true;
          grid[i * 3 + 1][j * 3 + 1] = true;
          grid[i * 3 + 2][j * 3 + 0] = true;
        }
      }
    }


    // for(int i = 0; i < h * 3; i++) {
    //   for(int j = 0; j < w * 3; j++) {
    //     if(grid[i][j]) {
    //       printf("X");
    //     } else {
    //       printf(" ");
    //     }
    //   }
    //   printf("\n");
    // }

    int longest = -1, cycles = 0;

    for(int i = 0; i < h * 3; i++) {
      for(int j = 0; j < w * 3; j++) {
        int res = flood_fill(j, i);

        if(res > 0) {
          longest = max(longest, res);
          cycles++;
        }
      }
    }

    printf("Maze #%d:\n", maze_no);

    if(cycles > 0) {
      printf("%d Cycles; the longest has length %d.\n\n", cycles, longest / 3);
    } else {
      printf("There are no cycles.\n\n");
    }
    
    maze_no++;
  }

  return 0;
}
