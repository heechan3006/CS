#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 50

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int R, C, T;
int sx, sy = -1;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ccw[] = { 1,0,3,2 };
int cw[] = { 1,2,3,0 };
void air_spread() {
	memset(copy_map, 0, sizeof(copy_map));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j]) {
				int A = map[i][j]/5;
				int remain = map[i][j];
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if ((nx == sx && ny == sy) || (nx == sx + 1 && ny == sy)) continue;
					copy_map[nx][ny] += A;
					remain -= A;
				}
				copy_map[i][j] += remain;
			}
		}
	}
}
void air_rotate(int x, int y, int dirs[]) {
	
	int sx = x;
	int sy = y;
	int nx = x;
	int ny = y+1;
	map[x][y + 1] = 0;
	y += 1;
	int d = 0;
	while (1) {
		if (nx + dx[dirs[d]] < 0 || ny + dy[dirs[d]] < 0 || nx + dx[dirs[d]] >= R || y + dy[dirs[d]] >= C) {
			d = (d + 1) % 4;
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
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (sy == -1) sx = i, sy = j;
				map[i][j] = 0;
			}
		}
	}
	while (T--) {
		air_spread();
		memcpy(map, copy_map, sizeof(copy_map));
		air_rotate(sx, sy, ccw);
		air_rotate(sx+1, sy, cw);
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