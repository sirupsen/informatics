#include<iostream>
#include<map>
#include<cmath>

int main()
{
  unsigned int;

  cin >> n;
  map<int,string> short_scale;
  map<int,string> long_scale;

  short_scale[6] = "million";
  long_scale[6] = "million";

  short_scale[12] = "billion";
  long_scale[12] = "milliard";

  short_scale[12] = "trillion";
  long_scale[12] = "billion";

  short_scale[15] = "quadrillion";
  long_scale[15] = "billiard";

  short_scale[18] = "quintillion";
  long_scale[18] = "trillion";

  short_scale[21] = "sextillion";
  long_scale[21] = "trilliard";

  int zeros = log10(n);

  return 0;
}
