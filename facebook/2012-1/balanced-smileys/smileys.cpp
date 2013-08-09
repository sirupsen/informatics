#include<iostream>
#include<cassert>
using namespace std;

string line;
bool possible;

void recurse(size_t pos, int balanced, bool smiley_flag)
{
  if(balanced < 0) return;

  if(pos == line.size()) {
    if(balanced == 0) possible = true;

    return;
  }

  // printf("%d:%d:%d\n", pos, line.size(), balanced);

  if((line[pos] >= 'a' && line[pos] <= 'z') || line[pos] == ' ') {
    recurse(pos + 1, balanced, false);
  } else if (line[pos] == ':') {
    recurse(pos + 1, balanced, true);
    recurse(pos + 1, balanced, false);
  } else if (line[pos] == '(') {
    smiley_flag ? recurse(pos + 1, balanced, false) : recurse(pos + 1, balanced + 1, false);
  } else if (line[pos] == ')') {
    smiley_flag ? recurse(pos + 1, balanced, false) : recurse(pos + 1, balanced - 1, false);
  } else {
    assert("Invalid input.");
  }
}

int main()
{
  for(unsigned int test_case = 0; getline(cin, line); test_case++) {
    if(test_case == 0) continue;
    possible = false;

    recurse(0, 0, false);

    if(possible) {
      printf("Case #%d: YES\n", test_case);
    } else {
      printf("Case #%d: NO\n", test_case);
    }
  }
}
