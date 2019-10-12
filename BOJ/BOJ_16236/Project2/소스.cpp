#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 20
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;
int sx, sy;
int size_cnt = 2;
int shark_size = 2;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
struct node {
	int x;
	int y;
	int num;
};
bool compare(node a, node b) {
	if (a.x <= b.x) {
		if (a.x == b.x) {
			if (a.y < b.y) return true;
			return false;
		}
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i; sy = j;
				map[i][j] = 0;
			}
		}
	}
	queue<pair<int, int> > q;
	q.push({ sx,sy });
	visited[sx][sy] = true;
	
	int ans = 0;
	vector<node> v;
	while (1) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		while (!q.empty()) {
			cnt++;
			if (v.size() > 0 && v[0].num<cnt-1) {
				break;
			}
			int q_size = q.size();
			while (q_size--) {
				int x = q.front().first;
				int y = q.front().second;
				if (map[x][y] != 0 && map[x][y] < shark_size) {
					v.push_back({ x,y,cnt-1});
				}
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visited[nx][ny]) continue;
					if (map[nx][ny] <= shark_size) {
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		if (v.size() > 0) {
			sort(v.begin(), v.end(), compare);
			size_cnt--;
			if (size_cnt == 0) {
				shark_size++;
				size_cnt = shark_size;
			}
			ans += v[0].num;
			map[v[0].x][v[0].y] = 0;

			while (!q.empty()) q.pop();
			q.push({ v[0].x,v[0].y });
			visited[v[0].x][v[0].y] = true;
			v.clear();
		}
		else {
			break;
		}
		
	}
	
	cout << ans << "\n";
	return 0;
}