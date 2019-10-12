#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int dist[101][101][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dir[] = { 0,2,1,3 };
int N, M;
struct node {
	int x;
	int y;
	int dir;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int sx, sy, s_dir, ex, ey, e_dir;
	cin >> sx >> sy >> s_dir >> ex >> ey >> e_dir;
	s_dir = dir[--s_dir];
	e_dir = dir[--e_dir];
	queue<node> q;
	q.push({ sx,sy,s_dir });
	dist[sx][sy][s_dir] = 0;
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dir;
		if (x == ex && y == ey && d == e_dir) {
			ans = dist[x][y][d];
			break;
		}
		q.pop();
		int right_dir = d + 1;
		if (right_dir > 3) right_dir = 0;
		int left_dir = d-1;
		if (left_dir < 0) left_dir = 3;
		if (dist[x][y][right_dir] == -1) {
			dist[x][y][right_dir] = dist[x][y][d] + 1;
			q.push({ x,y,right_dir });
		}
		if (dist[x][y][left_dir] == -1) {
			dist[x][y][left_dir] = dist[x][y][d] + 1;
			q.push({ x,y,left_dir });
		}

		for (int cnt = 1; cnt <= 3; cnt++){
			int nx = x + cnt*dx[d];
			int ny = y + cnt*dy[d];
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (map[nx][ny] == 1) break;
			if (dist[nx][ny][d] == -1) {
				dist[nx][ny][d] = dist[x][y][d] + 1;
				q.push({ nx,ny,d });
			}
	
			
		}
	}
	cout << ans << "\n";
}
