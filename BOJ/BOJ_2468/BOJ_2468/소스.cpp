#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 100

int map[MAXN][MAXN];
int N;
bool visited[MAXN][MAXN];
int cnt;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y,int h) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] > h){
			dfs(nx, ny,h);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 1;
	for (int h = 1; h <= MAXN; h++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] > h){
					dfs(i, j,h);
					cnt++;
				}
			}
		}
		if (ans < cnt) ans = cnt;
	}
	printf("%d", ans);
	return 0;
}
