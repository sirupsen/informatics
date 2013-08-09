#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 11
int const n = 10;

int res = 101;
int x_dir[] = {0, 0, 0, 1, -1};
int y_dir[] = {0, 1, -1, 0, 0};
bool on[MAX][MAX];
bool now[MAX][MAX];
bool button[MAX][MAX];

inline void get_min(int& a, int b) {
	if (b < a) a = b;
}

inline bool all_off() {
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (now[i][j]) return false;
	return true;
}

void do_switch(int x, int y) {
	int i, _x, _y;
	for (i = 0; i < 5; ++i) {
		_x = x + x_dir[i];
		_y = y + y_dir[i];
		if (_x >= 0 && _x < n && _y >= 0 && _y < n)
			now[_x][_y] = !now[_x][_y];
	}
}

void organize_lights() {
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			now[i][j] = on[i][j];
	for (i = 0; i < n; ++i)
		if (button[0][i]) do_switch(0, i);
	for (i = 1; i < n; ++i)
		for (j = 0; j < n; ++j) {
			button[i][j] = now[i - 1][j];
			if (now[i - 1][j])
				do_switch(i, j);
		}
}

void solve(int y = 0) {
	if (y == 10) {
		organize_lights();
		if (!all_off()) return;
		int cnt = 0, i, j;
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				cnt += button[i][j];
		get_min(res, cnt);
		return;
	}
	solve(y + 1);
	button[0][y] = true;
	solve(y + 1);
	button[0][y] = false;
}

int main() {
	char name[300], row[300];
	for (int i, j; scanf("%s", name) && strcmp(name, "end"); res = 101) {
		for (i = 0; i < n; ++i) {
			scanf("%s", row);
			for (j = 0; j < n; ++j)
				on[i][j] = row[j] == 'O';
		}
		solve();
		if (res > 100) res = -1;
		printf("%s %d\n", name, res);
	}
	return 0;
}