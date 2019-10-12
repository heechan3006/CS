//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 50
using namespace std;
int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];

int N, M, T;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ccw[] = { 0,3,2,1 };
int cw[] = { 0,1,2,3 };
int sx, sy = -1;
int ex, ey;
void rotate_air(int x, int y, int dirs[]) {
	
	int sx = x;
	int sy = y;
	int d = 0;
	int nx = x + dx[dirs[d]];
	int ny = y + dy[dirs[d]];
	x += dx[dirs[d]];
	y += dy[dirs[d]];
	map[sx][sy] = -1;
	map[nx][ny] = 0;
	while (1) {
		if (nx + dx[dirs[d]] < 0 || ny + dy[dirs[d]] < 0 || nx + dx[dirs[d]] >= N || ny + dy[dirs[d]] >= M) {
			d++;
		}
		nx += dx[dirs[d]];
		ny += dy[dirs[d]];
		if (nx == sx && ny == sy) break;
		map[nx][ny] = copy_map[x][y];
		x = nx;
		y = ny;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1){
				if (sy == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	while (T--) {
		//확산
		queue<pair<int, int> > q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = 0;		
				if (map[i][j] > 0) q.push({ i,j });
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int remain = map[x][y];
			int tmp = map[x][y]/5;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny] == -1) continue;
				copy_map[nx][ny] += tmp;
				remain -= tmp;
			}
			copy_map[x][y] += remain;
		}
		//공기청정기
		memcpy(map, copy_map, sizeof(copy_map));
		rotate_air(sx, sy, ccw);
		rotate_air(ex, ey, cw);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) ans+=map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
