#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct node {
	int x;
	int y;
	int d;
};
int N, M;
char map[51][51];
int dist[51][51];
int water[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	scanf("%d%d", &N, &M);
	deque<node> q;
	memset(dist, -1, sizeof(dist));
	memset(water, -1, sizeof(water));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '*') {
				q.push_front({ i,j,0 });
				water[i][j] = 0;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'S') {
				q.push_back({ i,j,1 });
				dist[i][j] = 0;
				map[i][j] = '.';
			}
			
		}
	}
	int ans = 98765432;
	while (!q.empty()){
		int q_size = q.size();
		while (q_size--) {
			int x = q.front().x;
			int y = q.front().y;
			int d = q.front().d;
			q.pop_front();
			if (map[x][y] == 'D') ans = dist[x][y];
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny] == 'X') continue;
				if (d == 0 && water[nx][ny] ==-1) {
					if (map[nx][ny] == 'D') continue;
					water[nx][ny] = water[x][y] + 1;
					q.push_back({ nx,ny,0 });
				}
				else if (d == 1 && dist[nx][ny] == -1 && (dist[x][y]+1 < water[nx][ny] || water[nx][ny]==-1)) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push_back({ nx,ny,1 });
				}
			}
		}
	}
	if (ans == 98765432) printf("KAKTUS\n");
	else printf("%d\n", ans);
	return 0;
}