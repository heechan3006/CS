#include <iostream>
#include <cstring>
using namespace std;
int ans = 4;
int map[31][12];
int N, M, H;
bool check() {
	for (int j = 1; j <= N; j++) {
		int x = 1, y = j;
		while (x<=H) {
			if (map[x][y]) y++;
			else if (map[x][y - 1]) y--;
			x++;
		}
		if (y != j) return false;
	}
	return true;
}
void dfs(int cnt) {
	if (ans == 0) return;
	if (ans <= cnt) return;
	if (cnt >= 0) {
		if (check()) {
			ans = cnt;
			return;
		}
	}
	for (int j = 1; j < N; j++) {
		for (int i = 1; i <= H; i++) {
			if (map[i][j]) continue;
			if (map[i][j - 1] || map[i][j + 1]) continue;
			map[i][j] = 1;
			dfs(cnt + 1);
			map[i][j] = 0;
			while (i<=H) {
				if (map[i][j - 1] || map[i][j + 1]) break;
				i++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	dfs(0);
	if (ans == 4) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}