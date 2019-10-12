#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 50

using namespace std;

char map[MAXN][MAXN];
//'.', '/', '\'
int dist[MAXN][MAXN][4];
int N;
int sx, sy = -1, ex, ey;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
struct node {
	int x;
	int y;
	int dir;
};
bool is_possible(int x, int y, int dir) {
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	
	return true;
}
int change_dir(int dir, int mode) {
	if (mode == 1) {
		if (dir == 0) return 3;
		else if (dir == 1) return 2;
		else if (dir == 2) return 1;
		else return 0;
	}
	else if (mode == 2) {
		if (dir == 0) return 1;
		else if (dir == 1) return 0;
		else if (dir == 2) return 3;
		else return 2;
	}
}
int main() {
	scanf("%d", &N);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '#') {
				if (sy == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
				map[i][j] = '!';
			}
		}
	}
	queue<node> q;
	for (int i = 0; i < 4; i++) {
		q.push({ sx,sy,i });
		dist[sx][sy][i] = 0;
	}

	int ans = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;

		if (x == ex && y == ey) {
			ans = dist[x][y][dir];
			break;
		}
		q.pop();

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		while (is_possible(nx, ny, dir) && map[nx][ny] == '.') {
			nx += dx[dir];
			ny += dy[dir];

		}
		if (is_possible(nx, ny, dir)&&map[nx][ny]=='!') {

			dist[nx][ny][dir] = dist[x][y][dir];
			q.push({ nx,ny,dir });
			int nxt_dir = change_dir(dir, 1);
			if (dist[nx][ny][nxt_dir] == -1) {
				dist[nx][ny][nxt_dir] = dist[x][y][dir] + 1;
				q.push({ nx,ny,nxt_dir });
			}
			nxt_dir = change_dir(dir, 2);
			if (dist[nx][ny][nxt_dir] == -1) {
				dist[nx][ny][nxt_dir] = dist[x][y][dir] + 1;
				q.push({ nx,ny,nxt_dir });
			}
		}
	}
	printf("%d\n", ans);
	return 0;

}