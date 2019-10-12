#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[50][50];
int visited[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
//동 서 남 북
int wall[] = { 4,1,8,2 };
int Group[50 * 50];
queue<pair<int, int>> q;
int idx;
void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = idx;
	Group[idx]++;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[cx][cy] & wall[k]) continue;
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = idx;
				Group[idx]++;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	idx = 0;
	// 조건 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				idx++;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", idx);
	// 조건 2
	int ans1 = 0;
	for (int i = 1; i <= idx; i++) {
		if (ans1 < Group[i]) ans1 = Group[i];
	}
	printf("%d\n", ans1);
	// 조건 3
	int ans2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] != visited[i][j]) {
					int sum = Group[visited[nx][ny]] + Group[visited[i][j]];
					if (ans2 < sum) ans2 = sum;
				}
			}
		}
	}
	printf("%d\n", ans2);
	return 0;
}