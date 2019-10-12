#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100

using namespace std;

char map[MAXN][MAXN];
struct node {
	int x;
	int y;
	int d;
	int cnt;
};
int dist[MAXN][MAXN][4];
int N, M;
int sx, sy, ex, ey = -1;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<node> q;

int bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		int cnt = q.front().cnt;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int next_cnt = cnt;
			if (d != k) next_cnt++;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '*') continue;
			if (dist[nx][ny][k] == -1 || dist[nx][ny][k] > next_cnt) {
				dist[nx][ny][k] = next_cnt;
				q.push({ nx,ny,k,next_cnt });
			}
		}
	}
	int ans = 987654321;
	for (int i = 0; i < 4; i++) {
		if (dist[ex][ey][i] == -1) continue;
		ans = min(ans, dist[ex][ey][i]);
	}
	return ans;
}
int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'C') {
				if (ey == -1) ex = i, ey = j;
				else sx = i, sy = j;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		q.push({ sx,sy,i,0 });
		dist[sx][sy][i] = 0;
	}

	
	printf("%d\n", bfs());

}