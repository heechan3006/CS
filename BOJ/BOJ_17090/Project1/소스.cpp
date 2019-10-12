#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 500
using namespace std;

char map[MAXN][MAXN];
bool check[MAXN][MAXN];

int N, M;
int cnt = 0;
queue<pair<int, int>> q;
bool is_range(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dir(char c) {
	if (c == 'U') return 3;
	else if (c == 'D') return 1;
	else if (c == 'R') return 0;
	else return 2;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int nx = i + dx[dir(map[i][j])];
			int ny = j + dy[dir(map[i][j])];
			if (!is_range(nx, ny)) {
				check[i][j] = true;
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (is_range(nx, ny) && !check[nx][ny]) {
				if (nx + dx[dir(map[nx][ny])] == x && ny + dy[dir(map[nx][ny])] == y) {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j]) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}