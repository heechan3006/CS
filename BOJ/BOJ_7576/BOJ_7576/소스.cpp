#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;
int M, N;
int map[1001][1001];
int dist[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };

int main() {
	//cin >> M >> N;
	scanf("%d%d", &M, &N);
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> map[i][j];
			scanf("%d", &map[i][j]);
			dist[i][j] = -1;
			
			if (map[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
			else if (map[i][j] == -1) {
				dist[i][j] = 0;
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] == -1 && map[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == -1) {
				ans = -1;
				break;
			}
			if (ans < dist[i][j]) ans = dist[i][j];
			
		}
		if (ans == -1)
			break;
	}
	printf("%d\n", ans);
}