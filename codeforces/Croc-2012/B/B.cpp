#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int main()
{
  string note;
  cin >> note;

  int i, j;

  if(note[0] == 'f') {
    cout << "ftp://";
    i = 3;
  } else if (note[0] == 'h') {
    cout << "http://";
    i = 4;
  }

  assert(i == 3 || i == 4);

  for(j = i; j < note.size(); j++)
    if(note[j + 1] == 'u' && note[j] == 'r' && j != i)
      break;

  cout << note.substr(i, j - i);

  cout << ".ru";

  if(j + 2 < note.size()) {
    cout << "/";

    cout << note.substr(j + 2, note.size() - (j + 2));
  }


  cout << endl;

  return 0;
}
