#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAXN 1000

using namespace std;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN][10];
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,0 } });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cur_count = q.front().second.first;
		int cur_wall = q.front().second.second;
		if (cx == N - 1 && cy == M - 1) {
			printf("%d", cur_count);
			return 0;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny][cur_wall]) continue;
			if (map[nx][ny] == 0) {
				visited[nx][ny][cur_wall] = true;
				q.push({ {nx,ny},{cur_count + 1,cur_wall } });
			}
			else if (map[nx][ny] == 1) {
				if (cur_wall < K) {
					visited[nx][ny][cur_wall + 1] = true;
					q.push({ {nx,ny},{cur_count + 1,cur_wall + 1} });
				}
			}
		}
	}
	printf("-1");
	return 0;
}
