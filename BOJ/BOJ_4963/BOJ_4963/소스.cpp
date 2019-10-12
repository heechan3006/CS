#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int map[51][51];
int dist[51][51];
int H, W;
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };
queue<pair<int, int>> q;
void bfs(int x, int y) {
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (dist[nx][ny] != -1) continue;
			if (map[nx][ny] == 1){
				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	while (1){
		cin >> W >> H;
		memset(map, 0, sizeof(map));
		if (W == 0 && H == 0) break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				dist[i][j] = -1;
			}
		}
		int cnt = 0;
	
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (dist[i][j] == -1 && map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}