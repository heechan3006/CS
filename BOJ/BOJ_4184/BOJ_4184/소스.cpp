#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1000 + 1
#define INF 987654321
using namespace std;
int R, C,N;
int map[MAXN][MAXN];
int sx, sy, ex, ey;
int dist[MAXN][MAXN];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1};
struct info {
	int cost;
	int x;
	int y;
	bool operator < (const info& a) const {
		return cost < a.cost;
	}
};

int dijkstra() {
	priority_queue<info> pq;
	pq.push({ 0,sx,sy });
	dist[sx][sy] = 0;
	while (!pq.empty()) {
		int q_size = pq.size();
		while (q_size--){
			int x = pq.top().x;
			int y = pq.top().y;
			int cost = -pq.top().cost;
			pq.pop();
			if (x == ex && y == ey) return dist[x][y];
			
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;
				int next_cost;
				if (map[x][y] == k) {
					next_cost = cost;
				}
				else {
					next_cost = cost + 1;
				}
				if (dist[nx][ny] > next_cost) {
					dist[nx][ny] = next_cost;
					pq.push({ -next_cost,nx,ny });
				}
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%1d", &map[i][j]);
			
		}
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		fill(&dist[1][1], &dist[R][C], INF);
		int ans = dijkstra();
		printf("%d\n", ans);
	}
	return 0;
}