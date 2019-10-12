#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int map[101][101];
int dist[101][101];
bool visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	map[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == 1) {
			dfs(nx, ny, cnt);
		}
	}
}
int bfs(int cnt) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			dist[i][j] = -1;
			if (map[i][j] == cnt) {
				q.push({ i,j });
				visited[i][j] = true;
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		if (map[cx][cy] != cnt && map[cx][cy] != 0) {
			return dist[cx][cy] - 1;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] != cnt) {
				visited[nx][ny] = true;
				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
	
}
int main() {
	scanf("%d", &N);
	memset(map, 0, sizeof(map));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			if (map[i][j] != 0){
				dfs(i, j, cnt++);
			}
		}
	}
	int ans = 10e5;
	for (int i = 1; i < cnt; i++) {
		ans = min(ans, bfs(i));
	}
	printf("%d\n", ans);
}