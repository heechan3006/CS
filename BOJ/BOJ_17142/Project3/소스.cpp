#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N,M;
vector<pair<int, int> > v;
vector<bool> used;
int target_cnt = 0;
int ans = INF;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs(queue<pair<int, int> > q) {
	int cnt = 0;
	int time = 0;
	while (!q.empty()) {
		int q_size = q.size();
		if (cnt == target_cnt) return time;
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (map[nx][ny] != 1 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					if (map[nx][ny] == 0) cnt++;
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
		queue<pair<int, int> > q;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < v.size(); i++) {
			if (used[i]) {
				q.push(v[i]);
				visited[v[i].first][v[i].second] = true;
			}
		}
		int time = bfs(q);
		if (time != -1 && ans > time) ans = time;
		return;
	}
	
	for (int i = now; i < v.size(); i++) {
		if (used[i]) continue;
		used[i] = true;
		dfs(i + 1, cnt + 1);
		used[i] = false;
	}
	
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j });
			else if (map[i][j] == 0) target_cnt++;
		}
	}
	
	used.resize(v.size(),false);
	dfs(0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}