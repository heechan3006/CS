#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int map[100][100];
int dist[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d", &N);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				dist[i][j] = 10e5;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++){
				scanf("%1d", &map[i][j]);
			}
		}
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		dist[0][0] = 0;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (dist[nx][ny] > dist[cx][cy] + map[nx][ny]) {
					dist[nx][ny] = dist[cx][cy] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
		printf("#%d %d\n", test_case, dist[N - 1][N - 1]);
	}
	return 0;
}