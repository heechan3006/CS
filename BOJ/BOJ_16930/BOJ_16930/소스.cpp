#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 1000
using namespace std;


char map[MAXN][MAXN];
int dist[MAXN][MAXN];
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sx, sy, ex, ey;
queue<pair<int, int>> q;
int bfs() {
	
	dist[sx][sy] = 0;
	q.push({ sx,sy });
	int ans = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == ex && y == ey) return dist[x][y];
			
			for (int k = 0; k < 4; k++) {
				
				for (int l = 1; l <= K; l++){
					int nx = x+l*dx[k];
					int ny = y+l*dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '#') break;
					if (dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny });
					}
					else if (dist[nx][ny] < dist[x][y] + 1) break;
					
				}
			}
		}
		
	}
	return -1;
}
int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	sx--;
	sy--;
	ex--;
	ey--;
	int ret = bfs();
	
	printf("%d\n", ret);
}