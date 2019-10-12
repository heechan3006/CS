#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, M;
int map[9][9];
int copy_map[9][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void go(int x, int y) {
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (copy_map[nx][ny] == 0) {
			copy_map[nx][ny] = 2;
			go(nx, ny);
		}
	}
}
int dfs(int ans) {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		go(v[i].first, v[i].second);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0) ans++;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

		}
	}
	int ans;
	int sum = 0;
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			if (map[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < N; x2++) {
				for (int y2 = 0; y2 < M; y2++) {
					if (map[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < N; x3++) {
						for (int y3 = 0; y3 < M; y3++) {
							if (map[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x2 == x3 && y2 == y3) continue;
							if (x1 == x3 && y1 == y3) continue;
							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;
							ans = dfs(0);
							map[x1][y1] = 0;
							map[x2][y2] = 0;
							map[x3][y3] = 0;
							if (sum < ans) sum = ans;
						}
					}
				}

			}
		}
	}
	printf("%d\n", sum);
}