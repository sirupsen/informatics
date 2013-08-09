#include <iostream>
#include <algorithm>

using namespace std;

int productPrices[1000];

struct Product
{
	int productID;
	int quantity;
};

class Basket
{
public:
	Product productsWanted[1000];
	int n;

	Basket()
	{
		n = 0;
	}

	void AddProduct(int productID, int quantity)
	{
		productsWanted[n].productID = productID;
		productsWanted[n].quantity = quantity;
		n++;
	}

	void SetQuantityR(int productID, int quantity)
	{
		int a = GetNumberOfProductNum(productID);
		productsWanted[a].quantity += quantity;
	}

	bool HasItems()
	{
		for (int i = 0; i < n; i++)
		{
			if (productsWanted[i].quantity > 0)
			{
				return true;
			}
		}

		return false;
	}

	int GetStandardPrice()
	{
		int price = 0;

		for (int i = 0; i < n; i++)
		{
			price += productPrices[productsWanted[i].productID] * productsWanted[i].quantity;
		}

		return price;
	}

	int GetNumberOfProducts(int productID)
	{
		for (int i = 0; i < n; i++)
		{
			if (productsWanted[i].productID == productID)
			{
				return productsWanted[i].quantity;
			}
		}

		return 0;
	}

	int GetNumberOfProductNum(int productID)
	{
		for (int i = 0; i < n; i++)
		{
			if (productsWanted[i].productID == productID)
			{
				return i;
			}
		}

		return -1;
	}

	int GetProducts()
	{
		int products = 0;

		for (int i = 0; i < n; i++)
		{
			products += productsWanted[i].quantity;
		}

		return products;
	}
};

class Offer
{
public:
	Basket products;
	int price;
	int savings;
	float savingsPrProduct;

	void AddProduct(int productID, int quantity)
	{
		products.AddProduct(productID, quantity);
	}

	void SetPrice(int p)
	{
		price = p;
	}

	void Calculate()
	{
		savings = products.GetStandardPrice() - price;
		savingsPrProduct = (float)savings/products.GetProducts();
	}

	bool CanApplySavings(Basket basket)
	{
		if (products.n == 0)
		{
			return false;
		}

		if (products.productsWanted[0].quantity == 0)
		{
			return false;
		}

		if (savingsPrProduct <= 0)
		{
			return false;
		}

		for (int i = 0; i < products.n; i++)
		{
			if (basket.GetNumberOfProducts(products.productsWanted[i].productID) < products.productsWanted[i].quantity)
			{
				return false;
			}
		}

		return true;
	}

	Basket ApplySavings(Basket basket)
	{
		for (int i = 0; i < products.n; i++)
		{
			basket.SetQuantityR(products.productsWanted[i].productID, -products.productsWanted[i].quantity);
		}

		return basket;
	}
};

Offer offers[100];
int maxSavings = 0;
int s;

bool CompareOffer(Offer a, Offer b)
{
	return (a.savingsPrProduct * a.products.n >= b.savingsPrProduct * b.products.n);
}

void GetSavings(Basket basket, int offerNum, int savings)
{
	if (offerNum < s-1)
	{
		GetSavings(basket, offerNum+1, savings);
	}

	if (offers[offerNum].CanApplySavings(basket))
	{
		savings += offers[offerNum].savings;
		basket = offers[offerNum].ApplySavings(basket);

		if (savings > maxSavings)
		{
			maxSavings = savings;
		}

		GetSavings(basket, offerNum, savings);
	}
}

int main()
{
	int b, totalnosave = 0;
	Basket basket;

	cin >> b;

	for (int i = 0; i < b; i++)
	{
		int c, k, p;

		cin >> c;
		cin >> k;
		cin >> p;

		totalnosave += p * k;

		productPrices[c] = p;
		basket.AddProduct(c, k);
	}

	cin >> s;

	for (int i = 0; i < s; i++)
	{
		int n, price;
		int input[6][2];

		cin >> n;

		for (int ii = 0; ii < n; ii++)
		{
			cin >> input[ii][0];
			cin >> input[ii][1];

			offers[i].AddProduct(input[ii][0], input[ii][1]);
		}

		cin >> price;

		offers[i].SetPrice(price);
		offers[i].Calculate();
	}

	sort(offers, offers + s, CompareOffer);

	GetSavings(basket, 0, 0);

	cout << totalnosave - maxSavings;

	system("PAUSE");
	return 0;
}