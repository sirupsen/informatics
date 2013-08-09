#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

struct Song {
  int time_end;
  int track_no;

  Song(int time_end, int track_no)
  {
    this->time_end = time_end;
    this->track_no = track_no;
  }

  bool operator <(const Song &b) const
  {
    return time_end <= b.time_end;
  }
};


int main()
{
  set<Song> playlist;

  int n, m;
  cin >> n >> m;

  int prev = 0;
  for(int i = 1; i <= n; i++)
  {
    int c, t;
    cin >> c >> t;

    Song new_song(prev + c * t, i);
    playlist.insert(new_song);

    prev = new_song.time_end;
  }

  while(m--)
  {
    int t; cin >> t;
    cout << playlist.upper_bound(Song(t,0))->track_no << endl;
  }

  return 0;
}
