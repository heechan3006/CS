#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[20][20];
bool visited[20][20];
bool num[101];
int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,1,-1};
int sx, sy;
int N;
int ans ;
int max_v ;
void dfs(int x, int y, int dir, int cnt) {
	// ±âÀú»ç·Ê
	if (x == sx && y == sy && dir == 3) {
		ans = max(ans, cnt);
		return;
	}
	
	for (int i = 1; i <= 2; i++) {
		int nx, ny, n_dir;
		if (i == 1) {
			n_dir = dir;
			nx = x + dx[n_dir];
			ny = y + dy[n_dir];
		}
		else {
			if (sx == x && sy == y) continue;
			if (dir == 3) continue;
			n_dir = dir + 1;
			nx = x + dx[n_dir];
			ny = y + dy[n_dir];

		}
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (nx == sx && ny == sy) {
			dfs(nx, ny, n_dir, cnt + 1);
			break;
		}
		if (!num[map[nx][ny]]) {
			num[map[nx][ny]] = true;
			dfs(nx, ny, n_dir, cnt + 1);
			num[map[nx][ny]] = false;
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		ans = -1;
		
		
		memset(num, false, sizeof(num));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j =0; j <N ;j++){
				cin >> map[i][j];
		
			}
		}
		for (int i = 0; i < N ; i++) {
			for (int j = 0; j < N ; j++) {
				num[map[i][j]] = true;
				sx = i;
				sy = j;

				dfs(i, j,0, 0);
				num[map[i][j]] = false;
			}
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
