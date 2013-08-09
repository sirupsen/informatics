#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

vector<vector<int> > prices;
int money, n_garments; 
int dp[300][50];

int solve(int m, int garment)
{
  if (m > money) {
    return 0;
  } else if (garment == n_garments) {
    return m;
  } else if (dp[m][garment] != -1) {
    return dp[m][garment];
  } else {
    int local_max = 0;
    for(vector<int>::iterator price = prices[garment].begin(); price != prices[garment].end(); ++price)
      local_max = max(local_max, solve(m + *price, garment + 1));

    return dp[m][garment] = local_max;
  }
}

int main()
{
  int n_cases;
  cin >> n_cases;

  for(size_t i = 0; i < n_cases; ++i) {
    cin >> money >> n_garments;
    memset(dp, -1, sizeof dp);

    // Read prices of garment models
    for(size_t j = 0; j < n_garments; ++j) {
      int n_models; cin >> n_models;
      vector<int> price;

      for(size_t k = 0; k < n_models; ++k) {
        int tmp; cin >> tmp;
        price.push_back(tmp);
      }

      prices.push_back(price);
    }

    int solution = solve(0, 0);
    if (solution) cout << solution << endl;
    else cout << "no solution" << endl;

    prices.clear();
  }

  return 0;
}
