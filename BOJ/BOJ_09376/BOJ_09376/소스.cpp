#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

int n, m;
char map[102][102];
int dist[102][102][3];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int t;
vector<pair<int, int>> person;


void bfs() {
	person.push_back(make_pair(0, 0));
	for (int k = 0; k < 3; k++) {
		int x = person[k].first;
		int y = person[k].second;
		queue<pair<int, int>> q2;
		dist[x][y][k] = 1;
		q2.push(make_pair(x, y));
		while (!q2.empty()) {
			int cx = q2.front().first;
			int cy = q2.front().second;
			q2.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >=0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && map[nx][ny] != '*' && (dist[nx][ny][k] == 0 || dist[nx][ny][k] > dist[cx][cy][k])) {
					if (map[nx][ny] == '#' && (dist[nx][ny][k] == 0 || dist[nx][ny][k] > dist[cx][cy][k] + 1)) {
						dist[nx][ny][k] = dist[cx][cy][k] + 1;
						q2.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] != '#') {
						dist[nx][ny][k] = dist[cx][cy][k];
						q2.push(make_pair(nx, ny));
					}
				}
	
			}
		}
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dist, 0, sizeof(dist));
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) map[i][j] = '.';
				else scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$') {
					map[i][j] = '.';
					person.push_back(make_pair(i, j));
				}
			}
		}
		bfs();
		int ans = 1e9;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (dist[i][j][0] > 0 && dist[i][j][1] > 0 && dist[i][j][2] > 0){
					int k = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];

					if (map[i][j] == '#') k -= 5;
					else k -= 3;
					if (ans > k) ans = k;
				}
			}
		}

		printf("%d\n", ans);
		person.clear();
	}
	return 0;
}