#include<iostream>
using namespace std;

int n;

int recurse(int last, int pictures, int pages)
{
  if(pictures == n) {
    return pages;
  } else if (pictures > n) {
    return INT_MAX;
  } else {
    return min(
        recurse(last * 2, pictures + last * 2, pages + 1),
        recurse(last, pictures + last, pages + 1)
    );
  }
}

int main()
{
  scanf("%d", &n);
  cout << recurse(1, 0, 0) << endl; 

  return 0;
}
