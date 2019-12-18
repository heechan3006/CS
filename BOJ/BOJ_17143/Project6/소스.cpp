#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
using namespace std;

struct shark {
	int s;
	int d;
	int z;
};

shark map[MAXN][MAXN];
shark tmp_map[MAXN][MAXN];
int R, C,M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
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
		
		memset(tmp_map, 0, sizeof(tmp_map));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!map[i][j].z) continue;
				int z = map[i][j].z;
				int s;
				int d = map[i][j].d;
				if (d < 2) s = map[i][j].s % (2 * (R - 1));
				else s = map[i][j].s % (2 * (C - 1));
				int x = i;
				int y = j;
				while (s--) {
					if (x + dx[d] < 0 || y + dy[d] < 0 || x + dx[d] >= R || y + dy[d] >= C) {
						d = (4 - d+1) % 4;
					}
					x += dx[d];
					y += dy[d];
				}
				if (tmp_map[x][y].z) {
					if (tmp_map[x][y].z < z) {
						tmp_map[x][y] = { map[i][j].s,d,z };
						M--;
					}
				}
				else {
					tmp_map[x][y] = { map[i][j].s,d,z };
				}
			}
		}
		memcpy(map, tmp_map, sizeof(tmp_map));
	}
	cout << ans << "\n";
	return 0;
}