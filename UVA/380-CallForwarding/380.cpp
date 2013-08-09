    #include<iostream>
    #include<algorithm>
    #include<cmath>
    #include<vector>
    using namespace std;

    struct Forward {
      int source;
      int time;
      int duration;
      int target;

      bool taken;
    };

    string pad_number(int n)
    {
      if(!n) return string("0000");

      string s;

      for(int i = log10(n) + 1; i <= 3; i++)
        s += '0';

      string p;

      while(n)
      {
        p += (char) ((n % 10) + '0');
        n /= 10;
      }

      reverse(p.begin(), p.end());

      return s + p;
    }

    void recurse(int orig, int current_no, int time, vector<Forward> &forwards)
    {
      bool forwarded = false;
      bool cycle = false;

      for(int i = 0; i < forwards.size(); i++)
      {
        if(time >= forwards[i].time
          && time <= forwards[i].time + forwards[i].duration
          && forwards[i].source == current_no)
        {
          if(forwards[i].taken)
          {
            forwarded = false;
            current_no = 9999;
            break;
          }
          else
          {
            forwarded = true;

            forwards[i].taken = true;
            recurse(orig, forwards[i].target, time, forwards);
            forwards[i].taken = false;
            break;
          }
        }
      }

      if(!forwarded)
      {
        cout << "AT " << pad_number(time) << " CALL TO " << pad_number(orig) << " RINGS " << pad_number(current_no) << endl;
      }
    }

    int main()
    {
      ios::sync_with_stdio(false);

      int n_test_cases; cin >> n_test_cases;

      cout << "CALL FORWARDING OUTPUT" << endl;

      for(int test_case_no = 1; test_case_no <= n_test_cases; test_case_no++)
      {
        cout << "SYSTEM " << test_case_no << endl;
        vector<Forward> forwards;

        Forward forward;

        while(cin >> forward.source && forward.source != 0)
        {
          cin >> forward.time >> forward.duration >> forward.target;
          forward.taken = false;
          forwards.push_back(forward);
        }


        int time, target;

        while(cin >> time)
        {
          if(time == 9000) break;

          cin >> target;

          recurse(target, target, time, forwards);
        }
      }

      cout << "END OF OUTPUT" << endl;

      return 0;
    }
