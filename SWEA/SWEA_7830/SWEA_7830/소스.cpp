#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 750
using namespace std;
int map[MAXN][MAXN];

int N, M;
int dx[] = { 1,1,-1,-1 };
int dy[] = { -1,1,1,-1 };
int check(int x, int y, int length) {
	if (length == 0) return 2;
	int nx = x;
	int ny = y;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		nx += dx[i] * length;
		ny += dy[i] * length;
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return 0;
	}
	
	int k = -1;
	for (int i = 0; i <length*4; i++) {
		if (i % length == 0) k++;
		x += dx[k];
		y += dy[k];
		if (i / length < 1 && map[x][y] == 0) return 0;
		if (map[x][y] == 0) return 1;
	}
	return 2;
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d%d", &N, &M);
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		int max_v = 0;
		int ans = 0;
		bool possible = false;
		for (int i = 0; (i < N)&& !possible; i++) {
			for (int j = 0; (j < M) && !possible; j++) {
				if (map[i][j]) {
					max_v = ans;
					bool flag = false;
					while (1){
						int res = check(i, j, max_v);
						if (res==1) {
							max_v++;
						}
						else if (res == 2) {
							ans = max_v + 1;
							max_v++;
						}
						else {
							break;
						}
					}
				}
			}
		}
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}