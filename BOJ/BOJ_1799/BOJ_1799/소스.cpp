#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 10
using namespace std;
int map[MAXN][MAXN];
int l[20];
int r[20];
int N;
int ans[2] = { 0,0 };



void dfs(int x,int y,int cnt, int color) {
	if (y >= N) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}
	if (x >= N) {
		ans[color] = max(ans[color], cnt);
		return;
	}
	if (map[x][y] && !l[N + y - x - 1] && !r[x + y]) {
		l[N + y - x - 1] = r[x + y] = 1;
		dfs(x, y + 2, cnt + 1, color);
		l[N + y - x - 1] = r[x + y] = 0;
	}
	dfs(x, y + 2, cnt, color);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	dfs(0, 0,0,0);
	dfs(0, 1, 0, 1);
	cout << ans[0]+ans[1] << "\n";
	return 0;
}