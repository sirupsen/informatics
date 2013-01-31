#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

bool is_alphabetic(int c)
{
  return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

char to_lower(char c) 
{
  if ((int) c >= 65 && (int) c <= 90)
    return (char) c + 32;
  else
    return c;
}

int main()
{
  string line;
  for(unsigned int test_case = 0; getline(cin, line); test_case++) {
    if(test_case == 0) continue;

    map<char, unsigned int> freq;

    for(auto c : line) 
      if (is_alphabetic(c)) freq[to_lower(c)]++;

    vector<unsigned int> chars;

    for(auto p : freq)
      chars.push_back(p.second);

    sort(chars.begin(), chars.end(), [](int a, int b) { return a > b; });

    unsigned int points = 26, total_points = 0;
    for(auto freq = chars.cbegin(); freq != chars.cend(); freq++, points--)
      total_points += *freq * points;

    printf("Case #%d: %d\n", test_case, total_points);
  }
}
