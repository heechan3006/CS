#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 200

using namespace std;

bool visited[MAXN][MAXN];

int N;
int sx, sy, ex, ey;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
int bfs() {
	queue<pair<int, int> > q;
	int cnt = 0;
	q.push({ sx,sy });
	visited[sx][sy] = true;
	while (!q.empty()) {
		int q_size = q.size();
		
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == ex && y == ey) {
				return cnt;
			}
			q.pop();
			for (int k = 0; k < 6; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny]) continue;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		cnt++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> sx >> sy >> ex >> ey;
	cout << bfs() <<"\n";
	return 0;
}