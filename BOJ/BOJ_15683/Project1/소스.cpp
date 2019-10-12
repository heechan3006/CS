#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int d[5] = {1,5,3,7,15};
int dirs[8];
int map[8][8];
int copy_map[8][8];
int N, M;
int ans;
struct info {
	int x;
	int y;
	int kind;
};
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

vector<info> v;
void check(int x, int y, int dir) {
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || y < 0 || x >= N || y >= M) return;
		if (copy_map[x][y] == 6) return;
		copy_map[x][y] = 1;
	}
}
void dfs(int now) {
	if (now == v.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].kind == 1) {
				check(v[i].x, v[i].y, dirs[i]);
			}
			else if (v[i].kind == 2) {
				check(v[i].x, v[i].y, dirs[i]);
				check(v[i].x, v[i].y, (dirs[i]+2)%4);
			}
			else if (v[i].kind == 3) {
				check(v[i].x, v[i].y, dirs[i]);
				check(v[i].x, v[i].y, (dirs[i] + 1) % 4);
			}
			else if (v[i].kind == 4) {
				check(v[i].x, v[i].y, dirs[i]);
				check(v[i].x, v[i].y, (dirs[i] + 1) % 4);
				check(v[i].x, v[i].y, (dirs[i] + 2) % 4);
			}
			else if (v[i].kind == 5) {
				check(v[i].x, v[i].y, dirs[i]);
				check(v[i].x, v[i].y, (dirs[i] + 1) % 4);
				check(v[i].x, v[i].y, (dirs[i] + 2) % 4);
				check(v[i].x, v[i].y, (dirs[i] + 3) % 4);
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0) sum++;
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		dirs[now] = i;
		dfs(now + 1);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				v.push_back({ i,j,map[i][j] });
			}
		}
	}
	ans = INF;
	dfs(0);
	printf("%d\n", ans);
}


