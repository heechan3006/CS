#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int total_cnt = 0;

int N, M;
vector<pair<int, int> > virus;
vector<bool> used;
int ans = INF;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs() {
	queue<pair<int, int> > q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < virus.size(); i++) {
		if (used[i]) {
			q.push(virus[i]);
			visited[virus[i].first][virus[i].second] = true;
		}
	}
	int time = 0;
	int cnt = 0;
	while (!q.empty()) {
		int q_size = q.size();
		if (cnt == total_cnt) return time;
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] != 1) {
					if (!map[nx][ny]) cnt++;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		time++;
	}
	return -1;
}
void dfs(int now, int cnt) {
	if (ans == 0) return;
	if (cnt == M) {
		int sum = bfs();
		if (sum != -1 && ans > sum) ans = sum;
		return;
	}
	for (int i = now; i < virus.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i + 1, cnt + 1);
			used[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ i,j });
			else if (map[i][j] == 0) total_cnt++;
		}
	}
	used.resize(virus.size(), false);
	dfs(0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}