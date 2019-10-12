#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 10
#define INF 987654321
using namespace std;
int N, M;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int max_v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[7][7];

struct node {
	int u;
	int v;
	int weights;
	bool operator < (const node& a) const
	{
		return a.weights < weights;
	}
};
int ans = INF;
vector<node> adj;
bool check(vector<node> tmp) {
	vector<bool> used(max_v, false);
	vector<vector<bool> > check(max_v, vector<bool> (max_v, false));
	for (int i = 0; i < tmp.size(); i++) {
		check[tmp[i].u][tmp[i].v] = true;
		check[tmp[i].v][tmp[i].u] = true;

	}
	queue<int> q;
	q.push(tmp[0].u);
	used[tmp[0].u] = true;
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < max_v; i++) {
			if (dist[now][i] != INF && check[now][i] && !used[i]) {
				used[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	if (cnt == max_v - 1) return true;
	return false;
}
void select(int now,int cnt,int sum,vector<bool>& used) {
	if (cnt >=max_v-2) {
		vector<node> tmp;
		for (int i = 0; i < adj.size(); i++) {
			if (used[i]) tmp.push_back(adj[i]);
		}
		if (check(tmp)) {
			if (ans > sum) ans = sum;
		}
	}
	for (int i = now; i < adj.size(); i++) {
		if (used[i]) continue;
		used[i] = true;
		select(now + 1, cnt + 1,sum + adj[i].weights,used);
		used[i] = false;
	}
}
void dfs(int x, int y, int target) {
	visited[x][y] = true;
	map[x][y] = target;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny]) {
			dfs(nx, ny, target);
		}
	}
}
void bfs(int start) {
	queue<pair<int, int> > q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == start) {
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
			if (map[nx][ny] == 0) {
				int len = 0;
				while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (map[nx][ny]) {

						if (len >= 2 && dist[start][map[nx][ny]] > len) {
							dist[start][map[nx][ny]] = len;
							dist[map[nx][ny]][start] = len;
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	max_v = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j]) {
				dfs(i, j, max_v);
				max_v++;
			}
		}
	}
	for (int i = 1; i < max_v; i++) {
		for (int j = 1; j < max_v; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i < max_v; i++) {
		bfs(i);	
	}
	for (int i = 1; i < max_v; i++) {
		for (int j = i + 1; j < max_v; j++) {
			if (dist[i][j] != INF) {
				adj.push_back({ i,j,dist[i][j] });
			}
		}
	}
	sort(adj.begin(), adj.end());
	vector<bool> used(max_v);
	select(0, 0, 0, used);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}