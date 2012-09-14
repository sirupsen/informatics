#include<cstdio>
#include<vector>
using namespace std;

int n;
struct O{
  int *ingredients;
  int order_id;
  int *n_ingredients;
};

int ingredients[20];
vector<O> orders;

void Bake(int I) {
}

void Init()
{
  n = 0;
}

void try_baking()
{
  for(vector<O>::const_iterator it = orders.begin(); it != orders.end(); ++it) {
    bool ok = true;
    for(size_t i = 0; i < *(it->n_ingredients); ++i) {
      if(ingredients[it->ingredients[i]] <= 0) {
        ok = false;
        break;
      }
    }

    if(ok) Bake(*(it->n_ingredients));
  }
}

void Order(int N, int *A)
{
  O new_order = {A, n, &N};
  orders.push_back(new_order);
  n++;
  try_baking();
}

void Delivery(int I)
{
  ingredients[I] += 1;
  try_baking();
}

int main() {
  return 0;
}
