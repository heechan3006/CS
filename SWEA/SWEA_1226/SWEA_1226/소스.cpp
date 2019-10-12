#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[16][16];
bool visited[16][16];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	//freopen("real_input.txt", "r", stdin);
	int sx, sy, ex, ey;
	int t;
	for (int test_case=1; test_case <= 10; test_case++){
		scanf("%d", &t);
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					sx = i;
					sy = j;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({ sx,sy });
		visited[sx][sy] = true;
		bool possible = false;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (map[cx][cy] == 3) possible = true;
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
				if (visited[nx][ny]) continue;
				if (!visited[nx][ny] && map[nx][ny] != 1) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		printf("#%d %d\n", t,possible);
	}
	return 0;
}