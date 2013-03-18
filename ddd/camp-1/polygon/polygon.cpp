#include<cstdio>
using namespace std;

int n;
enum Operand { MUL, ADD };

struct Node {
  int value;
  int index;
  Operand op;
};

vector<Node>

void input()
{
  scanf("%d", &n);

  Node last_node;

  for(int i = 0; i < n; i++) {
    int op, val;
    scanf("%d %d", &op, &val);

    Node new_node(val, index);
  }
}

int main()
{
  return 0;
}
