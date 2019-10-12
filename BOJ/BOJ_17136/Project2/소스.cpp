#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int map[10][10];
int num[] = { 5,5,5,5,5 };
int cnt = 0;
int ans = INF;
bool is_possible(int x, int y, int size) {
	//if (x + size > 9 || y + size > 9) return false;
	for (int i = x; i < x + size + 1; i++) {
		for (int j = y; j < y + size + 1; j++) {
			if (i>=10 || j>=10 ||map[i][j] == 0) return false;
		}
	}
	return true;
}
void check(int x, int y, int size, bool flag) {
	for (int i = x; i < x + size + 1; i++) {
		for (int j = y; j < y + size + 1; j++) {
			if (flag) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
}
void dfs(int x, int y, int num_cnt,int used_cnt) {
	if (ans <= used_cnt) return;
	if (y == 10) {
		dfs(x + 1, 0,num_cnt,used_cnt);
		return;
	}
	if (num_cnt == cnt) {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += 5 - num[i];
		}
		if (ans > sum) ans = sum;
		return;
	}
	if (!map[x][y]) {
		dfs(x, y + 1, num_cnt, used_cnt);
		return;
	}
	for (int i = 4; i >= 0; i--) {
		if (num[i] == 0) continue;
		if (is_possible(x, y, i)) {
			num[i]--;
			check(x, y, i, false);
			dfs(x, y+i+1, num_cnt + (i + 1) * (i + 1), used_cnt + 1);
			check(x, y, i, true);
			num[i]++;
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) cnt++;
		}
	}
	dfs(0, 0, 0,0);
	if (ans == INF) cout << "-1\n";
	else {
		cout << ans << "\n";
	}
	
	return 0;
}