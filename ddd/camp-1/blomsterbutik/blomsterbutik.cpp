#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;

int id_map[1000];

struct Type {
  int no;
  int amount;

  Type(int no, int amount)
  {
    this->no = no;
    this->amount = amount;
  }
};

struct Offer {
  vector<Type> types;
  int discount;
  int price;
  int total_wares;
  double discount_per_ware;
};

struct Ware {
  int amount;
  int price;

  Ware() {
    this->amount = 0;
    this->price = 0;
  }

  Ware(int amount, int price) {
    this->amount = amount;
    this->price = price;
  }
};

vector<Ware> cart;
vector<Offer> offers;

int best_reduced_cost = 0;
int lol = 0;
int max_level = 0;

void recurse(vector<Ware> cart, int offer_index, int reduced_cost, int items_in_cart, int level)
{
  max_level = max(level, max_level);

  if(offer_index >= offers.size())
    return;

  double super_potential = (double) reduced_cost + ceil((double) offers[offer_index].discount_per_ware * (double) items_in_cart);

  if((double) super_potential < (double) best_reduced_cost) {
    lol++;
    return;
  }

  if(reduced_cost > best_reduced_cost)
    best_reduced_cost = reduced_cost;

  bool offer_fully_applied = true;

  vector<Ware> new_cart = cart;
  int new_items_in_cart = items_in_cart;

  // Apply the offer
  Offer offer = offers[offer_index];
  for(vector<Type>::iterator type = offer.types.begin(); type != offer.types.end(); type++) {
    new_cart[id_map[type->no]].amount -= type->amount;
    new_items_in_cart -= type->amount;

    if(new_cart[id_map[type->no]].amount < 0)
      offer_fully_applied = false;
  }

  // Try applying more offers to this direction
  if(offer_fully_applied)
    recurse(new_cart, offer_index, reduced_cost + offer.discount, new_items_in_cart, level + 1);

  recurse(cart, offer_index + 1, reduced_cost, items_in_cart, level + 1);
}

bool compare_offers(Offer a, Offer b)
{
  return a.discount_per_ware > b.discount_per_ware;
}

int main()
{
  int n, no, amount, price, s, items_in_cart; cin >> n;

  cart.resize(26);

  for(int i = 0; i < n; i++) {
    cin >> no >> amount >> price;
    Ware ware(amount, price);
    id_map[no] = i;
    cart[id_map[no]] = ware;
    items_in_cart += amount;
  }

  cin >> s;

  for(int i = 0; i < s; i++) {
    cin >> n;
    Offer offer;

    int normal_price = 0;
    int total_wares = 0;

    bool good = true;

    for(int j = 0; j < n; j++) {
      cin >> no >> amount;

      total_wares += amount;
      normal_price += amount * cart[id_map[no]].price;

      if(cart[id_map[no]].amount < amount) {
        good = false;
        break;
      }

      Type type(no, amount);
      offer.types.push_back(type);
    }

    if(!good) continue;

    cin >> offer.price;
    offer.discount = normal_price - offer.price;
    offer.total_wares = total_wares;

    // printf("discount: %d, total wares: %d\n", offer.discount, offer.total_wares);
    offer.discount_per_ware = (double) offer.discount /  (double) offer.total_wares;

    if(offer.discount > 0)
      offers.push_back(offer);
  }


  sort(offers.begin(), offers.end(), compare_offers);

  // for(auto o : offers) {
  //   printf("%.2f\n", o.discount_per_ware);
  // }

  recurse(cart, 0, 0, items_in_cart, 0);

  int total_cost = 0;

  for(int i = 0; i < cart.size(); i++)
    total_cost += cart[i].amount * cart[i].price;

  // printf("max level: %d\n", max_level);
  // printf("Cuts: %d\n", lol);

  // printf("Total cost without discounts: %d\n", total_cost);
  // printf("Best discount achievable totals to: %d\n", best_reduced_cost);
  printf("%d\n", total_cost - best_reduced_cost);

  return 0;
}
