#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 20
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
struct node {
	int x;
	int y;
	int s;
	
	bool operator < (const node& a) const {
		if (a.s < s) return true;
		else if (a.s > s) return false;
		if (a.x < x) return true;
		else if (a.x > x) return false;
		if (a.y < y) return true;
		return false;
	}
};
int N;
int sx, sy;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int cnt = 0;
int shark_size = 2;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<node> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pq.push({ i,j,0 });
				visited[i][j] = true;
				map[i][j] = 0;
			}
		}
	}
	
	
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int s = pq.top().s;
		pq.pop();
		if (map[x][y]!=0 && map[x][y] < shark_size) {
			map[x][y] = 0;
			cnt++;
			if (cnt == shark_size) {
				shark_size++;
				cnt = 0;
			}
			ans += s;
			while (!pq.empty()) pq.pop();
			pq.push({ x,y,0 });
			memset(visited, false, sizeof(visited));
			visited[x][y] = true;
			continue;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[nx][ny] <= shark_size && !visited[nx][ny]) {
				visited[nx][ny] = true;
				pq.push({ nx,ny,s + 1 });
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

