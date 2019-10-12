#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[50][50];
int dist[50][50];

int tunnel[] = { (1 << 4) - 1,(1 << 3) + (1 << 1),
				(1 << 2) + (1 << 0),(1 << 2) + (1 << 1),
				(1 << 3) + (1 << 2),(1 << 3) + (1 << 0),
				(1 << 1) + (1 << 0) };
int N, M;
int sx, sy, L;
struct node {
	int x;
	int y;
	int idx;
};
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N >> M >> sx >> sy >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		memset(dist, -1, sizeof(dist));
		queue<node> q;
		q.push({ sx,sy,map[sx][sy] });
		dist[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int cur_idx = q.front().idx;
			q.pop();
			if (dist[x][y] >= L) break;
			for (int k = 0; k < 4; k++) {

				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 0 || dist[nx][ny] != -1) continue;
				int next_idx = map[nx][ny];
				bool flag = false;
				if (1 <= cur_idx && cur_idx <= 3) {
					if (tunnel[cur_idx - 1] & (1 << k)) {
						if (tunnel[next_idx - 1] & (1 << k)) {
							flag = true;

						}
					}
				}
				else {
					if ((((1<<4)-1)-tunnel[cur_idx - 1]) & (1 << k)) {
						if (tunnel[next_idx - 1] & (1 << k)) {
							flag = true;
						}
					}
				}
				if (flag) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny,next_idx });
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dist[i][j] < L && dist[i][j] != -1) {
					ans++;
				}
			}
		}
		cout << "#" << test_case<<" "<<ans << "\n";
	}
	return 0;
}