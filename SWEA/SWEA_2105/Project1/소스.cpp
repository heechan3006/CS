#include <iostream>
#include <cstring>

using namespace std;
int map[20][20];
int N;
bool visited[20][20];
bool used[101];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
int num_dir[4] = { 0, };
int ans = -1;
int sx, sy;
void dfs(int x, int y, int dir, int cnt) {
	if (dir > 3) return;
	if (x == sx && y == sy && dir == 3) {
		if (ans < cnt) ans = cnt;
		return;
	}
	for (int i = 1; i <= 2; i++) {
		int nx, ny;
		if (i == 1) {
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		else {
			if (dir == 3) continue;
			dir++;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (nx == sx && ny == sy) {
			dfs(nx, ny, dir, cnt);
			break;
		}
		if (!used[map[nx][ny]]) {
			used[map[nx][ny]] = true;
			dfs(nx, ny, dir, cnt+1);
			used[map[nx][ny]] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		memset(used, 0, sizeof(used));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = -1;
		
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i;
				sy = j;
				used[map[i][j]] = true;
				dfs(i, j, 0, 1);
				used[map[i][j]] = false;
			}
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}