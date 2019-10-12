#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct point { int x, y, d; };

int n, m, ex = -1, ey;
int sx, sy;
char a[100][100];
int dist[100][100][4];
queue<point> q;
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
const int mir[2][4] = { {3,2,1,0}, // '/'
	{2,3,0,1} };// '\'
bool check_dir(int now_dir, int next_dir) {
	if (now_dir == 0 && next_dir == 1) return false;
	else if (now_dir == 1 && next_dir == 0) return false;
	else if (now_dir == 2 && next_dir == 3) return false;
	else if (now_dir == 3 && next_dir == 2) return false;
	return true;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, d = q.front().d; q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '*') continue;
			if (d ==k){
				// basic 원래 진행방향대로 진행한 경우
				if (dist[nx][ny][d] == -1 || dist[nx][ny][d] > dist[x][y][d]) {
					q.push({ nx,ny,d });
					dist[nx][ny][d] = dist[x][y][d];
				}
			}
			else{
				// mirror 거울에 의해 진행방향이 90도 꺾인 경우	
				if (check_dir(d,k)){
					if (dist[nx][ny][k] == -1 || dist[nx][ny][k] > dist[x][y][d] + 1) {
						q.push({ nx,ny,k });
						dist[nx][ny][k] = dist[x][y][d] + 1;
					}
				}
			
			}
		}
	}
	int ans = 1e9;
	for (int k = 0; k < 4; k++)
		if (dist[ex][ey][k] != -1 && dist[ex][ey][k] < ans) ans = dist[ex][ey][k];
	printf("%d\n", ans);
}
int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d %d\n", &m, &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &a[i][j]);
			if (a[i][j] == 'C') {
				if (ex == -1)ex = i, ey = j;
				else sx = i, sy = j;
			}
		}
	}
	for (int k = 0; k < 4; k++) {
		
		q.push({ sx,sy,k });
		dist[sx][sy][k] = 0;
	}
	bfs();
	return 0;
}
