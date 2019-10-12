#include <iostream>
#include <cstring>
#define MAXN 500
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int remain[4][3] = { {0,1,2},{0,1,3},{0,2,3},{1,2,3} };
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int ans = 0;
void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
	}
	visited[x][y] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 1,map[i][j]);
			for (int k = 0; k < 4; k++) {
				bool flag = false;
				int sum = map[i][j];
				for (int idx = 0; idx < 3; idx++) {
					int nx = i + dx[remain[k][idx]];
					int ny = j + dy[remain[k][idx]];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
						flag = true;
						break;
					}
					sum += map[nx][ny];
				}
				if (!flag && ans < sum) ans = sum;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}