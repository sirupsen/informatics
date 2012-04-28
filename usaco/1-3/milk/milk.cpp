/*
ID: sirup1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct farmer {
  int unit_price;
  int gallons;
};

vector<farmer> farmers;

bool compare_farmer(farmer a, farmer b)
{
  return a.unit_price < b.unit_price;
}

int main()
{
  int gallons_needed = 0, n_farmers = 0, price = 0;

  ifstream input("milk.in");

  input >> gallons_needed;
  input >> n_farmers;

  // cout << "Gallons needed: " << gallons_needed << "\n";
  // cout << "Farmers: " << n_farmers << "\n";

  // Load all farmers into memory for sorting
  for(int i = 0; i < n_farmers; i++) {
    farmer current_farmer;
    input >> current_farmer.unit_price;
    input >> current_farmer.gallons;

    farmers.push_back(current_farmer);
  }

  vector<farmer>::iterator cur_farmer;

  sort(farmers.begin(), farmers.end(), compare_farmer);

  // for(cur_farmer = farmers.begin(); cur_farmer < farmers.end(); cur_farmer++)
  //   cout << "Farmor (price, gallons): " << cur_farmer->unit_price << " " << cur_farmer->gallons << "\n";

  // cout << "\n";

  int ages[5] = {4, 5, 3, 2, 3};

  for(int i = 0; i < 5; i++)
    printf("Age of sexy kid: %d\n", ages[i]);

  vector<int> nages;
  nages.push_back(4);
  nages.push_back(5);
  nages.push_back(3);
  nages.push_back(2);
  nages.push_back(3);

  vector<int>::iterator it;

  for(it = nages.begin(); it < nages.end(); it++)
    cout << "AGe of kid: " << (*it) << "\n";

  for(cur_farmer = farmers.begin(); cur_farmer < farmers.end() && gallons_needed != 0; cur_farmer++) {
    // Need everything the farmer has
    if (gallons_needed >= cur_farmer->gallons) {
      gallons_needed -= cur_farmer->gallons;
      price += cur_farmer->unit_price * cur_farmer->gallons;
    } else { // we're done, don't buy too much
      price += cur_farmer->unit_price * gallons_needed;
      gallons_needed = 0; // just to end the loop
    }
  }

  ofstream output("milk.out");

  output << price << "\n";

  // Sort by unit price

  return 0;
}
