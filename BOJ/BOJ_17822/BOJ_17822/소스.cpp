#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 50 + 1

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];

bool visited[MAXN][MAXN];
struct node {
	int x;
	int d;
	int k;
};
int N, M, T;
node info[MAXN];
vector<pair<int, int> > v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void rotate_arr(int x, int dir, int k) {
	if (dir == 0) {
		int start = M - k;
		int idx = 0;
		while (idx<M) {
			copy_map[x][idx++] = map[x][start++];
			if (start >= M) start = 0;
		}
	}
	else {
		int start = k;
		int idx = 0;
		while (idx < M) {
			copy_map[x][idx++] = map[x][start++];
			if (start >= M) start = 0;
		}
	}
}
void dfs(int x, int y, int target) {
	visited[x][y] = true;
	v.push_back({ x,y });
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx <= 0 || nx > N) continue;
		if (ny < 0) ny = M - 1;
		else if (ny >= M) ny = 0;
		if (copy_map[nx][ny] == target && !visited[nx][ny]) {
			dfs(nx, ny, target);
		}
	}
}
void go(node info) {
	int x = info.x;
	int d = info.d;
	int k = info.k;
	memcpy(copy_map, map, sizeof(map));
	for (int i = x; i <= N; i += x) {
		rotate_arr(i, d, k);
	}
	memset(visited, false, sizeof(visited));
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && copy_map[i][j]) {
				v.clear();
				dfs(i, j, copy_map[i][j]);
				if (v.size() >= 2) {
					flag = true;
					for (int idx = 0; idx < v.size(); idx++) {
						copy_map[v[idx].first][v[idx].second] = 0;
					}
				}
			}
		}
	}
	if (!flag) {
		int total_sum = 0;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j]) {
					total_sum += copy_map[i][j];
					cnt++;
				}
			}
		}
		if (cnt > 0) {
			
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (!copy_map[i][j]) continue;
					if (copy_map[i][j]*cnt > total_sum) copy_map[i][j]--;
					else if (copy_map[i][j]*cnt < total_sum) copy_map[i][j]++;
				}
			}
		}
	}
	memcpy(map, copy_map, sizeof(copy_map));
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		info[i] = { x,d,k };
	}
	
	for (int i = 0; i < T; i++) {
		go(info[i]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			ans += map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
