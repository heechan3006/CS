#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, char target) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		
		if (!visited[nx][ny] && map[nx][ny] == target) {
			dfs(nx, ny, target);
		}
	}
}
void dfs1(int x, int y, char target1,char target2) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!visited[nx][ny] && (map[nx][ny] == target1 || map[nx][ny] == target2)) {
			dfs1(nx, ny, target1,target2);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	int norm_cnt = 0;
	int abnorm_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j, map[i][j]);
				norm_cnt++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				if (map[i][j] == 'R' || map[i][j] == 'G') dfs1(i, j, 'R', 'G');
				else dfs(i, j, map[i][j]);
				abnorm_cnt++;
			}
		}
	}
	cout << norm_cnt << " "<< abnorm_cnt;
	return 0;
}
