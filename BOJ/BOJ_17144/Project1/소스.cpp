#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 50

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int R, C, T;
int sx=-1, sy;
int ccw[] = { 0,3,2,1 };
int cw[] = { 0,1,2,3 };
void dust_spread() {
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copy_map[i][j] = 0;
			if (map[i][j] != 0 && map[i][j] != -1) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int cnt = 0;
		int A = map[x][y];
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (map[nx][ny] >= 0) {
				copy_map[nx][ny] += A / 5;
				cnt++;
			}
		}
		int remain = A - (A / 5) * cnt;
		copy_map[x][y] += remain;
		
	}
	memcpy(map, copy_map,sizeof(map));
}
void wind(int x, int y, int dir[]) {
	copy_map[x][y] = -1;
	y++;
	copy_map[x][y] = 0;
	
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y ;
		while (x + dx[dir[i]] >= 0 && y + dy[dir[i]] >= 0 && x + dx[dir[i]] < R && y + dy[dir[i]] < C) {
			
			nx = x + dx[dir[i]];
			ny = y + dy[dir[i]];
			if (copy_map[nx][ny] == -1) break;
			copy_map[nx][ny] = map[x][y];
			x = nx;
			y = ny;
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && sx == -1) {
				sx = i, sy = j;
			}
		}
	}
	
	while (T--) {
		dust_spread();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		wind(sx, sy, ccw);
		wind(sx + 1, sy, cw);
		memcpy(map, copy_map, sizeof(map));
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1 || map[i][j] == 0) continue;
			ans += map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}