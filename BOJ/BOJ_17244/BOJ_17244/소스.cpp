#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 50
#define INF 987654321
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;
int sx, sy, ex, ey;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int target_cnt = 0;
int ans = INF;
int dist[7][7];
int used[7];
bool used_num[7];
vector<pair<int, int> > v;
int bfs(pair<int,int> start, pair<int,int> end) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > q;
	q.push(start);
	visited[start.first][start.second] = true;
	int cnt = 0;
	int sum = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == end.first && y == end.second) {
				return cnt;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] == '#') continue;
				else {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
}
void dfs(int now, int cnt) {
	if (cnt == target_cnt) {
		int sum = 0;
		for (int i = 0; i < target_cnt + 1; i++) {
			sum += dist[used[i]][used[i + 1]];
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 1; i < target_cnt + 1; i++) {
		if (used_num[i]) continue;
		used_num[i] = true;
		used[now] = i;
		dfs(now + 1, cnt + 1);
		used_num[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d", &M, &N);
	vector<pair<int, int> >tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'S') {
				sx = i, sy = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'E') {
				ex = i, ey = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'X') {
				target_cnt++;
				tmp.push_back({ i,j });
			}
		}
	}
	v.push_back({ sx,sy });
	for (int i = 0; i < tmp.size(); i++) {
		v.push_back(tmp[i]);
	}
	v.push_back({ ex,ey });
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int d = bfs(v[i],v[j]);
			dist[i][j] = d;
			dist[j][i] = d;
		}
	}
	used[0] = 0;
	used[target_cnt + 1] = target_cnt + 1;
	used_num[0] = true;
	used_num[target_cnt + 1] = true;
	dfs(1, 0);
	cout << ans << "\n";
	return 0;
}