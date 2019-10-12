#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[50][50];
bool visited[50][50];
int N, M;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int bfs(int x, int y) {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int q_size = q.size();
		
		while (q_size--){
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (map[cx][cy] == 1) return cnt;
			for (int k = 0; k < 8; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny]) continue;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
		cnt++;
	}
	return 0;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				int sum = bfs(i, j);
				if (ans < sum) ans = sum;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}