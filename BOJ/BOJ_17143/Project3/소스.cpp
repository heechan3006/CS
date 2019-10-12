#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 101

using namespace std;
struct shark {
	int x;
	int y;
	int speed;
	int dir;
	int z;
};
vector<shark> map[MAXN][MAXN];
int R, C, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int change_dir(int mode) {
	if (mode == 0) return 1;
	else if (mode == 1) return 0;
	else if (mode == 2) return 3;
	else return 2;
}
bool move_shark() {
	queue<shark> q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size()) {
				q.push(map[i][j][0]);
				map[i][j].pop_back();
			}
		}
	}
	if (!q.size()) return false;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int speed = q.front().speed;
		int dir = q.front().dir;
		int z = q.front().z;
		q.pop();
		
		if (dir < 2) {
			speed %= 2 * (R - 1);
			
			x += speed * dx[dir];
			
			while (x <= 0 || x > R) {
				if (x <= 0) dir = 1, x = 2 - x;
				if (x > R) dir = 0, x = 2 * R - x;
			}

			if (map[x][y].size()) {
				if (map[x][y][0].z < z) {
					map[x][y].pop_back();
					map[x][y].push_back({ x,y,speed,dir,z });
				}
			}
			else {
				map[x][y].push_back({ x,y,speed,dir,z });
			}
		}
		else {
			speed %= 2 * (C - 1);
			y += speed * dy[dir];
			while (y<=0 || y>C) {
				if (y <= 0) dir = 2, y = 2 - y;
				if (y > C) dir = 3, y = 2 * C - y;
			}
			if (map[x][y].size()) {
				if (map[x][y][0].z < z) {
					map[x][y].pop_back();
					map[x][y].push_back({ x,y,speed,dir,z });
				}
			}
			else {
				map[x][y].push_back({ x,y,speed,dir,z });
			}
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> M;
	while (M--) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		d--;
		map[r][c].push_back({ r,c,s,d,z });
	}
	int ans = 0;
	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
			if (map[i][j].size() > 0) {
				ans += map[i][j][0].z;
				map[i][j].pop_back();
				break;
			}
		}
		int flag = move_shark();
		if (!flag) {
			cout << ans << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}