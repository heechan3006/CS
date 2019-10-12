#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;
#define MAXN 1001
int N, M;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int ans = 0;
	scanf("%d %d", &M,&N);
	queue <pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			dist[i][j] = -1;
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == 0 && dist[nx][ny] == -1) {
					dist[nx][ny] = dist[cx][cy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] > ans) {
				ans = dist[i][j];
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && dist[i][j] == -1) {
				ans = -1;
			}
		}
	}
	printf("%d", ans);
	
}
