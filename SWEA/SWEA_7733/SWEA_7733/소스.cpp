#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 100

using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;

void dfs(int x, int y,int s) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] > s) {
			dfs(nx, ny, s);
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		memset(map, 0, sizeof(map));
		scanf("%d", &N);
		int max_value = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (max_value < map[i][j]) max_value = map[i][j];
			}
		}
		int ans = 1;
	
		for (int k = 1; k <= 100; k++){
			if (k > max_value) break;
			int cnt = 0;
			memset(visited, false, sizeof(visited));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] > k && !visited[i][j]) {
						dfs(i, j,k);
						cnt++;
					}
				}
			}
			if (ans < cnt) ans = cnt;
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}
