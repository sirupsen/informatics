#include <cstdio>

// Varer

int n_varetyper;

struct vare {
  int vare_nr;
  int amount;
  int unit_price;
};

class Offer {
  public:
    Offer() {
    }
};

vare varer[50];

// Offer stuff

int n_offers;
int n_varetyper;

void input()
{
  scanf("%d", &n_varetyper);

  int i;
  for(i = 0; i < n_varetyper; i++) {
    scanf("%d", &vare.vare_nr);
    scanf("%d", &vare.amount);
    scanf("%d", &vare.unit_price);
  }

  scanf("%d", &n_offers);
  for(i = 0; i < n_offers; i++) {
    int n_offer_pairs;
    int k;

    scanf("%d", &n_offer_pairs);
    for(k = 0; k < n_offer_pairs; k++) {
      scanf("%d %d")
    }
  }
}

void output() 
{
}

int main(int argc, char *argv[]) 
{
}
