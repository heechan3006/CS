#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 100
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &N, &M);
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'W') {
				q.push({ i,j });
				visited[i][j] = true;
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
			if (map[nx][ny] == '.' && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (map[nx][ny] == '+') {
				while (map[nx][ny] != '.') {
					
					if (map[nx][ny] == '#') {
						nx -= dx[k];
						ny -= dy[k];
						break;
					}
					nx += dx[k];
					ny += dy[k];
				}
				if (!visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.' && !visited[i][j]) {
				printf("P");
			}
			else {
				printf("%c",map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}