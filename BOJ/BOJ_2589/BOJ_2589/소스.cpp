#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char map[51][51];
int dist[51][51];
int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	dist[x][y] = 0;
	int cnt = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (dist[cx][cy] > cnt) cnt = dist[cx][cy];
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] != -1 || map[nx][ny] == 'W') continue;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}
	return cnt;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				memset(dist, -1, sizeof(dist));
				int sum = bfs(i, j);
				if (ans < sum) ans = sum;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
