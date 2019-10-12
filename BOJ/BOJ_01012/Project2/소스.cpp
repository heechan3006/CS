#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int map[51][51];
bool check[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int i, int j) {
	stack<pair<int, int>> s;
	s.push(pair<int, int>(i, j));
	check[i][j] = true;
	while (!s.empty()) {
		int cx = s.top().first;
		int cy = s.top().second;
		s.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (map[nx][ny] == 0 || check[nx][ny] == true) {
				continue;
			}
			check[nx][ny] = true;
			s.push(pair<int, int>(cx, cy));
			s.push(pair<int, int>(nx, ny));
			break;
		}
	}
}
int main() {
	int x, y;
	int cnt ;
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