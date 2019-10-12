#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char map[11][11];
int N, M;
bool visited[11][11][11][11];
int srx, sry, sbx, sby;
struct node {
	int rx;
	int ry;
	int bx;
	int by;
};
int dx[] = { 0,0,1,-1};
int dy[] = { 1,-1,0,0 };
int hole_x, hole_y;
int bfs() {
	queue<node> q;
	q.push({ srx,sry,sbx,sby });
	visited[srx][sry][sbx][sby] = true;
	int time = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--){
			int rx = q.front().rx;
			int ry = q.front().ry;
			int bx = q.front().bx;
			int by = q.front().by;
			q.pop();

			if (map[rx][ry] == 'O' && (rx != bx || ry != by)) {
				return time;
			}
			for (int k = 0; k < 4; k++) {
				int nrx = rx;
				int nry = ry;
				int nbx = bx;
				int nby = by;
			
				while (map[nrx+dx[k]][nry+dy[k]] != '#' && map[nrx][nry] != 'O') {
					
					nrx += dx[k];
					nry += dy[k];

				}
				while (map[nbx+dx[k]][nby+dy[k]] != '#' && map[nbx][nby] != 'O') {
					
					nbx += dx[k];
					nby += dy[k];
				}
				if (nrx == nbx && nry == nby) {
					if (map[nrx][nry] == 'O') continue;
					if (abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by)) {
						nrx -= dx[k];
						nry -= dy[k];
					}
					else {
						nbx -= dx[k];
						nby -= dy[k];
					}
				}
				if (visited[nrx][nry][nbx][nby]) continue;
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby });
			}
		}
		if (time == 10) return -1;
		time++;
		
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') {
				srx = i;
				sry = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				sbx = i;
				sby = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O') {
				hole_x = i;
				hole_y = j;
			}
		}
	}
	printf("%d\n",bfs());
	return 0;
}
