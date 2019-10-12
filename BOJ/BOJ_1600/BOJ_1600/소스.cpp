#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 200
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int dist[MAXN][MAXN][31];

int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dx1[] = { -2,-2,-1,-1,1,1,2,2 };
int dy1[] = { -1,1,-2,2,-2,2,-1,1 };

struct node {
	int x;
	int y;
	int cnt;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dist, -1, sizeof(dist));
	cin >> K >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	queue<node> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny]) continue;
			if (dist[nx][ny][cnt]==-1) {
				dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
				q.push({ nx,ny,cnt });
			}
		}
		if (cnt < K) {
			for (int k = 0; k < 8; k++) {
				int nx = x + dx1[k];
				int ny = y + dy1[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny]) continue;
				if (dist[nx][ny][cnt + 1] == -1) {
					dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= K; i++) {
		if (dist[N - 1][M - 1][i] == -1) continue;
		ans = min(ans, dist[N - 1][M - 1][i]);
	}
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}