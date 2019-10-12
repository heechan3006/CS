#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 1001
using namespace std;

char map[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N, M;
int bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> fire;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'J') {
				q.push({ i,j });
			}
			else if (map[i][j] == 'F') {
				fire.push({ i,j });
			}
		}
	}
	int res = 0;
	while (!q.empty()) {
		int fire_size = fire.size();
		while (fire_size--) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny] == 'J' || map[nx][ny] == '.') {
					map[nx][ny] = 'F';
					fire.push({ nx,ny });
				}
			}
		}
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == 0 || y == 0 || x == N - 1 || y == M - 1) return res + 1;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny] == '.') {
					map[nx][ny] = 'J';
					q.push({ nx,ny });
				}
			}
		}
		res++;
		
		
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int ans = bfs();
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
	return 0;
}