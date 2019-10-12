#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>

#define MAXN 10
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN];
int N, M;
int rx, ry, bx, by;
struct node {
	int rx;
	int ry;
	int bx;
	int by;
};
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int bfs() {
	queue<node> q;
	q.push({ rx,ry,bx,by });
	visited[rx][ry][bx][by] = true;
	int time = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int c_rx = q.front().rx;
			int c_ry = q.front().ry;
			int c_bx = q.front().bx;
			int c_by = q.front().by;
			if (map[c_rx][c_ry] == 'O' && map[c_bx][c_by] != 'O') return time;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int n_rx = c_rx;
				int n_ry = c_ry;
				int n_bx = c_bx;
				int n_by = c_by;
				bool flag = false;
				while (n_rx >= 0 && n_ry >= 0 && n_rx < N && n_ry < M) {
					if (map[n_rx][n_ry] == '#') {
						n_rx -= dx[k];
						n_ry -= dy[k];
						break;
					}
					else if (map[n_rx][n_ry] == 'O') {
						flag = true;
						break;
					}
					n_rx += dx[k];
					n_ry += dy[k];
				}
				while (n_bx >= 0 && n_by >= 0 && n_bx < N && n_by < M) {
					if (map[n_bx][n_by] == '#') {
						n_bx -= dx[k];
						n_by -= dy[k];
						break;
					}
					else if (map[n_bx][n_by] == 'O') {
						break;
					}
					n_bx += dx[k];
					n_by += dy[k];
				}
				if (n_rx == n_bx && n_ry == n_by && !flag) {
					if (c_rx - c_bx > 0) {
						if (k == 1) n_bx -= dx[k];
						else if (k == 3) n_rx -= dx[k];
					}
					else if (c_bx - c_rx > 0) {
						if (k == 1) n_rx -= dx[k];
						else if (k == 3) n_bx -= dx[k];
					}
					else if (c_ry - c_by > 0) {
						if (k == 0) n_by -= dy[k];
						else if (k == 2) n_ry -= dy[k];
					}
					else {
						if (k == 0) n_ry -= dy[k];
						else if (k == 2) n_by -= dy[k];
					}
				}
				if (visited[n_rx][n_ry][n_bx][n_by]) continue;
				visited[n_rx][n_ry][n_bx][n_by] = true;
				q.push({ n_rx,n_ry,n_bx,n_by });
			}
		}
		if (time == 10) return -1;
		time++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') rx = i, ry = j,map[i][j]='.';
			else if (map[i][j] == 'B') bx = i, by = j,map[i][j]='.';
		}
	}
	
	cout << bfs() <<"\n";
	return 0;
	
}