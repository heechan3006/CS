#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int map[102][102];
int dist[102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	for (int test_case = 1; test_case <= 10; test_case++){
		scanf("%d", &t);
		fill(&dist[0][0], &dist[102][102], -1);
		memset(map, 0, sizeof(map));
		int sx, sy, ex, ey;
		for(int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					sx = i;
					sy = j;
				}
				else if (map[i][j] == 3) {
					ex = i;
					ey = j;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({ sx,sy });
		dist[sx][sy] = 0;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
				if (dist[nx][ny] == -1 && map[nx][ny] != 1) {
					dist[nx][ny] = dist[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
		if (dist[ex][ey] != -1) {
			printf("#%d 1\n",t);
		}
		else {
			printf("#%d 0\n",t);
		}
	}
	return 0;
}