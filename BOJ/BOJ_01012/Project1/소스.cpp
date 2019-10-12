#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k;
int map[51][51];
bool check[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int i, int j) {
	check[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int cx = i + dx[k];
		int cy = j + dy[k];
		
		if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
			continue;
		}
		if (map[cx][cy] == 0 || check[cx][cy] == true) {
			continue;
		}
		dfs(cx, cy);
	}
}
int main() {
	int x, y;
	int cnt;
	int T;
	cin >> T;
	for (int c = 0; c < T; c++) {
		cnt = 0;
		cin >> m >> n >> k;
		fill(&map[0][0], &map[50][50], 0);
		fill(&check[0][0], &check[50][50], false);
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !check[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}