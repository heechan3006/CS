#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 20

using namespace std;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;
int sx, sy;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int shark_size= 2;
int tmp_cnt = 0;
struct node {
	int x;
	int y;
	int cnt;
	
	bool operator < (const node& a) const
	{
		if (a.cnt <= cnt) {
			if (a.cnt == cnt) {
				if (a.x <= x) {
					if (a.x == x) {
						if (a.y < y) return true;
						return false;
					}
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) sx = i, sy = j, map[i][j] = 0;
		}
	}
	int ans = 0;
	priority_queue<node> pq;
	pq.push({ sx,sy,0 });
	visited[sx][sy] = true;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		pq.pop();
		if (map[x][y] != 0 && map[x][y] < shark_size) {
			tmp_cnt++;
			if (tmp_cnt == shark_size) {
				shark_size++;
				tmp_cnt = 0;
			}
			map[x][y] = 0;
			ans += cnt;
			cnt = 0;
			memset(visited, false, sizeof(visited));
			while (!pq.empty()) pq.pop();

		}
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[nx][ny] > shark_size) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			pq.push({ nx,ny,cnt + 1 });
		}
	}

	cout << ans << "\n";
	return 0;
}