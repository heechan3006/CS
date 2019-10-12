#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[16][16];
int N;
int dx[] = { 1,0,1 };
int dy[] = { 1,1,0 };
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int sx = 0;
	int sy = 1;
	int cnt = 0;
	int nx, ny;
	queue<tuple<int, int,int>> q;
	q.push({ sx,sy,1 });
	while (!q.empty()) {
		int x,y,dir;
		tie(x, y, dir) = q.front();
		if (x == N - 1 && y == N - 1) cnt++;
		q.pop();
		if (dir == 0) {
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (0 <= nx && 0 <= ny && nx < N && ny < N) {
				if (!map[nx][ny] && !map[nx - 1][ny] && !map[nx][ny - 1]) {
					q.push({ nx,ny,dir });
				}
			}
			for (int i = 1; i < 3; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (!map[nx][ny]) {
					q.push({ nx,ny,i });
				}
			}
		}
		else{
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (0 <= nx && 0 <= ny && nx < N && ny < N) {
				if (!map[nx][ny]) {
					q.push({ nx,ny,dir });
				}
			}
			nx = x + dx[0];
			ny = y + dy[0];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!map[nx][ny]&& !map[nx-1][ny]&& !map[nx][ny-1]) {
				q.push({ nx,ny,0 });
			}
		}
		
	}
	printf("%d\n", cnt);
	return 0;
}