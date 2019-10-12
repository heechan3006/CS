#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 101

using namespace std;

int map[MAXN][MAXN][MAXN];

int dz[] = { -1,1,0,0,0,0 };
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,-1,1,0,0 };
int N, M, H;
int ans = 0;
typedef struct node {
	int z;
	int x;
	int y;
} node;
queue<node> q;
int main() {
	
	scanf("%d%d%d", &M, &N, &H);
	
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[k][i][j]);
				if (map[k][i][j] == 1) {
					q.push(node({ k, i, j }));
					
				}
				
			}
		}
	}
	while (!q.empty()) {
		int z = q.front().z;
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		
		for (int k = 0; k < 6; k++) {
			int nz = z + dz[k];
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
			if (map[nz][nx][ny]) continue;
			map[nz][nx][ny] = map[z][x][y] + 1;
			
			q.push({ nz,nx,ny });
			
		}
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[k][i][j] == 0) {
					printf("-1\n");
					return 0;
				}
				
				ans = max(ans, map[k][i][j]);
			
			}
		}
	}
	printf("%d\n", ans-1);
	return 0;
}
