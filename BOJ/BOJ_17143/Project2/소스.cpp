#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100

using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int R, C, K;
struct node {
	int s;
	int d;
	int z;
};
node map[MAXN][MAXN];

int ans = 0;
void solve() {

	for (int j = 0; j < C; j++) {
		if (K == 0) break;
		node tmp[MAXN][MAXN] = { 0 };
		for (int i = 0; i < R; i++) {
			if (map[i][j].z) {
				ans += map[i][j].z;
				map[i][j] = { 0,0,0 };
				K--;
				break;
			}
		}

		for (int i = 0; i < R; i++) {
			for (int k = 0; k < C; k++) {
				if (map[i][k].z) {
					
					if (map[i][k].d < 2) {
						int Last = map[i][k].s % (R * 2 - 2);
						int nx = i;
						while (Last--) {
							if (nx == 0 && map[i][k].d == 0) map[i][k].d = 1;
							if (nx == R - 1 && map[i][k].d == 1) map[i][k].d = 0;
							nx += dx[map[i][k].d];
						}
						if (map[i][k].z > tmp[nx][k].z) tmp[nx][k] = map[i][k];
					}
					else {
						int Last = map[i][k].s % (C * 2 - 2);
						int ny = k;
						while (Last--) {
							if (ny == 0 && map[i][k].d == 3) map[i][k].d = 2;
							if (ny == C - 1 && map[i][k].d == 2) map[i][k].d = 3;
							ny += dy[map[i][k].d];
						}
						if (map[i][k].z > tmp[i][ny].z) tmp[i][ny] = map[i][k];
					}
					map[i][k] = { 0,0,0 };
				}
			}
		}
		memcpy(map, tmp, sizeof(tmp));

	}
}
int main() {
	scanf("%d%d%d", &R, &C, &K);
	for (int i = 0; i < K; i++) {
		int tmp_x, tmp_y, tmp_s, tmp_d, tmp_z;
		scanf("%d%d%d%d%d", &tmp_x, &tmp_y, &tmp_s, &tmp_d, &tmp_z);
		tmp_x--;
		tmp_y--;
		tmp_d--;
		map[tmp_x][tmp_y] = { tmp_s, tmp_d, tmp_z };
	}
	solve();
	
	printf("%d\n", ans);
	return 0;
}

