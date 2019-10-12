#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int N, T;
int map[11][11];
bool visited[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;
bool check(int x, int y) {
	int cnt1 = 0;
	int cnt2 = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[nx][ny] == 0) {
			if (k == 0 || k == 1) cnt1++;
			else cnt2++;
		}
		
	}
	if (cnt1 >= 1 && cnt2 >= 1) return false;
	return true;
}

void bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int cx, cy, cur_time;
		tie(cx, cy, cur_time) = q.front();
		bool flag = false;
		
		if (cx == N - 1 && cy == N - 1) {
			if (ans > cur_time) ans = cur_time;
			return;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx,ny,cur_time+1 });
			}
			if (map[nx][ny] > 1) {
				if (cur_time % map[nx][ny] != map[nx][ny]-1) {
					flag = true;
				}
				else{
					int nnx = nx + dx[k];
					int nny = ny + dy[k];
					if (nnx < 0 || nny < 0 || nnx >= N || nny >= N) continue;
					if (map[nnx][nny] != 1) continue;
					visited[nx][ny] = true;
					q.push({ nx,ny,cur_time + 1 });
				}
			}
		}
		if (flag) q.push({ cx,cy,cur_time + 1 });
	}
	
}
int main() {
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	ans = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && check(i,j)) {
				memset(visited, false, sizeof(visited));
				map[i][j] = T;
				bfs();
				map[i][j] = 0;
				
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}