#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <tuple>
using namespace std;

char map[50][50];
int dist[50][50];

int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		scanf("%d%d", &N, &M);
		memset(dist, -1, sizeof(dist));
		memset(map, '.', sizeof(map));
		deque<tuple<int, int,int>> q;
		int ex, ey;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == 'S') {
					map[i][j] = '.';
					dist[i][j] = 0;
					q.push_back(make_tuple( i,j,0));
				}
				else if (map[i][j] == 'D') {
					ex = i;
					ey = j;
				}
				else if (map[i][j] == '*') {
					q.push_front(make_tuple( i,j,1 ));
				}
			}
		}
		bool flag = false;
		
		while (!q.empty() && !flag) {
			int q_size = q.size();
			while (q_size--) {
				int x, y, cur_mode;
				tie(x, y, cur_mode) = q.front();
				
				q.pop_front();
				
				if (x == ex && y == ey) {
					flag = true;
					break;
				}
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (map[nx][ny] == 'X') continue;
					if (cur_mode == 0) {
						if (dist[nx][ny] != -1 || map[nx][ny] == '*') continue;
						dist[nx][ny] = dist[x][y] + 1;
						q.push_back(make_tuple(nx,ny,cur_mode ));
					}
					else {
						if (map[nx][ny] == '.') {
							map[nx][ny] = '*';
							q.push_back(make_tuple(nx,ny,cur_mode));
						}
					}
				}
			}
		}
		printf("#%d ", test_case);
		if (flag) printf("%d\n", dist[ex][ey]);
		else printf("GAME OVER\n");
	}
	return 0;
}