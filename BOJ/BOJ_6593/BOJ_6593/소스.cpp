#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define INF 987654321
using namespace std;

char map[31][31][31];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,0,-1,0,1 };
int dz[] = { 0,0,-1,0,1,0 };
bool visited[31][31][31];
int L, R, C;
int sx, sy, sz,ex,ey,ez;
int ans;

void dfs(int x, int y, int z, int cnt) {
	
	if (x == ex && y == ey && z == ez) {
		if (ans > cnt) ans = cnt;
			return;
	}
	
	for (int k = 0; k < 6; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		int nz = z + dz[k];
		if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
		if (visited[nx][ny][nz]) continue;
		if (map[nx][ny][nz] != '#') {
			visited[nx][ny][nz] = true;
			dfs(nx, ny, nz, cnt + 1);
		}
	}
}
int main() {
	
	while (1){
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
		ans = INF;
		visited[sx][sy][sz] = true;
		dfs(sx, sy, sz,0);
		if (ans == INF) {
			printf("Trapped!\n");
		}
		else{
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
	return 0;
}
