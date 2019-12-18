#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAXN 10
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dist[7][7];
int max_v = 0;
int N, M;
struct node {
	int u;
	int v;
	int weights;
};
vector<node> adj;
vector<bool> used;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = INF;
void dfs(int x, int y, int target) {
	visited[x][y] = true;
	map[x][y] = target;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny]) {
			dfs(nx, ny, target);
		}
	}
}
void bfs(int target) {
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == target) q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 0) {
				int len = 0;
				while (1) {
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
					if (map[nx][ny]) {
						if (dist[target][map[nx][ny]] > len&& len >= 2) {
							dist[target][map[nx][ny]] = len;
							dist[map[nx][ny]][target] = len;
						}
						break;
					}
					nx += dx[k];
					ny += dy[k];
					len++;
				}
			}
		}
	}
}
bool check() {
	vector<vector<bool> > selected(max_v+1, vector<bool>(max_v+1, false));
	vector<bool> num(max_v + 1, false);
	queue<int> q;
	for (int i = 0; i < adj.size(); i++) {
		if (used[i]) {
			int u = adj[i].u;
			int v = adj[i].v;
			selected[u][v] = true;
			selected[v][u] = true;
			if (q.empty()) {
				q.push(u);
				num[u] = true;
			}
		}
	}
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= max_v; i++) {
			if (dist[now][i] == INF) continue;
			if (selected[now][i] && !num[i]) {
				num[i] = true;
				cnt++;
				q.push(i);
			}
		}
	}
	return cnt == max_v;
}
void go(int now, int cnt, int sum) {
	if (cnt > max_v) return;
	if (cnt >= max_v - 1) {
		if (check() && ans > sum) {
			ans = sum;
			return;
		}
	}
	for (int i = now; i < adj.size(); i++) {
		if (used[i]) continue;
		used[i] = true;
		go(i + 1, cnt + 1, sum + adj[i].weights);
		used[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				max_v++;
				dfs(i, j, max_v);
			}
		}
	}
	for (int i = 1; i <= max_v; i++) {
		for (int j = 1; j <= max_v; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= max_v; i++) {
		bfs(i);
	}
	for (int i = 1; i <= max_v; i++) {
		for (int j = i+1; j <= max_v; j++) {
			if (dist[i][j] != INF) adj.push_back({ i,j,dist[i][j] });
		}
	}
	used.resize(adj.size(),false);
	go(0, 0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}