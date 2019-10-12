#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 301
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny] || copy_map[nx][ny]== 0) continue;
		dfs(nx, ny);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			if (map[i][j]) q.push({ i,j });
		}
	}
	bool flag = false;
	int time = 0;
	while (!q.empty()) {
		time++;
		//copy map
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = copy_map[i][j];
			}
		}
		
		// bfs
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (!map[nx][ny]) cnt++;
			}
			copy_map[x][y] -= cnt;
			if (copy_map[x][y] < 0) copy_map[x][y] = 0;
			if (copy_map[x][y]) q.push({ x,y });
		}
		memset(visited, false, sizeof(visited));
		//dfs
		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] && !visited[i][j]) {
					dfs(i, j);
					num++;
				}
			}
		}
		if (num >= 2) {
			flag = true;
			break;
		}
		
	}
	if (flag) cout << time << "\n";
	else cout << "0\n";
}
