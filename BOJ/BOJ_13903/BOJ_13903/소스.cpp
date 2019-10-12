#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAXN 1000
#define INF 987654321
using namespace std;
int dist[MAXN][MAXN];
int map[MAXN][MAXN];
vector<pair<int, int> > dirs;
int R, C, N;
struct node {
	int x;
	int y;
	int d;
	bool operator < (node A) const {
		return d > A.d;
	}
};
int bfs() {
	priority_queue<node> pq;
	for (int i = 0; i < C; i++) {
		if (map[0][i]) {
			dist[0][i] = 0;
			pq.push({ 0,i,0 });
		}
	}
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int now_dist = pq.top().d;
		if (x == R - 1) return dist[x][y];
		if (dist[x][y] < now_dist) continue;
		pq.pop();
		for (int i = 0; i < N; i++) {
			int nx = x + dirs[i].first;
			int ny = y + dirs[i].second;
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (map[nx][ny] && dist[nx][ny] > now_dist + 1) {
				dist[nx][ny] = now_dist + 1;
				pq.push({ nx,ny,dist[nx][ny] });
			}
		}
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
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dist[i][j] = INF;
		}
	}
	
	int ans = bfs();
	cout << ans << "\n";
	return 0;
	
}