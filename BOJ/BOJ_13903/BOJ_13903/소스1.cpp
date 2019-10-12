#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAXN 1000
using namespace std;
bool visited[MAXN][MAXN];
int map[MAXN][MAXN];
vector<pair<int, int> > dirs;
int R, C, N;

int bfs() {
	queue<pair<int,int> > q;
	for (int i = 0; i < C; i++) {
		if (map[0][i]) {
			visited[0][i] = true;
			q.push({ 0,i});

		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == R - 1) return cnt;
			q.pop();
			for (int i = 0; i < N; i++) {
				int nx = x + dirs[i].first;
				int ny = y + dirs[i].second;
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (map[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny});
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		dirs.push_back({ x,y });
	}

	int ans = bfs();
	cout << ans << "\n";
	return 0;

}