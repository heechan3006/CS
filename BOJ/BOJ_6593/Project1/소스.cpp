#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

char map[31][31][31];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,0,-1,0,1 };
int dz[] = { 0,0,-1,0,1,0 };
bool visited[31][31][31];
int L, R, C;
int sx, sy, sz, ex, ey, ez;
int ans;
struct node {
	int x;
	int y;
	int z;
};
int bfs() {
	queue<node> q;
	q.push({ sx,sy,sz });
	visited[sx][sy][sz] = true;
	int cnt = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--){
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			if (x == ex && y == ey && z == ez) return cnt;
			for (int k = 0; k < 6; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				int nz = z + dz[k];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
				if (visited[nx][ny][nz] || map[nx][ny][nz] == '#') continue;
				visited[nx][ny][nz] = true;
				q.push({ nx,ny,nz });
			
			}
		}
		cnt++;
	}
	return -1;
}
int main() {

	while (1) {
		scanf("%d%d%d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					scanf(" %1c", &map[i][j][k]);
					if (map[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
					else if (map[i][j][k] == 'E') {
						ex = i, ey = j, ez = k;
					}
				}
			}
		}
		
		int ans = bfs();
		if (ans == -1) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
	return 0;
}
