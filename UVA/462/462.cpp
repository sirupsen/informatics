#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;

int main()
{
  string line;
  while(getline(cin, line)) {
    vector<string> hand;
    bool stopped['S'+1];
    map<char, int> suits;

    suits['S'] = suits['D'] = suits['H'] = suits['C'] = 0;
    stopped['S'] = stopped['D'] = stopped['H'] = stopped['C'] = false;

    int points_1_4, points_5_7;
    points_1_4 = points_5_7 = 0;

    for(int i = 0; i < 13; i++) {
      char card[5];
      card[0] = line[i*3];
      card[1] = line[i*3 + 1];

      suits[card[1]]++;
      hand.push_back(card);
    }

    vector<string>::iterator it;

    for(it = hand.begin(); it != hand.end(); it++) {
      string card = *it;

      // rule 1
      if (card[0] == 'A') points_1_4 += 4;
      if (card[0] == 'K') points_1_4 += 3;
      if (card[0] == 'Q') points_1_4 += 2;
      if (card[0] == 'J') points_1_4 += 1;

      if (card[0] == 'K' && suits[card[1]] <= 1) points_1_4 -= 1; // rule 2
      if (card[0] == 'Q' && suits[card[1]] <= 2) points_1_4 -= 1; // rule 3
      if (card[0] == 'J' && suits[card[1]] <= 3) points_1_4 -= 1; // rule 4

      // stopped?
      if (card[0] == 'A') stopped[card[1]] = true;
      if (card[0] == 'K' && suits[card[1]] >= 2) stopped[card[1]] = true;
      if (card[0] == 'Q' && suits[card[1]] >= 3) stopped[card[1]] = true;

      // cout << "Card: " << card << endl;
    }

    char max_suit_type;
    int max_suit_count = 0;

    map<char, int>::iterator mapit;
    for(mapit = suits.begin(); mapit != suits.end(); mapit++) {
      if ((*mapit).second == 2) points_5_7 += 1;
      if ((*mapit).second <= 1) points_5_7 += 2;

      // find biggest sumapit
      if ((*mapit).second > max_suit_count) {
        max_suit_type = (*mapit).first;
        max_suit_count = (*mapit).second;
      }

      cout << (*mapit).first << " => " << (*mapit).second << endl;
    }

    int total_points = points_1_4 + points_5_7;

    // cout << "Points from 1-4: " << points_1_4 << endl;
    // cout << "Points from 5-7: " << points_5_7 << endl;
    // cout << "Total points: " << total_points << endl;
    // cout << "Stopped S? " << stopped['S'] << endl;
    // cout << "Stopped D? " << stopped['D'] << endl;
    // cout << "Stopped H? " << stopped['H'] << endl;
    // cout << "Stopped C? " << stopped['C'] << endl;

    if (points_1_4 >= 16 && stopped['S'] && stopped['D'] && stopped['H'] && stopped['C']) {
      cout << "BID NO-TRUMP" << endl;
    } else if (total_points < 14) {
      cout << "PASS" << endl;
    } else {
      cout << "BID " << max_suit_type << endl;
    }
  }

  return 0;
}
