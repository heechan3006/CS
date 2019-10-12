#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 10
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int dist[7][7];
bool visited[MAXN][MAXN];
int N, M;
int max_v = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int u;
	int v;
	int weights;
};
vector<node> v;
vector<bool> used;
int ans = INF;
bool check() {
	vector<vector<bool> > selected(max_v+1, vector<bool>(max_v+1, false));
	vector<bool> num(max_v+1,false);
	queue<int> q;
	for (int i = 0; i < v.size(); i++) {
		if (used[i]) {
			if (q.empty()) {
				num[v[i].u] = true;
				q.push(v[i].u);
			}
			selected[v[i].u][v[i].v] = true;
			selected[v[i].v][v[i].u] = true;
		}
	}
	int cnt = max_v-1;
	
	q.push(1);
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
void backtracking(int now, int cnt,int sum) {
	
	if (cnt >= max_v - 1) {
		if (check()) {
			if (ans > sum) ans = sum;
		}

	}
	for (int i = now; i <v.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			backtracking(now + 1, cnt + 1,sum+v[i].weights);
			used[i] = false;
		}
	}
}
void dfs(int x, int y) {
	visited[x][y] = true;
	map[x][y] = max_v;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
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
				while (nx>=0&&ny>=0&&nx<N&&ny<M) {
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
			if (dist[i][j] != INF) v.push_back({ i,j,dist[i][j] });
		}
	}
	used.resize(v.size(),false);
	backtracking(0,0,0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;

}

