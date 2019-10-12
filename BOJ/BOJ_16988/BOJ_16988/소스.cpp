#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int ans = 0;
int map[20][20];
bool visited[20][20];
bool check[20][20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sum;
int total;
bool flag;
void dfs(int x, int y) {
	visited[x][y] = true;
	
	sum++;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == 2) {
			dfs(nx, ny);
		}
		else if (map[nx][ny] == 0) {
			flag = true;
		}
	}
}
void solve(int cnt) {
	if (cnt == 2) {
		memset(visited, false, sizeof(visited));
		
		total = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] == 2) {	
					sum = 0;
					flag = false;
					dfs(i, j);
					if (!flag) {
						total += sum;		
					}
				}
				if (ans < total) ans = total;
			}
		}
		
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j] && map[i][j] == 0) {
				check[i][j] = true;
				map[i][j] = 1;
				solve(cnt + 1);
				check[i][j] = false;
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}