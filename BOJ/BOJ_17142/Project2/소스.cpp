//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];

int N, M;
vector<pair<int, int> > v;
vector<bool> visited;
int dist[MAXN][MAXN];
int ans = INF;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int total_cnt = 0;
int bfs(queue<pair<int, int> >q) {
	int time = 0;
	int remain_cnt = total_cnt;
	bool flag = false;
	while (!q.empty()) {
		int q_size = q.size();
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (copy_map[nx][ny] ==1) continue;
			if (dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
				if (copy_map[nx][ny] == 0) {
					time = max(time, dist[nx][ny]);
					remain_cnt--;
				}
			}
		}
		
	}
	if (remain_cnt > 0) return -1;
	return time;
}
void dfs(int now,int cnt) {
	if (ans == 0) return;
	if (cnt == M) {
		memcpy(copy_map, map, sizeof(map));
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int> > q;
		for (int i = 0; i < v.size(); i++) {
			if (visited[i]) {
				q.push(v[i]);
				dist[v[i].first][v[i].second] = 0;
			}
			
		}
		int time = bfs(q);
		if (time != -1 && ans > time) ans = time;
		return ;
	}
	for (int i = now; i < v.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i + 1,cnt+1);
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 0)total_cnt++;
		}
	}
	visited.resize(v.size(),false);
	dfs(0,0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}
