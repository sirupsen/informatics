#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define BOARD 10

struct Field {
  int x;
  int y;
};

Field previous[BOARD][BOARD];
Field starting_field;
Field target_field;

int board[BOARD][BOARD];
int dist[BOARD][BOARD];
int route[BOARD][BOARD];
int visited[BOARD][BOARD];

void fill_board()
{
  for(int i = 0; i < BOARD; i++)
    for(int j = 0; j < BOARD; j++)
      board[i][j] = (rand() % 9) + 1; // avoid zero
}

void set_beginner_position()
{
  starting_field.x = rand() % BOARD;
  starting_field.y = rand() % BOARD;

  board[starting_field.y][starting_field.x] = 0;

  cout << "Starting: (" << starting_field.x << ";" << starting_field.y << ")\n";
}

void set_target_position()
{
  target_field.x = rand() % BOARD;
  target_field.y = rand() % BOARD;
  
  cout << "Target: (" << target_field.x << ";" << target_field.y << ")\n";
}

void print_board()
{
  bool color = false;

  for(int i = 0; i < BOARD; i++) {
    for(int j = 0; j < BOARD; j++) {
      if (i == target_field.y && j == target_field.x) {
        cout << "\e[1;31m";
        color = true;
      } else if (i == starting_field.y && j == starting_field.x) {
        cout << "\e[1;35m";
        color = true;
      } else if (route[i][j] == 10) {
        cout << "\e[0;32m";
        color = true;
      }

      cout << board[i][j] << " ";

      if (color) cout << "\e[0m"; // reset
    }
    
    cout << "\n";
  }
}

void seed_dist()
{
  for(int i = 0; i < BOARD; i++) {
    for(int j = 0; j < BOARD; j++) {
      dist[i][j] = INT_MAX;

      Field null_field = {-1, -1}; // undef
      previous[i][j] = null_field;
    }
  }

  dist[starting_field.y][starting_field.x] = 0;
}

bool board_empty()
{
  for(int i = 0; i < BOARD; i++)
    for(int j = 0; j < BOARD; j++)
      if (board[i][j] != -1) return false;

  return true;
}

Field closest_to_source() 
{
  int min = INT_MAX;
  Field min_field = {-1,-1};

  for(int i = 0; i < BOARD; i++) {
    for(int j = 0; j < BOARD; j++) {
      if (visited[i][j] != 1 && dist[i][j] < min) {
        min = dist[i][j];
        min_field.y = i;
        min_field.x = j;
      }
    }
  }

  return min_field;
}

void visit_neighbour(int y, int x, Field parent)
{
  // out of board
  if (x < 0 || x >= BOARD || y < 0 || y >= BOARD) return;

  int weight = board[y][x];
  int parent_weight = dist[parent.y][parent.x];
  int distance_through_u = weight + parent_weight;

  if (distance_through_u < dist[y][x]) {
    dist[y][x] = distance_through_u;
    previous[y][x] = parent;
  }
}


void dijkstra()
{
  int i = 0;

  while (!board_empty()) {
    Field current_field = closest_to_source();
    if (current_field.x == target_field.x && current_field.y == target_field.y) return;

    visited[current_field.y][current_field.x] = 1; // remove field from graph
    cout << "(" << current_field.x << ";" << current_field.y << "): " << dist[current_field.y][current_field.x] << "\n";

    visit_neighbour(current_field.y + 1, current_field.x, current_field);
    visit_neighbour(current_field.y - 1, current_field.x, current_field);

    visit_neighbour(current_field.y + 1, current_field.x + 1, current_field);
    visit_neighbour(current_field.y - 1, current_field.x - 1, current_field);
    visit_neighbour(current_field.y - 1, current_field.x + 1, current_field);
    visit_neighbour(current_field.y + 1, current_field.x - 1, current_field);

    visit_neighbour(current_field.y, current_field.x + 1, current_field);
    visit_neighbour(current_field.y, current_field.x - 1, current_field);

    // i++;
    // if(i == 10) break;
  }
}

void draw_target_route()
{
  Field v = target_field;
  cout << "Shortest route.. \n";

  cout << "(" << v.x << ";" << v.y << "): " << dist[v.y][v.x] << "\n";

  while(previous[v.y][v.x].x != -1 && previous[v.y][v.x].y != -1) {
    v = previous[v.y][v.x];
    route[v.y][v.x] = 10;
    cout << "(" << v.x << ";" << v.y << "): " << dist[v.y][v.x] << "\n";
  }

  print_board();
}

int main()
{
  srand(time(NULL)); // seed
  fill_board();
  set_beginner_position();
  set_target_position();
  print_board();
  seed_dist();
  dijkstra();
  draw_target_route();
}
