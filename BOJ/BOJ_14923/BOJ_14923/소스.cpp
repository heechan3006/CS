#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 1001
using namespace std;

int map[MAXN][MAXN];
int dist[MAXN][MAXN][2];
struct node {
	int x;
	int y;
	int cnt;
};
int Hx, Hy, Ex, Ey;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N, M;
int bfs() {
	queue<node> q;
	q.push({ Hx,Hy,0 });
	dist[Hx][Hy][0] = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (x == Ex && y == Ey) return dist[x][y][cnt];
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			
			if (map[nx][ny] == 1 && cnt == 0) {
				if (dist[nx][ny][1] != -1) continue;
				dist[nx][ny][1] = dist[x][y][0] + 1;
				q.push({ nx,ny,1 });
			}
			else if (map[nx][ny] == 0) {
				if (dist[nx][ny][cnt] != -1) continue;
				dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
				q.push({ nx,ny,cnt });
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d", &Hx, &Hy);
	scanf("%d%d", &Ex, &Ey);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(dist, -1, sizeof(dist));
	int ans = bfs();
	printf("%d", ans);
	return 0;
}