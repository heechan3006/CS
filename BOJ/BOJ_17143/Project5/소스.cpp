#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100
using namespace std;

struct shark {
	int s;
	int d;
	int z;
};

shark map[MAXN][MAXN];
shark tmp_map[MAXN][MAXN];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int R, C, M;
void move_shark() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp_map[i][j] = { 0,0,0 };
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].z != 0) {
				int s = map[i][j].s;
				int d = map[i][j].d;
				if (d == 0 || d == 1) {
					s %= (R - 1) * 2;
				}
				else {
					s %= (C - 1) * 2;
				}
				int x = i;
				int y = j;
				while (s--) {
					if (x + dx[d] < 0 || y + dy[d] < 0 || x + dx[d] >= R || y + dy[d] >= C) {
						if (d == 0) d = 1;
						else if (d == 1) d = 0;
						else if (d == 2) d = 3;
						else if (d == 3) d = 2;
					}
					x += dx[d];
					y += dy[d];
				}
				if (tmp_map[x][y].z <map[i][j].z) tmp_map[x][y] = { map[i][j].s,d,map[i][j].z };
				map[i][j] = { 0,0,0 };
			}
		}
	}
	memcpy(map, tmp_map, sizeof(tmp_map));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--;
		c--;
		d--;
		map[r][c] = { s,d,z };
	}
	int ans = 0;
	for (int j = 0; j < C; j++) {
		for (int i = 0; i < R; i++) {
			if (M == 0) {
				cout << ans << "\n";
				return 0;
			}
			if (map[i][j].z != 0) {
				ans += map[i][j].z;
				map[i][j] = { 0,0,0 };
				M--;
				break;
			}
		}
		move_shark();
	}
	cout << ans << "\n";
	return 0;
}