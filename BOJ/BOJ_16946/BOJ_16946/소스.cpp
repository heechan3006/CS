#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1002

using namespace std;
int N, M;
int map[MAXN][MAXN];
int ans[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>>q;
	queue<pair<int, int>>q1;
	q.push({ x,y });
	q1.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == 0){
				visited[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
				q1.push({ nx,ny });
				
			}

		}
	}
	bool visited1[MAXN][MAXN] = { 0, };
	while (!q1.empty()) {
		int cx = q1.front().first;
		int cy = q1.front().second;
		q1.pop();
		for (int k = 0 ; k < 4; k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited1[nx][ny]) continue;
			if (map[nx][ny] == 1) {
				ans[nx][ny] += cnt;
				visited1[nx][ny] = true;
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				ans[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", ans[i][j] % 10);
		}
		printf("\n");
	}
	return 0;
}
