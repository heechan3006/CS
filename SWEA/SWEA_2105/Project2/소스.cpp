#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 20

using namespace std;
int map[MAXN][MAXN];
bool used[101];

int N;
int ans;
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
int sx, sy;

void dfs(int x, int y, int dir, int length) {
	if (dir > 3) return;
	for (int i = 0; i < 2; i++) {
		int nx = x;
		int ny = y;
		if (i == 0) {
			nx += dx[dir];
			ny += dy[dir];
		}
		else {
			if (dir == 3) continue;
			dir++;
			nx += dx[dir];
			ny += dy[dir];
		}
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (used[map[nx][ny]]) {
			if (nx == sx && ny == sy && dir ==3) {
				if (ans < length) ans = length;
				return;
			}
			continue;
		}
		used[map[nx][ny]] = true;
		dfs(nx, ny, dir, length + 1);
		used[map[nx][ny]] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		ans = -1;

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i, sy = j;
				used[map[i][j]] = true;
				dfs(i, j, 0, 1);
				used[map[i][j]] = false;
			}
		}
		cout << "#" << test_case << " "<<ans<<"\n";
		
	}
	
	return 0;

}