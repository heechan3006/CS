//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int max_h = 1;
int ans = 1;
void dfs(int x, int y, int h) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[nx][ny] <= h) continue;
		if (!visited[nx][ny]) {
			dfs(nx, ny, h);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max_h < map[i][j]) max_h = map[i][j];
		}
	}
	for (int k = 1; k <= max_h; k++) {
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > k && !visited[i][j]) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		if (ans < cnt) ans = cnt;
	}
	cout << ans << "\n";
	return 0;
}