#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAXN 1000
using namespace std;

int N, M;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	scanf("%d%d", &N, &M);
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (i == 0 && map[i][j] == 0) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == N - 1) {
			cnt = 1;
			break;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!visited[nx][ny] && map[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	if (cnt == 0){
		printf("NO");
	}
	else {
		printf("YES");
	}
	return 0;
}
