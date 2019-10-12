#include <iostream>

using namespace std;

char map[15][15];
int used[15][15];

int N, M;
int ans;
bool check_range(int x, int y, int k) {
	if (x - k < 0 || x + k >= N || y - k < 0 || y + k >= M) return false;
	return true;
}
bool is_possible(int x, int y, int k) {
	if (map[x][y] != '#' || used[x][y] != 0) return false;
	for (int i = 1; i <= k; i++) {
		if (map[x - i][y] != '#' || map[x + i][y] != '#' || map[x][y - i] != '#' || map[x][y + i] != '#') return false;
		if (used[x - i][y] != 0 || used[x + i][y] != 0 || used[x][y - i] != 0 || used[x][y + i] != 0) return false;
	}
	return true;
}
void check(int x, int y, int k, int kind) {
	used[x][y] = kind;
	for (int i = 1; i <= k; i++) {
		used[x - i][y] = used[x + i][y] = used[x][y - i] = used[x][y + i] = kind;
	}
}
void dfs(int x, int y, int cnt) {
	if (cnt > 2) {
		int cnt_a = 0;
		int cnt_b = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (used[i][j] == 1) cnt_a++;
				if (used[i][j] == 2) cnt_b++;
			}
		}
		if (ans < cnt_a * cnt_b) ans = cnt_a * cnt_b;
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]=='#') {
				for (int k = 0; k < 8; k++) {
					if (k == 0) {
						if (used[i][j] == 0) {
							used[i][j] = cnt;
							dfs(i, j, cnt + 1);
							used[i][j] = 0;
						}
						else break;
					}
					else {
						if (!check_range(i, j, k)) break;
						if (!is_possible(i, j, k)) break;
						check(i, j, k, cnt);
						dfs(i, j, cnt + 1);
						check(i, j, k, 0);
					}
				}	
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	ans = 0;
	dfs(0, 0, 1);
	cout << ans << "\n";
	return 0;
}