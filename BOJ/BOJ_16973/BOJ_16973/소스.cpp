#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 1001
using namespace std;
int N, M, H, W, Sx, Sy, Fx, Fy;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool check(int x, int y, int k) {
	if (k == 0) {
		for (int i = x; i < x + H; i++) {
			if (map[i][y + W - 1] == 1) return false;
		}
	}
	else if (k == 1) {
		for (int i = x; i < x + H; i++) {
			if (map[i][y] == 1) return false;
		}
	}
	else if (k == 2) {
		for (int i = y; i < y + W; i++) {
			if (map[x + H - 1][i] == 1) return false;
		}
	}
	else {
		for (int i = y; i < y + W; i++) {
			if (map[x][i] == 1) return false;
		}
	}
	return true;
}
int bfs() {
	queue<pair<int, int>> q;
	q.push({ Sx,Sy });
	dist[Sx][Sy] = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		if (cx == Fx && cy == Fy) return dist[cx][cy];
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if(nx <= 0 || ny <= 0 || nx + H -1> N || ny + W -1> M) continue;
			if (dist[nx][ny] != -1) continue;
			if (check(nx, ny, k)) {
				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &N, &M);
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d%d%d%d%d", &H, &W, &Sx, &Sy, &Fx, &Fy);
	int ans = bfs();
	printf("%d", ans);
}