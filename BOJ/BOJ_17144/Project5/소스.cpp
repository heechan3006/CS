#include <iostream>
#include <cstring>
#define MAXN 50

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int R, C, T;
int sx = -1, sy;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ccw[] = { 0,3,2,1 };
int cw[] = { 0,1,2,3 };
void circulate(int x, int y, int dirs[]) {
	int d = 0;
	int nx = x+dx[dirs[d]];
	int ny = y+dy[dirs[d]];
	map[nx][ny] = 0;
	while (!(nx+dx[dirs[d]]==x && ny+dy[dirs[d]]==y)) {
		if (nx+dx[dirs[d]] < 0 || ny+dy[dirs[d]] < 0 || nx +dx[dirs[d]]>= R || ny +dy[dirs[d]]>= C) {
			d = (d + 1) % 4;
		}
		map[nx + dx[dirs[d]]][ny + dy[dirs[d]]] = copy_map[nx][ny];
		nx += dx[dirs[d]];
		ny += dy[dirs[d]];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (sx == -1) sx = i, sy = j;
				map[i][j] = 0;
			}
		}
	}
	while (T--) {
		memcpy(copy_map, map, sizeof(map));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j]) {
					int remain = map[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
						if ((nx == sx && ny == sy) || (nx == sx + 1 && ny == sy)) continue;
						copy_map[nx][ny] += remain;
						copy_map[i][j] -= remain;
					}
				}
			}
		}
		memcpy(map, copy_map, sizeof(copy_map));
		circulate(sx,sy,ccw);
		circulate(sx + 1, sy, cw);
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
