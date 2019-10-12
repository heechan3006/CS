#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool used[8 * 8];
int map[8][8];
int copy_map[8][8];
int ans;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> virus;
vector<pair<int, int>> v;
int cnt = 0;
int bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (used[i]) {
			copy_map[v[i].first][v[i].second] = 1;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	
	int res = cnt-3;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (copy_map[nx][ny] != 0) continue;
			copy_map[nx][ny] = 2;
			res--;
			q.push({ nx,ny });
		}
	}
	return res;
}
void dfs(int now, int num){
	if (num == 3) {
		int sum =bfs();
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = now; i < v.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i, num + 1);
			used[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				v.push_back({ i,j });
				cnt++;
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	ans = 0;
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}