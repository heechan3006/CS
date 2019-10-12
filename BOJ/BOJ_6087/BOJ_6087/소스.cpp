#include <iostream>
#include <queue>

using namespace std;

int dist[100][100];
char map[100][100];
int N, M;
int ex = -1;
int ey = -1;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'C') {
				if (ex == -1) {
					ex = i;
					ey = j;
				}
				else {
					q.push({ i,j });
					dist[i][j] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			while (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] != '*') {
				if (!dist[nx][ny]) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
	cout << dist[ex][ey]-1 << "\n";
	return 0;
}