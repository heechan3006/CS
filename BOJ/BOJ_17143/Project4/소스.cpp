#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
using namespace std;

int R, C, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

struct shark {
	int s;
	int d;
	int z;
};
shark map[MAXN][MAXN];

void move_shark() {
	queue<pair<pair<int, int>, shark> > q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].z != 0) {
				q.push({ {i,j},map[i][j] });
				map[i][j] = { 0,0,0 };
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int speed = q.front().second.s;
		int dir = q.front().second.d;
		int z = q.front().second.z;
		q.pop();
		if (dir == 0 || dir == 1) speed %= 2 * (R - 1);
		else speed %= 2 * (C - 1);
		int cnt = speed;
		int nx = x;
		int ny = y;
		while (cnt--) {
			if (nx + dx[dir] < 0 || ny + dy[dir] < 0 || nx + dx[dir] >= R || ny + dy[dir] >= C) {
				if (dir == 0 || dir == 1) dir = 1 - dir;
				else dir = 5 - dir;
			}
			nx += dx[dir];
			ny += dy[dir];
		}
		if (map[nx][ny].z == 0) {
			map[nx][ny] = { speed,dir,z };
		}
		else {
			if (map[nx][ny].z < z) {
				map[nx][ny] = { speed,dir,z };
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--;
		c--;
		d--;
		map[r][c] = { s,d,z };
	}
	int ans = 0;
	for (int j = 0; j < C; j++) {
		if (M == 0) break;
		for (int i = 0; i < R; i++) {
			if (map[i][j].z != 0) {
				ans += map[i][j].z;
				map[i][j] = { 0,0,0 };
				M--;
				break;
			}
		}
		move_shark();
	}
	cout << ans << "\n";
	return 0;
}