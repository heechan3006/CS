#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXN 50
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int N, M, sx, sy, d;
int map[MAXN][MAXN];
int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &sx, &sy, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int nx, ny;
	map[sx][sy] = 2;
	int ans = 1;
	while (1) {
		int dir = d;
		bool flag = false;
		for (int k = 0; k < 4; k++) {
			dir--;
			if (dir < 0) dir = 3;
			nx = sx + dx[dir];
			ny = sy + dy[dir];
			if (map[nx][ny] == 0) {
				flag = true;
				map[nx][ny] = 2;
				ans++;
				break;
			}
		}
		if (flag) {
			d = dir;
			sx = nx;
			sy = ny;
		}
		else {
			if (d == 2) dir = 0;
			else if (d == 0) dir = 2;
			else if (d == 1) dir = 3;
			else dir = 1;
			if (map[sx + dx[dir]][sy + dy[dir]] == 1) break;
			else {
				sx += dx[dir];
				sy += dy[dir];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}