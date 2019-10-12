#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101];
int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int idx) {
	visited[x][y] = true;
	map[x][y] = idx;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == 1) {
			dfs(nx, ny, idx);
		}
	}
}
int bfs(int idx) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == idx) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	int res = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				
				if (map[nx][ny] == idx) continue;
				if (map[nx][ny] == 0 && !visited[nx][ny]){
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				else if (map[nx][ny] != 0 && map[nx][ny] != idx) {
					return res;
				}
			}
		}
		res++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				dfs(i, j,num);
				num++;
			}
		}
	}
	int ans = 98765432;
	for (int i = 1; i < num; i++) {
		memset(visited, false, sizeof(visited));
		int sum = bfs(i);
		if (ans > sum) ans = sum;
	}
	cout << ans << "\n";
}