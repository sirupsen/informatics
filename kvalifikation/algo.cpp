#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void print_vector(vector<int>& v)
{
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
        printf("%d ", *iter);
    }
    printf("\n");
}

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);

    printf("v:\n");
    print_vector(v);

    sort(v.begin(), v.end());

    printf("\nsorted:\n");
    print_vector(v);
}