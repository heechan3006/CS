#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 300
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int N, M, R;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dirs[] = { 1,0,3,2 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
		}
	}
	int n = N;
	int m = M;
	for (int i = 0; i < min(N, M) / 2; i++) {
		int x = i;
		int y = i;
		int cycle = R % (2 * (N + M -4*i- 2));
		int tmp_x = x;
		int tmp_y = y;
		int tmp_d = 0;
		int tmp_nx = x;
		int tmp_ny = y;
		int d = 0;
		while (cycle--) {
			tmp_nx += dx[dirs[d]];
			tmp_ny += dy[dirs[d]];
			if (tmp_nx < i || tmp_ny < i || tmp_nx >= N - i  || tmp_ny >= M - i ) {
				tmp_nx -= dx[dirs[d]];
				tmp_ny -= dy[dirs[d]];
				d++;
				tmp_nx += dx[dirs[d]];
				tmp_ny += dy[dirs[d]];
			}
		}
		copy_map[tmp_nx][tmp_ny] = map[tmp_x][tmp_y];
		while (1) {
			tmp_nx += dx[dirs[d]];
			tmp_ny += dy[dirs[d]];
			tmp_x += dx[dirs[tmp_d]];
			tmp_y += dy[dirs[tmp_d]];
			if (tmp_nx < i || tmp_ny < i || tmp_nx >= N - i || tmp_ny >= M - i ) {
				tmp_nx -= dx[dirs[d]];
				tmp_ny -= dy[dirs[d]];
				d++;
				if (d > 3) d = 0;
				tmp_nx += dx[dirs[d]];
				tmp_ny += dy[dirs[d]];
			}
			if (tmp_x < i || tmp_y < i || tmp_x >= N - i || tmp_y >= M - i ) {
				tmp_x -= dx[dirs[tmp_d]];
				tmp_y -= dy[dirs[tmp_d]];
				tmp_d++;
				tmp_x += dx[dirs[tmp_d]];
				tmp_y += dy[dirs[tmp_d]];
			}
			if (tmp_x == x && tmp_y == y) break;
			copy_map[tmp_nx][tmp_ny] = map[tmp_x][tmp_y];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << copy_map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
