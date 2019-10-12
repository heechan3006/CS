#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

int map[5][5][5];
int copy_map[5][5][5];
int dist[5][5][5];
int d[5];
int dz[] = {-1,1,0,0,0,0};
int dx[] = {0,0,0,1,0,-1};
int dy[] = {0,0,1,0,-1,0};

int ans = 98765432;
void bfs() {
	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int cz, cx, cy;
		tie(cz, cx, cy) = q.front();
		q.pop();
		if (cz == 4 && cx == 4 && cy == 4) {
			if (ans > dist[cz][cx][cy]) {
				ans = dist[cz][cx][cy];
				if (ans == 12) {
					printf("12\n");
					exit(0);
				}
			}
			return;
		}
		
		for (int k = 0; k < 6; k++) {
			int nz = cz + dz[k];
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nz < 0 || nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
			if (dist[nz][nx][ny] == -1 && copy_map[nz][nx][ny]) {
				dist[nz][nx][ny] = dist[cz][cx][cy] + 1;
				q.push({ nz,nx,ny });
			}
		}
	}
	return;
}
void rotate_cube(int z) {
	int tmp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[j][4 - i] = copy_map[z][i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			copy_map[z][i][j] = tmp[i][j];
		}
	}
}
int main() {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> map[k][i][j];
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		d[i] = i;
	}
	do {
		for (int i = 0; i < 5; i++) {
			memcpy(copy_map[d[i]], map[i], sizeof(map[i]));
		}
		for (int i0 = 0; i0 < 4; i0++) {
			rotate_cube(0);
			if (!copy_map[0][0][0]) continue;
			for (int i1 = 0; i1 < 4; i1++) {
				rotate_cube(1);
				for (int i2 = 0; i2 < 4; i2++) {
					rotate_cube(2);
					for (int i3 = 0; i3 < 4; i3++) {
						rotate_cube(3);
						for (int i4 = 0; i4 < 4; i4++) {
							rotate_cube(4);
							if (copy_map[4][4][4]) bfs();
						}
					}
				}
			}
		}
	} while (next_permutation(d, d + 5));
	if (ans == 98765432) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}