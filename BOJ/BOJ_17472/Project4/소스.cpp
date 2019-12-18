#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAXN 10
#define INF 987654321
using namespace std;

int N, M;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
struct node {
	int u;
	int v;
	int weights;
};
int dist[7][7];
int max_v = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = INF;
vector<node> adj;
vector<bool> used;
bool check() {
	vector<vector<bool> > selected(max_v + 1, vector<bool>(max_v + 1, false));
	vector<bool> num(max_v + 1, false);
	queue<int> q;
	for (int i = 0; i < adj.size(); i++) {
		if (used[i]) {
			if (q.empty()) {
				num[adj[i].u] = true;
				q.push(adj[i].u);
			}
			selected[adj[i].u][adj[i].v] = true;
			selected[adj[i].v][adj[i].u] = true;
		}
	}
	int cnt = max_v - 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= max_v; i++) {
			if (dist[cur][i] == INF) continue;
			if (selected[cur][i] && !num[i]) {
				num[i] = true;
				cnt--;
				q.push(i);
			}
		}
	}
	return cnt == 0;
}
bool is_range(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}
void dfs(int x, int y) {

	visited[x][y] = true;
	map[x][y] = max_v;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (is_range(nx, ny) && !visited[nx][ny] && map[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
void bfs(int target) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == target) {
				q.push({ i,j });
				visited[i][j] = true;
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
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (!map[nx][ny]) {
				int len = 0;
				while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (map[nx][ny]) {
						if (len >= 2 && dist[target][map[nx][ny]] > len) {
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
void B_tracking(int now, int cnt, int sum) {
	if (cnt >= max_v - 1) {
		if (check()) {
			if (ans > sum) ans = sum;
		}
	}
	for (int i = now; i < adj.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			B_tracking(now + 1, cnt + 1, sum + adj[i].weights);
			used[i] = false;
		}
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
			if (!visited[i][j] && map[i][j]) {
				max_v++;
				dfs(i, j);
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
		for (int j = i + 1; j <= max_v; j++) {
			if (dist[i][j] != INF) adj.push_back({ i,j,dist[i][j] });
		}
	}
	used.resize(adj.size(), false);
	B_tracking(0, 0,0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}