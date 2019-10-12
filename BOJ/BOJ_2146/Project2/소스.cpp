#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100

using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;
void dfs(int x, int y,int idx) {
	map[x][y] = idx;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[nx][ny] == 1) {
			dfs(nx, ny, idx);
		}
	}
}
int bfs(queue<pair<int, int> > q , int target) {

	int dist = 0;
	while (!q.empty()) {
		int q_size = q.size();
		
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			if (map[x][y] != 0 && map[x][y] != target) return dist-1;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] != target) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		dist++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int idx = 2;
	for (int i = 0; i < N; i++) {
		for (int j =0;j < N; j++){
			if (map[i][j] == 0) continue;
			if (map[i][j] == 1) {
				dfs(i, j,idx);
				idx++;
			}
		}
	}
	int ans = 987654321;
	for (int k =2; k <= idx; k++){
		memset(visited, false, sizeof(visited));
		queue<pair<int, int> > q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == k) {
					q.push({ i,j });			
					visited[i][j] = true;
				}
			}
		}
		int res = bfs(q, k);
		if (res!=-1 && ans > res) ans = res;
		if (ans == 1) break;
		
	}
	cout << ans << "\n";
	return 0;
}