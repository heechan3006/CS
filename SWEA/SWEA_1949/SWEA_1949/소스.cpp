#include <iostream>
#include <cstring>

using namespace std;

int map[8][8];
bool visited[8][8];
int N, K;
int max_h;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans ;
void dfs(int x, int y, bool is_used, int cnt) {
	if (ans < cnt) {
		ans = cnt;
	}
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] < map[x][y]) {
		
			dfs(nx, ny, is_used,cnt+1);
			
		}
		if (is_used ==false && (map[nx][ny] >= map[x][y])) {
			if (map[nx][ny]-K< map[x][y]){
				int tmp = map[nx][ny];
				is_used = true;
				map[nx][ny] = map[x][y] - 1;
				dfs(nx, ny, is_used, cnt + 1);
				map[nx][ny] = tmp;
				is_used = false;
			}
			
		}
		
	}
	visited[x][y] = false;
	if (ans < cnt) {
		ans = cnt;
	}
	
}
int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	for (int test_case= 1; test_case<=t; test_case++){
		cin >> N >> K;
		max_h = 0;
		ans = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > max_h) max_h = map[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_h) {
					
					dfs(i, j, false,1);
					
				}
			}
		}
		cout << "#" << test_case << " " << ans << "\n";
		
	}
	return 0;
}