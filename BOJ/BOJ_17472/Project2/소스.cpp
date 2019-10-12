#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 10
#define INF 987654321
using namespace std;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<bool> used;
int N, M;
int max_v=0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int u;
	int v;
	int weights;
};
vector<node> adj;
int ans = INF;
void bfs(int target) {
	queue<pair<int, int> > q;
	memset(visited, false, sizeof(visited));
	
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
			if (!visited[nx][ny] && map[nx][ny] == 0) {
				int len = 0;
				visited[nx][ny] = true;
				while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (map[nx][ny]) {
						if (dist[target][map[nx][ny]] > len && len>=2) {
							dist[target][map[nx][ny]] = len;
							dist[map[nx][ny]][target] = len;
							visited[nx][ny] = true;
							
						}
						break;
					}
					len++;
					nx += dx[k];
					ny += dy[k];
				}
			}
		}
	}
}
void dfs(int x, int y, int target) {
	visited[x][y] = true;
	map[x][y] = target;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, target);
		}
	}
}
bool check() {
	queue<int> q;
	vector<bool> visit_num(max_v+1,false);
	vector<vector<bool> > visit_load(max_v + 1, vector<bool>(max_v + 1, false));
	int cnt = max_v;
	for (int i = 0; i < used.size(); i++) {
		if (used[i]) {
			if (q.empty()) {
				q.push(adj[i].u);
				visit_num[adj[i].u] = true;
				cnt--;
			}
			visit_load[adj[i].u][adj[i].v] = true;
			visit_load[adj[i].v][adj[i].u] = true;
			
			
		}
	}
	while (!q.empty()) {
		int now = q.front();
		if (cnt == 0) return true;
		q.pop();
		for (int i = 1; i <= max_v; i++) {
			if (dist[now][i] != INF && visit_load[now][i] && !visit_num[i]) {
				visit_num[i] = true;
				q.push(i);
				cnt--;
			}
		}
	}
	return false;
}
void back(int now, int cnt, int sum) {
	
	if (cnt >= max_v-1) {
		if (check() && ans>sum) {
			ans = sum;
		}
		return;
	}
	for (int i = now; i < adj.size(); i++) {
		if (used[i]) continue;
		used[i] = true;
		back(now + 1, cnt+1,sum + adj[i].weights);
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
		for (int j=0;j<M;j++){
			if (!visited[i][j] && map[i][j]) {
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
		for (int j = i + 1; j <= max_v; j++) {
			if (dist[i][j] != INF) {
				adj.push_back({ i,j, dist[i][j] });
			}
		}
	}
	used.resize(adj.size(), false);

	back(0,0,0);
	if (ans == INF)cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}
