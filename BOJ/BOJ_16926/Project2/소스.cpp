//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 300
using namespace std;
int N, M, R;
int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int dx[] = {0,1,0,-1};
int dy[] = { 1,0,-1,0 };
int dirs[] = { 1,0,3,2 };
void rotate_arr(int s,int cnt) {
	int sx = s;
	int sy = s;
	int nx=s,x = s;
	int ny=s,y = s;
	int d = 0;
	int nd = 0;
	while (cnt--) {
		if (nx + dx[dirs[d]] < s || ny + dy[dirs[d]] < s || nx + dx[dirs[d]] >= N - s || ny + dy[dirs[d]] >= M - s) {
			d = (d + 1) % 4;
		}
		nx += dx[dirs[d]];
		ny += dy[dirs[d]];
	}
	copy_map[nx][ny] = map[x][y];
	while (1) {
		if (nx + dx[dirs[d]] < s || ny + dy[dirs[d]] < s || nx + dx[dirs[d]] >= N - s || ny + dy[dirs[d]] >= M - s) {
			d = (d + 1) % 4;
		}
		if (x + dx[dirs[nd]] < s || y + dy[dirs[nd]] < s || x + dx[dirs[nd]] >= N - s || y + dy[dirs[nd]] >= M - s) {
			nd = (nd + 1) % 4;
		}
		nx += dx[dirs[d]];
		ny += dy[dirs[d]];
		x += dx[dirs[nd]];
		y += dy[dirs[nd]];
		if (x == sx && y == sy) break;
		copy_map[nx][ny] = map[x][y];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> R;
	int n = N;
	int m = M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	memset(copy_map, 0, sizeof(copy_map));
	
	for (int i = 0; i < min(N,M) / 2; i++) {
		rotate_arr(i,R%(2*(N+M-4*i-2)));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << copy_map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}