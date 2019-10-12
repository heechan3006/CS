#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAXN 1000
using namespace std;

int N, M;
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
int Group[MAXN * MAXN];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int idx;
queue < pair<int, int>> q;
void bfs(int x, int y) {
	q.push({x,y});
	visited[x][y] = idx;
	Group[idx] += 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] != 0) continue;
			if (map[nx][ny] == 1) {
				visited[nx][ny] = idx;	
				Group[idx] += 1;
				q.push({nx,ny});
				
			}
		}
	}
	
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	
	idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				idx++;
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				vector<int> v;
				bool stop = false;
				int sum = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (visited[nx][ny] == 0) continue;
					for (int d = 0; d < v.size(); d++) {
						if (v[d] == visited[nx][ny]) {
							stop = true;
							break;
						}
					}
					if (stop) {
						stop = false;
						continue;
					}
					v.push_back(visited[nx][ny]);
					sum += Group[visited[nx][ny]];
				}
				if (ans < sum) ans = sum;
			}
		}
	}
	printf("%d", ans+1);
}
