#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 1000
#define INF 987654321

using namespace std;

int T;
int K, W, H;
int battle_ship[26];
char map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sx, sy;
struct info {
	int cost;
	int x;
	int y;
	
	bool operator < (const info& a) const {
		return cost < a.cost;
	}
};
int main() {
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &K, &W, &H);
		memset(battle_ship, 0, sizeof(battle_ship));
		for (int i = 0; i < K; i++) {
			char alpha;
			int cost;
			scanf(" %1c %d", &alpha, &cost);
			battle_ship[alpha - 'A'] = cost;
		}
		
		fill(&dist[0][0], &dist[H][W], INF);
		int ans = INF;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == 'E') {
					sx = i;
					sy = j;
				}
			}
		}
		priority_queue<info> pq;
		pq.push({ 0,sx,sy });
		dist[sx][sy] = 0;

		while (!pq.empty()) {
			int cost = -pq.top().cost;
			int x = pq.top().x;
			int y = pq.top().y;
			pq.pop();
			if (x == 0 || y == 0 || x == H - 1 || y == W - 1) {
				ans = dist[x][y];
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				int next_cost = cost + battle_ship[map[nx][ny] - 'A'];
				if (dist[nx][ny] > next_cost) {
					dist[nx][ny] = next_cost;
					pq.push({ -next_cost,nx,ny });
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}