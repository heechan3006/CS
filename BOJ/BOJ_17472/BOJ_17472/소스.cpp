#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
const int INF = 987654321;
const int MAXN = 10;
using namespace std;
struct node {
	int u;
	int v;
	int weights;
	bool operator < (const node& a) const
	{
		return weights < a.weights;
	};
};
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[7][7];
bool used[7];
vector<node> adj;
int max_v = 1;
int parent[7];
int ans = 0;

void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (!visited[nx][ny] && map[nx][ny]==1) {
			dfs(nx, ny, cnt);
		}
	}
}

void bfs(int u, int v) {
	memset(visited, false, sizeof(visited));
	int sx = -1, sy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == u) {
				sx = i, sy = j;
				break;
			}
		}
	}
	if (sx == -1) return;
	queue<pair<pair<int, int>, int> > q;
	q.push({ {sx,sy},map[sx][sy] });
	visited[sx][sy] = true;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int idx = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == idx ) {
				visited[nx][ny] = true;
				q.push({ {nx,ny},idx });
			}
			else if (map[nx][ny] == 0) {
				int len = 0;
				while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (map[nx][ny] != 0) {
						if (map[nx][ny] == v && len >= 2 && (dist[idx][map[nx][ny]]==-1 || dist[idx][map[nx][ny]] > len)) {
							dist[idx][map[nx][ny]] = len;
							dist[map[nx][ny]][idx] = len;
							
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
int find(int u) {
	if (u == parent[u]) return u;
	return find(parent[u]);
}
bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	parent[v] = u;
	return true;
}
bool check() {
	int u = parent[1];
	for (int i = 2; i < max_v; i++) {
		int v = find(i);
		if (u != v) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				dfs(i, j, max_v);
				max_v++;
			}
		}
	}
	
	for (int i = 1; i < max_v; i++) {
		for (int j = i + 1; j < max_v; j++) {
			bfs(i, j);
		}
	}
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	adj.clear();
	for (int i = 1; i < max_v; i++) {
		for (int j = i+1; j < max_v; j++) {
			if (dist[i][j] != -1) {
				adj.push_back({ i,j,dist[i][j] });
			}
		}
	}
	sort(adj.begin(), adj.end());
	
	for (int i = 1; i < max_v; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < adj.size(); i++) {
		if (Union(adj[i].u, adj[i].v)) {
			ans += adj[i].weights;
		}
	}
	if (ans == 0) cout << "-1\n";
	else {
		if (check() == true) cout << ans << "\n";
		else cout << "-1\n";
	}
	return 0;
}

