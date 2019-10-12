#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
bool visited[10][10];
int paper[6];
int ans = 0;
int res = 25;
int measure(int x, int y) {
	int tmp = 5;
	for (int i = x; i < 10; i++) {
		for (int j = y; j < 10; j++) {
			if (!map[i][j]) {
				tmp = min(tmp, max(i - x, j - y));
				break;
			}
		}
	}
	tmp = min(tmp, 10 - x);
	tmp = min(tmp, 10 - y);
	return tmp;
}
void check(int x, int y, int k, bool flag) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			map[i][j] = flag;
		}
	}
}
void go(int cnt) {
	if (cnt >= res) return;
	
	pair<int, int> coord = make_pair(10,10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]==1) {
				coord.first = i;
				coord.second = j;
				break;
			}
		}
		if (coord.first != 10) break;
	}
	if (coord.first != 10) {
		bool flag = false;
		int t = measure(coord.first, coord.second);
		for (int i = t; i >= 1; i--) {
			if (paper[i] == 5) continue;
			else {
				flag = true;
				check(coord.first, coord.second, i, false);
				paper[i]++;
				go(cnt + 1);
				check(coord.first, coord.second, i, true);
				paper[i]--;
			}
			if (!flag) return;
		}
	}
	else res = min(res, cnt);
	
}
int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) ans++;

		}
	}
	go(0);
	if (res == 25) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}