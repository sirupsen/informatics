#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAXITEMS 5
#define MAXOFFERS 10000

using namespace std;

typedef int basket_t[MAXITEMS];

struct offer_t
{
	basket_t basket;
	int price, savings;
	
	double goodness;
	
	bool operator< (const offer_t &o) const
	{
		return goodness > o.goodness;
	}
};

struct item_t
{
	int price, count;
};

offer_t offer[MAXOFFERS];
int offer_cnt;

item_t item[MAXITEMS];
int item_rev_index[1000];

int max_savings = 0;
int max_price = 0;
int max_level = 0;

void read()
{
	int B, C, K, P, S, N, T;

	scanf("%d", &B);
	for(int i = 0; i < B; i++) {
		scanf("%d %d %d", &C, &K, &P);
		item_rev_index[C] = i;
		item[i].price = P;
		item[i].count = K;
		max_price += P*K;
	}
	
	scanf("%d", &S);
	for(int j = 0; j < S; j++) {
		scanf("%d", &N);
		for(int k = 0; k < N; k++) {
			scanf("%d %d", &C, &K);
			C = item_rev_index[C];
			offer[j].basket[C] = K;
		}
		scanf("%d", &P);
		offer[j].price = P;
	}
	offer_cnt = S;
}

void initialize_offers()
{
	for(int i = 0; i < offer_cnt; i++) {
		double sum = 0.0f;
		int price = 0;
		int cnt = 0;
		
		for(int j = 0; j < MAXITEMS; j++) {
			cnt = offer[i].basket[j];
			sum += (double)cnt;
			price += cnt*item[j].price;
		}
		offer[i].savings = price - offer[i].price;
		offer[i].goodness = (double)offer[i].savings/sum;
	}
	
	sort(&offer[0], &offer[offer_cnt]);
}

int basket_sum(basket_t basket)
{
	int sum = 0;
	for(int i = 0; i < MAXITEMS; i++) {
		sum += basket[i];
	}
	return sum;
}

bool basket_sub(basket_t op1, basket_t op2, basket_t result)
{
	for(int i = 0; i < MAXITEMS; i++) {
		result[i] = op1[i]-op2[i];
		if(result[i] < 0) return false;
	}
	
	return true;
}

int cuts = 0;

bool promising(int offer_index, int savings, basket_t basket, int level)
{
  max_level = max(level, max_level);
	int new_savings = savings+ceil(offer[offer_index].goodness*(double)basket_sum(basket));
	
	return !(new_savings < max_savings);    
}

void solve(int offer_start, int savings, basket_t basket, int level=0)
{
	max_savings = max(savings, max_savings);
	
	if(!promising(offer_start, savings, basket, level)) {
    cuts++;
    return;
  }

	basket_t next_basket;
	if(basket_sub(basket, offer[offer_start].basket, next_basket))
    solve(offer_start, savings+offer[offer_start].savings, next_basket, level+1);

  if(offer_start + 1 < offer_cnt)
    solve(offer_start + 1, savings, basket, level + 1);

  // solve(offer_start+1, savings+offer[offer_start+1].savings, next_basket, level+1)
	
	// for(int i = offer_start; i < offer_cnt; i++) {
	// 	if(basket_sub(basket, offer[i].basket, next_basket))
	// 		solve(i, savings+offer[i].savings, next_basket, level+1);
	// }
}

int main()
{
	read();
	initialize_offers();
	basket_t basket;
	for(int i = 0; i < MAXITEMS; i++)
		basket[i] = item[i].count;
	solve(0, 0, basket);

  printf("Max level: %d\n", max_level);
  printf("cuts: %d\n", cuts);
	printf("%d\n", max_price - max_savings);
	
	return 0;
}

