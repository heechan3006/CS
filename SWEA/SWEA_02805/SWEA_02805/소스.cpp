#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int map[50][50];
bool visited[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int t;
queue<pair<int, int>> q;
bool check_range(int x, int y, int start_x, int start_y) {
	int dist = abs(start_x - x) + abs(start_y - y);
	if (dist <= start_x) return true;
	else return false;
}
int bfs(int x, int y) {
	visited[x][y] = true;
	int ans = map[x][y];
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (check_range(nx, ny, x, y) && !visited[nx][ny]) {
				q.push({ nx,ny });
				ans += map[nx][ny];
				visited[nx][ny] = true;
			}
		}
	}
	return ans;
}
int main() {
	cin >> t;
	for (int test_case = 1 ; test_case <=t; test_case ++){
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		int start_x = (n - 1) / 2;
		int start_y = (n - 1) / 2;
		printf("#%d %d\n", test_case, bfs(start_x, start_y));
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}