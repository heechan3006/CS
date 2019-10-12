#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
#include <tuple>
using namespace std;

char map[8][8];

bool visited[8][8];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int bfs() {
	queue<pair<int, int>> q;
	q.push({ 7,0 });
	visited[7][0] = true;
	while (1) {
		int Size = q.size();
		int ok = 0;

		while (Size--) {
			memset(visited, false, sizeof(visited));

			int cx, cy;
			tie(cx, cy) = q.front();
			q.pop();

			if (map[cx][cy] == '#') continue;
			if (cx == 0 && cy == 7) return 1;

			for (int k = 0; k < 8; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
				if (map[nx][ny] == '#') continue;
				q.push({ nx,ny });

			}
			q.push({ cx,cy });
			ok = 1;
		}
		if (ok == 0) return 0;
		for (int j = 0; j < 8; j++) {
			for (int i = 7; i > 0; i--) {
				if (map[i][j] == '#') map[i][j] = '.';
				map[i][j] = map[i - 1][j];
				map[i - 1][j] = '.';
			}
		}
	}
}
int main() {
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	printf("%d", bfs());
	return 0;
}