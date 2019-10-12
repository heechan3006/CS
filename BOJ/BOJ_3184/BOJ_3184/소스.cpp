#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 250
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;
int wolf, sheep;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == '#') continue;
		else {
			if (map[nx][ny] == 'o') sheep++;
			else if (map[nx][ny] == 'v') wolf++;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	int ans_1 = 0;
	int ans_2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'o' && !visited[i][j]) {
				sheep = 1;
				wolf = 0;
				dfs(i, j);
				if (sheep > wolf) ans_1 += sheep;
				else ans_2 += wolf;
			}
			else if (map[i][j] == 'v' && !visited[i][j]) {
				sheep = 0;
				wolf = 1;
				dfs(i, j);
				if (sheep > wolf) ans_1 += sheep;
				else ans_2 += wolf;
			}
		}
	}
	printf("%d %d", ans_1, ans_2);
	return 0;
}