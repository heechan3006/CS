#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
int N, M, K;
int dx[] = { 0,0, 1,-1 };
int dy[] = { 1,-1,0,0 };
char map[100][100];
int D[100][100][80];
int len ;
string s;
int dfs(int x, int y, int idx) {
	if (D[x][y][idx] != -1) return D[x][y][idx];
	if (idx >= len) return 1;
	D[x][y][idx] = 0;
	for (int k = 1; k <= K; k++) {
		for (int i = 0; i < 4; i++) {
			int nx = x + k * dx[i];
			int ny = y + k * dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] != s[idx]) continue;
			D[x][y][idx] = D[x][y][idx] + dfs(nx, ny, idx + 1);
		}
	}
	return D[x][y][idx];
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> s;
	len = s.length();
	memset(D, -1, sizeof(D));
	
	len = s.size();
	int ans = 0;
	char tmp = s[0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == tmp) {
				ans += dfs(i, j, 1);
			}
		}
	}
	printf("%d\n", ans);
	
}