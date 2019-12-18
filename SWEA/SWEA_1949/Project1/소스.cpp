#include <iostream>
#include <cstring>
#define MAXN 8

using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, K;
int max_h ;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans ;
void dfs(int x, int y, int cnt, int flag) {
	if (ans < cnt) ans = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[x][y] > map[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, flag);
			visited[nx][ny] = false;
		}
		else if (!flag && map[x][y] > map[nx][ny] - K) {
			int tmp = map[nx][ny];
			map[nx][ny] = map[x][y] - 1;
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, flag + 1);
			visited[nx][ny] = false;
			map[nx][ny] = tmp;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N >> K;
		ans = 0;
		max_h = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (max_h < map[i][j]) max_h = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_h) {
					visited[i][j] = true;
					dfs(i, j, 1, 0);
					visited[i][j] = false;
				}
			}
		}
		cout <<"#"<<test_case<<" "<< ans << "\n";
	}
	return 0;
}