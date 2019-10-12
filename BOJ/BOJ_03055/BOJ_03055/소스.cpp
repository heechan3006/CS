#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 50

int N, M;

int water[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	cin >> N >> M;
	vector<string> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(&water[0][0], &water[MAXN-1][MAXN-1], -1);
	
	
	queue<pair<int, int>> q;
	int sx, sy, ex, ey;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == '*') {
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
		}
	}
	
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}
			if (a[nx][ny] == 'X') continue;
			if (a[nx][ny] == 'D') continue;
			if (water[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				water[nx][ny] = water[cx][cy] + 1;
			}
		}
	}
	fill(&dist[0][0], &dist[MAXN - 1][MAXN - 1], -1);
	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int cx, cy;
		tie(cx, cy) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (a[nx][ny] == 'X') continue;
			if (dist[nx][ny] != -1) continue;
			if (water[nx][ny] != -1 && dist[cx][cy]+1 >= water[nx][ny]) {
				continue;
			}
			q.push(make_pair(nx, ny));
			dist[nx][ny] = dist[cx][cy] + 1;
			
		}
	}
	if (dist[ex][ey] == -1) {
		printf("KAKTUS");
	}
	else {
		printf("%d", dist[ex][ey]);
	}
	return 0;
}