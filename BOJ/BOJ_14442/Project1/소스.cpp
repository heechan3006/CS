#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1000+1
using namespace std;
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
struct info {
	int x;
	int y;
	int cnt;
};
int bfs() {
	queue<info> q;
	q.push({ 1,1,0 });
	visited[1][1] |= (1<<0);
	int res = 1;
	while (!q.empty()) {
		int q_size = q.size();
		
		while (q_size--){
			int x = q.front().x;
			int y = q.front().y;
			int cnt = q.front().cnt;
			if (x == N && y == M) return res;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
				if (map[nx][ny] == 1 && cnt < K) {
					if (visited[nx][ny] & (1 << cnt + 1)) continue;

					visited[nx][ny] |= (1<<cnt+1);
					q.push({ nx,ny,cnt + 1 });
					
				}
				else if (map[nx][ny] == 0) {
					if (visited[nx][ny] & (1 << cnt)) continue;
					visited[nx][ny] |= (1<<cnt);
					q.push({ nx,ny,cnt });
				}
			}
		}
		res++;
	}
	return -1;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	memset(visited, false, sizeof(visited));
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}