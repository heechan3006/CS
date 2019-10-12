#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];

vector<pair<int, int>> virus;
vector<int> selected;
int N, M;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int zero_cnt = 0;
int bfs() {
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < selected.size(); i++) {
		if (selected[i]) {
			q.push({ virus[i] });
			visited[virus[i].first][virus[i].second] = true;
		}
	}
	int cnt = 0;
	int tmp_cnt = zero_cnt;
	while (!q.empty()) {
		int q_size = q.size();
		if (tmp_cnt == 0) return cnt;
		while (q_size--){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k]; 
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] == 0 || map[nx][ny] == 2){
					if (map[nx][ny] == 0) tmp_cnt--;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
	
	return -1;
}
void dfs(int now, int cnt) {
	if (cnt == M) {
		int sum = bfs();
		if (ans > sum && sum != -1) ans = sum;
		return;
	}
	for (int i = now; i < selected.size(); i++) {
		if (selected[i]) continue;
		selected[i] = 1;
		dfs(i + 1, cnt + 1);
		selected[i] = 0;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				zero_cnt++;
			}
		}
	}
	ans = INF;
	selected.resize(virus.size(),0);
	dfs(0, 0);
	if (ans == INF) printf("-1\n");
	else{
		printf("%d", ans);
	}
	return 0;
}