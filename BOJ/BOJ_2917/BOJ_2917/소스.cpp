#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 500;

int N, M;

queue<pair<int, int> > tree;
int dist[MAXN][MAXN];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> wolf;
pair<int, int> home;


int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			scanf(" %1c", &tmp);
			if (tmp == '+') {
				dist[i][j] = 0;
				tree.push({ i,j });
			}
			else if (tmp == 'V') {
				wolf = { i,j };
			}
			else if (tmp == 'J') {
				home = { i,j };
			}
		}
	}
	while (tree.size()) {
		int x = tree.front().first;
		int y = tree.front().second;
		tree.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				tree.push({ nx,ny });
			}
		}
	}
	priority_queue<pair<pair<int,int>, pair<int, int> > > pq;
	
	pq.push({ {dist[wolf.first][wolf.second],dist[wolf.first][wolf.second]},wolf });
	int ans = dist[wolf.first][wolf.second];
	
	while (pq.size()) {
		int cur_dist = pq.top().first.first;
		int min_dist = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		if (x == home.first && y == home.second) {
			printf("%d\n", min_dist);
			break;
		}
		pq.pop();
		if (dist[x][y] == -1) continue;
		dist[x][y] = -1;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M ) {
				continue;
			}
			if (dist[nx][ny]!= -1) {
				
				pq.push({ {dist[nx][ny],min(dist[nx][ny],min_dist)}, {nx,ny} });
			}
		}
	}

	return 0;
}
