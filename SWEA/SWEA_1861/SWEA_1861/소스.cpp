#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int N;
int map[1001][1001];
int dist[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sum = 0;
void dfs(int x, int y) {
	dist[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if ((map[nx][ny] - map[x][y]) == 1) {
			if (dist[nx][ny] == 0) dfs(nx, ny);
			dist[x][y] = max(dist[x][y], dist[nx][ny] + 1);
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<= t; test_case++){
		scanf("%d", &N);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				dist[i][j] = 0;
			}
		}
		int ans = 0;
		int loc = 10e5;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] == 0) dfs(i, j);
			}
		}
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ans < dist[i][j]) {
					ans = dist[i][j];
					loc = map[i][j];
				}
				else if (ans == dist[i][j]) {
					loc = min(loc, map[i][j]);
				}
			}
		}
	
	printf("#%d %d %d\n",test_case, loc, ans);
	}
	return 0;
}