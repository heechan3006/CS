#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char map[25][25];
bool visited[25][25];

char block[] = { '|','-','+','1','2','3','4' };

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int N, M;
int sx, sy, ex, ey;
int cnt;
struct node {
	int x;
	int y;
	int dir;
};
bool is_range(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}
void bfs() {
	int sd = -1;
	int ed = -1;
	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		int e_nx = ex + dx[i];
		int e_ny = ey + dy[i];
		if (!is_range(nx,ny)) continue;
		if (map[nx][ny] != '.') sd = i;
	}
	for (int i = 0; i < 4; i++) {
		int nx = ex + dx[i];
		int ny = ey + dy[i];
		if (!is_range(nx, ny)) continue;
		if (map[nx][ny] != '.') ed = i;
	}
	if (sd != -1){
		queue<node> q;
		q.push({ sx,sy,sd});
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int d = q.front().dir;
			q.pop();
			int nx = x + dx[d];
			int ny = y + dy[d];
			if ()
			
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cnt = 2;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'M') {
				sx = i, sy = j;
			}
			else if (map[i][j] == 'Z') {
				ex = i, ey = j;
			}
		}
	}
	bfs();
}